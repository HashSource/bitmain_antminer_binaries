
/* WARNING: Unknown calling convention */

void enable_device(cgpu_info *cgpu)

{
  cgpu_info **ppcVar1;
  int iVar2;
  char *func;
  char *func_00;
  char *func_01;
  int line;
  int line_00;
  int line_01;
  
  cgpu->deven = DEV_ENABLED;
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)&devices_lock);
  if (iVar2 != 0) {
    _wr_lock((pthread_rwlock_t *)"enable_device",(char *)0x2b51,func,line);
  }
  ppcVar1 = devices;
  cgpu->cgminer_id = cgminer_id_count;
  ppcVar1[cgminer_id_count] = cgpu;
  cgminer_id_count = cgminer_id_count + 1;
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&devices_lock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"enable_device",(char *)0x2b53,func_00,line_00);
  }
  (*selective_yield)();
  if (hotplug_mode == false) {
    mining_threads = cgpu->threads + mining_threads;
  }
  else {
    new_threads = cgpu->threads + new_threads;
  }
  iVar2 = pthread_rwlock_init((pthread_rwlock_t *)&cgpu->qlock,(pthread_rwlockattr_t *)0x0);
  if (iVar2 != 0) {
    _rwlock_init((pthread_rwlock_t *)"enable_device",(char *)0x2b5e,func_01,line_01);
  }
  cgpu->queued_work = (work *)0x0;
  return;
}

