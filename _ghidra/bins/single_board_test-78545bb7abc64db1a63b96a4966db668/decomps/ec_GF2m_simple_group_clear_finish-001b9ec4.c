
void ec_GF2m_simple_group_clear_finish(int param_1)

{
  BN_clear_free(*(BIGNUM **)(param_1 + 0x28));
  BN_clear_free(*(BIGNUM **)(param_1 + 0x44));
  BN_clear_free(*(BIGNUM **)(param_1 + 0x48));
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}

