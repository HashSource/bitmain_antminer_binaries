
void ECDSA_METHOD_free(void *param_1)

{
  if (-1 < *(int *)((int)param_1 + 0x10) << 0x1e) {
    return;
  }
  CRYPTO_free(param_1);
  return;
}

