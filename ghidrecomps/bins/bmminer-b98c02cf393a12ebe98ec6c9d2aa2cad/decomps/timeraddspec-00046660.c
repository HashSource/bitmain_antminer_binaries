
void timeraddspec(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  
  iVar2 = *param_2;
  iVar3 = param_2[1] + param_1[1];
  param_1[1] = iVar3;
  iVar2 = iVar2 + *param_1;
  *param_1 = iVar2;
  if (iVar3 < 1000000000) {
    if (iVar3 < 0) {
      do {
        iVar2 = iVar2 + -1;
        iVar3 = iVar3 + 1000000000;
      } while (iVar3 < 0);
      *param_1 = iVar2;
      param_1[1] = iVar3;
      return;
    }
  }
  else {
    iVar4 = iVar2 + 1;
    iVar1 = iVar3 + -1000000000;
    bVar6 = SBORROW4(iVar1,999999999);
    bVar5 = iVar1 != 999999999;
    if (999999999 < iVar1) {
      iVar4 = iVar2 + 2;
      iVar1 = -2000000000;
    }
    *param_1 = iVar4;
    if (bVar5 && iVar3 + -1999999999 < 0 == bVar6) {
      iVar1 = iVar1 + iVar3;
    }
    param_1[1] = iVar1;
  }
  return;
}

