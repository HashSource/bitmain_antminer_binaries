
int BN_pseudo_rand_range(BIGNUM *rnd,BIGNUM *range)

{
  int iVar1;
  
  iVar1 = bn_rand_range(1,rnd,range);
  return iVar1;
}

