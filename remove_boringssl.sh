set -x

git submodule update --init
git submodule update --remote --force

#DISABLED - too dependent on boringssl
rm -rf envoy/source/extensions/quic_listeners/

#REPLACED - reasonable port from boringssl to openssl
rm -rf envoy/source/common/crypto
rm -rf envoy/source/extensions/common/crypto
rm -rf envoy/source/extensions/transport_sockets/tls 
rm -rf envoy/source/extensions/filters/listener/tls_inspector
rm -rf envoy/source/extensions/filters/http/lua
rm -rf envoy/test/extensions/transport_sockets/tls
rm -rf envoy/test/extensions/filters/listener/tls_inspector
/usr/bin/cp -rf source/* envoy/source/

BUILD_OPTIONS="
build --cxxopt -D_GLIBCXX_USE_CXX11_ABI=1
build --cxxopt -DENVOY_IGNORE_GLIBCXX_USE_CXX11_ABI_ERROR=1
build --cxxopt -Wnon-virtual-dtor
build --cxxopt -Wformat
build --cxxopt -Wformat-security
build --cxxopt -Wno-error=deprecated-declarations
build --cxxopt -Wno-error=unused-variable
build --cxxopt -w
build --cxxopt -ldl
"
echo "${BUILD_OPTIONS}" >> envoy/.bazelrc

$@
