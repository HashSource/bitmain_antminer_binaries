
void dynamic_data_ctx_free_func(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    if ((DSO *)*param_2 != (DSO *)0x0) {
      DSO_free((DSO *)*param_2);
    }
    if ((void *)param_2[3] != (void *)0x0) {
      CRYPTO_free((void *)param_2[3]);
    }
    if ((void *)param_2[5] != (void *)0x0) {
      CRYPTO_free((void *)param_2[5]);
    }
    if ((_STACK *)param_2[10] != (_STACK *)0x0) {
      sk_pop_free((_STACK *)param_2[10],(func *)0xa8241);
    }
    CRYPTO_free(param_2);
    return;
  }
  return;
}

