
int BN_from_montgomery(BIGNUM *r,BIGNUM *a,BN_MONT_CTX *mont,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = bn_from_mont_fixed_top();
  bn_correct_top(r);
  return iVar1;
}

