
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  int iVar1;
  
  if (bits == 0) {
    if (bottom == 0 && top == -1) {
      BN_set_word(rnd,0);
      return 1;
    }
  }
  else if ((-1 < bits) && (top < 1 || bits != 1)) {
    iVar1 = bnrand_part_0(1,rnd,bits,top,bottom);
    return iVar1;
  }
  ERR_put_error(3,0x7f,0x76,"crypto/bn/bn_rand.c",0x5d);
  return 0;
}

