
void * buffer_new(int param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x20,DAT_000a9eb0,0x60);
  if (ptr == (undefined4 *)0x0) {
    return (void *)0x0;
  }
  pvVar1 = CRYPTO_malloc(0x1000,DAT_000a9eb0,99);
  ptr[2] = pvVar1;
  if (pvVar1 != (void *)0x0) {
    pvVar1 = CRYPTO_malloc(0x1000,DAT_000a9eb0,0x68);
    ptr[5] = pvVar1;
    if (pvVar1 != (void *)0x0) {
      *ptr = 0x1000;
      ptr[1] = 0x1000;
      ptr[3] = 0;
      ptr[4] = 0;
      ptr[6] = 0;
      ptr[7] = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 **)(param_1 + 0x20) = ptr;
      *(undefined4 *)(param_1 + 0xc) = 1;
      return (void *)0x1;
    }
    CRYPTO_free((void *)ptr[2]);
    pvVar1 = (void *)0x0;
  }
  CRYPTO_free(ptr);
  return pvVar1;
}

