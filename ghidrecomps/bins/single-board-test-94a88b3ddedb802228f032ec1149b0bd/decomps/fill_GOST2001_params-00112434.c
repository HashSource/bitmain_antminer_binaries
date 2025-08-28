
undefined4 fill_GOST2001_params(EC_KEY *param_1,int param_2)

{
  int *piVar1;
  BN_CTX *ctx;
  int iVar2;
  EC_GROUP *group;
  EC_POINT *p;
  undefined4 uVar3;
  int *piVar4;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24 [2];
  
  local_38 = (BIGNUM *)0x0;
  local_34 = (BIGNUM *)0x0;
  local_30 = (BIGNUM *)0x0;
  local_2c = (BIGNUM *)0x0;
  local_28 = (BIGNUM *)0x0;
  local_24[0] = (BIGNUM *)0x0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
LAB_001124b2:
    uVar3 = 0;
  }
  else {
    BN_CTX_start(ctx);
    local_38 = BN_CTX_get(ctx);
    local_30 = BN_CTX_get(ctx);
    local_2c = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_24[0] = BN_CTX_get(ctx);
    local_34 = BN_CTX_get(ctx);
    if (((local_38 == (BIGNUM *)0x0 || local_30 == (BIGNUM *)0x0) ||
        (local_2c == (BIGNUM *)0x0 || local_28 == (BIGNUM *)0x0)) ||
       (local_24[0] == (BIGNUM *)0x0 || local_34 == (BIGNUM *)0x0)) {
      ERR_GOST_error(0x65,0x41,"gost2001.c",0x39);
joined_r0x001124f4:
      if (ctx == (BN_CTX *)0x0) goto LAB_001124b2;
      uVar3 = 0;
    }
    else {
      if (R3410_2001_paramset == 0) {
LAB_001124e6:
        ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
        goto joined_r0x001124f4;
      }
      if (R3410_2001_paramset == param_2) {
        piVar4 = &R3410_2001_paramset;
      }
      else {
        piVar1 = &DAT_0019e63c;
        do {
          piVar4 = piVar1;
          if (*piVar4 == 0) goto LAB_001124e6;
          piVar1 = piVar4 + 7;
        } while (*piVar4 != param_2);
      }
      iVar2 = BN_hex2bn(&local_38,(char *)piVar4[3]);
      if (((iVar2 == 0) || (iVar2 = BN_hex2bn(&local_30,(char *)piVar4[1]), iVar2 == 0)) ||
         (iVar2 = BN_hex2bn(&local_2c,(char *)piVar4[2]), iVar2 == 0)) {
        ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
        goto joined_r0x001124f4;
      }
      group = EC_GROUP_new_curve_GFp(local_38,local_30,local_2c,ctx);
      if (group == (EC_GROUP *)0x0) {
        ERR_GOST_error(0x65,0x41,"gost2001.c",0x4d);
        goto joined_r0x001124f4;
      }
      p = EC_POINT_new(group);
      if (p == (EC_POINT *)0x0) {
        ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
        uVar3 = 0;
      }
      else {
        iVar2 = BN_hex2bn(&local_28,(char *)piVar4[5]);
        if (((iVar2 == 0) || (iVar2 = BN_hex2bn(local_24,(char *)piVar4[6]), iVar2 == 0)) ||
           ((iVar2 = EC_POINT_set_affine_coordinates_GFp(group,p,local_28,local_24[0],ctx),
            iVar2 == 0 || (iVar2 = BN_hex2bn(&local_34,(char *)piVar4[4]), iVar2 == 0)))) {
          uVar3 = 0;
          ERR_GOST_error(0x65,0x44,"gost2001.c",0x5b);
        }
        else {
          iVar2 = EC_GROUP_set_generator(group,p,local_34,(BIGNUM *)0x0);
          if (iVar2 == 0) {
            ERR_GOST_error(0x65,0x44,"gost2001.c",0x66);
            uVar3 = 0;
          }
          else {
            EC_GROUP_set_curve_name(group,*piVar4);
            iVar2 = EC_KEY_set_group(param_1,group);
            if (iVar2 == 0) {
              ERR_GOST_error(0x65,0x44,"gost2001.c",0x6b);
              uVar3 = 0;
            }
            else {
              uVar3 = 1;
            }
          }
        }
        EC_POINT_free(p);
      }
      EC_GROUP_free(group);
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  return uVar3;
}

