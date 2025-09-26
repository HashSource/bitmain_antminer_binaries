
void uint64_free(undefined4 *param_1)

{
  CRYPTO_free((void *)*param_1);
  *param_1 = 0;
  return;
}

