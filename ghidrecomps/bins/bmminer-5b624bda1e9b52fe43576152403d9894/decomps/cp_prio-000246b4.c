
/* WARNING: Unknown calling convention */

int cp_prio(void)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  int line;
  int iVar2;
  int prio;
  
  iVar1 = pthread_mutex_lock(DAT_00024718);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00024728,(char *)0x1c88,in_r2,in_r3);
  }
  iVar1 = pthread_rwlock_rdlock(DAT_0002471c);
  if (iVar1 != 0) {
    _rd_lock(DAT_00024728,(char *)0x1c88,in_r2,in_r3);
  }
  iVar1 = pthread_mutex_unlock(DAT_00024718);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00024728,(char *)0x1c88,in_r2,in_r3);
  }
  line = *(int *)(DAT_00024720 + 0x498);
  iVar2 = *(int *)(line + 4);
  iVar1 = pthread_rwlock_unlock(DAT_0002471c);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00024728,(char *)0x1c8a,in_r2,line);
  }
  (**DAT_00024724)();
  return iVar2;
}

