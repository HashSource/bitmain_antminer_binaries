
/* WARNING: Unknown calling convention */

cgpu_info * get_devices(int id)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  cgpu_info *pcVar2;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&devices_lock);
  if (iVar1 != 0) {
    _rd_lock((pthread_rwlock_t *)"get_devices",(char *)0x252,func,line);
  }
  pcVar2 = devices[id];
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&devices_lock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"get_devices",(char *)0x254,func_00,line_00);
  }
  (*selective_yield)();
  return pcVar2;
}

