
int SSL_set_session_secret_cb(SSL *s,tls_session_secret_cb_fn tls_session_secret_cb,void *arg)

{
  if (s != (SSL *)0x0) {
    s[3].generate_session_id = (GEN_SESSION_CB)tls_session_secret_cb;
    s[3].verify_mode = (int)arg;
    return 1;
  }
  return 0;
}

