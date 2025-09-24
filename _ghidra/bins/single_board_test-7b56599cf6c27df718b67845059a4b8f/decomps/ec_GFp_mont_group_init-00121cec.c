
void ec_GFp_mont_group_init(int param_1)

{
  ec_GFp_simple_group_init();
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  return;
}

