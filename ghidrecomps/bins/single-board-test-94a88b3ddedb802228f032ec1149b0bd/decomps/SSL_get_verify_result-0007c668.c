
long SSL_get_verify_result(SSL *ssl)

{
  return ssl->debug;
}

