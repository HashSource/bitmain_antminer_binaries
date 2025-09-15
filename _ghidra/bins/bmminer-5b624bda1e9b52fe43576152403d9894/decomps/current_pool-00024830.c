
/* WARNING: Unknown calling convention */

pool * current_pool(void)

{
  pool *ppVar1;
  int iVar2;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"current_pool",(char *)0x323,func,line);
  }
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _rd_lock((pthread_rwlock_t *)"current_pool",(char *)0x323,func_00,line_00);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"current_pool",(char *)0x323,func_01,line_01);
  }
  ppVar1 = currentpool;
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"current_pool",(char *)0x327,func_02,line_02);
  }
  (*selective_yield)();
  return ppVar1;
}

