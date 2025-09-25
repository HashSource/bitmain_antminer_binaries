
int BN_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = bn_mul_fixed_top();
  bn_correct_top(r);
  return iVar1;
}

