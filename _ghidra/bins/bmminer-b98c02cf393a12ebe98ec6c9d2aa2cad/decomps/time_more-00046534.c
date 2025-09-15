
bool time_more(int *param_1,int *param_2)

{
  if (*param_1 != *param_2) {
    return *param_2 < *param_1;
  }
  return param_2[1] < param_1[1];
}

