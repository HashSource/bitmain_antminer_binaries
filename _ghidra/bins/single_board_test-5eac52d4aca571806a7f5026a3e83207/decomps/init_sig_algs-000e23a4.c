
undefined4 init_sig_algs(int param_1)

{
  int iVar1;
  
  CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x268));
  iVar1 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x268) = 0;
  *(undefined4 *)(iVar1 + 0x270) = 0;
  return 1;
}

