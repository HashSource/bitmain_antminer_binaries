
int json_incref(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != -1)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  return param_1;
}

