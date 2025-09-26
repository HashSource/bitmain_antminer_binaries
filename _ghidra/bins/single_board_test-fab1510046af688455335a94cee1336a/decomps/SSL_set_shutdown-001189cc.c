
void SSL_set_shutdown(SSL *ssl,int mode)

{
  ssl->shutdown = mode;
  return;
}

