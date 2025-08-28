
/* WARNING: Unknown calling convention */

work * get_queued(cgpu_info *cgpu)

{
  int iVar1;
  work *pwVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock((pthread_rwlock_t *)"get_queued",(char *)0x2457,func,line);
  }
  pwVar2 = __get_queued(cgpu);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"get_queued",(char *)0x2459,func_00,line_00);
  }
  (*selective_yield)();
  return pwVar2;
}

