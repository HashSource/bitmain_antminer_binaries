
int dh_cmp_parameters(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 8),
                 *(BIGNUM **)(*(int *)(param_2 + 0x14) + 8));
  if ((iVar1 == 0) &&
     (iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0xc),
                     *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0xc)), iVar1 == 0)) {
    if (*(undefined1 **)(param_1 + 0xc) != &dhx_asn1_meth) {
      return 1;
    }
    uVar2 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x24),
                   *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x24));
    iVar1 = 1 - uVar2;
    if (1 < uVar2) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 0;
}

