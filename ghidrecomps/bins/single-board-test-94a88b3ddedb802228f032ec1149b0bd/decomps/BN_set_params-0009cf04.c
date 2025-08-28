
void BN_set_params(int mul,int high,int low,int mont)

{
  if (-1 < mul) {
    if (0x1e < mul) {
      mul = 0x1f;
    }
    bn_limit_num = 1 << (mul & 0xffU);
    bn_limit_bits = mul;
  }
  if (-1 < high) {
    if (0x1e < high) {
      high = 0x1f;
    }
    bn_limit_num_high = 1 << (high & 0xffU);
    bn_limit_bits_high = high;
  }
  if (-1 < low) {
    if (0x1e < low) {
      low = 0x1f;
    }
    bn_limit_num_low = 1 << (low & 0xffU);
    bn_limit_bits_low = low;
  }
  if (-1 < mont) {
    if (0x1e < mont) {
      mont = 0x1f;
    }
    bn_limit_num_mont = 1 << (mont & 0xffU);
    bn_limit_bits_mont = mont;
  }
  return;
}

