
void SSL_CTX_set_msg_callback(SSL_CTX *ctx,cb *cb)

{
  ctx->msg_callback = (_func_3237 *)cb;
  return;
}

