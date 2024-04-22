
int rsa_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x10),
                 *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x10));
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x14),
                 *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x14));
  iVar1 = 1 - uVar2;
  if (1 < uVar2) {
    iVar1 = 0;
  }
  return iVar1;
}

