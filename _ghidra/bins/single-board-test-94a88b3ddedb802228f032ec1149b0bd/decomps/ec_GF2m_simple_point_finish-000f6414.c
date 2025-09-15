
void ec_GF2m_simple_point_finish(int param_1)

{
  BN_free((BIGNUM *)(param_1 + 4));
  BN_free((BIGNUM *)(param_1 + 0x18));
  BN_free((BIGNUM *)(param_1 + 0x2c));
  return;
}

