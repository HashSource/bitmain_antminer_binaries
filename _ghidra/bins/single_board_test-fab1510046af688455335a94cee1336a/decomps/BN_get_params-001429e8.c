
int BN_get_params(int which)

{
  int iVar1;
  
  if (which == 0) {
    return bn_limit_bits;
  }
  if (which != 1) {
    if (which != 2) {
      iVar1 = bn_limit_bits_mont;
      if (which != 3) {
        iVar1 = 0;
      }
      return iVar1;
    }
    return bn_limit_bits_low;
  }
  return bn_limit_bits_high;
}

