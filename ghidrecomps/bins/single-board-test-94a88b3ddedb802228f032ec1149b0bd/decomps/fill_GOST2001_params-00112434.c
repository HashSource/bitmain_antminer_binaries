
undefined4 fill_GOST2001_params(EC_KEY *param_1,int param_2)

{
  BN_CTX *ctx;
  EC_GROUP *group;
  EC_POINT *p;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
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
    ERR_GOST_error(0x65,0x41,DAT_00112608,0x2d);
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
      ERR_GOST_error(0x65,0x41,DAT_00112608,0x39);
    }
    else {
      iVar1 = *DAT_0011260c;
      piVar2 = DAT_0011260c;
      while (iVar1 != 0) {
        if (iVar1 == param_2) {
          iVar1 = BN_hex2bn(&local_38,(char *)piVar2[3]);
          if (((iVar1 == 0) || (iVar1 = BN_hex2bn(&local_30,(char *)piVar2[1]), iVar1 == 0)) ||
             (iVar1 = BN_hex2bn(&local_2c,(char *)piVar2[2]), iVar1 == 0)) {
            ERR_GOST_error(0x65,0x44,DAT_00112608,0x47);
            goto joined_r0x001124f4;
          }
          group = EC_GROUP_new_curve_GFp(local_38,local_30,local_2c,ctx);
          if (group == (EC_GROUP *)0x0) {
            ERR_GOST_error(0x65,0x41,DAT_00112608,0x4d);
            goto joined_r0x001124f4;
          }
          p = EC_POINT_new(group);
          if (p == (EC_POINT *)0x0) {
            ERR_GOST_error(0x65,0x41,DAT_00112608,0x53);
            uVar3 = 0;
          }
          else {
            iVar1 = BN_hex2bn(&local_28,(char *)piVar2[5]);
            if (((iVar1 == 0) || (iVar1 = BN_hex2bn(local_24,(char *)piVar2[6]), iVar1 == 0)) ||
               ((iVar1 = EC_POINT_set_affine_coordinates_GFp(group,p,local_28,local_24[0],ctx),
                iVar1 == 0 || (iVar1 = BN_hex2bn(&local_34,(char *)piVar2[4]), iVar1 == 0)))) {
              uVar3 = 0;
              ERR_GOST_error(0x65,0x44,DAT_00112608,0x5b);
            }
            else {
              iVar1 = EC_GROUP_set_generator(group,p,local_34,(BIGNUM *)0x0);
              if (iVar1 == 0) {
                ERR_GOST_error(0x65,0x44,DAT_00112608,0x66);
                uVar3 = 0;
              }
              else {
                EC_GROUP_set_curve_name(group,*piVar2);
                iVar1 = EC_KEY_set_group(param_1,group);
                if (iVar1 == 0) {
                  ERR_GOST_error(0x65,0x44,DAT_00112608,0x6b);
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
          goto LAB_001124f8;
        }
        piVar2 = piVar2 + 7;
        iVar1 = *piVar2;
      }
      ERR_GOST_error(0x65,0x82,DAT_00112608,0x40);
    }
joined_r0x001124f4:
    if (ctx != (BN_CTX *)0x0) {
      uVar3 = 0;
LAB_001124f8:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return uVar3;
    }
  }
  return 0;
}

