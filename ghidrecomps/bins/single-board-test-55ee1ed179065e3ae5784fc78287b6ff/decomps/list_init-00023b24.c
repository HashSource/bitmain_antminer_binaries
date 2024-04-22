
void list_init(int param_1)

{
  *(int *)(param_1 + 4) = param_1;
  *(int *)param_1 = param_1;
  return;
}

