
int EC_GROUP_cmp(EC_GROUP *a,EC_GROUP *b,BN_CTX *ctx)

{
  EC_METHOD *pEVar1;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *b_00;
  BIGNUM *b_01;
  EC_POINT *a_00;
  EC_POINT *b_02;
  BN_CTX *local_34;
  
  pEVar1 = EC_GROUP_method_of(a);
  iVar2 = EC_METHOD_get_field_type(pEVar1);
  pEVar1 = EC_GROUP_method_of(b);
  iVar3 = EC_METHOD_get_field_type(pEVar1);
  if (iVar2 != iVar3) {
    return 1;
  }
  iVar2 = EC_GROUP_get_curve_name(a);
  if ((iVar2 != 0) && (iVar2 = EC_GROUP_get_curve_name(b), iVar2 != 0)) {
    iVar2 = EC_GROUP_get_curve_name(a);
    iVar3 = EC_GROUP_get_curve_name(b);
    if (iVar2 != iVar3) {
      return 1;
    }
  }
  if ((**(uint **)a & 2) != 0) {
    return 0;
  }
  if (ctx == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    local_34 = ctx;
    if (ctx == (BN_CTX *)0x0) {
      return -1;
    }
  }
  else {
    local_34 = (BN_CTX *)0x0;
  }
  BN_CTX_start(ctx);
  pBVar4 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  pBVar6 = BN_CTX_get(ctx);
  pBVar7 = BN_CTX_get(ctx);
  b_00 = BN_CTX_get(ctx);
  b_01 = BN_CTX_get(ctx);
  if (b_01 == (BIGNUM *)0x0) {
LAB_0011ef26:
    BN_CTX_end(ctx);
    BN_CTX_free(local_34);
    return -1;
  }
  iVar2 = (**(code **)(*(int *)a + 0x1c))(a,pBVar4,pBVar5,pBVar6,ctx);
  if ((((iVar2 != 0) &&
       (iVar2 = (**(code **)(*(int *)b + 0x1c))(b,pBVar7,b_00,b_01,ctx), iVar2 != 0)) &&
      (iVar2 = BN_cmp(pBVar4,pBVar7), iVar2 == 0)) &&
     ((iVar2 = BN_cmp(pBVar5,b_00), iVar2 == 0 && (iVar2 = BN_cmp(pBVar6,b_01), iVar2 == 0)))) {
    a_00 = EC_GROUP_get0_generator(a);
    b_02 = EC_GROUP_get0_generator(b);
    iVar2 = EC_POINT_cmp(a,a_00,b_02,ctx);
    if (iVar2 == 0) {
      pBVar4 = (BIGNUM *)EC_GROUP_get0_order(a);
      pBVar5 = (BIGNUM *)EC_GROUP_get0_order(b);
      pBVar6 = (BIGNUM *)EC_GROUP_get0_cofactor(a);
      pBVar7 = (BIGNUM *)EC_GROUP_get0_cofactor(b);
      if (pBVar5 == (BIGNUM *)0x0 || pBVar4 == (BIGNUM *)0x0) goto LAB_0011ef26;
      iVar2 = BN_cmp(pBVar4,pBVar5);
      if (iVar2 == 0) {
        iVar2 = BN_cmp(pBVar6,pBVar7);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        goto LAB_0011ee3c;
      }
    }
  }
  iVar2 = 1;
LAB_0011ee3c:
  BN_CTX_end(ctx);
  BN_CTX_free(local_34);
  return iVar2;
}

