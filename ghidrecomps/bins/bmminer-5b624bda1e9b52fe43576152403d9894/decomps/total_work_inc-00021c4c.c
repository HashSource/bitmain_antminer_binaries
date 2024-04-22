
/* WARNING: Unknown calling convention */

int total_work_inc(void)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  int iVar2;
  char *in_r2;
  char *func;
  int in_r3;
  int iVar3;
  int ret;
  
  iVar1 = pthread_mutex_lock(DAT_00021cb4);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00021cc4,(char *)0x886,in_r2,in_r3);
  }
  iVar1 = pthread_rwlock_wrlock(DAT_00021cb8);
  if (iVar1 != 0) {
    _wr_lock(DAT_00021cc4,(char *)0x886,in_r2,in_r3);
  }
  iVar1 = DAT_00021cbc;
  __rwlock = DAT_00021cb8;
  iVar3 = *(int *)(DAT_00021cbc + 0x4e8);
  func = (char *)(iVar3 + 1);
  *(char **)(DAT_00021cbc + 0x4e8) = func;
  iVar2 = pthread_rwlock_unlock(__rwlock);
  if (iVar2 != 0) {
    _rw_unlock(DAT_00021cc4,(char *)0x888,func,iVar1);
  }
  iVar2 = pthread_mutex_unlock(DAT_00021cb4);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00021cc4,(char *)0x888,func,iVar1);
  }
  (**DAT_00021cc0)();
  return iVar3;
}

