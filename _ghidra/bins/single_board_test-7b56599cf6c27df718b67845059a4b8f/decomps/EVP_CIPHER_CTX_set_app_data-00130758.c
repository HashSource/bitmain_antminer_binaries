
void EVP_CIPHER_CTX_set_app_data(EVP_CIPHER_CTX *ctx,void *data)

{
  ctx->app_data = data;
  return;
}

