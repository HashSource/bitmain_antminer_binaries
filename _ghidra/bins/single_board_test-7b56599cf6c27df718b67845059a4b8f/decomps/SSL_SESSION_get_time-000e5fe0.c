
long SSL_SESSION_get_time(SSL_SESSION *s)

{
  if (s != (SSL_SESSION *)0x0) {
    s = (SSL_SESSION *)s->time;
  }
  return (long)s;
}

