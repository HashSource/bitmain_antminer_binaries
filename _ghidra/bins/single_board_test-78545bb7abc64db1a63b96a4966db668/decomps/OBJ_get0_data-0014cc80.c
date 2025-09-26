
int OBJ_get0_data(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x10);
  }
  return param_1;
}

