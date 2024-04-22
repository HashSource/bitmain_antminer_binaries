
BIGNUM * bn_c2i(BIGNUM **param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,
               int param_6)

{
  BIGNUM *pBVar1;
  
  pBVar1 = *param_1;
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = BN_new();
    *param_1 = pBVar1;
  }
  pBVar1 = BN_bin2bn(param_2,param_3,pBVar1);
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = *param_1;
    if (pBVar1 != (BIGNUM *)0x0) {
      if (*(int *)(param_6 + 0x14) << 0x1f < 0) {
        BN_clear_free(pBVar1);
      }
      else {
        BN_free(pBVar1);
      }
      pBVar1 = (BIGNUM *)0x0;
      *param_1 = (BIGNUM *)0x0;
    }
  }
  else {
    pBVar1 = (BIGNUM *)0x1;
  }
  return pBVar1;
}

