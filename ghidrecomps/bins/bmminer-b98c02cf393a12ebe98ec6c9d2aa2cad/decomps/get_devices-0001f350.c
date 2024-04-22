
undefined4 get_devices(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(devices + param_1 * 4);
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      return uVar2;
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_0001f3a4,0x25f);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f3a4,0x261);
}

