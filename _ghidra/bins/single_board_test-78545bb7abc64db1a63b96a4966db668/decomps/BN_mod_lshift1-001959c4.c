
int BN_mod_lshift1(BIGNUM *r,BIGNUM *a,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = BN_lshift1(r,a);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_nnmod(r,r,m,ctx);
  return iVar1;
}

