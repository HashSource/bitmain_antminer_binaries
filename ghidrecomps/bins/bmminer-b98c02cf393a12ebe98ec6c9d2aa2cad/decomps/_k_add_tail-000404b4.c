
void _k_add_tail(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char acStack_818 [2048];
  
  if (*param_2 != *param_1) {
    snprintf(acStack_818,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             *param_1,DAT_0004058c,*param_2,param_3,param_4,param_5,"klist.c",DAT_0004058c,0xec);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  if (*(char *)(param_1 + 0xb) == '\0') {
    snprintf(acStack_818,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",*param_1,
             DAT_0004058c,param_3,param_4,param_5,"klist.c",DAT_0004058c,0xf1);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar1 = param_1[4];
  param_2[2] = 0;
  param_2[1] = iVar1;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 8) = param_2;
  }
  param_1[4] = (int)param_2;
  if (param_1[3] == 0) {
    param_1[3] = (int)param_2;
  }
  param_1[7] = param_1[7] + 1;
  param_1[8] = param_1[8] + 1;
  return;
}

