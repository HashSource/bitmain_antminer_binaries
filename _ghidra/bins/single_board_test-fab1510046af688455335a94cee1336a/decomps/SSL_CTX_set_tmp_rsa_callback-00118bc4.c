
void SSL_CTX_set_tmp_rsa_callback(SSL_CTX *ctx,cb *cb)

{
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,5,(fp *)cb);
  return;
}

