
uint SSL_SESSION_get_compress_id(SSL_SESSION *s)

{
  return s->compress_meth;
}

