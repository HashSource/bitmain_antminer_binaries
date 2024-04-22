
undefined4 current_pool(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_000208d0,0x330);
  }
  iVar2 = pthread_rwlock_rdlock(DAT_000208cc);
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
    uVar1 = currentpool;
    if (iVar2 == 0) {
      iVar2 = pthread_rwlock_unlock(DAT_000208cc);
      if (iVar2 == 0) {
        (*selective_yield)();
        return uVar1;
      }
                    /* WARNING: Subroutine does not return */
      _rw_unlock_part_40_constprop_79(DAT_000208d0,0x334);
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_000208d0,0x330);
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_000208d0,0x330);
}

