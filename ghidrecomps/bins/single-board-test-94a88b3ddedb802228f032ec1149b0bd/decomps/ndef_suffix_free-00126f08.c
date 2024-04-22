
undefined4
ndef_suffix_free(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,void **param_4)

{
  void *ptr;
  void *pvVar1;
  
  if (param_4 != (void **)0x0) {
    pvVar1 = *param_4;
    ptr = *(void **)((int)pvVar1 + 0x14);
    if (ptr != (void *)0x0) {
      CRYPTO_free(ptr);
    }
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
    *param_2 = 0;
    *param_3 = 0;
    CRYPTO_free(*param_4);
    *param_4 = (void *)0x0;
    return 1;
  }
  return 0;
}

