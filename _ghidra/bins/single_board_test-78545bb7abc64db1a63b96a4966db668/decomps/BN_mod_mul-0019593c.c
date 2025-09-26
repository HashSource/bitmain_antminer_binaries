
int BN_mod_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  BIGNUM *r_00;
  int iVar1;
  
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  if (r_00 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar1 = BN_sqr(r_00,a,ctx);
    }
    else {
      iVar1 = BN_mul(r_00,a,b,ctx);
    }
    if (iVar1 != 0) {
      iVar1 = BN_nnmod(r,r_00,m,ctx);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      BN_CTX_end(ctx);
      return iVar1;
    }
  }
  BN_CTX_end(ctx);
  return 0;
}

