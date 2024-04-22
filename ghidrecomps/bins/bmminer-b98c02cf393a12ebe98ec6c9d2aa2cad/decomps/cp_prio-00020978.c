
undefined4 cp_prio(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_000209f0,0x1ca3);
  }
  iVar1 = pthread_rwlock_rdlock(DAT_000209ec);
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(currentpool + 4);
      iVar1 = pthread_rwlock_unlock(DAT_000209ec);
      if (iVar1 == 0) {
        (*selective_yield)();
        return uVar2;
      }
                    /* WARNING: Subroutine does not return */
      _rw_unlock_part_40_constprop_79(DAT_000209f0,0x1ca5);
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_000209f0,0x1ca3);
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_000209f0,0x1ca3);
}

