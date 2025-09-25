
void pkey_rsa_cleanup(int param_1)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  if (ptr != (void *)0x0) {
    BN_free(*(BIGNUM **)((int)ptr + 4));
    CRYPTO_free(*(void **)((int)ptr + 0x28));
    CRYPTO_free(*(void **)((int)ptr + 0x2c));
    CRYPTO_free(ptr);
    return;
  }
  return;
}

