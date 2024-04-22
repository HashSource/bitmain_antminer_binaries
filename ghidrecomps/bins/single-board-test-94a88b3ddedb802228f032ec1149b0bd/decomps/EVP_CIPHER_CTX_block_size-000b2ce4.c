
int EVP_CIPHER_CTX_block_size(EVP_CIPHER_CTX *ctx)

{
  return ctx->cipher->block_size;
}

