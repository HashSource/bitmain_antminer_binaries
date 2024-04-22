
void ssl2_free(int param_1)

{
  void *ptr;
  
  if (param_1 != 0) {
    ptr = *(void **)(param_1 + 0x54);
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    if (*(void **)((int)ptr + 0x34) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x34));
    }
    OPENSSL_cleanse(ptr,0x120);
    CRYPTO_free(ptr);
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}

