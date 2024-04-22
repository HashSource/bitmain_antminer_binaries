
void opt_set_uintval(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_14 [2];
  
  iVar1 = opt_set_longval(param_1,local_14);
  if (iVar1 == 0) {
    if (local_14[0] < 0) {
      arg_bad("\'%s\' is negative",param_1);
      return;
    }
    *param_2 = local_14[0];
  }
  return;
}

