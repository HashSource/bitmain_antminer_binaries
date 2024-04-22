
undefined4 setstropt(int *param_1,int param_2)

{
  int iVar1;
  
  (**DAT_000432f4)(*param_1);
  *param_1 = 0;
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (**DAT_000432f8)(param_2);
  if (iVar1 != 0) {
    *param_1 = iVar1;
    return 0;
  }
  return 0x1b;
}

