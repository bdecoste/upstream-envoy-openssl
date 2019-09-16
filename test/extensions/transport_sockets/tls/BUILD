licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_test",
    "envoy_cc_test_library",
    "envoy_package",
)

envoy_package()

envoy_cc_test(
    name = "ssl_socket_test",
    repository = "@envoy",
    srcs = [
        "ssl_certs_test.h",
        "ssl_socket_test.cc",
    ],
    data = [
        "gen_unittest_certs.sh",
        "@ssl//:tls_test_data_certs",
    ],
    external_deps = ["ssl"],
    deps = [
        "@envoy//include/envoy/network:transport_socket_interface",
        "@envoy//source/common/buffer:buffer_lib",
        "@envoy//source/common/common:empty_string",
        "@envoy//source/common/event:dispatcher_includes",
        "@envoy//source/common/event:dispatcher_lib",
        "@envoy//source/common/json:json_loader_lib",
        "@envoy//source/common/network:listen_socket_lib",
        "@envoy//source/common/network:transport_socket_options_lib",
        "@envoy//source/common/network:utility_lib",
        "@envoy//source/common/stats:isolated_store_lib",
        "@envoy//source/common/stats:stats_lib",
        "@ssl//:tls_inspector_lib",        
        "@ssl//:tls_context_config_lib",
        "@ssl//:tls_context_lib",
        "@ssl//:openssl_impl_lib",
        "@ssl//:tls_ssl_socket_lib",
        "@ssl//:tls_utility_lib",
        "@ssl//:tls_test_data_cert_infos",
        "@envoy//test/mocks/buffer:buffer_mocks",
        "@envoy//test/mocks/network:network_mocks",
        "@envoy//test/mocks/runtime:runtime_mocks",
        "@envoy//test/mocks/server:server_mocks",
        "@envoy//test/mocks/stats:stats_mocks",
        "@envoy//test/test_common:environment_lib",
        "@envoy//test/test_common:network_utility_lib",
        "@envoy//test/test_common:simulated_time_system_lib",
        "@envoy//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "context_impl_test",
    repository = "@envoy",
    srcs = [
        "context_impl_test.cc",
        "ssl_certs_test.h",
    ],
    data = [
        "gen_unittest_certs.sh",
        "@ssl//:tls_test_data_certs",
    ],
    deps = [
        "@ssl//:tls_ssl_test_utils",
        "@envoy//source/common/json:json_loader_lib",
        "@envoy//source/common/stats:isolated_store_lib",
        "@envoy//source/common/stats:stats_lib",
        "@ssl//:tls_context_config_lib",
        "@ssl//:tls_context_lib",
        "@ssl//:tls_test_data_cert_infos",
        "@envoy//test/mocks/runtime:runtime_mocks",
        "@envoy//test/mocks/secret:secret_mocks",
        "@envoy//test/mocks/server:server_mocks",
        "@envoy//test/test_common:environment_lib",
        "@envoy//test/test_common:simulated_time_system_lib",
    ],
)

envoy_cc_test(
    name = "utility_test",
    repository = "@envoy",
    srcs = [
        "utility_test.cc",
    ],
    data = [
        "gen_unittest_certs.sh",
        "@ssl//:tls_test_data_certs",
    ],
    external_deps = [
        "ssl",
    ],
    deps = [
        "@ssl//:tls_ssl_test_utils",
        "@ssl//:tls_utility_lib",
        "@ssl//:tls_test_data_cert_infos",
        "@envoy//test/test_common:environment_lib",
        "@envoy//test/test_common:simulated_time_system_lib",
    ],
)

envoy_cc_test_library(
    name = "ssl_test_utils",
    repository = "@envoy",
    srcs = [
        "ssl_test_utility.h",
    ],
    deps = [
        "//boringssl_compat:bssl_compat_lib",
        "@ssl//:tls_utility_lib",
        "@envoy//test/test_common:environment_lib",
    ],
)
