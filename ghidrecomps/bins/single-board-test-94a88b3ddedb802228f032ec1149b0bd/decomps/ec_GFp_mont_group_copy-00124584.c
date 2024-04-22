
undefined4 ec_GFp_mont_group_copy(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BN_MONT_CTX *pBVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  
  uVar4 = param_4;
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    param_4 = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0xa4));
    param_4 = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  iVar1 = ec_GFp_simple_group_copy(param_1,param_2,param_3,param_4,uVar4);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_2 + 0xa0) != 0) {
    pBVar2 = BN_MONT_CTX_new();
    *(BN_MONT_CTX **)(param_1 + 0xa0) = pBVar2;
    if (pBVar2 == (BN_MONT_CTX *)0x0) {
      return 0;
    }
    pBVar2 = BN_MONT_CTX_copy(pBVar2,*(BN_MONT_CTX **)(param_2 + 0xa0));
    if (pBVar2 == (BN_MONT_CTX *)0x0) goto LAB_001245e2;
  }
  if (*(BIGNUM **)(param_2 + 0xa4) == (BIGNUM *)0x0) {
    return 1;
  }
  pBVar3 = BN_dup(*(BIGNUM **)(param_2 + 0xa4));
  *(BIGNUM **)(param_1 + 0xa4) = pBVar3;
  if (pBVar3 != (BIGNUM *)0x0) {
    return 1;
  }
LAB_001245e2:
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
    return 0;
  }
  return 0;
}

