
void SSL_CTX_set_tmp_dh_callback(SSL_CTX *ctx,dh *dh)

{
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,6,(fp *)dh);
  return;
}

