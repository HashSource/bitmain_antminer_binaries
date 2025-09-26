
void ec_group_simple_order_bits(int param_1)

{
  if (*(BIGNUM **)(param_1 + 8) != (BIGNUM *)0x0) {
    BN_num_bits(*(BIGNUM **)(param_1 + 8));
    return;
  }
  return;
}

