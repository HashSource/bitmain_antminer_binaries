
EVP_CIPHER_CTX * CMAC_CTX_get0_cipher_ctx(CMAC_CTX *ctx)

{
  return (EVP_CIPHER_CTX *)ctx;
}

