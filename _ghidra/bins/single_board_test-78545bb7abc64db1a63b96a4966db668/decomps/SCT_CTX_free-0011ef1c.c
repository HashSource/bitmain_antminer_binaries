
void SCT_CTX_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)*param_1);
    CRYPTO_free((void *)param_1[1]);
    CRYPTO_free((void *)param_1[3]);
    CRYPTO_free((void *)param_1[5]);
    CRYPTO_free((void *)param_1[7]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

