
int EC_GROUP_precompute_mult(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  if (*(int *)(*(int *)group + 0x78) == 0) {
    iVar1 = ec_wNAF_precompute_mult();
    return iVar1;
  }
  pcVar2 = *(code **)(*(int *)group + 0x7c);
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)();
    return iVar1;
  }
  return 1;
}

