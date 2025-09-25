
BIGNUM * ec_GFp_simple_get_Jprojective_coordinates_GFp
                   (int *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,
                   BIGNUM *param_6)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  
  if (*(int *)(*param_1 + 0x9c) == 0) {
    if (((param_3 == (BIGNUM *)0x0) ||
        (pBVar2 = BN_copy(param_3,*(BIGNUM **)(param_2 + 8)), pBVar2 != (BIGNUM *)0x0)) &&
       ((param_4 == (BIGNUM *)0x0 ||
        (pBVar2 = BN_copy(param_4,*(BIGNUM **)(param_2 + 0xc)), pBVar2 != (BIGNUM *)0x0)))) {
      pBVar1 = (BIGNUM *)0x1;
      pBVar2 = param_5;
      if (param_5 != (BIGNUM *)0x0) {
        pBVar2 = (BIGNUM *)0x0;
        pBVar1 = BN_copy(param_5,*(BIGNUM **)(param_2 + 0x10));
        if (pBVar1 != (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)0x1;
        }
      }
    }
    else {
      pBVar1 = (BIGNUM *)0x0;
      pBVar2 = (BIGNUM *)0x0;
    }
  }
  else {
    pBVar2 = (BIGNUM *)0x0;
    if ((param_6 == (BIGNUM *)0x0) &&
       (pBVar2 = (BIGNUM *)BN_CTX_new(), param_6 = pBVar2, pBVar2 == (BIGNUM *)0x0)) {
      return (BIGNUM *)0x0;
    }
    if (((param_3 == (BIGNUM *)0x0) ||
        (pBVar1 = (BIGNUM *)
                  (**(code **)(*param_1 + 0x9c))
                            (param_1,param_3,*(undefined4 *)(param_2 + 8),param_6),
        pBVar1 != (BIGNUM *)0x0)) &&
       ((param_4 == (BIGNUM *)0x0 ||
        (pBVar1 = (BIGNUM *)
                  (**(code **)(*param_1 + 0x9c))
                            (param_1,param_4,*(undefined4 *)(param_2 + 0xc),param_6),
        pBVar1 != (BIGNUM *)0x0)))) {
      if (param_5 == (BIGNUM *)0x0) {
        pBVar1 = (BIGNUM *)0x1;
      }
      else {
        pBVar1 = (BIGNUM *)
                 (**(code **)(*param_1 + 0x9c))
                           (param_1,param_5,*(undefined4 *)(param_2 + 0x10),param_6);
        if (pBVar1 != (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)0x1;
        }
      }
    }
  }
  BN_CTX_free((BN_CTX *)pBVar2);
  return pBVar1;
}

