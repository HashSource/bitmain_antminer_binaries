
void cgtimer_sub(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = param_2[1];
  iVar3 = *param_1 - *param_2;
  iVar1 = param_1[1] - iVar2;
  bVar4 = iVar1 < 0;
  *param_3 = iVar3;
  if (bVar4) {
    iVar3 = iVar3 + -1;
    iVar2 = 1000000000;
  }
  if (bVar4) {
    iVar2 = iVar2 + iVar1;
    *param_3 = iVar3;
  }
  else {
    param_3[1] = iVar1;
  }
  if (bVar4) {
    param_3[1] = iVar2;
  }
  return;
}

