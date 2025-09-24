
ECDSA_SIG * sm2_sig_gen(EC_KEY *param_1,BIGNUM *param_2)

{
  BIGNUM *a;
  EC_GROUP *group;
  BIGNUM *m;
  EC_POINT *r;
  BN_CTX *ctx;
  BIGNUM *n;
  BIGNUM *pBVar1;
  BIGNUM *b;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar2;
  ECDSA_SIG *pEVar3;
  BIGNUM *local_34;
  
  a = EC_KEY_get0_private_key(param_1);
  group = EC_KEY_get0_group(param_1);
  m = (BIGNUM *)EC_GROUP_get0_order();
  r = EC_POINT_new(group);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0 || r == (EC_POINT *)0x0) {
    r_01 = (BIGNUM *)0x0;
    local_34 = (BIGNUM *)0x0;
    ERR_put_error(0x35,0x6a,0x41,"crypto/sm2/sm2_sign.c",0xcb);
  }
  else {
    BN_CTX_start(ctx);
    n = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    b = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    if (r_00 == (BIGNUM *)0x0) {
      ERR_put_error(0x35,0x6a,0x41,"crypto/sm2/sm2_sign.c",0xd5);
      r_01 = (BIGNUM *)0x0;
      local_34 = (BIGNUM *)0x0;
    }
    else {
      r_01 = BN_new();
      local_34 = BN_new();
      if (local_34 == (BIGNUM *)0x0 || r_01 == (BIGNUM *)0x0) {
        iVar2 = 0xe1;
      }
      else {
        do {
          do {
            iVar2 = BN_priv_rand_range(n,m);
            if (iVar2 == 0) {
              iVar2 = 0xe7;
LAB_0015f50e:
              ERR_put_error(0x35,0x6a,0x44,"crypto/sm2/sm2_sign.c",iVar2);
              goto LAB_0015f4e6;
            }
            iVar2 = EC_POINT_mul(group,r,n,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
            if (((iVar2 == 0) ||
                (iVar2 = EC_POINT_get_affine_coordinates(group,r,b,0,ctx), iVar2 == 0)) ||
               (iVar2 = BN_mod_add(r_01,param_2,b,m,ctx), iVar2 == 0)) {
              iVar2 = 0xef;
              goto LAB_0015f50e;
            }
            iVar2 = BN_is_zero(r_01);
          } while (iVar2 != 0);
          iVar2 = BN_add(pBVar1,r_01,n);
          if (iVar2 == 0) {
            iVar2 = 0xf8;
            goto LAB_0015f50e;
          }
          iVar2 = BN_cmp(pBVar1,m);
        } while (iVar2 == 0);
        pBVar1 = BN_value_one();
        iVar2 = BN_add(local_34,a,pBVar1);
        if (((iVar2 == 0) ||
            (iVar2 = ec_group_do_inverse_ord(group,local_34,local_34,ctx), iVar2 == 0)) ||
           ((iVar2 = BN_mod_mul(r_00,a,r_01,m,ctx), iVar2 == 0 ||
            ((iVar2 = BN_sub(r_00,n,r_00), iVar2 == 0 ||
             (iVar2 = BN_mod_mul(local_34,local_34,r_00,m,ctx), iVar2 == 0)))))) {
          ERR_put_error(0x35,0x6a,3,"crypto/sm2/sm2_sign.c",0x104);
          goto LAB_0015f4e6;
        }
        pEVar3 = ECDSA_SIG_new();
        if (pEVar3 != (ECDSA_SIG *)0x0) {
          ECDSA_SIG_set0(pEVar3,r_01,local_34);
          goto LAB_0015f4f4;
        }
        iVar2 = 0x10a;
      }
      ERR_put_error(0x35,0x6a,0x41,"crypto/sm2/sm2_sign.c",iVar2);
    }
  }
LAB_0015f4e6:
  pEVar3 = (ECDSA_SIG *)0x0;
  BN_free(r_01);
  BN_free(local_34);
LAB_0015f4f4:
  BN_CTX_free(ctx);
  EC_POINT_free(r);
  return pEVar3;
}

