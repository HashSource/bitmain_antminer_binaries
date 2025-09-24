
void do_all_sorted_fn(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == *param_2) {
    iVar1 = param_2[1];
    param_2[1] = iVar1 + 1;
    *(int **)(param_2[2] + iVar1 * 4) = param_1;
  }
  return;
}

