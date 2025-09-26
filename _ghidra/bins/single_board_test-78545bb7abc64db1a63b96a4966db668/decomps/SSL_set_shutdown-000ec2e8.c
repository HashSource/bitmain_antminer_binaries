
void SSL_set_shutdown(SSL *ssl,int mode)

{
  ssl->new_session = mode;
  return;
}

