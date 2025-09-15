
void SSL_CTX_set_verify(SSL_CTX *ctx,int mode,callback *callback)

{
  ctx->verify_mode = mode;
  ctx->default_verify_callback = (_func_3238 *)callback;
  return;
}

