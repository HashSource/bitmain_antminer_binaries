
/* WARNING: Unknown calling convention */

void add_queued(cgpu_info *cgpu,work *work)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock(DAT_000219ac,(char *)0x2460,in_r2,in_r3);
  }
  __add_queued(cgpu,work);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock(DAT_000219ac,(char *)0x2462,in_r2,in_r3);
  }
  (**DAT_000219a8)();
  return;
}

