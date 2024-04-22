
/* WARNING: Unknown calling convention */

void work_completed(cgpu_info *cgpu,work *work)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  work *local_14 [2];
  
  local_14[0] = work;
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock(DAT_00021960,(char *)0x24f8,in_r2,in_r3);
  }
  __work_completed(cgpu,local_14[0]);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00021960,(char *)0x24fa,in_r2,in_r3);
  }
  (**DAT_00021958)();
  _free_work(local_14,DAT_0002195c,DAT_00021960->__size,0x24fc);
  return;
}

