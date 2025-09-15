
long SSL_SESSION_set_time(SSL_SESSION *s,long t)

{
  if (s != (SSL_SESSION *)0x0) {
    *(long *)(s->krb5_client_princ + 0x1c) = t;
    return t;
  }
  return 0;
}

