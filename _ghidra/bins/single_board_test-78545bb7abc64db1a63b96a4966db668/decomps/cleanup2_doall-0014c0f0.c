
void cleanup2_doall(int param_1)

{
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(*(int *)(param_1 + 4) + 8) + 1;
  return;
}

