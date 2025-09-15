
long SSL_SESSION_get_timeout(SSL_SESSION *s)

{
  if (s != (SSL_SESSION *)0x0) {
    s = *(SSL_SESSION **)(s->krb5_client_princ + 0x18);
  }
  return (long)s;
}

