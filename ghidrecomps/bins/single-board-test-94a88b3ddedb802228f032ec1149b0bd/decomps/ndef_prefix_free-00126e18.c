
undefined4 ndef_prefix_free(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  void *ptr;
  int iVar1;
  
  if (param_4 != (int *)0x0) {
    iVar1 = *param_4;
    ptr = *(void **)(iVar1 + 0x14);
    if (ptr != (void *)0x0) {
      CRYPTO_free(ptr);
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *param_2 = 0;
    *param_3 = 0;
    return 1;
  }
  return 0;
}

