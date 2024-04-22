
undefined4 ec_GFp_simple_group_init(int param_1)

{
  BN_init((BIGNUM *)(param_1 + 0x48));
  BN_init((BIGNUM *)(param_1 + 0x74));
  BN_init((BIGNUM *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x9c) = 0;
  return 1;
}

