
/* WARNING: Unknown calling convention */

void hash_queued_work(thr_info *mythr)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  char *func;
  char *func_00;
  int line;
  int line_00;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv;
  int thr_id;
  int thr_id_00;
  bool bVar4;
  int64_t iVar5;
  uint64_t local_850;
  work *work;
  timeval tv_start;
  timeval tv_end;
  char tmp42 [2048];
  
  thr_id_00 = mythr->id;
  dev = mythr->cgpu;
  tv_start.tv_sec = 0;
  drv = dev->drv;
  local_850 = 0;
  tv_start.tv_usec = 0;
  do {
    if (dev->shutdown != false) {
LAB_00028ddc:
      dev->deven = DEV_DISABLED;
      return;
    }
    mythr->work_update = false;
    do {
      while (dev->unqueued_work != (work *)0x0) {
LAB_00028c8a:
        _Var1 = (*drv->queue_full)(dev);
        if (_Var1) goto LAB_00028cf6;
      }
      work = get_work(mythr,thr_id_00);
      iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)&dev->qlock);
      if (iVar2 != 0) {
        _wr_lock((pthread_rwlock_t *)"fill_queue",(char *)0x2417,func,line);
      }
      bVar4 = dev->unqueued_work == (work *)0x0;
      if (bVar4) {
        dev->unqueued_work = work;
      }
      iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&dev->qlock);
      if (iVar2 != 0) {
        _rw_unlock((pthread_rwlock_t *)"fill_queue",(char *)0x2422,func_00,line_00);
      }
      (*selective_yield)();
      if (bVar4) goto LAB_00028c8a;
      _discard_work(&work,"cgminer.c","fill_queue",0x2426);
      _Var1 = (*drv->queue_full)(dev);
    } while (!_Var1);
LAB_00028cf6:
    iVar5 = (*drv->scanwork)(mythr);
    mythr->work_restart = false;
    if (iVar5 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s %d failure, disabling!",drv->name,dev->device_id);
        _applog(3,tmp42,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      goto LAB_00028ddc;
    }
    local_850 = iVar5 + local_850;
    cgtime(&tv_end);
    iVar2 = tv_end.tv_sec - tv_start.tv_sec;
    iVar3 = tv_end.tv_usec - tv_start.tv_usec;
    if (iVar3 < 0) {
      iVar2 = iVar2 + -1;
      iVar3 = iVar3 + 1000000;
    }
    if (((local_850 == 0) || ((iVar2 < 1 && (iVar3 < 0x30d41)))) && (iVar2 < opt_log_interval)) {
      if (mythr->pause != false) goto LAB_00028d96;
LAB_00028d6a:
      if (dev->deven != DEV_ENABLED) goto LAB_00028d96;
    }
    else {
      hashmeter(thr_id_00,local_850);
      local_850 = 0;
      copy_time(&tv_start,&tv_end);
      if (mythr->pause == false) goto LAB_00028d6a;
LAB_00028d96:
      mt_disable(mythr,thr_id_00,drv);
    }
    if (mythr->work_update != false) {
      (*drv->update_work)(dev);
    }
  } while( true );
}

