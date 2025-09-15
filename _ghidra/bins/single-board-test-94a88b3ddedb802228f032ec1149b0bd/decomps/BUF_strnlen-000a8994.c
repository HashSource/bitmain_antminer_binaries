
uint BUF_strnlen(byte *param_1,uint param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = param_2 - 1;
  if ((param_2 != 0) && (param_2 = (uint)*param_1, param_2 != 0)) {
    iVar3 = 0;
    pbVar1 = param_1 + 1;
    do {
      pbVar2 = pbVar1;
      bVar5 = iVar4 == iVar3;
      iVar3 = iVar3 + 1;
      if (bVar5) {
        return (int)pbVar2 - (int)param_1;
      }
      pbVar1 = pbVar2 + 1;
    } while (*pbVar2 != 0);
    param_2 = (int)pbVar2 - (int)param_1;
  }
  return param_2;
}

