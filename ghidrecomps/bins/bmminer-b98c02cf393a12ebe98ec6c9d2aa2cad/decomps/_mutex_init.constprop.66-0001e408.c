
void _mutex_init_constprop_66
               (pthread_mutex_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char acStack_818 [2052];
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  iVar1 = pthread_mutex_init(param_1,(pthread_mutexattr_t *)0x0);
  if (iVar1 == 0) {
    return;
  }
  uVar3 = 0x1e421;
  uVar4 = _mutex_init_part_42_constprop_67(param_2,param_3);
  uStack_14 = uVar3;
  piVar2 = __errno_location();
  snprintf(acStack_818,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar2,
           "cgminer.c",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  _applog(3,acStack_818,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

