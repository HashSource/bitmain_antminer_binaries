
undefined4 json_integer_set(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 3)) {
    param_1[2] = param_3;
    param_1[3] = param_4;
    return 0;
  }
  return 0xffffffff;
}

