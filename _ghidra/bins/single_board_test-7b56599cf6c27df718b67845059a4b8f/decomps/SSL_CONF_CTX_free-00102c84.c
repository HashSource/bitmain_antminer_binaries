
void SSL_CONF_CTX_free(void *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined4 *)((int)param_1 + 0x14);
    do {
      puVar1 = puVar1 + 1;
      CRYPTO_free((void *)*puVar1);
    } while (puVar1 != (undefined4 *)((int)param_1 + 0x38));
    CRYPTO_free(*(void **)((int)param_1 + 4));
    OPENSSL_sk_pop_free(*(undefined4 *)((int)param_1 + 0x54),0x16da91);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

