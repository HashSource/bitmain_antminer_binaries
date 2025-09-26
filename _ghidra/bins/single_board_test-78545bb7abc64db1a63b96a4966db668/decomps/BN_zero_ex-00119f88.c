
void BN_zero_ex(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

