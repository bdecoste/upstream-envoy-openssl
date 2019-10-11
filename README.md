To build OpenSSL-enabled Envoy run

```
$ CXXFLAGS="-DENVOY_SSL_VERSION=\\\"OpenSSL\\\"" bazel build //:envoy --define boringssl=disabled
```

If you need OpenSSL dynamically linked to Envoy then re-map `@boringssl` to
`@openssl_shared` by editing the `WORKSPACE` file.
