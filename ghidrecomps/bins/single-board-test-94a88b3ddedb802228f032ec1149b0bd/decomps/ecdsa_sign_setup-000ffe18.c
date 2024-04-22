
BIGNUM * ecdsa_sign_setup(EC_KEY *param_1,BN_CTX *param_2,BIGNUM **param_3,BIGNUM **param_4)

{
  EC_GROUP *group;
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *order;
  BIGNUM *x;
  int iVar2;
  EC_METHOD *meth;
  BN_MONT_CTX *in_mont;
  BN_CTX *ctx;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *r_00;
  
  if ((param_1 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_1), group == (EC_GROUP *)0x0))
  {
    ERR_put_error(0x2a,0x67,0x43,DAT_001000a4,100);
    return (BIGNUM *)0x0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x2a,0x67,0x41,DAT_001000a4,0x6a);
    return (BIGNUM *)0x0;
  }
  pBVar1 = BN_new();
  r = BN_new();
  order = BN_new();
  x = BN_new();
  if ((pBVar1 == (BIGNUM *)0x0 || r == (BIGNUM *)0x0) ||
     (order == (BIGNUM *)0x0 || x == (BIGNUM *)0x0)) {
    ERR_put_error(0x2a,0x67,0x41,DAT_001000a4,0x75);
    r_00 = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      r_00 = (BIGNUM *)0x0;
      goto LAB_000ffe86;
    }
  }
  else {
    r_00 = (BIGNUM *)EC_POINT_new(group);
    if (r_00 == (BIGNUM *)0x0) {
      iVar4 = 0x79;
    }
    else {
      iVar2 = EC_GROUP_get_order(group,order,ctx);
      iVar4 = 0x7d;
      if (iVar2 != 0) {
        do {
          do {
            iVar4 = BN_rand_range(pBVar1,order);
            if (iVar4 == 0) {
              ERR_put_error(0x2a,0x67,0x68,DAT_001000a4,0x86);
              goto LAB_000ffe86;
            }
          } while (pBVar1->top == 0);
          iVar4 = BN_add(pBVar1,pBVar1,order);
          if (iVar4 == 0) goto LAB_000ffe86;
          iVar4 = BN_num_bits(pBVar1);
          iVar2 = BN_num_bits(order);
          if ((iVar4 <= iVar2) && (iVar4 = BN_add(pBVar1,pBVar1,order), iVar4 == 0))
          goto LAB_000ffe86;
          iVar4 = EC_POINT_mul(group,(EC_POINT *)r_00,pBVar1,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (iVar4 == 0) {
            iVar4 = 0x98;
            goto LAB_00100050;
          }
          meth = EC_GROUP_method_of(group);
          iVar4 = EC_METHOD_get_field_type(meth);
          if (iVar4 == 0x196) {
            iVar4 = EC_POINT_get_affine_coordinates_GFp(group,(EC_POINT *)r_00,x,(BIGNUM *)0x0,ctx);
            if (iVar4 == 0) {
              iVar4 = 0x9f;
              goto LAB_00100050;
            }
          }
          else {
            iVar4 = EC_POINT_get_affine_coordinates_GF2m();
            if (iVar4 == 0) {
              iVar4 = 0xa9;
              goto LAB_00100050;
            }
          }
          iVar4 = BN_nnmod(r,x,order,ctx);
          if (iVar4 == 0) {
            iVar4 = 0xaf;
            goto LAB_00100088;
          }
        } while (r->top == 0);
        iVar4 = EC_GROUP_get_mont_data(group);
        if (iVar4 == 0) {
          pBVar3 = BN_mod_inverse(pBVar1,pBVar1,order,ctx);
          if (pBVar3 != (BIGNUM *)0x0) {
LAB_000fffe0:
            if (*param_4 != (BIGNUM *)0x0) {
              BN_clear_free(*param_4);
            }
            if (*param_3 != (BIGNUM *)0x0) {
              BN_clear_free(*param_3);
            }
            *param_4 = r;
            *param_3 = pBVar1;
            pBVar1 = (BIGNUM *)0x1;
            goto joined_r0x00100004;
          }
          iVar4 = 0xcb;
        }
        else {
          iVar2 = BN_set_word(x,2);
          iVar4 = 0xbc;
          if (iVar2 != 0) {
            iVar2 = BN_mod_sub(x,order,x,order,ctx);
            iVar4 = 0xc0;
            if (iVar2 != 0) {
              x->flags = x->flags | 4;
              in_mont = (BN_MONT_CTX *)EC_GROUP_get_mont_data(group);
              iVar2 = BN_mod_exp_mont_consttime(pBVar1,pBVar1,x,order,ctx,in_mont);
              iVar4 = 0xc6;
              if (iVar2 != 0) goto LAB_000fffe0;
            }
          }
        }
LAB_00100088:
        ERR_put_error(0x2a,0x67,3,DAT_001000a4,iVar4);
        goto LAB_000ffe86;
      }
    }
LAB_00100050:
    ERR_put_error(0x2a,0x67,0x10,DAT_001000a4,iVar4);
LAB_000ffe86:
    BN_clear_free(pBVar1);
  }
  pBVar1 = r;
  if (r != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
    BN_clear_free(r);
  }
joined_r0x00100004:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (r_00 != (BIGNUM *)0x0) {
    EC_POINT_free((EC_POINT *)r_00);
  }
  if (x != (BIGNUM *)0x0) {
    BN_clear_free(x);
  }
  return pBVar1;
}

