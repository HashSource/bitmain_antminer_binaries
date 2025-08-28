
void switchpool(undefined4 param_1,undefined4 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  if (total_pools == 0) {
    message(param_1,8,0);
    return;
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    lVar1 = strtol(param_3,(char **)0x0,10);
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
    if (iVar2 != 0) {
      _mutex_lock_part_3_constprop_27("switchpool",0xba5);
    }
    _rd_lock_constprop_25(0x80cc6c,"switchpool",0xba5);
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
    if (iVar2 != 0) {
      _mutex_unlock_noyield_part_5_constprop_32("switchpool",0xba5);
    }
    if ((-1 < lVar1) && (lVar1 < total_pools)) {
      iVar3 = *(int *)(pools + lVar1 * 4);
      *(undefined4 *)(iVar3 + 100) = 1;
      iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(control_lock + 0x18));
      if (iVar2 != 0) {
        _rw_unlock_part_4_constprop_30("switchpool",0xbaf);
      }
      (*selective_yield)();
      switch_pools(iVar3);
      message(param_1,0x1b,lVar1,0);
      return;
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(control_lock + 0x18));
    if (iVar2 != 0) {
      _rw_unlock_part_4_constprop_30("switchpool",0xba8);
    }
    (*selective_yield)();
    message(param_1,0x1a,lVar1,0);
    return;
  }
  message(param_1,0x19,0);
  return;
}

