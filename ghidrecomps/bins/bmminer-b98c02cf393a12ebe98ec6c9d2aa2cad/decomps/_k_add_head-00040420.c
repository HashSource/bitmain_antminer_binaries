
void _k_add_head(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char acStack_818 [2052];
  
  if (*param_2 != *param_1) {
    snprintf(acStack_818,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             *param_1,DAT_000404b0,*param_2,param_3,param_4,param_5,"klist.c",DAT_000404b0,0xcd);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar1 = param_1[3];
  param_2[1] = 0;
  param_2[2] = iVar1;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  param_1[3] = (int)param_2;
  if ((*(char *)(param_1 + 0xb) != '\0') && (param_1[4] == 0)) {
    param_1[4] = (int)param_2;
  }
  param_1[7] = param_1[7] + 1;
  param_1[8] = param_1[8] + 1;
  return;
}

