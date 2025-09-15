
int total_work_inc(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75("total_work_inc",0x89d);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(control_lock + 0x18));
  iVar1 = total_work;
  if (iVar2 == 0) {
    total_work = total_work + 1;
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(control_lock + 0x18));
    if (iVar2 == 0) {
      iVar2 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
      if (iVar2 == 0) {
        (*selective_yield)();
        return iVar1;
      }
                    /* WARNING: Subroutine does not return */
      _mutex_unlock_noyield_part_48_constprop_77("total_work_inc",0x89f);
    }
  }
  else {
    _wr_lock_part_54_constprop_73("total_work_inc",0x89d);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79("total_work_inc",0x89f);
}

