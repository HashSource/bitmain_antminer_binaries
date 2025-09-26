
undefined4 asn1_bio_free(int param_1)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x20);
  if (ptr != (void *)0x0) {
    if (*(void **)((int)ptr + 4) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 4));
    }
    CRYPTO_free(ptr);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

