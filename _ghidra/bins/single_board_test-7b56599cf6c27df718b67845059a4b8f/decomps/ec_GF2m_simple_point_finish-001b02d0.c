
void ec_GF2m_simple_point_finish(int param_1)

{
  BN_free(*(BIGNUM **)(param_1 + 8));
  BN_free(*(BIGNUM **)(param_1 + 0xc));
  BN_free(*(BIGNUM **)(param_1 + 0x10));
  return;
}

