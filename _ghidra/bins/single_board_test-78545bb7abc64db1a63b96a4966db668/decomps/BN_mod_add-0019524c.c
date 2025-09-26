
int BN_mod_add(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = BN_add(r,a,b);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_nnmod(r,r,m,ctx);
  return iVar1;
}

