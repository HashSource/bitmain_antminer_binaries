
void SSL_CTX_sess_set_get_cb(SSL_CTX *ctx,get_session_cb *get_session_cb)

{
  ctx->get_session_cb = (_func_3231 *)get_session_cb;
  return;
}

