licenses(["notice"])  # Apache 2

# Built-in TLS connection transport socket.

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "config",
    repository = "@envoy",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    deps = [
        ":ssl_socket_lib",
        "@envoy//include/envoy/network:transport_socket_interface",
        "@envoy//include/envoy/registry",
        "@envoy//include/envoy/server:transport_socket_config_interface",
        "@envoy//source/extensions/transport_sockets:well_known_names",
    ],
)

envoy_cc_library(
    name = "ssl_socket_lib",
    repository = "@envoy",
    srcs = ["ssl_socket.cc"],
    hdrs = ["ssl_socket.h"],
    external_deps = [
        "abseil_synchronization",
        "ssl",
    ],
    deps = [
        ":context_config_lib",
        ":context_lib",
        ":utility_lib",
        "@envoy//include/envoy/network:connection_interface",
        "@envoy//include/envoy/network:transport_socket_interface",
        "@envoy//include/envoy/stats:stats_macros",
        "@envoy//source/common/common:assert_lib",
        "@envoy//source/common/common:empty_string",
        "@envoy//source/common/common:minimal_logger_lib",
        "@envoy//source/common/common:thread_annotations",
        "@envoy//source/common/http:headers_lib",
        "@boringssl_compat//:bssl_compat_lib",
    ],
)

envoy_cc_library(
    name = "context_config_lib",
    repository = "@envoy",
    srcs = ["context_config_impl.cc"],
    hdrs = ["context_config_impl.h"],
    external_deps = [
        "ssl",
    ],
    deps = [
        "@envoy//include/envoy/secret:secret_callbacks_interface",
        "@envoy//include/envoy/secret:secret_provider_interface",
        "@envoy//include/envoy/server:transport_socket_config_interface",
        "@envoy//include/envoy/ssl:context_config_interface",
        "@envoy//source/common/common:assert_lib",
        "@envoy//source/common/common:empty_string",
        "@envoy//source/common/config:datasource_lib",
        "@envoy//source/common/json:json_loader_lib",
        "@envoy//source/common/protobuf:utility_lib",
        "@envoy//source/common/secret:sds_api_lib",
        "@envoy//source/common/ssl:certificate_validation_context_config_impl_lib",
        "@envoy//source/common/ssl:tls_certificate_config_impl_lib",
        "@envoy_api//envoy/api/v2/auth:cert_cc",
    ],
)

envoy_cc_library(
    name = "context_lib",
    repository = "@envoy",
    srcs = [
        "context_impl.cc",
        "context_manager_impl.cc",
    ],
    hdrs = [
        "context_impl.h",
        "context_manager_impl.h",
    ],
    external_deps = [
        "abseil_synchronization",
        "ssl",
    ],
    deps = [
        ":utility_lib",
        "@envoy//include/envoy/stats:stats_interface",
        "@envoy//include/envoy/stats:stats_macros",
        "@envoy//include/envoy/ssl:context_config_interface",
        "@envoy//include/envoy/ssl:context_interface",
        "@envoy//include/envoy/ssl:context_manager_interface",
        "@envoy//source/common/common:assert_lib",
        "@envoy//source/common/common:base64_lib",
        "@envoy//source/common/common:hex_lib",
        "@envoy//source/common/common:utility_lib",
        "@envoy//source/common/protobuf:utility_lib",
        "@envoy//source/extensions/transport_sockets/tls/private_key:private_key_manager_lib",
        "@envoy_api//envoy/admin/v2alpha:certs_cc",
        "@boringssl_compat//:bssl_compat_lib",
    ],
)

envoy_cc_library(
    name = "utility_lib",
    repository = "@envoy",
    srcs = ["utility.cc"],
    hdrs = ["utility.h"],
    external_deps = [
        "ssl",
    ],
    deps = [
        ":openssl_impl_lib",
        "@envoy//source/common/common:assert_lib",
        "@envoy//source/common/common:utility_lib",
        "@boringssl_compat//:bssl_compat_lib",
    ],
)

envoy_cc_library(
    name = "openssl_impl_lib",
    repository = "@envoy",
    srcs = [
        "openssl_impl.cc",
    ],
    hdrs = [
        "openssl_impl.h",
    ],
    external_deps = [
        "ssl",
    ],
    deps = [
        "@boringssl_compat//:bssl_compat_lib",
    ]
)
