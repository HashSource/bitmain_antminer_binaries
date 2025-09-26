
int BN_rand_range(BIGNUM *rnd,BIGNUM *range)

{
  int iVar1;
  
  iVar1 = bn_rand_range(0,rnd,range);
  return iVar1;
}

