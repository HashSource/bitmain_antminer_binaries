
bool time_less(int *param_1,int *param_2)

{
  if (*param_1 == *param_2) {
    return param_1[1] < param_2[1];
  }
  return *param_1 < *param_2;
}

