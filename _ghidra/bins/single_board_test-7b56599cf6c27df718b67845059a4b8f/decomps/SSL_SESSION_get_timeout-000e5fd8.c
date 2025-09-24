
long SSL_SESSION_get_timeout(SSL_SESSION *s)

{
  if (s != (SSL_SESSION *)0x0) {
    s = (SSL_SESSION *)s->timeout;
  }
  return (long)s;
}

