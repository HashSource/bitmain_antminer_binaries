
void add_queued(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    __add_queued(param_1,param_2);
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001ef9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*selective_yield)();
      return;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_0001efb4,0x2481);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001efb4,0x2483);
}

