
void CTLOG_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    CRYPTO_free((void *)*param_1);
    EVP_PKEY_free((EVP_PKEY *)param_1[9]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

