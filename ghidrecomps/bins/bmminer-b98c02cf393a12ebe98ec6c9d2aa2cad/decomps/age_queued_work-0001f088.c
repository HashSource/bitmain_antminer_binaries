
int age_queued_work(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  double in_d0;
  double dVar4;
  int local_34;
  undefined auStack_30 [12];
  
  cgtime(auStack_30);
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x140));
  uVar1 = DAT_0001f13c;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x160);
    local_34 = iVar2;
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0x160);
      iVar2 = 0;
      while( true ) {
        dVar4 = (double)tdiff(auStack_30,local_34 + 0x1a8);
        if (dVar4 != in_d0 && dVar4 < in_d0 == (NAN(dVar4) || NAN(in_d0))) {
          __work_completed(param_1,local_34);
          iVar2 = iVar2 + 1;
          _free_work(&local_34,"cgminer.c",uVar1,0x250a);
        }
        local_34 = iVar3;
        if (iVar3 == 0) break;
        iVar3 = *(int *)(iVar3 + 0x160);
      }
    }
    iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar3 == 0) {
      (*selective_yield)();
      return iVar2;
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_0001f13c,0x2504);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0001f13c,0x250f);
}

