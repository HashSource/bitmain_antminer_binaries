
void SSL_CTX_sess_set_new_cb(SSL_CTX *ctx,new_session_cb *new_session_cb)

{
  ctx->new_session_cb = (_func_3229 *)new_session_cb;
  return;
}

