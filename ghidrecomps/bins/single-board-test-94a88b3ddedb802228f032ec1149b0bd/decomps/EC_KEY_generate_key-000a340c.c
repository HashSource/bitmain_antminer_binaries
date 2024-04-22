
int EC_KEY_generate_key(EC_KEY *key)

{
  BIGNUM *order;
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *rnd;
  EC_POINT *r;
  
  if ((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) {
    ERR_put_error(0x10,0xb3,0x43,DAT_000a34f4,0xf3);
    return 0;
  }
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    rnd = (BIGNUM *)0x0;
  }
  else {
    rnd = *(BIGNUM **)(key + 0xc);
    if (((rnd != (BIGNUM *)0x0) || (rnd = BN_new(), rnd != (BIGNUM *)0x0)) &&
       (iVar1 = EC_GROUP_get_order(*(EC_GROUP **)(key + 4),order,ctx), iVar1 != 0)) {
      do {
        iVar1 = BN_rand_range(rnd,order);
        if (iVar1 == 0) goto LAB_000a3444;
      } while (rnd->top == 0);
      r = *(EC_POINT **)(key + 8);
      if ((r != (EC_POINT *)0x0) ||
         (r = EC_POINT_new(*(EC_GROUP **)(key + 4)), r != (EC_POINT *)0x0)) {
        iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
        if (iVar1 != 0) {
          iVar1 = 1;
          *(BIGNUM **)(key + 0xc) = rnd;
          *(EC_POINT **)(key + 8) = r;
        }
        BN_free(order);
        if (*(int *)(key + 8) == 0) {
          EC_POINT_free(r);
        }
        goto LAB_000a344c;
      }
    }
  }
LAB_000a3444:
  iVar1 = 0;
  BN_free(order);
LAB_000a344c:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(key + 0xc) == 0)) {
    BN_free(rnd);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
    return iVar1;
  }
  return iVar1;
}

