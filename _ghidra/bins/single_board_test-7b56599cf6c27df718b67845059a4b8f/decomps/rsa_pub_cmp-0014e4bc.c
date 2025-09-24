
bool rsa_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = RSA_flags(*(RSA **)(param_1 + 0x18));
  if ((-1 < iVar1 << 0x1f) && (uVar2 = RSA_flags(*(RSA **)(param_2 + 0x18)), (uVar2 & 1) == 0)) {
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x10),
                   *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x10));
    if (iVar1 != 0) {
      return false;
    }
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x14),
                   *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x14));
    return iVar1 == 0;
  }
  return true;
}

