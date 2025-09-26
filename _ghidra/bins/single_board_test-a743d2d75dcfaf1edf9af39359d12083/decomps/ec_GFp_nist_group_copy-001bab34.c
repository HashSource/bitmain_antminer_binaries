
void ec_GFp_nist_group_copy(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);
  ec_GFp_simple_group_copy();
  return;
}

