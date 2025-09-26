
int dsa_cmp_parameters(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0xc),
                 *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0xc));
  if ((iVar1 == 0) &&
     (iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x10),
                     *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x10)), iVar1 == 0)) {
    uVar2 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x14),
                   *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x14));
    iVar1 = 1 - uVar2;
    if (1 < uVar2) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 0;
}

