
void SSL_CTX_set_tmp_ecdh_callback(SSL_CTX *ctx,ecdh *ecdh)

{
  (*ctx->method->ssl_ctx_callback_ctrl)(ctx,7,(fp *)ecdh);
  return;
}

