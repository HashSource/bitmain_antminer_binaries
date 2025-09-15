
int ms_tdiff(int *param_1,int *param_2)

{
  if (*param_1 - *param_2 < 0xe11) {
    return (*param_1 - *param_2) * 1000 + (param_1[1] - param_2[1]) / 1000;
  }
  return 3600000;
}

