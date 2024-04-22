
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  int iVar1;
  
  if ((bits < 0) || (bits == 1 && 0 < top)) {
    ERR_put_error(3,0x7f,0x76,DAT_000f2498,0x7d);
    iVar1 = 0;
  }
  else if (bits == 0) {
    BN_set_word(rnd,0);
    iVar1 = 1;
  }
  else {
    iVar1 = bnrand_part_0(1,rnd,bits,top,bottom);
  }
  return iVar1;
}

