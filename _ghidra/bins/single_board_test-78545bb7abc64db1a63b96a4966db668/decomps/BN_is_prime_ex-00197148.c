
int BN_is_prime_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,BN_GENCB *cb)

{
  int iVar1;
  
  iVar1 = BN_is_prime_fasttest_ex(p,nchecks,ctx,0,cb);
  return iVar1;
}

