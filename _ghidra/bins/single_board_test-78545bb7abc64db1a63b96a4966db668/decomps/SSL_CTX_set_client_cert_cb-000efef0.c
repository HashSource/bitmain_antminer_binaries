
void SSL_CTX_set_client_cert_cb(SSL_CTX *ctx,client_cert_cb *client_cert_cb)

{
  ctx->app_gen_cookie_cb = (_func_3234 *)client_cert_cb;
  return;
}

