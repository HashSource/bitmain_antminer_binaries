
undefined4 ec_GF2m_simple_is_on_curve(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  BN_CTX *c;
  code *pcVar5;
  code *pcVar6;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 == 0) {
    pcVar5 = *(code **)(*(int *)param_1 + 0x88);
    pcVar6 = *(code **)(*(int *)param_1 + 0x8c);
    if ((*(int *)(param_2 + 0x14) == 0) ||
       ((c = (BN_CTX *)0x0, param_3 == (BN_CTX *)0x0 &&
        (param_3 = BN_CTX_new(), c = param_3, param_3 == (BN_CTX *)0x0)))) {
      uVar4 = 0xffffffff;
    }
    else {
      BN_CTX_start(param_3);
      pBVar2 = BN_CTX_get(param_3);
      pBVar3 = BN_CTX_get(param_3);
      if (((((pBVar3 == (BIGNUM *)0x0) ||
            (iVar1 = BN_GF2m_add(pBVar3,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 0x44)
                                ), iVar1 == 0)) ||
           (iVar1 = (*pcVar5)(param_1,pBVar3,pBVar3,*(undefined4 *)(param_2 + 8),param_3),
           iVar1 == 0)) ||
          ((iVar1 = BN_GF2m_add(pBVar3,pBVar3,*(undefined4 *)(param_2 + 0xc)), iVar1 == 0 ||
           (iVar1 = (*pcVar5)(param_1,pBVar3,pBVar3,*(undefined4 *)(param_2 + 8),param_3),
           iVar1 == 0)))) ||
         ((iVar1 = BN_GF2m_add(pBVar3,pBVar3,*(undefined4 *)(param_1 + 0x48)), iVar1 == 0 ||
          ((iVar1 = (*pcVar6)(param_1,pBVar2,*(undefined4 *)(param_2 + 0xc),param_3), iVar1 == 0 ||
           (iVar1 = BN_GF2m_add(pBVar3,pBVar3,pBVar2), iVar1 == 0)))))) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = BN_is_zero(pBVar3);
      }
      BN_CTX_end(param_3);
      BN_CTX_free(c);
    }
    return uVar4;
  }
  return 1;
}

