
void BN_set_params(int mul,int high,int low,int mont)

{
  if ((-1 < mul) && (bn_limit_bits = mul, 0x1e < mul)) {
    bn_limit_bits = 0x1f;
  }
  if ((-1 < high) && (bn_limit_bits_high = high, 0x1e < high)) {
    bn_limit_bits_high = 0x1f;
  }
  if ((-1 < low) && (bn_limit_bits_low = low, 0x1e < low)) {
    bn_limit_bits_low = 0x1f;
  }
  if ((-1 < mont) && (bn_limit_bits_mont = mont, 0x1e < mont)) {
    bn_limit_bits_mont = 0x1f;
  }
  return;
}

