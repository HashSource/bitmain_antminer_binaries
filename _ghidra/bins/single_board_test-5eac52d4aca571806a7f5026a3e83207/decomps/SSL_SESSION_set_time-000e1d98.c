
long SSL_SESSION_set_time(SSL_SESSION *s,long t)

{
  if (s != (SSL_SESSION *)0x0) {
    s->time = t;
    s = (SSL_SESSION *)t;
  }
  return (long)s;
}

