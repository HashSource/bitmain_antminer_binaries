
undefined4 gost2001_compute_public(EC_KEY *param_1)

{
  EC_GROUP *group;
  BN_CTX *ctx;
  BIGNUM *n;
  EC_POINT *r;
  int iVar1;
  undefined4 uVar2;
  
  group = EC_KEY_get0_group(param_1);
  if (group == (EC_GROUP *)0x0) {
    ERR_GOST_error(0x68,0x72,DAT_00112d18,0x187);
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x68,0x41,DAT_00112d18,0x18c);
    return 0;
  }
  BN_CTX_start(ctx);
  n = EC_KEY_get0_private_key(param_1);
  if (n == (BIGNUM *)0x0) {
    ERR_GOST_error(0x68,0x10,DAT_00112d18,0x191);
  }
  else {
    r = EC_POINT_new(group);
    if (r != (EC_POINT *)0x0) {
      iVar1 = EC_POINT_mul(group,r,n,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
      if (iVar1 == 0) {
        ERR_GOST_error(0x68,0x10,DAT_00112d18,0x19b);
        uVar2 = 0;
      }
      else {
        iVar1 = EC_KEY_set_public_key(param_1,r);
        if (iVar1 == 0) {
          ERR_GOST_error(0x68,0x10,DAT_00112d18,0x19f);
          uVar2 = 0;
        }
        else {
          uVar2 = 0x100;
        }
      }
      EC_POINT_free(r);
      goto LAB_00112c9c;
    }
    ERR_GOST_error(0x68,0x41,DAT_00112d18,0x197);
  }
  uVar2 = 0;
LAB_00112c9c:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar2;
}

