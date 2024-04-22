
undefined4 ec_GF2m_simple_point_init(int param_1)

{
  BN_init((BIGNUM *)(param_1 + 4));
  BN_init((BIGNUM *)(param_1 + 0x18));
  BN_init((BIGNUM *)(param_1 + 0x2c));
  return 1;
}

