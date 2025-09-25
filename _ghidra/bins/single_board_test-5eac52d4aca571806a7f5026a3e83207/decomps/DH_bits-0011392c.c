
void DH_bits(int param_1)

{
  BN_num_bits(*(BIGNUM **)(param_1 + 8));
  return;
}

