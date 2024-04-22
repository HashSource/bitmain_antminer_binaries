
undefined4 ssl2_new(undefined4 *param_1)

{
  void *__s;
  void *pvVar1;
  undefined4 uVar2;
  
  __s = CRYPTO_malloc(0x120,DAT_00064c20,0x143);
  if (__s != (void *)0x0) {
    memset(__s,0,0x120);
    pvVar1 = CRYPTO_malloc(0x8001,DAT_00064c20,0x14c);
    *(void **)((int)__s + 0x30) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      if (*(void **)((int)__s + 0x34) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)__s + 0x34));
      }
    }
    else {
      pvVar1 = CRYPTO_malloc(0x8002,DAT_00064c20,0x153);
      *(void **)((int)__s + 0x34) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        uVar2 = *(undefined4 *)((int)__s + 0x30);
        param_1[0x15] = __s;
        memset(__s,0,0x120);
        *(undefined4 *)((int)__s + 0x30) = uVar2;
        *(void **)((int)__s + 0x34) = pvVar1;
        *(undefined4 *)((int)__s + 4) = 1;
        param_1[0x13] = uVar2;
        *param_1 = 2;
        param_1[0x14] = 0;
        return 1;
      }
    }
    if (*(void **)((int)__s + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)__s + 0x30));
    }
    CRYPTO_free(__s);
  }
  return 0;
}

