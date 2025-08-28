
int age_queued_work(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double in_d0;
  undefined4 extraout_s1;
  int local_34;
  undefined1 auStack_30 [12];
  
  cgtime(auStack_30);
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x160);
    local_34 = iVar1;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x160);
      iVar1 = 0;
      while( true ) {
        uVar3 = tdiff(auStack_30,local_34 + 0x1a8);
        if (in_d0 < (double)CONCAT44(extraout_s1,uVar3)) {
          __work_completed(param_1,local_34);
          iVar1 = iVar1 + 1;
          _free_work(&local_34,"cgminer.c","age_queued_work",0x250a);
        }
        local_34 = iVar2;
        if (iVar2 == 0) break;
        iVar2 = *(int *)(iVar2 + 0x160);
      }
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar2 == 0) {
      (*selective_yield)();
      return iVar1;
    }
  }
  else {
    _wr_lock_part_54_constprop_73("age_queued_work",0x2504);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79("age_queued_work",0x250f);
}

