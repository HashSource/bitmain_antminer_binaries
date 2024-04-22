
void dtls1_hm_fragment_free(void *param_1)

{
  if (*(int *)((int)param_1 + 0x14) != 0) {
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)param_1 + 0x18));
    EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)param_1 + 0x1c));
  }
  if (*(void **)((int)param_1 + 0x2c) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x2c));
  }
  if (*(void **)((int)param_1 + 0x30) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x30));
  }
  CRYPTO_free(param_1);
  return;
}

