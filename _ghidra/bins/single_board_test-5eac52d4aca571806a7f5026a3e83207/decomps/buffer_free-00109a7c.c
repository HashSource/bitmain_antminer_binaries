
undefined4 buffer_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x24);
    CRYPTO_free(*(void **)(iVar1 + 8));
    CRYPTO_free(*(void **)(iVar1 + 0x14));
    CRYPTO_free(*(void **)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    return 1;
  }
  return 0;
}

