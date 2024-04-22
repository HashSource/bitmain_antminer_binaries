
int ec_GF2m_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  code *pcVar4;
  BN_CTX *c;
  EC_POINT *pEVar5;
  code *pcVar6;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar1 != 0) {
    return 1;
  }
  pcVar6 = *(code **)(*param_1 + 0x84);
  pcVar4 = *(code **)(*param_1 + 0x88);
  if (*(int *)(param_2 + 0x40) == 0) {
    return -1;
  }
  if (param_3 == (BN_CTX *)0x0) {
    param_3 = BN_CTX_new();
    c = param_3;
    if (param_3 == (BN_CTX *)0x0) {
      return -1;
    }
  }
  else {
    c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_3);
  pBVar2 = BN_CTX_get(param_3);
  pBVar3 = BN_CTX_get(param_3);
  if (pBVar3 != (BIGNUM *)0x0) {
    pEVar5 = param_2 + 4;
    iVar1 = BN_GF2m_add(pBVar3,pEVar5,param_1 + 0x1d);
    if ((iVar1 != 0) && (iVar1 = (*pcVar6)(param_1,pBVar3,pBVar3,pEVar5,param_3), iVar1 != 0)) {
      iVar1 = BN_GF2m_add(pBVar3,pBVar3,param_2 + 0x18);
      if (((iVar1 != 0) &&
          (((iVar1 = (*pcVar6)(param_1,pBVar3,pBVar3,pEVar5,param_3), iVar1 != 0 &&
            (iVar1 = BN_GF2m_add(pBVar3,pBVar3,param_1 + 0x22), iVar1 != 0)) &&
           (iVar1 = (*pcVar4)(param_1,pBVar2,param_2 + 0x18,param_3), iVar1 != 0)))) &&
         (iVar1 = BN_GF2m_add(pBVar3,pBVar3,pBVar2), iVar1 != 0)) {
        iVar1 = 1 - pBVar3->top;
        if (1 < (uint)pBVar3->top) {
          iVar1 = 0;
        }
        goto LAB_000f6948;
      }
    }
  }
  iVar1 = -1;
LAB_000f6948:
  BN_CTX_end(param_3);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar1;
}

