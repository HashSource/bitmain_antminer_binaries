
BIGNUM * ec_GFp_simple_group_get_curve
                   (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  BN_CTX *c;
  
  if ((param_2 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(param_2,(BIGNUM *)param_1[10]), pBVar1 == (BIGNUM *)0x0)) {
    return (BIGNUM *)0x0;
  }
  if (param_4 != (BIGNUM *)0x0 || param_3 != (BIGNUM *)0x0) {
    if (*(int *)(*param_1 + 0x9c) == 0) {
      if ((param_3 == (BIGNUM *)0x0) ||
         (pBVar1 = BN_copy(param_3,(BIGNUM *)param_1[0x11]), pBVar1 != (BIGNUM *)0x0)) {
        if (param_4 == (BIGNUM *)0x0) goto LAB_0011e7d8;
        c = (BN_CTX *)0x0;
        pBVar1 = BN_copy(param_4,(BIGNUM *)param_1[0x12]);
        if (pBVar1 != (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)0x1;
        }
      }
      else {
        pBVar1 = (BIGNUM *)0x0;
        c = (BN_CTX *)0x0;
      }
    }
    else {
      c = (BN_CTX *)0x0;
      if ((param_5 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_5 = c, c == (BN_CTX *)0x0)) {
        return (BIGNUM *)0x0;
      }
      if ((param_3 != (BIGNUM *)0x0) &&
         (iVar2 = (**(code **)(*param_1 + 0x9c))(param_1,param_3,param_1[0x11],param_5), iVar2 == 0)
         ) {
        BN_CTX_free(c);
        return (BIGNUM *)0x0;
      }
      if (param_4 == (BIGNUM *)0x0) {
        BN_CTX_free(c);
        return (BIGNUM *)0x1;
      }
      pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x9c))(param_1,param_4,param_1[0x12],param_5);
      if (pBVar1 != (BIGNUM *)0x0) {
        pBVar1 = (BIGNUM *)0x1;
      }
    }
    BN_CTX_free(c);
    return pBVar1;
  }
LAB_0011e7d8:
  BN_CTX_free((BN_CTX *)0x0);
  return (BIGNUM *)0x1;
}

