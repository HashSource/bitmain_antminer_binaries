
int BN_pseudo_rand_range(BIGNUM *rnd,BIGNUM *range)

{
  int iVar1;
  
  if ((range->neg == 0) && (iVar1 = BN_is_zero(range), iVar1 == 0)) {
    iVar1 = bnrand_range_part_1(0,rnd,range);
    return iVar1;
  }
  ERR_put_error(3,0x8a,0x73,"crypto/bn/bn_rand.c",0x77);
  return 0;
}

