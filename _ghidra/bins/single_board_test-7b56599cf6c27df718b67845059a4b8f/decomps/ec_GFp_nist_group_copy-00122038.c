
void ec_GFp_nist_group_copy(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
  ec_GFp_simple_group_copy();
  return;
}

