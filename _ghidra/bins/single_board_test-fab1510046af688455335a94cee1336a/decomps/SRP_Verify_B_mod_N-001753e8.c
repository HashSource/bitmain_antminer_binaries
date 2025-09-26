
int SRP_Verify_B_mod_N(BIGNUM *param_1,BIGNUM *param_2)

{
  BN_CTX *ctx;
  BIGNUM *r;
  int iVar1;
  
  if ((param_1 != (BIGNUM *)0x0 && param_2 != (BIGNUM *)0x0) &&
     (ctx = BN_CTX_new(), ctx != (BN_CTX *)0x0)) {
    r = BN_new();
    if ((r == (BIGNUM *)0x0) || (iVar1 = BN_nnmod(r,param_1,param_2,ctx), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = r->top;
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    BN_CTX_free(ctx);
    BN_free(r);
    return iVar1;
  }
  return 0;
}

