
int dsa_pub_cmp(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x18),
                 *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x18));
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

