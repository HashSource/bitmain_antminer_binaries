
/* WARNING: Unknown calling convention */

void add_queued(cgpu_info *cgpu,work *work)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock((pthread_rwlock_t *)"add_queued",(char *)0x2460,func,line);
  }
  __add_queued(cgpu,work);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"add_queued",(char *)0x2462,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

