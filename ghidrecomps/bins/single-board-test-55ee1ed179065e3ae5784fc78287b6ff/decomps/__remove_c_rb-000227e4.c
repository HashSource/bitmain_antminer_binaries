
int * __remove_c_rb(int *param_1,int *param_2)

{
  int iVar1;
  int *local_10;
  int local_c;
  
  local_10 = param_2;
  if (((int *)*param_2 != param_1 + 1) && ((int *)param_2[1] != param_1 + 1)) {
    for (local_10 = (int *)param_2[1]; (int *)*local_10 != param_1 + 1; local_10 = (int *)*local_10)
    {
    }
  }
  if ((int *)*local_10 == param_1 + 1) {
    local_c = local_10[1];
  }
  else {
    local_c = *local_10;
  }
  *(int *)(local_c + 8) = local_10[2];
  if (local_10[2] == 0) {
    *param_1 = local_c;
  }
  else if (*(int **)local_10[2] == local_10) {
    *(int *)local_10[2] = local_c;
  }
  else {
    *(int *)(local_10[2] + 4) = local_c;
  }
  if (local_10 != param_2) {
    iVar1 = param_2[4];
    param_2[4] = local_10[4];
    local_10[4] = iVar1;
    iVar1 = param_2[5];
    param_2[5] = local_10[5];
    local_10[5] = iVar1;
  }
  if (local_10[3] == 0) {
    __rb_remove_fixup(param_1,local_c);
  }
  debug_verify_properties(param_1);
  return local_10;
}

