
int ecdsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,EC_KEY *param_4)

{
  EC_GROUP *group;
  EC_POINT *q;
  BN_CTX *ctx;
  BIGNUM *order;
  BIGNUM *r;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *x;
  BIGNUM *pBVar1;
  uint uVar2;
  EC_POINT *r_00;
  EC_METHOD *meth;
  int iVar3;
  int iVar4;
  
  if ((((param_4 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_4), group == (EC_GROUP *)0x0)
       ) || (q = EC_KEY_get0_public_key(param_4), q == (EC_POINT *)0x0)) ||
     (param_3 == (BIGNUM **)0x0)) {
    ERR_put_error(0x2a,0x66,0x67,DAT_000ffe14,0x16c);
    return -1;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(0x2a,0x66,0x41,DAT_000ffe14,0x172);
    return -1;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  ret_00 = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  iVar3 = 0x17c;
  if (x == (BIGNUM *)0x0) goto LAB_000ffcd6;
  iVar3 = EC_GROUP_get_order(group,order,ctx);
  if (iVar3 == 0) {
    ERR_put_error(0x2a,0x66,0x10,DAT_000ffe14,0x181);
    iVar4 = -1;
    goto LAB_000ffc1c;
  }
  pBVar1 = *param_3;
  if ((((pBVar1->top == 0) || (pBVar1->neg != 0)) ||
      ((iVar3 = BN_ucmp(pBVar1,order), -1 < iVar3 ||
       ((pBVar1 = param_3[1], pBVar1->top == 0 || (pBVar1->neg != 0)))))) ||
     (iVar3 = BN_ucmp(pBVar1,order), -1 < iVar3)) {
    iVar4 = 0;
    ERR_put_error(0x2a,0x66,100,DAT_000ffe14,0x188);
    goto LAB_000ffc1c;
  }
  pBVar1 = BN_mod_inverse(ret,param_3[1],order,ctx);
  if (pBVar1 == (BIGNUM *)0x0) {
    iVar3 = 0x18e;
  }
  else {
    uVar2 = BN_num_bits(order);
    if ((int)(uVar2 + param_2 * -8) < 0 != SBORROW4(uVar2,param_2 * 8)) {
      param_2 = uVar2 + 7;
      if (param_2 < 0) {
        param_2 = uVar2 + 0xe;
      }
      param_2 = param_2 >> 3;
    }
    pBVar1 = BN_bin2bn(param_1,param_2,ret_00);
    if (pBVar1 == (BIGNUM *)0x0) {
      iVar3 = 0x199;
    }
    else if (((int)(uVar2 + param_2 * -8) < 0 == SBORROW4(uVar2,param_2 * 8)) ||
            (iVar3 = BN_rshift(ret_00,ret_00,8 - (uVar2 & 7)), iVar3 != 0)) {
      iVar3 = BN_mod_mul(r,ret_00,ret,order,ctx);
      if (iVar3 == 0) {
        iVar3 = 0x1a3;
      }
      else {
        iVar3 = BN_mod_mul(ret,*param_3,ret,order,ctx);
        if (iVar3 != 0) {
          r_00 = EC_POINT_new(group);
          if (r_00 == (EC_POINT *)0x0) {
            ERR_put_error(0x2a,0x66,0x41,DAT_000ffe14,0x1ad);
            iVar4 = -1;
            goto LAB_000ffc1c;
          }
          iVar3 = EC_POINT_mul(group,r_00,r,q,ret,ctx);
          if (iVar3 == 0) {
            iVar3 = 0x1b1;
          }
          else {
            meth = EC_GROUP_method_of(group);
            iVar3 = EC_METHOD_get_field_type(meth);
            if (iVar3 == 0x196) {
              iVar3 = EC_POINT_get_affine_coordinates_GFp(group,r_00,x,(BIGNUM *)0x0,ctx);
              if (iVar3 != 0) goto LAB_000ffdae;
              iVar3 = 0x1b7;
            }
            else {
              iVar3 = EC_POINT_get_affine_coordinates_GF2m();
              if (iVar3 != 0) {
LAB_000ffdae:
                iVar3 = BN_nnmod(r,x,order,ctx);
                if (iVar3 == 0) {
                  ERR_put_error(0x2a,0x66,3,DAT_000ffe14,0x1c5);
                  iVar4 = -1;
                }
                else {
                  uVar2 = BN_ucmp(r,*param_3);
                  iVar4 = 1 - uVar2;
                  if (1 < uVar2) {
                    iVar4 = 0;
                  }
                }
                goto LAB_000ffd72;
              }
              iVar3 = 0x1bf;
            }
          }
          iVar4 = -1;
          ERR_put_error(0x2a,0x66,0x10,DAT_000ffe14,iVar3);
LAB_000ffd72:
          BN_CTX_end(ctx);
          BN_CTX_free(ctx);
          EC_POINT_free(r_00);
          return iVar4;
        }
        iVar3 = 0x1a8;
      }
    }
    else {
      iVar3 = 0x19e;
    }
  }
LAB_000ffcd6:
  iVar4 = -1;
  ERR_put_error(0x2a,0x66,3,DAT_000ffe14,iVar3);
LAB_000ffc1c:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar4;
}

