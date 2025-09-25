
int BN_get_params(int which)

{
  if (which == 0) {
    return bn_limit_bits;
  }
  if (which == 1) {
    return bn_limit_bits_high;
  }
  if (which == 2) {
    return bn_limit_bits_low;
  }
  if (which != 3) {
    return 0;
  }
  return bn_limit_bits_mont;
}

