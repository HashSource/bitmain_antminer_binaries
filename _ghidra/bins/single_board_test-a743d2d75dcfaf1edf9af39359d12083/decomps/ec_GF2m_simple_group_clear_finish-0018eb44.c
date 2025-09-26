
void ec_GF2m_simple_group_clear_finish(int param_1)

{
  BN_clear_free((BIGNUM *)(param_1 + 0x48));
  BN_clear_free((BIGNUM *)(param_1 + 0x74));
  BN_clear_free((BIGNUM *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  return;
}

