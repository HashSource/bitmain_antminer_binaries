
void _k_insert_before(int *param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                     undefined4 param_6)

{
  int iVar1;
  int iVar2;
  char acStack_818 [2048];
  
  if (*param_2 != *param_1) {
    snprintf(acStack_818,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             *param_1,DAT_0004066c,*param_2,param_4,param_5,param_6,"klist.c",DAT_0004066c,0x106);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  if (param_3 == 0) {
    snprintf(acStack_818,0x800,
             "%s() (%s) can\'t before a null item - from %s %s() line %d in %s %s():%d",DAT_0004066c
             ,*param_1,param_4,param_5,param_6,"klist.c",DAT_0004066c,0x10b);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar1 = *(int *)(param_3 + 4);
  param_2[2] = param_3;
  param_2[1] = iVar1;
  if (*(int *)(param_3 + 4) == 0) {
    param_1[3] = (int)param_2;
  }
  else {
    *(int **)(*(int *)(param_3 + 4) + 8) = param_2;
  }
  iVar1 = param_1[7];
  iVar2 = param_1[8];
  *(int **)(param_3 + 4) = param_2;
  param_1[7] = iVar1 + 1;
  param_1[8] = iVar2 + 1;
  return;
}

