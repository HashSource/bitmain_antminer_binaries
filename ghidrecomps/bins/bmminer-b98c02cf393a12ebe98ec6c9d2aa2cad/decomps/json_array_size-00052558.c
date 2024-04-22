
int * json_array_size(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 == 1) {
      return (int *)param_1[3];
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}

