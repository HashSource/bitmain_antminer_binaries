
undefined4 ndef_suffix_free(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  void *ptr;
  int iVar1;
  
  if (param_4 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_4;
  if (iVar1 != 0) {
    CRYPTO_free(*(void **)(iVar1 + 0x14));
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *param_2 = 0;
    ptr = (void *)*param_4;
    *param_3 = 0;
    CRYPTO_free(ptr);
    *param_4 = 0;
    return 1;
  }
  return 0;
}

