
void pkey_rsa_cleanup(int param_1)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  if (ptr != (void *)0x0) {
    if (*(BIGNUM **)((int)ptr + 4) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)((int)ptr + 4));
    }
    if (*(void **)((int)ptr + 0x20) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x20));
    }
    if (*(void **)((int)ptr + 0x24) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x24));
    }
    CRYPTO_free(ptr);
    return;
  }
  return;
}

