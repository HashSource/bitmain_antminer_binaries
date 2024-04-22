
int ec_GFp_simple_group_get_curve
              (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BN_CTX *c;
  
  pBVar3 = param_4;
  if ((param_2 == (BIGNUM *)0x0) ||
     (pBVar1 = BN_copy(param_2,(BIGNUM *)(param_1 + 0x12)), pBVar1 != (BIGNUM *)0x0)) {
    pBVar1 = param_3;
    if (param_3 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)0x1;
    }
    pBVar4 = param_4;
    if (param_4 != (BIGNUM *)0x0) {
      pBVar4 = (BIGNUM *)0x1;
    }
    if (((uint)pBVar4 | (uint)pBVar1) != 0) {
      if (*(int *)(*param_1 + 0x94) != 0) {
        c = (BN_CTX *)0x0;
        if ((param_5 != (BN_CTX *)0x0) || (c = BN_CTX_new(), param_5 = c, c != (BN_CTX *)0x0)) {
          if ((pBVar1 == (BIGNUM *)0x0) ||
             (iVar2 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_1 + 0x1d,param_5,pBVar3),
             iVar2 != 0)) {
            if (pBVar4 == (BIGNUM *)0x0) {
              iVar2 = 1;
            }
            else {
              iVar2 = (**(code **)(*param_1 + 0x94))(param_1,param_4,param_1 + 0x22,param_5);
              if (iVar2 != 0) {
                iVar2 = 1;
              }
            }
          }
          else {
            iVar2 = 0;
          }
          if (c == (BN_CTX *)0x0) {
            return iVar2;
          }
          BN_CTX_free(c);
          return iVar2;
        }
        goto LAB_00129ce6;
      }
      if ((pBVar1 != (BIGNUM *)0x0) &&
         (pBVar3 = BN_copy(param_3,(BIGNUM *)(param_1 + 0x1d)), pBVar3 == (BIGNUM *)0x0)) {
        return 0;
      }
      if (pBVar4 != (BIGNUM *)0x0) {
        pBVar3 = BN_copy(param_4,(BIGNUM *)(param_1 + 0x22));
        if (pBVar3 == (BIGNUM *)0x0) {
          return 0;
        }
        return 1;
      }
    }
    iVar2 = 1;
  }
  else {
LAB_00129ce6:
    iVar2 = 0;
  }
  return iVar2;
}

