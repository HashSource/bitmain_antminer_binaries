
int next_name(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  bVar1 = *(byte *)(param_1 + *param_2);
  param_1 = param_1 + *param_2;
  if ((bVar1 & 0xdf) == 0 || bVar1 == 0x3d) {
    return 0;
  }
  pbVar4 = (byte *)(param_1 + 1);
  iVar2 = 0;
  do {
    iVar3 = iVar2;
    pbVar4 = pbVar4 + 1;
    bVar1 = *pbVar4;
    if ((bVar1 & 0xdf) == 0) break;
    iVar2 = iVar3 + 1;
  } while (bVar1 != 0x3d && bVar1 != 0x7c);
  *param_2 = iVar3;
  return param_1 + 2;
}

