
stack_st_X509 * SSL_get_peer_cert_chain(SSL *s)

{
  if (((s != (SSL *)0x0) && (s = (SSL *)s->session, (SSL_SESSION *)s != (SSL_SESSION *)0x0)) &&
     (s = *(SSL **)((int)((SSL_SESSION *)s)->krb5_client_princ + 8),
     (SSL_SESSION *)s != (SSL_SESSION *)0x0)) {
    s = (SSL *)((SSL_SESSION *)s)->ssl_version;
  }
  return (stack_st_X509 *)s;
}

