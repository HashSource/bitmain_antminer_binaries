
uint ossl_ecdsa_verify_sig(uchar *param_1,int param_2,undefined4 *param_3,EC_KEY *param_4)

{
  EC_GROUP *group;
  EC_POINT *q;
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *ret;
  BIGNUM *m;
  BIGNUM *b_00;
  BIGNUM *pBVar2;
  uint uVar3;
  EC_POINT *r_00;
  
  if (((param_4 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_4), group == (EC_GROUP *)0x0))
     || (q = EC_KEY_get0_public_key(param_4), param_3 == (undefined4 *)0x0 || q == (EC_POINT *)0x0))
  {
    ERR_put_error(0x10,0xfa,0x7c,"crypto/ec/ecdsa_ossl.c",0x14b);
    return 0xffffffff;
  }
  iVar1 = EC_KEY_can_sign(param_4);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xfa,0x9f,"crypto/ec/ecdsa_ossl.c",0x150);
    return 0xffffffff;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(0x10,0xfa,0x41,"crypto/ec/ecdsa_ossl.c",0x156);
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  b = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  m = BN_CTX_get(ctx);
  if (m == (BIGNUM *)0x0) {
    uVar3 = 0xffffffff;
    ERR_put_error(0x10,0xfa,3,"crypto/ec/ecdsa_ossl.c",0x15f);
    r_00 = (EC_POINT *)0x0;
    goto LAB_0012afb2;
  }
  b_00 = (BIGNUM *)EC_GROUP_get0_order(group);
  if (b_00 == (BIGNUM *)0x0) {
    uVar3 = 0xffffffff;
    ERR_put_error(0x10,0xfa,0x10,"crypto/ec/ecdsa_ossl.c",0x165);
    r_00 = (EC_POINT *)0x0;
    goto LAB_0012afb2;
  }
  iVar1 = BN_is_zero(*param_3);
  if ((((iVar1 != 0) || (iVar1 = BN_is_negative(*param_3), iVar1 != 0)) ||
      ((iVar1 = BN_ucmp((BIGNUM *)*param_3,b_00), -1 < iVar1 ||
       ((iVar1 = BN_is_zero(param_3[1]), iVar1 != 0 ||
        (iVar1 = BN_is_negative(param_3[1]), iVar1 != 0)))))) ||
     (iVar1 = BN_ucmp((BIGNUM *)param_3[1],b_00), -1 < iVar1)) {
    r_00 = (EC_POINT *)0x0;
    uVar3 = 0;
    ERR_put_error(0x10,0xfa,0x9c,"crypto/ec/ecdsa_ossl.c",0x16c);
    goto LAB_0012afb2;
  }
  iVar1 = ec_group_do_inverse_ord(group,b,param_3[1],ctx);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    ERR_put_error(0x10,0xfa,3,"crypto/ec/ecdsa_ossl.c",0x172);
    r_00 = (EC_POINT *)0x0;
    goto LAB_0012afb2;
  }
  uVar3 = BN_num_bits(b_00);
  if ((int)(uVar3 + param_2 * -8) < 0 == SBORROW4(uVar3,param_2 * 8)) {
    pBVar2 = BN_bin2bn(param_1,param_2,ret);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012b134;
LAB_0012b0fa:
    iVar1 = BN_mod_mul(r,ret,b,b_00,ctx);
    if (iVar1 == 0) {
      iVar1 = 0x187;
    }
    else {
      iVar1 = BN_mod_mul(b,(BIGNUM *)*param_3,b,b_00,ctx);
      if (iVar1 != 0) {
        r_00 = EC_POINT_new(group);
        if (r_00 == (EC_POINT *)0x0) {
          uVar3 = 0xffffffff;
          ERR_put_error(0x10,0xfa,0x41,"crypto/ec/ecdsa_ossl.c",0x191);
        }
        else {
          iVar1 = EC_POINT_mul(group,r_00,r,q,b,ctx);
          if (iVar1 == 0) {
            uVar3 = 0xffffffff;
            ERR_put_error(0x10,0xfa,0x10,"crypto/ec/ecdsa_ossl.c",0x195);
          }
          else {
            iVar1 = EC_POINT_get_affine_coordinates(group,r_00,m,0,ctx);
            if (iVar1 == 0) {
              uVar3 = 0xffffffff;
              ERR_put_error(0x10,0xfa,0x10,"crypto/ec/ecdsa_ossl.c",0x19a);
            }
            else {
              iVar1 = BN_nnmod(r,m,b_00,ctx);
              if (iVar1 == 0) {
                uVar3 = 0xffffffff;
                ERR_put_error(0x10,0xfa,3,"crypto/ec/ecdsa_ossl.c",0x19f);
              }
              else {
                iVar1 = BN_ucmp(r,(BIGNUM *)*param_3);
                uVar3 = (uint)(iVar1 == 0);
              }
            }
          }
        }
        goto LAB_0012afb2;
      }
      iVar1 = 0x18c;
    }
  }
  else {
    iVar1 = uVar3 + 7;
    if (iVar1 < 0) {
      iVar1 = uVar3 + 0xe;
    }
    iVar1 = iVar1 >> 3;
    pBVar2 = BN_bin2bn(param_1,iVar1,ret);
    if (pBVar2 == (BIGNUM *)0x0) {
LAB_0012b134:
      r_00 = (EC_POINT *)0x0;
      ERR_put_error(0x10,0xfa,3,"crypto/ec/ecdsa_ossl.c",0x17d);
      uVar3 = 0xffffffff;
      goto LAB_0012afb2;
    }
    if (((int)(uVar3 + iVar1 * -8) < 0 == SBORROW4(uVar3,iVar1 * 8)) ||
       (iVar1 = BN_rshift(ret,ret,8 - (uVar3 & 7)), iVar1 != 0)) goto LAB_0012b0fa;
    iVar1 = 0x182;
  }
  r_00 = (EC_POINT *)0x0;
  uVar3 = 0xffffffff;
  ERR_put_error(0x10,0xfa,3,"crypto/ec/ecdsa_ossl.c",iVar1);
LAB_0012afb2:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(r_00);
  return uVar3;
}

