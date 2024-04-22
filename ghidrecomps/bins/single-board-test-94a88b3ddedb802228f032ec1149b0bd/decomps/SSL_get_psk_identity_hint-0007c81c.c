
char * SSL_get_psk_identity_hint(SSL *s)

{
  if ((s != (SSL *)0x0) && (s = (SSL *)s->session, (SSL_SESSION *)s != (SSL_SESSION *)0x0)) {
    s = (SSL *)((SSL_SESSION *)s)->krb5_client_princ_len;
  }
  return (char *)s;
}

