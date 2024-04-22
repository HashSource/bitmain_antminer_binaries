
int EVP_CIPHER_CTX_iv_length(EVP_CIPHER_CTX *ctx)

{
  return ctx->cipher->iv_len;
}

