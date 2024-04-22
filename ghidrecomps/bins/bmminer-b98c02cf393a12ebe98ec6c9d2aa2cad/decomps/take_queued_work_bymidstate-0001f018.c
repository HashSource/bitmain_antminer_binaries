
int take_queued_work_bymidstate
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    iVar1 = __find_work_bymidstate
                      (*(undefined4 *)(param_1 + 0x160),param_2,param_3,param_4,param_5,param_6);
    if (iVar1 != 0) {
      __work_completed(param_1,iVar1);
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar2 == 0) {
      (*selective_yield)();
      return iVar1;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_0001f084,0x2526);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f084,0x252a);
}

