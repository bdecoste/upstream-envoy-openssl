licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_test",
    "envoy_package",
)

envoy_package()

envoy_cc_test(
    name = "ssl_integration_test",
    repository = "@envoy",
    srcs = [
        "ssl_integration_test.cc",
        "ssl_integration_test.h",
    ],
    data = [
        "@envoy//test/config/integration/certs",
    ],
    deps = [
        "@envoy//source/common/event:dispatcher_includes",
        "@envoy//source/common/event:dispatcher_lib",
        "@envoy//source/common/network:connection_lib",
        "@envoy//source/common/network:utility_lib",
        "@ssl//:tls_inspector_config",
        "@ssl//:tls_config",
        "@ssl//:tls_context_config_lib",
        "@ssl//:tls_context_lib",
        "@envoy//test/integration:http_integration_lib",
        "@envoy//test/mocks/secret:secret_mocks",
        "@envoy//test/test_common:utility_lib",
        "@envoy_api//envoy/config/transport_socket/tap/v2alpha:tap_cc",
        "@envoy_api//envoy/data/tap/v2alpha:transport_cc",
    ],
)
