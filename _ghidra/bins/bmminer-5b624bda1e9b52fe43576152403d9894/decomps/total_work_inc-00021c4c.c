
/* WARNING: Unknown calling convention */

int total_work_inc(void)

{
  uint uVar1;
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
    _mutex_lock((pthread_mutex_t *)"total_work_inc",(char *)0x886,func,line);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _wr_lock((pthread_rwlock_t *)"total_work_inc",(char *)0x886,func_00,line_00);
  }
  uVar1 = total_work;
  total_work = total_work + 1;
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"total_work_inc",(char *)0x888,func_01,line_01);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"total_work_inc",(char *)0x888,func_02,line_02);
  }
  (*selective_yield)();
  return uVar1;
}

