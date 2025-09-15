
undefined8 json_integer_value(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 3)) {
    return *(undefined8 *)(param_1 + 2);
  }
  return 0;
}

