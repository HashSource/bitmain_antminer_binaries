
undefined4 ec_GF2m_simple_group_init(int param_1)

{
  BN_init((BIGNUM *)(param_1 + 0x48));
  BN_init((BIGNUM *)(param_1 + 0x74));
  BN_init((BIGNUM *)(param_1 + 0x88));
  return 1;
}

