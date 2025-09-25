
void pkey_dsa_cleanup(int param_1)

{
  CRYPTO_free(*(void **)(param_1 + 0x14));
  return;
}

