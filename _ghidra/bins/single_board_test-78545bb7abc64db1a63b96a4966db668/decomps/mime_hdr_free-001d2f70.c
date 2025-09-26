
void mime_hdr_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    CRYPTO_free((void *)*param_1);
    CRYPTO_free((void *)param_1[1]);
    if (param_1[2] != 0) {
      OPENSSL_sk_pop_free(param_1[2],0x1d2ef5);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

