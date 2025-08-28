
/* WARNING: Unknown calling convention */

void * restart_thread(void *arg)

{
  thr_info **pptVar1;
  pthread_t __th;
  int iVar2;
  int iVar3;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  cgpu_info *cgpu;
  
  __th = pthread_self();
  pthread_detach(__th);
  discard_stale();
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)&mining_thr_lock);
  if (iVar2 != 0) {
    _rd_lock((pthread_rwlock_t *)"restart_thread",(char *)0x14e0,func,line);
  }
  iVar2 = mining_threads;
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)&mining_thr_lock);
  if (iVar3 != 0) {
    _rw_unlock((pthread_rwlock_t *)"restart_thread",(char *)0x14e2,func_00,line_00);
  }
  (*selective_yield)();
  if (0 < iVar2) {
    iVar3 = 0;
    do {
      while( true ) {
        pptVar1 = mining_thr + iVar3;
        iVar3 = iVar3 + 1;
        cgpu = (*pptVar1)->cgpu;
        if ((cgpu == (cgpu_info *)0x0) || (cgpu->deven != DEV_ENABLED)) break;
        (*pptVar1)->work_restart = true;
        flush_queue(cgpu);
        (*cgpu->drv->flush_work)(cgpu);
        if (iVar3 == iVar2) goto LAB_00028460;
      }
    } while (iVar3 != iVar2);
  }
LAB_00028460:
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&restart_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"restart_thread",(char *)0x14f7,func_01,line_01);
  }
  pthread_cond_broadcast((pthread_cond_t *)&restart_cond);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&restart_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"restart_thread",(char *)0x14f9,func_02,line_02);
  }
  (*selective_yield)();
  return (void *)0x0;
}

