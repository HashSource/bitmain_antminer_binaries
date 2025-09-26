
void dtls1_hm_fragment_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(int *)((int)param_1 + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)param_1 + 0x18));
      EVP_MD_CTX_free(*(undefined4 *)((int)param_1 + 0x1c));
    }
    CRYPTO_free(*(void **)((int)param_1 + 0x2c));
    CRYPTO_free(*(void **)((int)param_1 + 0x30));
    CRYPTO_free(param_1);
    return;
  }
  return;
}

