
void SSL_CTX_set_cookie_generate_cb(SSL_CTX *ctx,app_gen_cookie_cb *app_gen_cookie_cb)

{
  ctx->app_gen_cookie_cb = (_func_3234 *)app_gen_cookie_cb;
  return;
}

