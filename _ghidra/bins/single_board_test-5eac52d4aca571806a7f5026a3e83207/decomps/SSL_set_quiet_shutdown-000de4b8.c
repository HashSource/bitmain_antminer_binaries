
void SSL_set_quiet_shutdown(SSL *ssl,int mode)

{
  ssl->server = mode;
  return;
}

