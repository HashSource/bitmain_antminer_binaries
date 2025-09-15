
undefined4 ec_GFp_simple_point_set_to_infinity(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 0;
  BN_set_word((BIGNUM *)(param_2 + 0x2c),0);
  return 1;
}

