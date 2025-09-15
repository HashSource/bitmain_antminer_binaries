
void SSL_set_verify_result(SSL *ssl,long v)

{
  ssl->debug = v;
  return;
}

