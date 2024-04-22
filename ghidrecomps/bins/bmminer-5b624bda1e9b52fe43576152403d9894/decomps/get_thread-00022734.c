
/* WARNING: Unknown calling convention */

thr_info * get_thread(int thr_id)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  int line;
  thr_info *thr;
  thr_info *ptVar2;
  
  iVar1 = pthread_rwlock_rdlock(DAT_00022774);
  if (iVar1 != 0) {
    _rd_lock(DAT_00022780,(char *)0x23e,in_r2,in_r3);
  }
  line = *DAT_00022778;
  ptVar2 = *(thr_info **)(line + thr_id * 4);
  iVar1 = pthread_rwlock_unlock(DAT_00022774);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00022780,(char *)0x240,in_r2,line);
  }
  (**DAT_0002277c)();
  return ptVar2;
}

