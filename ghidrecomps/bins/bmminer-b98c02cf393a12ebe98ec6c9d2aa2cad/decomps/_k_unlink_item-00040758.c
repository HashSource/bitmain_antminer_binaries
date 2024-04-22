
void _k_unlink_item(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  char acStack_818 [2052];
  
  if (*param_2 != *param_1) {
    snprintf(acStack_818,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             *param_1,DAT_000407f0,*param_2,param_3,param_4,param_5,"klist.c",DAT_000407f0,0x138);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar2 = param_2[1];
  if (iVar2 != 0) {
    *(int *)(iVar2 + 8) = param_2[2];
  }
  iVar1 = param_2[2];
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = iVar2;
  }
  if (param_2 == (int *)param_1[3]) {
    param_1[3] = iVar1;
  }
  if (*(char *)(param_1 + 0xb) != '\0') {
    piVar3 = (int *)param_1[4];
    bVar4 = param_2 == piVar3;
    if (bVar4) {
      piVar3 = (int *)param_2[1];
    }
    if (bVar4) {
      param_1[4] = (int)piVar3;
    }
  }
  iVar2 = param_1[7];
  param_2[2] = 0;
  param_2[1] = 0;
  param_1[7] = iVar2 + -1;
  return;
}

