
void SSL_set_debug(SSL *s,int debug)

{
  s->ctx = (SSL_CTX *)debug;
  return;
}

