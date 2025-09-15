
void _rwlock_init_constprop_22(pthread_rwlock_t *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  char acStack_810 [2052];
  
  iVar1 = pthread_rwlock_init(param_1,(pthread_rwlockattr_t *)0x0);
  if (iVar1 == 0) {
    return;
  }
  piVar2 = __errno_location();
  snprintf(acStack_810,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar2,
           "driver-btm-c5.c","bitmain_c5_prepare",param_2);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

