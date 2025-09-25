
undefined4
ossl_ecdsa_sign_setup(EC_KEY *param_1,BN_CTX *param_2,undefined4 *param_3,undefined4 *param_4)

{
  EC_GROUP *group;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  EC_POINT *r;
  BIGNUM *a_01;
  int iVar3;
  BN_CTX *ctx;
  undefined4 uVar4;
  
  if ((param_1 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_1), group == (EC_GROUP *)0x0))
  {
    ERR_put_error(0x10,0xf8,0x43,"crypto/ec/ecdsa_ossl.c",0x2f);
    return 0;
  }
  pBVar1 = EC_KEY_get0_private_key(param_1);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xf8,0x7d,"crypto/ec/ecdsa_ossl.c",0x33);
    return 0;
  }
  iVar2 = EC_KEY_can_sign(param_1);
  if (iVar2 == 0) {
    ERR_put_error(0x10,0xf8,0x9f,"crypto/ec/ecdsa_ossl.c",0x38);
    return 0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x10,0xf8,0x41,"crypto/ec/ecdsa_ossl.c",0x3e);
    return 0;
  }
  pBVar1 = BN_new();
  a = BN_new();
  a_00 = BN_new();
  if (a_00 == (BIGNUM *)0x0 || (a == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0)) {
    r = (EC_POINT *)0x0;
    ERR_put_error(0x10,0xf8,0x41,"crypto/ec/ecdsa_ossl.c",0x47);
  }
  else {
    r = EC_POINT_new(group);
    if (r == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x4b);
    }
    else {
      a_01 = (BIGNUM *)EC_GROUP_get0_order(group);
      iVar2 = BN_num_bits(a_01);
      iVar3 = BN_set_bit(pBVar1,iVar2);
      if (((iVar3 != 0) && (iVar3 = BN_set_bit(a,iVar2), iVar3 != 0)) &&
         (iVar2 = BN_set_bit(a_00,iVar2), iVar2 != 0)) {
        do {
          do {
            iVar2 = BN_priv_rand_range(pBVar1,a_01);
            if (iVar2 == 0) {
              ERR_put_error(0x10,0xf8,0x9e,"crypto/ec/ecdsa_ossl.c",100);
              goto LAB_0011c8e8;
            }
            iVar2 = BN_is_zero(pBVar1);
          } while (iVar2 != 0);
          iVar2 = EC_POINT_mul(group,r,pBVar1,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (iVar2 == 0) {
            ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x6c);
            goto LAB_0011c8e8;
          }
          iVar2 = EC_POINT_get_affine_coordinates(group,r,a_00,0,ctx);
          if (iVar2 == 0) {
            ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x71);
            goto LAB_0011c8e8;
          }
          iVar2 = BN_nnmod(a,a_00,a_01,ctx);
          if (iVar2 == 0) {
            iVar2 = 0x76;
            goto LAB_0011ca4a;
          }
          iVar2 = BN_is_zero(a);
        } while (iVar2 != 0);
        iVar2 = ec_group_do_inverse_ord(group,pBVar1,pBVar1,ctx);
        if (iVar2 != 0) {
          uVar4 = 1;
          BN_clear_free((BIGNUM *)*param_4);
          BN_clear_free((BIGNUM *)*param_3);
          *param_4 = a;
          *param_3 = pBVar1;
          goto LAB_0011c8f6;
        }
        iVar2 = 0x7d;
LAB_0011ca4a:
        ERR_put_error(0x10,0xf8,3,"crypto/ec/ecdsa_ossl.c",iVar2);
      }
    }
  }
LAB_0011c8e8:
  uVar4 = 0;
  BN_clear_free(pBVar1);
  BN_clear_free(a);
LAB_0011c8f6:
  if (param_2 != ctx) {
    BN_CTX_free(ctx);
  }
  EC_POINT_free(r);
  BN_clear_free(a_00);
  return uVar4;
}

