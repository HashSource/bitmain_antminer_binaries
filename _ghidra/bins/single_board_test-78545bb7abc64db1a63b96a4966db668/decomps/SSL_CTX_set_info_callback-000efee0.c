
void SSL_CTX_set_info_callback(SSL_CTX *ctx,cb *cb)

{
  ctx->client_CA = (stack_st_X509_NAME *)cb;
  return;
}

