set -x

git submodule update --init
git submodule update --remote --force

ls -l envoy/source/extensions/transport_sockets

#DISABLED - too dependent on boringssl
rm -rf envoy/source/extensions/quic_listeners/

#REPLACED - reasonable port from boringssl to openssl
rm -rf envoy/source/common/crypto
rm -rf envoy/source/extensions/common/crypto
rm -rf envoy/source/extensions/transport_sockets/tls/BUILD 
rm -rf envoy/source/extensions/transport_sockets/tls/integration
rm -rf envoy/source/extensions/transport_sockets/tls/*.*
rm -rf envoy/source/extensions/filters/listener/tls_inspector
rm -rf envoy/source/extensions/filters/http/lua
rm -rf envoy/test/extensions/transport_sockets/tls
rm -rf envoy/test/extensions/transport_sockets/tls/integration
rm -rf envoy/test/extensions/transport_sockets/tls/test_data
rm -rf envoy/test/extensions/filters/listener/tls_inspector

$@
