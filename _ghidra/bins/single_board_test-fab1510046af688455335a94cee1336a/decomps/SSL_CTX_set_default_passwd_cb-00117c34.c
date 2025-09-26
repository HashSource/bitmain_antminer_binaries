
void SSL_CTX_set_default_passwd_cb(SSL_CTX *ctx,undefined1 *cb)

{
  ctx->default_passwd_callback = cb;
  return;
}

