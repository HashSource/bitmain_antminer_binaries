
void tls1_free(int param_1)

{
  if (*(void **)(param_1 + 0x15c) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x15c));
  }
  ssl3_free(param_1);
  return;
}

