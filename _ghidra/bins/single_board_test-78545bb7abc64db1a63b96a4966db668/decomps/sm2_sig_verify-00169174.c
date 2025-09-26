
bool sm2_sig_verify(EC_KEY *param_1,undefined4 param_2,BIGNUM *param_3)

{
  BIGNUM *pBVar1;
  EC_GROUP *group;
  BIGNUM *a;
  BN_CTX *ctx;
  EC_POINT *r;
  BIGNUM *r_00;
  BIGNUM *b;
  BIGNUM *pBVar2;
  int iVar3;
  EC_POINT *q;
  bool bVar4;
  BIGNUM *local_30;
  BIGNUM *local_2c [2];
  
  group = EC_KEY_get0_group(param_1);
  a = (BIGNUM *)EC_GROUP_get0_order();
  local_30 = (BIGNUM *)0x0;
  local_2c[0] = (BIGNUM *)0x0;
  ctx = BN_CTX_new();
  r = EC_POINT_new(group);
  if (r == (EC_POINT *)0x0 || ctx == (BN_CTX *)0x0) {
    iVar3 = 0x12e;
  }
  else {
    bVar4 = false;
    BN_CTX_start(ctx);
    r_00 = BN_CTX_get(ctx);
    b = BN_CTX_get(ctx);
    if (b != (BIGNUM *)0x0) {
      ECDSA_SIG_get0(param_2,&local_30,local_2c);
      pBVar1 = local_30;
      pBVar2 = BN_value_one();
      iVar3 = BN_cmp(pBVar1,pBVar2);
      pBVar1 = local_2c[0];
      if (-1 < iVar3) {
        pBVar2 = BN_value_one();
        iVar3 = BN_cmp(pBVar1,pBVar2);
        if (((-1 < iVar3) && (iVar3 = BN_cmp(a,local_30), 0 < iVar3)) &&
           (iVar3 = BN_cmp(a,local_2c[0]), 0 < iVar3)) {
          iVar3 = BN_mod_add(r_00,local_30,local_2c[0],a,ctx);
          if (iVar3 == 0) {
            ERR_put_error(0x35,0x6b,3,"crypto/sm2/sm2_sign.c",0x14f);
            bVar4 = false;
          }
          else {
            iVar3 = BN_is_zero(r_00);
            pBVar1 = local_2c[0];
            if (iVar3 == 0) {
              q = EC_KEY_get0_public_key(param_1);
              iVar3 = EC_POINT_mul(group,r,pBVar1,q,r_00,ctx);
              if ((iVar3 == 0) ||
                 (iVar3 = EC_POINT_get_affine_coordinates(group,r,b,0,ctx), iVar3 == 0)) {
                bVar4 = false;
                ERR_put_error(0x35,0x6b,0x10,"crypto/sm2/sm2_sign.c",0x15a);
              }
              else {
                iVar3 = BN_mod_add(r_00,param_3,b,a,ctx);
                if (iVar3 == 0) {
                  ERR_put_error(0x35,0x6b,3,"crypto/sm2/sm2_sign.c",0x15f);
                  bVar4 = false;
                }
                else {
                  iVar3 = BN_cmp(local_30,r_00);
                  bVar4 = iVar3 == 0;
                }
              }
            }
            else {
              ERR_put_error(0x35,0x6b,0x65,"crypto/sm2/sm2_sign.c",0x154);
            }
          }
          goto LAB_00169294;
        }
      }
      bVar4 = false;
      ERR_put_error(0x35,0x6b,0x65,"crypto/sm2/sm2_sign.c",0x14a);
      goto LAB_00169294;
    }
    iVar3 = 0x136;
  }
  bVar4 = false;
  ERR_put_error(0x35,0x6b,0x41,"crypto/sm2/sm2_sign.c",iVar3);
LAB_00169294:
  EC_POINT_free(r);
  BN_CTX_free(ctx);
  return bVar4;
}

