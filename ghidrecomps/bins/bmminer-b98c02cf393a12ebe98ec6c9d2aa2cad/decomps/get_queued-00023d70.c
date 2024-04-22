
undefined4 get_queued(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    uVar2 = __get_queued(param_1);
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar1 == 0) {
      (*selective_yield)();
      return uVar2;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_00023db4,0x2478);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_00023db4,0x247a);
}

