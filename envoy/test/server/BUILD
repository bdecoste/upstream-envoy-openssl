licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_fuzz_test",
    "envoy_cc_test",
    "envoy_cc_test_binary",
    "envoy_cc_test_library",
    "envoy_package",
    "envoy_select_hot_restart",
)
load(
    "//source/extensions:all_extensions.bzl",
    "envoy_all_extensions",
)

envoy_package()

envoy_cc_test(
    name = "backtrace_test",
    srcs = ["backtrace_test.cc"],
    tags = ["backtrace"],
    deps = ["//source/server:backtrace_lib"],
)

envoy_cc_test(
    name = "configuration_impl_test",
    srcs = ["configuration_impl_test.cc"],
    data = [
        "//test/config/integration/certs",
    ],
    deps = [
        "//source/common/api:api_lib",
        "//source/common/event:dispatcher_lib",
        "//source/common/http:context_lib",
        "//source/common/upstream:cluster_manager_lib",
        "//source/extensions/stat_sinks/statsd:config",
        "//source/extensions/transport_sockets/raw_buffer:config",
        "//source/server:configuration_lib",
        "//test/common/upstream:utility_lib",
        "//test/mocks:common_lib",
        "//test/mocks/network:network_mocks",
        "//test/mocks/server:server_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "connection_handler_test",
    srcs = ["connection_handler_test.cc"],
    deps = [
        "//source/common/common:utility_lib",
        "//source/common/network:address_lib",
        "//source/common/stats:stats_lib",
        "//source/server:active_raw_udp_listener_config",
        "//source/server:connection_handler_lib",
        "//test/mocks/network:network_mocks",
        "//test/mocks/server:server_mocks",
        "//test/test_common:network_utility_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)

envoy_cc_test(
    name = "drain_manager_impl_test",
    srcs = ["drain_manager_impl_test.cc"],
    deps = [
        "//source/server:drain_manager_lib",
        "//test/mocks/server:server_mocks",
    ],
)

envoy_cc_test(
    name = "hot_restart_impl_test",
    srcs = envoy_select_hot_restart(["hot_restart_impl_test.cc"]),
    deps = [
        "//source/common/api:os_sys_calls_lib",
        "//source/common/stats:stats_lib",
        "//source/server:hot_restart_lib",
        "//test/mocks/server:server_mocks",
        "//test/test_common:logging_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)

envoy_cc_test(
    name = "hot_restarting_parent_test",
    srcs = envoy_select_hot_restart(["hot_restarting_parent_test.cc"]),
    deps = [
        "//source/common/stats:stats_lib",
        "//source/server:hot_restart_lib",
        "//test/mocks/server:server_mocks",
    ],
)

envoy_cc_test(
    name = "guarddog_impl_test",
    srcs = ["guarddog_impl_test.cc"],
    deps = [
        "//include/envoy/common:time_interface",
        "//source/common/api:api_lib",
        "//source/common/common:macros",
        "//source/common/common:utility_lib",
        "//source/common/stats:stats_lib",
        "//source/server:guarddog_lib",
        "//test/mocks:common_lib",
        "//test/mocks/server:server_mocks",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "options_impl_test",
    srcs = ["options_impl_test.cc"],
    deps = [
        "//source/common/common:utility_lib",
        "//source/common/stats:stats_lib",
        "//source/server:options_lib",
        "//test/mocks/api:api_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:logging_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
        "//test/test_common:utility_lib",
        "@envoy_api//envoy/config/bootstrap/v2:bootstrap_cc",
    ],
)

envoy_cc_test(
    name = "overload_manager_impl_test",
    srcs = ["overload_manager_impl_test.cc"],
    deps = [
        "//include/envoy/registry",
        "//source/common/stats:isolated_store_lib",
        "//source/extensions/resource_monitors/common:factory_base_lib",
        "//source/server:overload_manager_lib",
        "//test/mocks/event:event_mocks",
        "//test/mocks/protobuf:protobuf_mocks",
        "//test/mocks/thread_local:thread_local_mocks",
        "//test/test_common:registry_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "lds_api_test",
    srcs = ["lds_api_test.cc"],
    data = [
        "//test/config/integration/certs",
    ],
    deps = [
        "//source/common/protobuf:utility_lib",
        "//source/server:lds_api_lib",
        "//test/mocks/config:config_mocks",
        "//test/mocks/protobuf:protobuf_mocks",
        "//test/mocks/server:server_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:utility_lib",
        "@envoy_api//envoy/api/v2:lds_cc",
    ],
)

envoy_cc_test_library(
    name = "listener_manager_impl_test_lib",
    hdrs = ["listener_manager_impl_test.h"],
    deps = [
        "//source/server:listener_manager_lib",
        "//test/mocks/network:network_mocks",
        "//test/mocks/server:server_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:test_time_lib",
    ],
)

envoy_cc_test(
    name = "listener_manager_impl_test",
    srcs = ["listener_manager_impl_test.cc"],
    data = ["//test/extensions/transport_sockets/tls/test_data:certs"],
    deps = [
        ":listener_manager_impl_test_lib",
        ":utility_lib",
        "//source/common/api:os_sys_calls_lib",
        "//source/common/config:metadata_lib",
        "//source/common/network:addr_family_aware_socket_option_lib",
        "//source/common/network:listen_socket_lib",
        "//source/common/network:socket_option_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf",
        "//source/extensions/filters/listener/original_dst:config",
        "//source/extensions/filters/listener/tls_inspector:config",
        "//source/extensions/filters/network/http_connection_manager:config",
        "//source/extensions/filters/network/tcp_proxy:config",
        "//source/extensions/transport_sockets/raw_buffer:config",
        "//source/extensions/transport_sockets/tls:config",
        "//source/extensions/transport_sockets/tls:ssl_socket_lib",
        "//source/server:active_raw_udp_listener_config",
        "//test/test_common:registry_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)

# Stand-alone quic test because of FIPS.
envoy_cc_test(
    name = "listener_manager_impl_quic_only_test",
    srcs = ["listener_manager_impl_quic_only_test.cc"],
    tags = ["nofips"],
    deps = [
        ":listener_manager_impl_test_lib",
        "//source/extensions/quic_listeners/quiche:active_quic_listener_config_lib",
        "//source/extensions/transport_sockets/raw_buffer:config",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)

envoy_cc_test(
    name = "filter_chain_manager_impl_test",
    srcs = ["filter_chain_manager_impl_test.cc"],
    data = ["//test/extensions/transport_sockets/tls/test_data:certs"],
    deps = [
        ":utility_lib",
        "//source/common/api:os_sys_calls_lib",
        "//source/common/config:metadata_lib",
        "//source/common/network:addr_family_aware_socket_option_lib",
        "//source/common/network:listen_socket_lib",
        "//source/common/network:socket_option_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf",
        "//source/extensions/filters/listener/original_dst:config",
        "//source/extensions/filters/listener/tls_inspector:config",
        "//source/extensions/filters/network/http_connection_manager:config",
        "//source/extensions/transport_sockets/raw_buffer:config",
        "//source/extensions/transport_sockets/tls:config",
        "//source/extensions/transport_sockets/tls:ssl_socket_lib",
        "//source/server:filter_chain_manager_lib",
        "//source/server:listener_manager_lib",
        "//test/mocks/network:network_mocks",
        "//test/mocks/server:server_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:registry_lib",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:test_time_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)

envoy_cc_fuzz_test(
    name = "server_fuzz_test",
    srcs = ["server_fuzz_test.cc"],
    corpus = "server_corpus",
    deps = [
        "//source/common/thread_local:thread_local_lib",
        "//source/server:proto_descriptors_lib",
        "//source/server:server_lib",
        "//test/integration:integration_lib",
        "//test/mocks/server:server_mocks",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:environment_lib",
        "//test/test_common:test_time_lib",
    ] + envoy_all_extensions(),
)

filegroup(
    name = "runtime_test_data",
    srcs = glob(["test_data/runtime/**"]),
)

filegroup(
    name = "static_validation_test_data",
    srcs = glob(["test_data/static_validation/**"]),
)

envoy_cc_test(
    name = "server_test",
    srcs = ["server_test.cc"],
    data = [
        ":cluster_dupe_bootstrap.yaml",
        ":cluster_health_check_bootstrap.yaml",
        ":empty_bootstrap.yaml",
        ":invalid_bootstrap.yaml",
        ":invalid_layered_runtime_duplicate_name.yaml",
        ":invalid_layered_runtime_missing_name.yaml",
        ":invalid_layered_runtime_no_layer_specifier.yaml",
        ":invalid_legacy_runtime_bootstrap.yaml",
        ":invalid_runtime_bootstrap.yaml",
        ":node_bootstrap.yaml",
        ":node_bootstrap_no_admin_port.yaml",
        ":node_bootstrap_with_admin_socket_options.yaml",
        ":node_bootstrap_without_access_log.yaml",
        ":runtime_bootstrap.yaml",
        ":runtime_test_data",
        ":static_validation_test_data",
        ":stats_sink_bootstrap.yaml",
        ":zipkin_tracing.yaml",
    ],
    deps = [
        "//source/common/common:version_lib",
        "//source/extensions/access_loggers/file:config",
        "//source/extensions/filters/http/buffer:config",
        "//source/extensions/filters/http/dynamo:config",
        "//source/extensions/filters/http/grpc_http1_bridge:config",
        "//source/extensions/filters/http/health_check:config",
        "//source/extensions/filters/http/ratelimit:config",
        "//source/extensions/filters/http/router:config",
        "//source/extensions/filters/network/http_connection_manager:config",
        "//source/extensions/filters/network/redis_proxy:config",
        "//source/extensions/stat_sinks/statsd:config",
        "//source/extensions/tracers/zipkin:config",
        "//source/server:server_lib",
        "//test/integration:integration_lib",
        "//test/mocks/server:server_mocks",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:test_time_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "ssl_context_manager_test",
    srcs = ["ssl_context_manager_test.cc"],
    deps = [
        "//source/server:ssl_context_manager_lib",
        "//test/mocks/ssl:ssl_mocks",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test_library(
    name = "utility_lib",
    hdrs = ["utility.h"],
    deps = [
        "//source/common/protobuf:utility_lib",
        "//test/test_common:utility_lib",
        "@envoy_api//envoy/api/v2:lds_cc",
    ],
)

envoy_cc_test(
    name = "worker_impl_test",
    srcs = ["worker_impl_test.cc"],
    deps = [
        "//source/common/api:api_lib",
        "//source/common/event:dispatcher_lib",
        "//source/server:worker_lib",
        "//test/mocks/network:network_mocks",
        "//test/mocks/server:server_mocks",
        "//test/mocks/thread_local:thread_local_mocks",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test_binary(
    name = "filter_chain_benchmark_test",
    srcs = ["filter_chain_benchmark_test.cc"],
    external_deps = [
        "benchmark",
        "googletest",
    ],
    deps = [
        "//source/server:filter_chain_manager_lib",
        "//test/test_common:environment_lib",
        "//test/mocks/network:network_mocks",
        # tranport socket config registration
        "//source/extensions/transport_sockets/tls:config",
    ],
)
