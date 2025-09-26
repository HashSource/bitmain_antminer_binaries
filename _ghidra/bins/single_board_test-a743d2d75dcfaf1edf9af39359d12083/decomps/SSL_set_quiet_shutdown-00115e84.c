
void SSL_set_quiet_shutdown(SSL *ssl,int mode)

{
  ssl->quiet_shutdown = mode;
  return;
}

