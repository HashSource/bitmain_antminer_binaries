
int restart_wait(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  timespec local_20;
  
  cgtime(&local_28);
  local_20.tv_sec = local_28 + param_2 / 1000;
  local_24 = local_24 + param_2 * 1000 + (param_2 / 1000) * -1000000;
  if (999999 < local_24) {
    local_20.tv_sec = local_20.tv_sec + 1;
    local_24 = local_24 + -1000000;
  }
  local_20.tv_nsec = local_24 * 1000;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)restart_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_0001ed14,0x14e0);
  }
  iVar1 = 0;
  if (*(char *)(param_1 + 0x3e) == '\0') {
    iVar1 = pthread_cond_timedwait
                      ((pthread_cond_t *)restart_cond,(pthread_mutex_t *)restart_lock,&local_20);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)restart_lock);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_unlock_noyield_part_48_constprop_77(DAT_0001ed14,0x14ea);
  }
  (*selective_yield)();
  return iVar1;
}

