
void dynamic_data_ctx_free_func(undefined4 param_1,DSO **param_2)

{
  if (param_2 != (DSO **)0x0) {
    if (*param_2 != (DSO *)0x0) {
      DSO_free(*param_2);
    }
    if (param_2[3] != (DSO *)0x0) {
      CRYPTO_free(param_2[3]);
    }
    if (param_2[5] != (DSO *)0x0) {
      CRYPTO_free(param_2[5]);
    }
    if (param_2[10] != (DSO *)0x0) {
      sk_pop_free((_STACK *)param_2[10],DAT_000a8278);
    }
    CRYPTO_free(param_2);
    return;
  }
  return;
}

