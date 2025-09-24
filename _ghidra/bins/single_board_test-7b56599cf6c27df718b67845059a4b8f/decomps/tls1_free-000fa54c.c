
void tls1_free(int param_1)

{
  CRYPTO_free(*(void **)(param_1 + 0x580));
  ssl3_free(param_1);
  return;
}

