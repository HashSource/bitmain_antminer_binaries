
void SSL_CTX_set_cert_verify_callback(SSL_CTX *ctx,cb *cb,void *arg)

{
  ctx->app_verify_arg = cb;
  ctx->default_passwd_callback = (undefined1 *)arg;
  return;
}

