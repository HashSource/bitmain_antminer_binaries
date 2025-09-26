
void ec_GF2m_simple_group_finish(int param_1)

{
  BN_free(*(BIGNUM **)(param_1 + 0x28));
  BN_free(*(BIGNUM **)(param_1 + 0x44));
  BN_free(*(BIGNUM **)(param_1 + 0x48));
  return;
}

