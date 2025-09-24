
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *a)

{
  EVP_CIPHER_CTX_reset();
  CRYPTO_free(a);
  return;
}

