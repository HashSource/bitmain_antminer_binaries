
void do_all_sorted_fn(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_r4;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  if (iVar1 == iVar2) {
    unaff_r4 = param_2[1] + 1;
    *(int **)(param_2[2] + param_2[1] * 4) = param_1;
  }
  if (iVar1 == iVar2) {
    param_2[1] = unaff_r4;
  }
  return;
}

