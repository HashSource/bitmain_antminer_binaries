
undefined4 ec_key_simple_check_key(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  EC_POINT *r;
  BN_CTX *ctx;
  BIGNUM *m;
  
  if (((param_1 == 0) || (*(EC_GROUP **)(param_1 + 0xc) == (EC_GROUP *)0x0)) ||
     (*(EC_POINT **)(param_1 + 0x10) == (EC_POINT *)0x0)) {
    ERR_put_error(0x10,0x102,0x43,"crypto/ec/ec_key.c",0x117);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(param_1 + 0xc),*(EC_POINT **)(param_1 + 0x10));
  if (iVar1 != 0) {
    r = (EC_POINT *)0x0;
    ctx = (BN_CTX *)0x0;
    uVar2 = 0;
    ERR_put_error(0x10,0x102,0x6a,"crypto/ec/ec_key.c",0x11c);
    goto LAB_00119408;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    uVar2 = 0;
    r = (EC_POINT *)0x0;
    goto LAB_00119408;
  }
  r = EC_POINT_new(*(EC_GROUP **)(param_1 + 0xc));
  if (r != (EC_POINT *)0x0) {
    iVar1 = EC_POINT_is_on_curve(*(EC_GROUP **)(param_1 + 0xc),*(EC_POINT **)(param_1 + 0x10),ctx);
    uVar2 = 0;
    if (iVar1 < 1) {
      ERR_put_error(0x10,0x102,0x6b,"crypto/ec/ec_key.c",0x127);
      goto LAB_00119408;
    }
    m = *(BIGNUM **)(*(int *)(param_1 + 0xc) + 8);
    iVar1 = BN_is_zero(m);
    if (iVar1 != 0) {
      ERR_put_error(0x10,0x102,0x7a,"crypto/ec/ec_key.c",0x12d);
      goto LAB_00119408;
    }
    iVar1 = EC_POINT_mul(*(EC_GROUP **)(param_1 + 0xc),r,(BIGNUM *)0x0,
                         *(EC_POINT **)(param_1 + 0x10),m,ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x102,0x10,"crypto/ec/ec_key.c",0x131);
      uVar2 = 0;
      goto LAB_00119408;
    }
    iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(param_1 + 0xc),r);
    if (iVar1 != 0) {
      if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
        iVar1 = BN_cmp(*(BIGNUM **)(param_1 + 0x14),m);
        if (-1 < iVar1) {
          iVar1 = 0x13e;
          goto LAB_001194ba;
        }
        iVar1 = EC_POINT_mul(*(EC_GROUP **)(param_1 + 0xc),r,*(BIGNUM **)(param_1 + 0x14),
                             (EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
        if (iVar1 == 0) {
          ERR_put_error(0x10,0x102,0x10,"crypto/ec/ec_key.c",0x143);
          uVar2 = 0;
          goto LAB_00119408;
        }
        iVar1 = EC_POINT_cmp(*(EC_GROUP **)(param_1 + 0xc),r,*(EC_POINT **)(param_1 + 0x10),ctx);
        if (iVar1 != 0) {
          uVar2 = 0;
          ERR_put_error(0x10,0x102,0x7b,"crypto/ec/ec_key.c",0x147);
          goto LAB_00119408;
        }
      }
      uVar2 = 1;
      goto LAB_00119408;
    }
    iVar1 = 0x135;
LAB_001194ba:
    ERR_put_error(0x10,0x102,0x82,"crypto/ec/ec_key.c",iVar1);
  }
  uVar2 = 0;
LAB_00119408:
  BN_CTX_free(ctx);
  EC_POINT_free(r);
  return uVar2;
}

