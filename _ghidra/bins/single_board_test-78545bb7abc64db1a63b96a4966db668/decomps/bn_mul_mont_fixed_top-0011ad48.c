
int bn_mul_mont_fixed_top(undefined4 param_1,int param_2,int param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_3 + 4) + *(int *)(param_2 + 4);
  iVar2 = *(int *)(param_4 + 0x1c) * 2;
  if (iVar3 != iVar2 && iVar3 + *(int *)(param_4 + 0x1c) * -2 < 0 == SBORROW4(iVar3,iVar2)) {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  if (pBVar1 != (BIGNUM *)0x0) {
    if (param_2 == param_3) {
      iVar2 = bn_sqr_fixed_top(pBVar1,param_2,param_5);
    }
    else {
      iVar2 = bn_mul_fixed_top(pBVar1,param_2,param_3,param_5);
    }
    if (iVar2 != 0) {
      iVar2 = bn_from_montgomery_word(param_1,pBVar1,param_4);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      BN_CTX_end(param_5);
      return iVar2;
    }
  }
  BN_CTX_end(param_5);
  return 0;
}

