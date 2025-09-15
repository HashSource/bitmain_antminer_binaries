
void subtime(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = *param_2;
  iVar2 = param_1[1] - param_2[1];
  *param_2 = iVar1 - iVar3;
  param_2[1] = iVar2;
  if (iVar2 < 0) {
    *param_2 = (iVar1 - iVar3) + -1;
    param_2[1] = (int)(&DAT_000f4240 + iVar2);
  }
  return;
}

