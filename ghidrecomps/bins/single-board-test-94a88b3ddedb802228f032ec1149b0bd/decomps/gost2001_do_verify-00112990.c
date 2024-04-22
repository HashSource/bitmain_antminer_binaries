
BN_CTX * gost2001_do_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,EC_KEY *param_4)

{
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *order;
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *x;
  BIGNUM *rem;
  BIGNUM *ret;
  EC_POINT *q;
  int iVar2;
  EC_POINT *r_02;
  BIGNUM *m;
  BN_CTX *pBVar3;
  
  ctx = BN_CTX_new();
  group = EC_KEY_get0_group(param_4);
  if (ctx == (BN_CTX *)0x0 || group == (EC_GROUP *)0x0) {
    m = (BIGNUM *)0x0;
    ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x112);
LAB_001129c2:
    pBVar3 = ctx;
    if (ctx == (BN_CTX *)0x0) goto LAB_001129d4;
    pBVar3 = (BN_CTX *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    order = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    x = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    if ((((order == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0) ||
         (r == (BIGNUM *)0x0 || r_00 == (BIGNUM *)0x0)) ||
        (r_01 == (BIGNUM *)0x0 || x == (BIGNUM *)0x0)) ||
       (rem == (BIGNUM *)0x0 || ret == (BIGNUM *)0x0)) {
      ERR_GOST_error(0x6a,0x41,DAT_00112c38,0x120);
      m = (BIGNUM *)0x0;
      goto LAB_001129c2;
    }
    q = EC_KEY_get0_public_key(param_4);
    if ((q == (EC_POINT *)0x0) || (iVar2 = EC_GROUP_get_order(group,order,ctx), iVar2 == 0)) {
      ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x126);
      m = (BIGNUM *)0x0;
      goto LAB_001129c2;
    }
    if (((param_3[1]->top == 0) || ((*param_3)->top == 0)) ||
       ((iVar2 = BN_cmp(param_3[1],order), 0 < iVar2 || (iVar2 = BN_cmp(*param_3,order), 0 < iVar2))
       )) {
      ERR_GOST_error(0x6a,0x7f,DAT_00112c38,0x12d);
      m = (BIGNUM *)0x0;
      goto LAB_001129c2;
    }
    m = (BIGNUM *)hashsum2bn(param_1);
    if ((m == (BIGNUM *)0x0) || (iVar2 = BN_div((BIGNUM *)0x0,pBVar1,m,order,ctx), iVar2 == 0)) {
      ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x134);
      goto LAB_001129c2;
    }
    if ((pBVar1->top == 0) && (iVar2 = BN_set_word(pBVar1,1), iVar2 == 0)) {
      ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x13e);
      goto LAB_001129c2;
    }
    pBVar1 = BN_mod_inverse(ret,pBVar1,order,ctx);
    if ((((pBVar1 == (BIGNUM *)0x0) ||
         (iVar2 = BN_mod_mul(r,param_3[1],pBVar1,order,ctx), iVar2 == 0)) ||
        (iVar2 = BN_sub(r_01,order,*param_3), iVar2 == 0)) ||
       (iVar2 = BN_mod_mul(r_00,r_01,pBVar1,order,ctx), iVar2 == 0)) {
      ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x146);
      goto LAB_001129c2;
    }
    r_02 = EC_POINT_new(group);
    if (r_02 == (EC_POINT *)0x0) {
      ERR_GOST_error(0x6a,0x41,DAT_00112c38,0x153);
      goto LAB_001129c2;
    }
    iVar2 = EC_POINT_mul(group,r_02,r,q,r_00,ctx);
    if (iVar2 == 0) {
      ERR_GOST_error(0x6a,0x10,DAT_00112c38,0x157);
      pBVar3 = (BN_CTX *)0x0;
    }
    else {
      iVar2 = EC_POINT_get_affine_coordinates_GFp(group,r_02,x,(BIGNUM *)0x0,ctx);
      if (iVar2 == 0) {
        ERR_GOST_error(0x6a,0x10,DAT_00112c38,0x15b);
        pBVar3 = (BN_CTX *)0x0;
      }
      else {
        iVar2 = BN_div((BIGNUM *)0x0,rem,x,order,ctx);
        if (iVar2 == 0) {
          ERR_GOST_error(0x6a,0x44,DAT_00112c38,0x15f);
          pBVar3 = (BN_CTX *)0x0;
        }
        else {
          iVar2 = BN_cmp(rem,*param_3);
          if (iVar2 == 0) {
            pBVar3 = (BN_CTX *)0x1;
          }
          else {
            ERR_GOST_error(0x6a,0x7e,DAT_00112c38,0x16a);
            pBVar3 = (BN_CTX *)0x0;
          }
        }
      }
    }
    EC_POINT_free(r_02);
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_001129d4:
  if (m != (BIGNUM *)0x0) {
    BN_free(m);
  }
  return pBVar3;
}

