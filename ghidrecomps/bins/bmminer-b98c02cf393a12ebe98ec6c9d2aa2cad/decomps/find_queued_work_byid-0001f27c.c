
int find_queued_work_byid(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x160);
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 0x154);
      for (iVar2 = *(int *)(iVar1 + 0x160); (param_2 != iVar3 && (iVar1 = iVar2, iVar2 != 0));
          iVar2 = *(int *)(iVar2 + 0x160)) {
        iVar3 = *(int *)(iVar2 + 0x154);
      }
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar2 == 0) {
      (*selective_yield)();
      return iVar1;
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_0001f2e4,0x24de);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f2e4,0x24e0);
}

