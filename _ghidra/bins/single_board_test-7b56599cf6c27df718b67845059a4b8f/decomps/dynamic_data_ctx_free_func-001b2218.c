
void dynamic_data_ctx_free_func(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    DSO_free((DSO *)*param_2);
    CRYPTO_free((void *)param_2[3]);
    CRYPTO_free((void *)param_2[5]);
    OPENSSL_sk_pop_free(param_2[10],0x1b2209);
    CRYPTO_free(param_2);
    return;
  }
  return;
}

