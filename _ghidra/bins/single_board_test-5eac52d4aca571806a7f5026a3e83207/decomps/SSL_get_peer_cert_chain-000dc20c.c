
stack_st_X509 * SSL_get_peer_cert_chain(SSL *s)

{
  if ((s != (SSL *)0x0) && (s = (SSL *)s[2].tlsext_ticket_expected, s != (SSL *)0x0)) {
    s = (SSL *)s[1].method;
  }
  return (stack_st_X509 *)s;
}

