licenses(["notice"])  # Apache 2

# Lua scripting L7 HTTP filter (https://www.lua.org/, http://luajit.org/)
# Public docs: docs/root/configuration/http_filters/lua_filter.rst

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "lua_filter_lib",
    repository = "@envoy",
    srcs = ["lua_filter.cc"],
    hdrs = ["lua_filter.h"],
    deps = [
        ":wrappers_lib",
        "@envoy//include/envoy/http:codes_interface",
        "@envoy//include/envoy/http:filter_interface",
        "@envoy//include/envoy/upstream:cluster_manager_interface",
        "@envoy//source/common/buffer:buffer_lib",
        "@envoy//source/common/common:enum_to_int",
        "@envoy//source/common/crypto:utility_lib",
        "@envoy//source/extensions/common/crypto:utility_lib",
        "@envoy//source/common/http:message_lib",
        "@envoy//source/extensions/filters/common/lua:lua_lib",
        "@envoy//source/extensions/filters/common/lua:wrappers_lib",
        "@envoy//source/extensions/filters/http:well_known_names",
    ],
)

envoy_cc_library(
    name = "wrappers_lib",
    repository = "@envoy",
    srcs = ["wrappers.cc"],
    hdrs = ["wrappers.h"],
    deps = [
        "@envoy//include/envoy/http:header_map_interface",
        "@envoy//include/envoy/stream_info:stream_info_interface",
        "@envoy//source/common/crypto:utility_lib",
        "@envoy//source/common/http:utility_lib",
        "@envoy//source/extensions/common/crypto:utility_lib",
        "@envoy//source/extensions/filters/common/lua:lua_lib",
        "@envoy//source/extensions/filters/common/lua:wrappers_lib",
    ],
)

envoy_cc_library(
    name = "config",
    repository = "@envoy",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    deps = [
        ":lua_filter_lib",
        "@envoy//include/envoy/registry",
        "@envoy//source/common/config:filter_json_lib",
        "@envoy//source/extensions/filters/http:well_known_names",
        "@envoy//source/extensions/filters/http/common:factory_base_lib",
    ],
)
