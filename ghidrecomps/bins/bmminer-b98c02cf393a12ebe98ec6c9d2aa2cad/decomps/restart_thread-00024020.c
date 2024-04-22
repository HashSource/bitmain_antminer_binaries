
undefined4 restart_thread(void)

{
  pthread_t __th;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  __th = pthread_self();
  pthread_detach(__th);
  discard_stale();
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)mining_thr_lock);
  iVar2 = mining_threads;
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)mining_thr_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      if (0 < iVar2) {
        iVar1 = 0;
        do {
          while( true ) {
            iVar3 = *(int *)(mining_thr + iVar1 * 4);
            iVar4 = *(int *)(iVar3 + 0x24);
            if ((iVar4 == 0) || (*(int *)(iVar4 + 0x20) != 0)) break;
            *(undefined *)(iVar3 + 0x3e) = 1;
            flush_queue(iVar4);
            iVar1 = iVar1 + 1;
            (**(code **)(*(int *)(iVar4 + 4) + 0x4c))(iVar4);
            if (iVar2 == iVar1) goto LAB_000240b0;
          }
          iVar1 = iVar1 + 1;
        } while (iVar2 != iVar1);
      }
LAB_000240b0:
      iVar2 = pthread_mutex_lock((pthread_mutex_t *)restart_lock);
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        _mutex_lock_part_47_constprop_75(DAT_0002410c,0x150e);
      }
      pthread_cond_broadcast((pthread_cond_t *)restart_cond);
      iVar2 = pthread_mutex_unlock((pthread_mutex_t *)restart_lock);
      if (iVar2 == 0) {
        (*selective_yield)();
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      _mutex_unlock_noyield_part_48_constprop_77(DAT_0002410c,0x1510);
    }
  }
  else {
    _rd_lock_part_39_constprop_80(DAT_0002410c,0x14f7);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(DAT_0002410c,0x14f9);
}

