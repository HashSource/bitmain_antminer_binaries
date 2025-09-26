
void bn_set_all_zero(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (param_1[2] <= iVar1) {
    return;
  }
  (*(code *)(undefined *)0x0)(*param_1 + iVar1 * 4,0,(param_1[2] - iVar1) * 4);
  return;
}

