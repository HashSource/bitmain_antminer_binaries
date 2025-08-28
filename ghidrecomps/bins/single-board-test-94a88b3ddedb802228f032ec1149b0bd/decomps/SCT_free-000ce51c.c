
void SCT_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      CRYPTO_free((void *)*param_1);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

