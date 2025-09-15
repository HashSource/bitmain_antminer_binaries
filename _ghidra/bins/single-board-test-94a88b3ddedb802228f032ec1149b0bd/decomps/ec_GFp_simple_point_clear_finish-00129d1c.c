
void ec_GFp_simple_point_clear_finish(int param_1)

{
  BN_clear_free((BIGNUM *)(param_1 + 4));
  BN_clear_free((BIGNUM *)(param_1 + 0x18));
  BN_clear_free((BIGNUM *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

