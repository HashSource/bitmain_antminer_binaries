
undefined4
bn_secure_c2i(int *param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,
             int param_6)

{
  BIGNUM *pBVar1;
  
  pBVar1 = (BIGNUM *)*param_1;
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)BN_secure_new();
    *param_1 = (int)pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  pBVar1 = BN_bin2bn(param_2,param_3,pBVar1);
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)*param_1;
    if (pBVar1 != (BIGNUM *)0x0) {
      if (*(int *)(param_6 + 0x14) << 0x1f < 0) {
        BN_clear_free(pBVar1);
      }
      else {
        BN_free(pBVar1);
      }
      *param_1 = 0;
    }
    return 0;
  }
  BN_set_flags(*param_1,4);
  return 1;
}

