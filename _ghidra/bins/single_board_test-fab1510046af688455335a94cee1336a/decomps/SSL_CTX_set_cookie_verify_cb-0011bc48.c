
void SSL_CTX_set_cookie_verify_cb(SSL_CTX *ctx,app_verify_cookie_cb *app_verify_cookie_cb)

{
  ctx->app_verify_cookie_cb = (_func_3235 *)app_verify_cookie_cb;
  return;
}

