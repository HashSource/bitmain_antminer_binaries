
/* WARNING: Unknown calling convention */

work * get_queued(cgpu_info *cgpu)

{
  int iVar1;
  work *pwVar2;
  work *work;
  char *in_r2;
  int in_r3;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock(DAT_00028a38,(char *)0x2457,in_r2,in_r3);
  }
  pwVar2 = __get_queued(cgpu);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00028a38,(char *)0x2459,in_r2,in_r3);
  }
  (**DAT_00028a34)();
  return pwVar2;
}

