
/* WARNING: Unknown calling convention */

thr_info * get_thread(int thr_id)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  thr_info *thr;
  thr_info *ptVar2;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&mining_thr_lock);
  if (iVar1 != 0) {
    _rd_lock((pthread_rwlock_t *)"get_thread",(char *)0x23e,func,line);
  }
  ptVar2 = mining_thr[thr_id];
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&mining_thr_lock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"get_thread",(char *)0x240,func_00,line_00);
  }
  (*selective_yield)();
  return ptVar2;
}

