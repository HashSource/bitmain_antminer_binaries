
undefined4 print_gost_01_isra_1(BIO *param_1,EVP_PKEY *param_2,int param_3,int param_4)

{
  BN_CTX *ctx;
  BIGNUM *pBVar1;
  BIGNUM *y;
  EC_KEY *pEVar2;
  EC_POINT *p;
  EC_GROUP *pEVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  void *pvVar7;
  
  if (param_4 == 2) {
    iVar4 = BIO_indent(param_1,param_3,0x80);
    if (iVar4 == 0) {
      return 0;
    }
    BIO_printf(param_1,DAT_00115d64);
    iVar4 = EVP_PKEY_base_id(param_2);
    if (iVar4 == 0x32b) {
      pEVar2 = (EC_KEY *)EVP_PKEY_get0(param_2);
      if ((pEVar2 != (EC_KEY *)0x0) &&
         (pBVar1 = EC_KEY_get0_private_key(pEVar2), pBVar1 != (BIGNUM *)0x0)) goto LAB_00115d32;
LAB_00115cfa:
      BIO_printf(param_1,DAT_00115d68);
    }
    else {
      if ((iVar4 != 0x32c) ||
         ((pvVar7 = EVP_PKEY_get0(param_2), pvVar7 == (void *)0x0 ||
          (pBVar1 = *(BIGNUM **)((int)pvVar7 + 0x1c), pBVar1 == (BIGNUM *)0x0)))) goto LAB_00115cfa;
LAB_00115d32:
      BN_print(param_1,pBVar1);
    }
    BIO_printf(param_1,DAT_00115d58);
  }
  else if (param_4 < 1) goto LAB_00115ca0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x83,0x41,DAT_00115d4c,0x1b8);
    return 0;
  }
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar2 = (EC_KEY *)EVP_PKEY_get0(param_2);
  p = EC_KEY_get0_public_key(pEVar2);
  pEVar2 = (EC_KEY *)EVP_PKEY_get0(param_2);
  pEVar3 = EC_KEY_get0_group(pEVar2);
  iVar4 = EC_POINT_get_affine_coordinates_GFp(pEVar3,p,pBVar1,y,ctx);
  if (iVar4 == 0) {
    ERR_GOST_error(0x83,0x10,DAT_00115d4c,0x1c2);
    BN_CTX_free(ctx);
    return 0;
  }
  iVar4 = BIO_indent(param_1,param_3,0x80);
  if (iVar4 == 0) {
    return 0;
  }
  BIO_printf(param_1,DAT_00115d50);
  iVar4 = BIO_indent(param_1,param_3 + 3,0x80);
  if (iVar4 == 0) {
    return 0;
  }
  BIO_printf(param_1,DAT_00115d54);
  BN_print(param_1,pBVar1);
  BIO_printf(param_1,DAT_00115d58);
  BIO_indent(param_1,param_3 + 3,0x80);
  BIO_printf(param_1,DAT_00115d5c);
  BN_print(param_1,y);
  BIO_printf(param_1,DAT_00115d58);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_00115ca0:
  pEVar2 = (EC_KEY *)EVP_PKEY_get0(param_2);
  pEVar3 = EC_KEY_get0_group(pEVar2);
  iVar4 = EC_GROUP_get_curve_name(pEVar3);
  iVar5 = BIO_indent(param_1,param_3,0x80);
  if (iVar5 == 0) {
    return 0;
  }
  pcVar6 = OBJ_nid2ln(iVar4);
  BIO_printf(param_1,DAT_00115d60,pcVar6);
  return 1;
}

