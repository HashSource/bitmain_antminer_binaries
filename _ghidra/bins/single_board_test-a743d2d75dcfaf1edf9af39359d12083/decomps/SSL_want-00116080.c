
int SSL_want(SSL *s)

{
  return s->rwstate;
}

