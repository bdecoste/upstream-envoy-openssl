package(default_visibility = ["//visibility:public"])

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_binary",
    "envoy_cc_library",
    "envoy_cc_test",
)

envoy_cc_binary(
    name = "envoy_source",
    repository = "@envoy",
    deps = [
        "//ssl:lua_config",
        "//source/common/crypto:utility_lib",
        "//source/extensions/transport_sockets/tls:config",
        "//source/extensions/transport_sockets/tls:ssl_socket_lib",
        "//source/extensions/transport_sockets/tls:context_config_lib",
        "//source/extensions/transport_sockets/tls:context_lib",
        "//source/extensions/transport_sockets/tls:utility_lib",
        "//source/extensions/transport_sockets/tls:openssl_impl_lib",
        "//source/extensions/filters/listener/tls_inspector:tls_inspector_lib",
        "//source/extensions/filters/listener/tls_inspector:config",
        "//source/extensions/filters/listener/tls_inspector:openssl_impl_lib",
        "//source/extensions/common/crypto:utility_lib",
        "//source/extensions/filters/http/lua:lua_filter_lib",
        "//source/extensions/filters/http/lua:wrappers_lib",
        "//source/extensions/filters/http/lua:config",
        "@envoy//source/exe:envoy_main_entry_lib",
    ],
)

envoy_cc_binary(
    name = "envoy_test",
    testonly = 1,
    repository = "@envoy",
    deps = [
        "//test/extensions/transport_sockets/tls:ssl_socket_test",
        "//test/extensions/transport_sockets/tls:context_impl_test",
        "//test/extensions/transport_sockets/tls:utility_test",
        "//test/extensions/transport_sockets/tls:ssl_test_utils",
        "//test/extensions/transport_sockets/tls/integration:ssl_integration_test",
        "//test/extensions/transport_sockets/tls/test_data:certs",
        "//test/extensions/filters/listener/tls_inspector:tls_inspector_test",
        "//test/extensions/filters/listener/tls_inspector:tls_inspector_benchmark",
        "//test/extensions/filters/listener/tls_inspector:tls_utility_lib",
        "//test/extensions/transport_sockets/tls/test_data:certs",
        "//test/extensions/transport_sockets/tls/test_data:cert_infos",
    ],
)

