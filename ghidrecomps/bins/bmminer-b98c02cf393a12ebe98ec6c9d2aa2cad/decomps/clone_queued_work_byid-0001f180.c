
undefined4 clone_queued_work_byid(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x160);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      iVar4 = *(int *)(iVar2 + 0x154);
      iVar1 = *(int *)(iVar2 + 0x160);
      while (param_2 != iVar4) {
        if (iVar1 == 0) {
          uVar3 = 0;
          goto LAB_0001f1ba;
        }
        iVar4 = *(int *)(iVar1 + 0x154);
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar1 + 0x160);
      }
      uVar3 = make_work();
      _copy_work(uVar3,iVar2,0);
    }
LAB_0001f1ba:
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar2 == 0) {
      (*selective_yield)();
      return uVar3;
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_0001f1fc,0x24ea);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f1fc,0x24ee);
}

