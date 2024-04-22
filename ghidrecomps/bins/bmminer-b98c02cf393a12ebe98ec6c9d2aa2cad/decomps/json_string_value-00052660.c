
int * json_string_value(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 == 2) {
      return (int *)param_1[2];
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}

