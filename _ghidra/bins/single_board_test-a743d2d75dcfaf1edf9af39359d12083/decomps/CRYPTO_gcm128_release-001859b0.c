
void CRYPTO_gcm128_release(void *param_1)

{
  if (param_1 != (void *)0x0) {
    OPENSSL_cleanse(param_1,0x178);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

