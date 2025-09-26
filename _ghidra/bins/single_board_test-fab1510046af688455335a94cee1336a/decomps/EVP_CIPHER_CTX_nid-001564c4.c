
int EVP_CIPHER_CTX_nid(EVP_CIPHER_CTX *ctx)

{
  return ctx->cipher->nid;
}

