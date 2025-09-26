
void ec_GFp_simple_group_clear_finish(int param_1)

{
  BN_clear_free((BIGNUM *)(param_1 + 0x48));
  BN_clear_free((BIGNUM *)(param_1 + 0x74));
  BN_clear_free((BIGNUM *)(param_1 + 0x88));
  return;
}

