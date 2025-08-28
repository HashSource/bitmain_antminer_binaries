
undefined4 us_tdiff(int *param_1,int *param_2)

{
  if (*param_1 - *param_2 < 0x3d) {
    return SUB84((double)(longlong)((*param_1 - *param_2) * 1000000 + (param_1[1] - param_2[1])),0);
  }
  return 0;
}

