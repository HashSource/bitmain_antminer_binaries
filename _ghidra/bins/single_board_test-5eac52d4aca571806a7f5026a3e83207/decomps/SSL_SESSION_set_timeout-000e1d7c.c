
long SSL_SESSION_set_timeout(SSL_SESSION *s,long t)

{
  if (s != (SSL_SESSION *)0x0) {
    s->timeout = t;
    s = (SSL_SESSION *)0x1;
  }
  return (long)s;
}

