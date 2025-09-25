
undefined4 MDC2_Final(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = param_2[7];
  iVar2 = *param_2;
  uVar3 = (uint)(iVar1 == 2);
  if (iVar2 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    bVar4 = iVar1 == 2;
    if (bVar4) {
      uVar3 = (int)param_2 + iVar2;
      iVar2 = iVar2 + 1;
      iVar1 = 0x80;
    }
    if (bVar4) {
      *(char *)(uVar3 + 4) = (char)iVar1;
    }
    memset((void *)((int)param_2 + iVar2 + 4),0,8 - iVar2);
    mdc2_body(param_2,param_2 + 1,8);
  }
  iVar2 = param_2[4];
  *param_1 = param_2[3];
  param_1[1] = iVar2;
  iVar2 = param_2[6];
  param_1[2] = param_2[5];
  param_1[3] = iVar2;
  return 1;
}

