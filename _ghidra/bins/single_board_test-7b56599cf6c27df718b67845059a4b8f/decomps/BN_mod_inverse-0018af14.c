
BIGNUM * BN_mod_inverse(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BN_CTX *c;
  int local_14;
  
  local_14 = 0;
  c = (BN_CTX *)0x0;
  if ((ctx == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), c = ctx, ctx == (BN_CTX *)0x0)) {
    ERR_put_error(3,0x6e,0x41,"crypto/bn/bn_gcd.c",0x20d);
    return (BIGNUM *)0x0;
  }
  pBVar1 = (BIGNUM *)int_bn_mod_inverse(ret,a,n,ctx,&local_14);
  if (local_14 != 0) {
    ERR_put_error(3,0x6e,0x6c,"crypto/bn/bn_gcd.c",0x214);
  }
  BN_CTX_free(c);
  return pBVar1;
}

