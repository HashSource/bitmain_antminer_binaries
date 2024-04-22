
double us_tdiff(int *param_1,int *param_2)

{
  if (*param_1 - *param_2 < 0x3d) {
    return (double)(longlong)((*param_1 - *param_2) * 1000000 + (param_1[1] - param_2[1]));
  }
  return DAT_00046968;
}

