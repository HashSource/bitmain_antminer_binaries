
int * json_array_get(int *param_1,uint param_2)

{
  if (param_1 != (int *)0x0) {
    if ((*param_1 == 1) && (param_2 < (uint)param_1[3])) {
      return *(int **)(param_1[4] + param_2 * 4);
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}

