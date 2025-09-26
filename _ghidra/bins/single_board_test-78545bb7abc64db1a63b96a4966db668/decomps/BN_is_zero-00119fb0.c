
bool BN_is_zero(int param_1)

{
  return *(int *)(param_1 + 4) == 0;
}

