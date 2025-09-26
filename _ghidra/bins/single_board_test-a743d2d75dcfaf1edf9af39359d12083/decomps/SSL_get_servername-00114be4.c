
char * SSL_get_servername(SSL *s,int type)

{
  char *pcVar1;
  
  if (type != 0) {
    return (char *)0x0;
  }
  pcVar1 = (char *)s->tlsext_debug_arg;
  if (s->session != (SSL_SESSION *)0x0) {
    if (pcVar1 != (char *)0x0) {
      return pcVar1;
    }
    return *(char **)(s->session->krb5_client_princ + 0x40);
  }
  return pcVar1;
}

