
void xptable_free(void *param_1)

{
  if ((param_1 != (void *)0x0) && (*(int *)((int)param_1 + 8) << 0x1f < 0)) {
    if (*(int *)((int)param_1 + 8) << 0x1e < 0) {
      CRYPTO_free(*(void **)((int)param_1 + 0x10));
      CRYPTO_free(*(void **)((int)param_1 + 0x14));
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

