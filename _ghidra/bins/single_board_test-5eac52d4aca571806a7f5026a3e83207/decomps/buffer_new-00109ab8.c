
undefined4 buffer_new(int param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  undefined4 uVar2;
  
  ptr = (undefined4 *)CRYPTO_zalloc(0x20,"crypto/bio/bf_buff.c",0x31);
  if (ptr != (undefined4 *)0x0) {
    *ptr = 0x1000;
    pvVar1 = CRYPTO_malloc(0x1000,"crypto/bio/bf_buff.c",0x36);
    ptr[2] = pvVar1;
    if (pvVar1 == (void *)0x0) {
      CRYPTO_free(ptr);
      uVar2 = 0;
    }
    else {
      ptr[1] = 0x1000;
      pvVar1 = CRYPTO_malloc(0x1000,"crypto/bio/bf_buff.c",0x3c);
      ptr[5] = pvVar1;
      if (pvVar1 == (void *)0x0) {
        CRYPTO_free((void *)ptr[2]);
        CRYPTO_free(ptr);
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
        *(undefined4 **)(param_1 + 0x24) = ptr;
        *(undefined4 *)(param_1 + 0x10) = 1;
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    return uVar2;
  }
  return 0;
}

