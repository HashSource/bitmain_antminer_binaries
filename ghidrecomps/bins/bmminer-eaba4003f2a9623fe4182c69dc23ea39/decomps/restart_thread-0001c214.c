
void * restart_thread(void *arg)

{
  int iVar1;
  pthread_t __th;
  cgpu_info *cgpu_00;
  void *arg_local;
  cgpu_info *cgpu;
  int mt;
  int i;
  
  __th = pthread_self();
  pthread_detach(__th);
  discard_stale();
  _rd_lock(&mining_thr_lock,"cgminer.c","restart_thread",0x14e7);
  iVar1 = mining_threads;
  _rd_unlock(&mining_thr_lock,"cgminer.c","restart_thread",0x14e9);
  for (i = 0; i < iVar1; i = i + 1) {
    cgpu_00 = mining_thr[i]->cgpu;
    if ((cgpu_00 != (cgpu_info *)0x0) && (cgpu_00->deven == DEV_ENABLED)) {
      mining_thr[i]->work_restart = true;
      flush_queue(cgpu_00);
      (*cgpu_00->drv->flush_work)(cgpu_00);
    }
  }
  _mutex_lock(&restart_lock,"cgminer.c","restart_thread",0x14fe);
  pthread_cond_broadcast((pthread_cond_t *)&restart_cond);
  _mutex_unlock(&restart_lock,"cgminer.c","restart_thread",0x1500);
  return (void *)0x0;
}

