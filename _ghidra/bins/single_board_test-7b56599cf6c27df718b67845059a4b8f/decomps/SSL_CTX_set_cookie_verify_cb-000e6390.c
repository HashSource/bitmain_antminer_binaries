
void SSL_CTX_set_cookie_verify_cb(SSL_CTX *ctx,app_verify_cookie_cb *app_verify_cookie_cb)

{
  (ctx->ex_data).sk = (stack_st_void *)app_verify_cookie_cb;
  return;
}

