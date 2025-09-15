
undefined4 json_real_value(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 4)) {
    return (int)*(undefined8 *)(param_1 + 2);
  }
  return 0;
}

