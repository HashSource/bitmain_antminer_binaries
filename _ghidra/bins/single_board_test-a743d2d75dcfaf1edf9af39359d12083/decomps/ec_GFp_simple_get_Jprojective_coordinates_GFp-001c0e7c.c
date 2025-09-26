
BIGNUM * ec_GFp_simple_get_Jprojective_coordinates_GFp
                   (int *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,
                   BN_CTX *param_6)

{
  int iVar1;
  BIGNUM *pBVar2;
  BN_CTX *c;
  
  if (*(int *)(*param_1 + 0x94) == 0) {
    if (((param_3 == (BIGNUM *)0x0) ||
        (pBVar2 = BN_copy(param_3,(BIGNUM *)(param_2 + 4)), pBVar2 != (BIGNUM *)0x0)) &&
       ((param_4 == (BIGNUM *)0x0 ||
        (pBVar2 = BN_copy(param_4,(BIGNUM *)(param_2 + 0x18)), pBVar2 != (BIGNUM *)0x0)))) {
      pBVar2 = (BIGNUM *)0x1;
      if ((param_5 != (BIGNUM *)0x0) &&
         (pBVar2 = BN_copy(param_5,(BIGNUM *)(param_2 + 0x2c)), pBVar2 != (BIGNUM *)0x0)) {
        pBVar2 = (BIGNUM *)0x1;
      }
    }
    else {
      pBVar2 = (BIGNUM *)0x0;
    }
  }
  else {
    c = (BN_CTX *)0x0;
    if ((param_6 == (BN_CTX *)0x0) &&
       (param_6 = BN_CTX_new(), c = param_6, param_6 == (BN_CTX *)0x0)) {
      pBVar2 = (BIGNUM *)0x0;
    }
    else {
      if (((param_3 == (BIGNUM *)0x0) ||
          (iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_6), iVar1 != 0))
         && ((param_4 == (BIGNUM *)0x0 ||
             (iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_6),
             iVar1 != 0)))) {
        if (param_5 == (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
        else {
          pBVar2 = (BIGNUM *)(**(code **)(*param_1 + 0x94))(param_1,param_5,param_2 + 0x2c,param_6);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
        }
      }
      else {
        pBVar2 = (BIGNUM *)0x0;
      }
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
      }
    }
  }
  return pBVar2;
}

