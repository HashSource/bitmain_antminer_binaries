
void _k_unlink_tail(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char acStack_818 [2052];
  
  if (*(char *)(param_1 + 0xb) == '\0') {
    snprintf(acStack_818,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",*param_1,
             DAT_0004041c,param_2,param_3,param_4,"klist.c",DAT_0004041c,0xb5);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar1 = param_1[4];
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    param_1[4] = iVar2;
    if (iVar2 == 0) {
      param_1[3] = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    iVar2 = param_1[7];
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 4) = 0;
    param_1[7] = iVar2 + -1;
  }
  return;
}

