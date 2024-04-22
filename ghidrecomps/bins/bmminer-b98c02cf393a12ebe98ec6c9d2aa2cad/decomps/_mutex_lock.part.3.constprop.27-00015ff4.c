
void _mutex_lock_part_3_constprop_27(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  char acStack_810 [2052];
  
  piVar1 = __errno_location();
  snprintf(acStack_810,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar1,"api.c",
           param_1,param_2);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

