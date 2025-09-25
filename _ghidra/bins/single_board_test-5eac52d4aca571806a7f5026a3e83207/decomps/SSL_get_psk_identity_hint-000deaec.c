
char * SSL_get_psk_identity_hint(SSL *s)

{
  if ((s != (SSL *)0x0) && (s = (SSL *)s[2].tlsext_ticket_expected, s != (SSL *)0x0)) {
    s = (SSL *)s->tlsext_hb_seq;
  }
  return (char *)s;
}

