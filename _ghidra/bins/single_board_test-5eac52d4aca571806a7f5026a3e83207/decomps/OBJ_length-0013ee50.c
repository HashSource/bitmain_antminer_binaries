
int OBJ_length(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0xc);
  }
  return param_1;
}

