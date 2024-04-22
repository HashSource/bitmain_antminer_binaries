
void enable_device(int *param_1)

{
  int iVar1;
  int iVar2;
  
  param_1[8] = 0;
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)devices_lock);
  iVar2 = devices;
  if (iVar1 == 0) {
    *param_1 = cgminer_id_count;
    *(int **)(iVar2 + cgminer_id_count * 4) = param_1;
    cgminer_id_count = cgminer_id_count + 1;
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
    if (iVar2 == 0) {
      (*selective_yield)();
      if (hotplug_mode == '\0') {
        mining_threads = mining_threads + param_1[0x25];
      }
      else {
        new_threads = new_threads + param_1[0x25];
      }
      iVar2 = pthread_rwlock_init((pthread_rwlock_t *)(param_1 + 0x50),(pthread_rwlockattr_t *)0x0);
      if (iVar2 == 0) {
        param_1[0x58] = 0;
        return;
      }
                    /* WARNING: Subroutine does not return */
      _rwlock_init_part_43_constprop_69(DAT_000298d8,0x2b82);
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_000298d8,0x2b75);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_000298d8,0x2b77);
}

