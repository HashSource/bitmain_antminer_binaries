
void _rd_lock_constprop_25(pthread_rwlock_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  char acStack_810 [2052];
  
  iVar1 = pthread_rwlock_rdlock(param_1);
  if (iVar1 == 0) {
    return;
  }
  piVar2 = __errno_location();
  snprintf(acStack_810,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
           param_2,param_3);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

