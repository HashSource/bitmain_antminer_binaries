
uint ec_GFp_simple_cmp(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  code *pcVar7;
  BN_CTX *c;
  code *pcVar8;
  BIGNUM *b;
  BIGNUM *local_38;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
    return (uint)(iVar1 == 0);
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_3 + 0x14) != 0)) {
    iVar1 = BN_cmp(*(BIGNUM **)(param_2 + 8),*(BIGNUM **)(param_3 + 8));
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = BN_cmp(*(BIGNUM **)(param_2 + 0xc),*(BIGNUM **)(param_3 + 0xc));
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  pcVar7 = *(code **)(*(int *)param_1 + 0x88);
  pcVar8 = *(code **)(*(int *)param_1 + 0x8c);
  c = (BN_CTX *)0x0;
  if ((param_4 == (BN_CTX *)0x0) && (param_4 = BN_CTX_new(), c = param_4, param_4 == (BN_CTX *)0x0))
  {
    return 0xffffffff;
  }
  BN_CTX_start(param_4);
  pBVar2 = BN_CTX_get(param_4);
  pBVar3 = BN_CTX_get(param_4);
  pBVar4 = BN_CTX_get(param_4);
  pBVar5 = BN_CTX_get(param_4);
  if (pBVar5 == (BIGNUM *)0x0) {
LAB_0011f9e4:
    uVar6 = 0xffffffff;
  }
  else {
    if (*(int *)(param_3 + 0x14) == 0) {
      iVar1 = (*pcVar8)(param_1,pBVar5,*(undefined4 *)(param_3 + 0x10),param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar2,*(undefined4 *)(param_2 + 8),pBVar5,param_4),
         local_38 = pBVar2, iVar1 == 0)) goto LAB_0011f9e4;
    }
    else {
      local_38 = *(BIGNUM **)(param_2 + 8);
    }
    if (*(int *)(param_2 + 0x14) == 0) {
      iVar1 = (*pcVar8)(param_1,pBVar4,*(undefined4 *)(param_2 + 0x10),param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar3,*(undefined4 *)(param_3 + 8),pBVar4,param_4), b = pBVar3,
         iVar1 == 0)) goto LAB_0011f9e4;
    }
    else {
      b = *(BIGNUM **)(param_3 + 8);
    }
    iVar1 = BN_cmp(local_38,b);
    if (iVar1 != 0) {
      uVar6 = 1;
      goto LAB_0011f9e8;
    }
    if (*(int *)(param_3 + 0x14) == 0) {
      iVar1 = (*pcVar7)(param_1,pBVar5,pBVar5,*(undefined4 *)(param_3 + 0x10),param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar2,*(undefined4 *)(param_2 + 0xc),pBVar5,param_4),
         iVar1 == 0)) goto LAB_0011f9e4;
    }
    else {
      local_38 = *(BIGNUM **)(param_2 + 0xc);
    }
    if (*(int *)(param_2 + 0x14) == 0) {
      iVar1 = (*pcVar7)(param_1,pBVar4,pBVar4,*(undefined4 *)(param_2 + 0x10),param_4);
      if ((iVar1 == 0) ||
         (iVar1 = (*pcVar7)(param_1,pBVar3,*(undefined4 *)(param_3 + 0xc),pBVar4,param_4),
         iVar1 == 0)) goto LAB_0011f9e4;
    }
    else {
      b = *(BIGNUM **)(param_3 + 0xc);
    }
    uVar6 = BN_cmp(local_38,b);
    if (uVar6 != 0) {
      uVar6 = 1;
    }
  }
LAB_0011f9e8:
  BN_CTX_end(param_4);
  BN_CTX_free(c);
  return uVar6;
}

