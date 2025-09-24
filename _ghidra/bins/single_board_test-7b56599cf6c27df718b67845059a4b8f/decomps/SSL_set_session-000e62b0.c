
int SSL_set_session(SSL *to,SSL_SESSION *session)

{
  int iVar1;
  SSL_METHOD *method;
  
  ssl_clear_bad_session();
  method = (SSL_METHOD *)(to[3].method)->version;
  if ((method != (SSL_METHOD *)to->type) && (iVar1 = SSL_set_ssl_method(to,method), iVar1 == 0)) {
    return 0;
  }
  if (session != (SSL_SESSION *)0x0) {
    SSL_SESSION_up_ref(session);
    to[3].wbio = (BIO *)session->verify_result;
  }
  SSL_SESSION_free((SSL_SESSION *)to[2].tlsext_ticket_expected);
  to[2].tlsext_ticket_expected = (int)session;
  return 1;
}

