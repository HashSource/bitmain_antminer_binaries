
undefined4 init_sig_algs_cert(int param_1)

{
  int iVar1;
  
  CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x26c));
  iVar1 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x26c) = 0;
  *(undefined4 *)(iVar1 + 0x274) = 0;
  return 1;
}

