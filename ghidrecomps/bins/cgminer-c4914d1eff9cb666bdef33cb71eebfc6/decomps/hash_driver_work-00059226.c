
void hash_driver_work(thr_info *mythr)

{
  longlong lVar1;
  cgpu_info *dev;
  device_drv *drv_00;
  int thr_id_00;
  int64_t iVar2;
  undefined4 in_stack_fffff7a0;
  undefined4 in_stack_fffff7a4;
  thr_info *mythr_local;
  char tmp42 [2048];
  timeval diff;
  timeval tv_end;
  timeval tv_start;
  int64_t hashes;
  int thr_id;
  device_drv *drv;
  cgpu_info *cgpu;
  int64_t hashes_done;
  
  tv_start.tv_sec = 0;
  tv_start.tv_usec = 0;
  dev = mythr->cgpu;
  drv_00 = dev->drv;
  thr_id_00 = mythr->id;
  lVar1 = 0;
  do {
    if (dev->shutdown == true) {
LAB_0005947c:
      dev->deven = DEV_DISABLED;
      return;
    }
    mythr->work_update = false;
    iVar2 = (*drv_00->scanwork)(mythr);
    mythr->work_restart = false;
    if ((int)((ulonglong)iVar2 >> 0x20) == -1 && (int)iVar2 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s %d failure, disabling!",drv_00->name,dev->device_id);
        _applog(3,tmp42,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      goto LAB_0005947c;
    }
    lVar1 = iVar2 + lVar1;
    cgtime(&tv_end);
    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    diff.tv_usec = tv_end.tv_usec - tv_start.tv_usec;
    if (diff.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
      diff.tv_usec = diff.tv_usec + 1000000;
    }
    if (((lVar1 != 0) && ((0 < diff.tv_sec || (200000 < diff.tv_usec)))) ||
       (opt_log_interval <= diff.tv_sec)) {
      hashmeter(thr_id_00,CONCAT44(in_stack_fffff7a4,in_stack_fffff7a0));
      lVar1 = 0;
      copy_time(&tv_start,&tv_end);
    }
    if ((mythr->pause != false) || (dev->deven != DEV_ENABLED)) {
      mt_disable(mythr,thr_id_00,drv_00);
    }
    if (mythr->work_update != false) {
      _mutex_lock(&update_job_lock,"cgminer.c","hash_driver_work",0x25f0);
      (*drv_00->update_work)(dev);
      _mutex_unlock(&update_job_lock,"cgminer.c","hash_driver_work",0x25f2);
    }
  } while( true );
}

