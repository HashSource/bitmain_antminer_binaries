
int SSL_set_session_secret_cb(SSL *s,tls_session_secret_cb_fn tls_session_secret_cb,void *arg)

{
  if (s != (SSL *)0x0) {
    s->tls_session_ticket_ext_cb_arg = tls_session_secret_cb;
    s->tls_session_secret_cb = (tls_session_secret_cb_fn)arg;
    return 1;
  }
  return 0;
}

