
void SSL_CTX_set_verify(SSL_CTX *ctx,int mode,callback *callback)

{
  *(int *)(ctx->sid_ctx + 8) = mode;
  ctx->max_send_fragment = (uint)callback;
  return;
}

