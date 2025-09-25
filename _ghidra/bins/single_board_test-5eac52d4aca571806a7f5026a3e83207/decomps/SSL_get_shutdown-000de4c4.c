
int SSL_get_shutdown(SSL *ssl)

{
  return ssl->new_session;
}

