
/* WARNING: Unknown calling convention */

void hash_driver_work(thr_info *mythr)

{
  char cVar1;
  uint64_t hashes_done;
  uint64_t uVar2;
  int iVar3;
  _func_int64_t_thr_info_ptr *p_Var4;
  char *func;
  char *func_00;
  int iVar5;
  int line;
  int line_00;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv;
  device_drv *drv_00;
  int thr_id;
  int thr_id_00;
  bool bVar6;
  int64_t iVar7;
  timeval tv_start;
  timeval tv_end;
  char tmp42 [2048];
  
  thr_id_00 = mythr->id;
  hashes_done = 0;
  dev = mythr->cgpu;
  tv_start.tv_sec = 0;
  drv_00 = dev->drv;
  tv_start.tv_usec = 0;
LAB_000236ac:
  cVar1 = dev->shutdown;
  do {
    if (cVar1 != '\0') {
LAB_00023768:
      dev->deven = DEV_DISABLED;
      return;
    }
    p_Var4 = drv_00->scanwork;
    mythr->work_update = false;
    iVar7 = (*p_Var4)(mythr);
    mythr->work_restart = false;
    if (iVar7 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s %d failure, disabling!",drv_00->name,dev->device_id);
        _applog(3,tmp42,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      goto LAB_00023768;
    }
    hashes_done = iVar7 + hashes_done;
    cgtime(&tv_end);
    iVar5 = tv_end.tv_usec - tv_start.tv_usec;
    bVar6 = iVar5 < 0;
    if (bVar6) {
      iVar5 = iVar5 + 0xf4000;
    }
    iVar3 = tv_end.tv_sec - tv_start.tv_sec;
    if (bVar6) {
      iVar5 = iVar5 + 0x240;
      iVar3 = iVar3 + -1;
    }
    if (((hashes_done == 0) || ((iVar3 < 1 && (iVar5 < 0x30d41)))) && (iVar3 < opt_log_interval)) {
      uVar2 = hashes_done;
      if (mythr->pause != false) goto LAB_0002378c;
LAB_00023728:
      hashes_done = uVar2;
      if (dev->deven != DEV_ENABLED) goto LAB_0002378c;
    }
    else {
      hashmeter(thr_id_00,hashes_done);
      copy_time(&tv_start,&tv_end);
      hashes_done = 0;
      uVar2 = 0;
      if (mythr->pause == false) goto LAB_00023728;
LAB_0002378c:
      mt_disable(mythr,thr_id_00,drv_00);
    }
    if (mythr->work_update == false) goto LAB_000236ac;
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)&update_job_lock);
    if (iVar5 != 0) {
      _mutex_lock((pthread_mutex_t *)"hash_driver_work",(char *)0x259b,func,line);
    }
    (*drv_00->update_work)(dev);
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&update_job_lock);
    if (iVar5 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"hash_driver_work",(char *)0x259d,func_00,line_00);
    }
    (*selective_yield)();
    cVar1 = dev->shutdown;
  } while( true );
}

