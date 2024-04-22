
int SSL_get_servername_type(SSL *s)

{
  if ((s->session != (SSL_SESSION *)0x0) &&
     ((s->tlsext_debug_arg != (void *)0x0 || (*(int *)(s->session->krb5_client_princ + 0x40) != 0)))
     ) {
    return 0;
  }
  return -1;
}

