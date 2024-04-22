
void work_completed(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14 [2];
  
  local_14[0] = param_2;
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    __work_completed(param_1,local_14[0]);
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar1 == 0) {
      (*selective_yield)();
      _free_work(local_14,"cgminer.c",DAT_0001f014,0x251d);
      return;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_0001f014,0x2519);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f014,0x251b);
}

