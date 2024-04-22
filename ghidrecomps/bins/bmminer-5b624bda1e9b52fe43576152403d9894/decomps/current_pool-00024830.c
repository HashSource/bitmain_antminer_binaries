
/* WARNING: Unknown calling convention */

pool * current_pool(void)

{
  int iVar1;
  int iVar2;
  char *in_r2;
  int in_r3;
  pool *ppVar3;
  pool *pool;
  
  iVar1 = pthread_mutex_lock(DAT_00024894);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_000248a4,(char *)0x323,in_r2,in_r3);
  }
  iVar1 = pthread_rwlock_rdlock(DAT_00024898);
  if (iVar1 != 0) {
    _rd_lock(DAT_000248a4,(char *)0x323,in_r2,in_r3);
  }
  iVar1 = pthread_mutex_unlock(DAT_00024894);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_000248a4,(char *)0x323,in_r2,in_r3);
  }
  ppVar3 = *(pool **)(DAT_0002489c + 0x498);
  iVar1 = DAT_0002489c;
  iVar2 = pthread_rwlock_unlock(DAT_00024898);
  if (iVar2 != 0) {
    _rw_unlock(DAT_000248a4,(char *)0x327,in_r2,iVar1);
  }
  (**DAT_000248a0)();
  return ppVar3;
}

