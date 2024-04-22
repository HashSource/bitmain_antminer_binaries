
undefined4 MDC2_Final(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  if (iVar1 != 0 || param_2[7] == 2) {
    iVar2 = iVar1;
    if (param_2[7] == 2) {
      iVar2 = iVar1 + 1;
      *(undefined *)((int)param_2 + iVar1 + 4) = 0x80;
    }
    memset((void *)((int)param_2 + iVar2 + 4),0,8 - iVar2);
    mdc2_body(param_2,param_2 + 1,8);
  }
  iVar1 = param_2[4];
  *param_1 = param_2[3];
  param_1[1] = iVar1;
  iVar1 = param_2[6];
  param_1[2] = param_2[5];
  param_1[3] = iVar1;
  return 1;
}

