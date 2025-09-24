
undefined4 init_alpn(int param_1)

{
  int iVar1;
  int iVar2;
  
  CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x340));
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar2 + 0x340) = 0;
  *(undefined4 *)(iVar2 + 0x344) = 0;
  if (iVar1 != 0) {
    CRYPTO_free(*(void **)(iVar2 + 0x348));
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar1 + 0x348) = 0;
    *(undefined4 *)(iVar1 + 0x34c) = 0;
  }
  return 1;
}

