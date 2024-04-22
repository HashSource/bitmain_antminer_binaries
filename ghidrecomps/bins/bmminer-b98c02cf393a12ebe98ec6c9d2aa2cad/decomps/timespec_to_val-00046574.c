
void timespec_to_val(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = iVar1 / 1000;
  return;
}

