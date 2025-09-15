
/* WARNING: Unknown calling convention */

int cp_prio(void)

{
  int iVar1;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int iVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"cp_prio",(char *)0x1c88,func,line);
  }
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar1 != 0) {
    _rd_lock((pthread_rwlock_t *)"cp_prio",(char *)0x1c88,func_00,line_00);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"cp_prio",(char *)0x1c88,func_01,line_01);
  }
  iVar2 = currentpool->prio;
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"cp_prio",(char *)0x1c8a,func_02,line_02);
  }
  (*selective_yield)();
  return iVar2;
}

