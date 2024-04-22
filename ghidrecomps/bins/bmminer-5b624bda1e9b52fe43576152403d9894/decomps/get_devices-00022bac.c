
/* WARNING: Unknown calling convention */

cgpu_info * get_devices(int id)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  int line;
  cgpu_info *pcVar2;
  cgpu_info *cgpu;
  
  iVar1 = pthread_rwlock_rdlock(DAT_00022bec);
  if (iVar1 != 0) {
    _rd_lock(DAT_00022bf8,(char *)0x252,in_r2,in_r3);
  }
  line = *DAT_00022bf0;
  pcVar2 = *(cgpu_info **)(line + id * 4);
  iVar1 = pthread_rwlock_unlock(DAT_00022bec);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00022bf8,(char *)0x254,in_r2,line);
  }
  (**DAT_00022bf4)();
  return pcVar2;
}

