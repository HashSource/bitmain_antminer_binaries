
int SSL_set_session_ticket_ext_cb(SSL *s,tls_session_ticket_ext_cb_fn cb,void *arg)

{
  if (s != (SSL *)0x0) {
    *(tls_session_ticket_ext_cb_fn *)(s[3].sid_ctx + 0x1c) = cb;
    s[3].session = (SSL_SESSION *)arg;
    return 1;
  }
  return 0;
}

