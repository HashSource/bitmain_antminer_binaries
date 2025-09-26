
void ec_GF2m_simple_point_clear_finish(int param_1)

{
  BN_clear_free(*(BIGNUM **)(param_1 + 8));
  BN_clear_free(*(BIGNUM **)(param_1 + 0xc));
  BN_clear_free(*(BIGNUM **)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

