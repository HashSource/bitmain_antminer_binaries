
EVP_CIPHER * EVP_CIPHER_CTX_cipher(EVP_CIPHER_CTX *ctx)

{
  return ctx->cipher;
}

