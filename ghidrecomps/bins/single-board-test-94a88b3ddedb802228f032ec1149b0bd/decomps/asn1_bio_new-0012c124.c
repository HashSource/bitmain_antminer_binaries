
undefined4 asn1_bio_new(int param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x40,DAT_0012c178,0x95);
  if (ptr == (undefined4 *)0x0) {
    return 0;
  }
  pvVar1 = CRYPTO_malloc(0x14,DAT_0012c178,0xa4);
  ptr[1] = pvVar1;
  if (pvVar1 != (void *)0x0) {
    ptr[2] = 0x14;
    ptr[3] = 0;
    ptr[4] = 0;
    ptr[5] = 0;
    ptr[6] = 0;
    ptr[0xc] = 0;
    ptr[0xe] = 0;
    ptr[0xd] = 0;
    *ptr = 0;
    ptr[7] = 4;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 **)(param_1 + 0x20) = ptr;
    *(undefined4 *)(param_1 + 0xc) = 1;
    return 1;
  }
  CRYPTO_free(ptr);
  return 0;
}

