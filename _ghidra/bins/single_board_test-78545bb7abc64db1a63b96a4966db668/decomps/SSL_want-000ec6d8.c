
int SSL_want(SSL *s)

{
  return (int)s->bbio;
}

