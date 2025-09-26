
void custom_exts_free(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    CRYPTO_free((void *)*param_1);
    return;
  }
  return;
}

