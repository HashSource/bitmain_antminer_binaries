
void _cglock_init_constprop_65(pthread_mutex_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(param_1,(pthread_mutexattr_t *)0x0);
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_init((pthread_rwlock_t *)(param_1 + 1),(pthread_rwlockattr_t *)0x0);
    if (iVar1 == 0) {
      return;
    }
  }
  else {
    _mutex_init_part_42_constprop_67(param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  _rwlock_init_part_43_constprop_69(param_2,param_3);
}

