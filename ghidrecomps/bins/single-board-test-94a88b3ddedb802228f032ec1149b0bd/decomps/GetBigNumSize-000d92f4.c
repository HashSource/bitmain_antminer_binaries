
undefined4 GetBigNumSize(int param_1,int *param_2)

{
  *param_2 = *(int *)(param_1 + 4) << 2;
  return 0;
}

