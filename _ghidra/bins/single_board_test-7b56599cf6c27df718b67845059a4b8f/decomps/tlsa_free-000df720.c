
void tlsa_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 4));
    EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0xc));
    CRYPTO_free(param_1);
    return;
  }
  return;
}

