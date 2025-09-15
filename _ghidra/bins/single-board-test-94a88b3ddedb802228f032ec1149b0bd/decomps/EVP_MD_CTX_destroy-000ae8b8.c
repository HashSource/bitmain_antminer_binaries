
void EVP_MD_CTX_destroy(EVP_MD_CTX *ctx)

{
  if (ctx != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_cleanup(ctx);
    CRYPTO_free(ctx);
    return;
  }
  return;
}

