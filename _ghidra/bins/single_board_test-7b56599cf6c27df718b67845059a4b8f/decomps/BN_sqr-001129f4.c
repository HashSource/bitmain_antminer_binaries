
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = bn_sqr_fixed_top();
  bn_correct_top(r);
  return iVar1;
}

