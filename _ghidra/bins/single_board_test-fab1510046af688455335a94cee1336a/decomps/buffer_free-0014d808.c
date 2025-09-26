
undefined4 buffer_free(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x20);
    pvVar1 = *(void **)(iVar2 + 8);
    if (pvVar1 != (void *)0x0) {
      CRYPTO_free(pvVar1);
    }
    pvVar1 = *(void **)(iVar2 + 0x14);
    if (pvVar1 != (void *)0x0) {
      CRYPTO_free(pvVar1);
    }
    CRYPTO_free(*(void **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

