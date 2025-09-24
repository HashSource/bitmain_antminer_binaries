
void CMAC_CTX_free(CMAC_CTX *ctx)

{
  if (ctx != (CMAC_CTX *)0x0) {
    CMAC_CTX_cleanup(ctx);
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)ctx);
    CRYPTO_free(ctx);
    return;
  }
  return;
}

