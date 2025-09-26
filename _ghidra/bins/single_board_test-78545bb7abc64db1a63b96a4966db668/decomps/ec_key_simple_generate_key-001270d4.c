
undefined4 ec_key_simple_generate_key(int param_1)

{
  BN_CTX *ctx;
  int iVar1;
  int iVar2;
  BIGNUM *n;
  BIGNUM *r;
  
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) ||
     ((n = *(BIGNUM **)(param_1 + 0x14), n == (BIGNUM *)0x0 && (n = BN_new(), n == (BIGNUM *)0x0))))
  {
    n = (BIGNUM *)0x0;
    r = n;
  }
  else {
    iVar1 = EC_GROUP_get0_order(*(undefined4 *)(param_1 + 0xc));
    if (iVar1 == 0) {
      r = (BIGNUM *)0x0;
    }
    else {
      do {
        iVar2 = BN_priv_rand_range(n,iVar1);
        if (iVar2 == 0) {
          r = (BIGNUM *)0x0;
          goto LAB_0012710c;
        }
        iVar2 = BN_is_zero(n);
      } while (iVar2 != 0);
      r = *(BIGNUM **)(param_1 + 0x10);
      if (((r != (BIGNUM *)0x0) ||
          (r = (BIGNUM *)EC_POINT_new(*(EC_GROUP **)(param_1 + 0xc)), r != (BIGNUM *)0x0)) &&
         (iVar1 = EC_POINT_mul(*(EC_GROUP **)(param_1 + 0xc),(EC_POINT *)r,n,(EC_POINT *)0x0,
                               (BIGNUM *)0x0,ctx), iVar1 != 0)) {
        *(BIGNUM **)(param_1 + 0x14) = n;
        *(BIGNUM **)(param_1 + 0x10) = r;
        BN_CTX_free(ctx);
        return 1;
      }
    }
  }
LAB_0012710c:
  if (*(int *)(param_1 + 0x10) == 0) {
    EC_POINT_free((EC_POINT *)r);
  }
  if (n != *(BIGNUM **)(param_1 + 0x14)) {
    BN_free(n);
  }
  BN_CTX_free(ctx);
  return 0;
}

