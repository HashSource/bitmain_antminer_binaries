
void _rwlock_init_constprop_22(pthread_rwlock_t *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char acStack_810 [2052];
  
  iVar2 = pthread_rwlock_init(param_1,(pthread_rwlockattr_t *)0x0);
  uVar1 = DAT_0002d398;
  if (iVar2 == 0) {
    return;
  }
  piVar3 = __errno_location();
  snprintf(acStack_810,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar3,
           "driver-btm-c5.c",uVar1,param_2);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

