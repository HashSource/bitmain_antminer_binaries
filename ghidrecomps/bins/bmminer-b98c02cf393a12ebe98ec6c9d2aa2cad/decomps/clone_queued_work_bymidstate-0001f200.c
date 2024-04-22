
undefined4
clone_queued_work_bymidstate
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x140));
  if (iVar1 == 0) {
    iVar1 = __find_work_bymidstate
                      (*(undefined4 *)(param_1 + 0x160),param_2,param_3,param_4,param_5,param_6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = make_work();
      _copy_work(uVar2,iVar1,0);
    }
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar1 == 0) {
      (*selective_yield)();
      return uVar2;
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_0001f278,0x24bb);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f278,0x24bf);
}

