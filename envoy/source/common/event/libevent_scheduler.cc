#include "common/event/libevent_scheduler.h"

#include "common/common/assert.h"
#include "common/event/timer_impl.h"

#include "event2/util.h"

namespace Envoy {
namespace Event {

namespace {
void recordTimeval(Stats::Histogram& histogram, const timeval& tv) {
  histogram.recordValue(tv.tv_sec * 1000000 + tv.tv_usec);
}
} // namespace

LibeventScheduler::LibeventScheduler() : libevent_(event_base_new()) {
  // The dispatcher won't work as expected if libevent hasn't been configured to use threads.
  RELEASE_ASSERT(Libevent::Global::initialized(), "");
}

TimerPtr LibeventScheduler::createTimer(const TimerCb& cb, Dispatcher& dispatcher) {
  return std::make_unique<TimerImpl>(libevent_, cb, dispatcher);
};

void LibeventScheduler::run(Dispatcher::RunType mode) {
  int flag = 0;
  switch (mode) {
  case Dispatcher::RunType::NonBlock:
    flag = EVLOOP_NONBLOCK;
#ifdef WIN32
    // On Windows, EVLOOP_NONBLOCK will cause the libevent event_base_loop to run forever.
    // This is because libevent only supports level triggering on Windows, and so the write
    // event callbacks will trigger every time through the loop. Adding EVLOOP_ONCE ensures the
    // loop will run at most once
    flag |= EVLOOP_NONBLOCK | EVLOOP_ONCE;
#endif
    break;
  case Dispatcher::RunType::Block:
    // The default flags have 'block' behavior. See
    // http://www.wangafu.net/~nickm/libevent-book/Ref3_eventloop.html
    break;
  case Dispatcher::RunType::RunUntilExit:
    flag = EVLOOP_NO_EXIT_ON_EMPTY;
    break;
  }
  event_base_loop(libevent_.get(), flag);
}

void LibeventScheduler::loopExit() { event_base_loopexit(libevent_.get(), nullptr); }

void LibeventScheduler::initializeStats(DispatcherStats* stats) {
  stats_ = stats;
  // These are thread safe.
  evwatch_prepare_new(libevent_.get(), &onPrepare, this);
  evwatch_check_new(libevent_.get(), &onCheck, this);
}

void LibeventScheduler::onPrepare(evwatch*, const evwatch_prepare_cb_info* info, void* arg) {
  // `self` is `this`, passed in from evwatch_prepare_new.
  auto self = static_cast<LibeventScheduler*>(arg);

  // Record poll timeout and prepare time for this iteration of the event loop. The timeout is the
  // expected polling duration, whereas the actual polling duration will be the difference measured
  // between the prepare time and the check time immediately after polling. These are compared in
  // onCheck to compute the poll_delay stat.
  self->timeout_set_ = evwatch_prepare_get_timeout(info, &self->timeout_);
  evutil_gettimeofday(&self->prepare_time_, nullptr);

  // If we have a check time available from a previous iteration of the event loop (that is, all but
  // the first), compute the loop_duration stat.
  if (self->check_time_.tv_sec != 0) {
    timeval delta;
    evutil_timersub(&self->prepare_time_, &self->check_time_, &delta);
    recordTimeval(self->stats_->loop_duration_us_, delta);
  }
}

void LibeventScheduler::onCheck(evwatch*, const evwatch_check_cb_info*, void* arg) {
  // `self` is `this`, passed in from evwatch_check_new.
  auto self = static_cast<LibeventScheduler*>(arg);

  // Record check time for this iteration of the event loop. Use this together with prepare time
  // from above to compute the actual polling duration, and store it for the next iteration of the
  // event loop to compute the loop duration.
  evutil_gettimeofday(&self->check_time_, nullptr);
  if (self->timeout_set_) {
    timeval delta, delay;
    evutil_timersub(&self->check_time_, &self->prepare_time_, &delta);
    evutil_timersub(&delta, &self->timeout_, &delay);

    // Delay can be negative, meaning polling completed early. This happens in normal operation,
    // either because I/O was ready before we hit the timeout, or just because the kernel was
    // feeling saucy. Disregard negative delays in stats, since they don't indicate anything
    // particularly useful.
    if (delay.tv_sec >= 0) {
      recordTimeval(self->stats_->poll_delay_us_, delay);
    }
  }
}

} // namespace Event
} // namespace Envoy