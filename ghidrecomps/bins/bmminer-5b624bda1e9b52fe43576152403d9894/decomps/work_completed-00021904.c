
/* WARNING: Unknown calling convention */

void work_completed(cgpu_info *cgpu,work *work)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  work *local_14 [2];
  
  local_14[0] = work;
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock((pthread_rwlock_t *)"work_completed",(char *)0x24f8,func,line);
  }
  __work_completed(cgpu,local_14[0]);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"work_completed",(char *)0x24fa,func_00,line_00);
  }
  (*selective_yield)();
  _free_work(local_14,"cgminer.c","work_completed",0x24fc);
  return;
}

