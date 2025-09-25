
void SSL_CTX_sess_set_remove_cb(SSL_CTX *ctx,remove_session_cb *remove_session_cb)

{
  ctx->get_session_cb = (_func_3231 *)remove_session_cb;
  return;
}

