#workspace(name = "envoy_openssl")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
      name = "openssl",
      urls = ["https://github.com/openssl/openssl/archive/OpenSSL_1_1_1b.tar.gz"],
      sha256 = "d6418b0e1e39ef058b630e248bbb3b04241d6fad57bdb86db0b338c2374bda80",
      build_file = "@//:openssl.BUILD",
      strip_prefix = "openssl-OpenSSL_1_1_1b",
)

new_local_repository(
    name = "openssl_shared",
    path = "/usr/lib/x86_64-linux-gnu",
    build_file = "openssl_host_shared.BUILD"
)

local_repository(
    name = "envoy",
    path = "envoy",
    repo_mapping = {
        "@boringssl": "@openssl",
    },
)

local_repository(
    name = "boringssl_compat",
    path = "boringssl_compat",
)

local_repository(
    name = "envoy_build_config",
    path = "envoy_build_config",
)

load("//bazel:api_binding.bzl", "envoy_api_binding")

envoy_api_binding()

load("//bazel:api_repositories.bzl", "envoy_api_dependencies")

envoy_api_dependencies()

load("//bazel:repositories.bzl", "envoy_dependencies")

envoy_dependencies()

load("//bazel:dependency_imports.bzl", "envoy_dependency_imports")

envoy_dependency_imports()

load("@envoy//bazel:repository_locations.bzl", "REPOSITORY_LOCATIONS")

http_archive(
    name = "com_github_google_jwt_verify_patched",
    urls = REPOSITORY_LOCATIONS["com_github_google_jwt_verify"]["urls"],
    sha256 = REPOSITORY_LOCATIONS["com_github_google_jwt_verify"]["sha256"],
    strip_prefix = REPOSITORY_LOCATIONS["com_github_google_jwt_verify"].get("strip_prefix", ""),
    patches=["//:jwt_verify-make-compatible-with-openssl.patch"],
    patch_args=["-p1"]
)
# TODO: Consider not using `bind`. See https://github.com/bazelbuild/bazel/issues/1952 for details.
bind(
    name = "jwt_verify_lib",
    actual = "@com_github_google_jwt_verify_patched//:jwt_verify_lib",
)

