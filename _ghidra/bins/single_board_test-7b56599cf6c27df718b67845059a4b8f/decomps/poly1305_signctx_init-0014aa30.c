
undefined4 poly1305_signctx_init(int param_1,EVP_MD_CTX *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x18);
  if (*piVar1 != 0x20) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  EVP_MD_CTX_set_flags(param_2,0x100);
  EVP_MD_CTX_set_update_fn(param_2,0x14aa6d);
  Poly1305_Init(iVar2 + 0x10,piVar1[2]);
  return 1;
}

