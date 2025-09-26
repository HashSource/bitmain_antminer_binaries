
int SSL_set_session_ticket_ext_cb(SSL *s,tls_session_ticket_ext_cb_fn cb,void *arg)

{
  if (s != (SSL *)0x0) {
    s->tlsext_session_ticket = (TLS_SESSION_TICKET_EXT *)cb;
    s->tls_session_ticket_ext_cb = (tls_session_ticket_ext_cb_fn)arg;
    return 1;
  }
  return 0;
}

