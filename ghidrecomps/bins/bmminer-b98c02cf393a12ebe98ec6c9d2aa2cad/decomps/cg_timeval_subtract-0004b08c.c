
undefined4 cg_timeval_subtract(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  iVar2 = *param_3;
  if (iVar3 == iVar2 || iVar3 < iVar2) {
    if ((iVar3 != iVar2) || (param_2[1] <= param_3[1])) {
      iVar1 = param_3[1] - param_2[1];
      *param_1 = iVar2 - iVar3;
      param_1[1] = iVar1;
      if (iVar1 < 0) {
        *param_1 = (iVar2 - iVar3) + -1;
        param_1[1] = (int)(&DAT_000f4240 + iVar1);
        return 0;
      }
      return 0;
    }
  }
  return 0xffffffff;
}

