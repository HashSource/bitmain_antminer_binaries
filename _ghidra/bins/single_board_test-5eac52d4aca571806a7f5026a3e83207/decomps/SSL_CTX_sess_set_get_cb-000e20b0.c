
void SSL_CTX_sess_set_get_cb(SSL_CTX *ctx,get_session_cb *get_session_cb)

{
  (ctx->stats).sess_connect = (int)get_session_cb;
  return;
}

