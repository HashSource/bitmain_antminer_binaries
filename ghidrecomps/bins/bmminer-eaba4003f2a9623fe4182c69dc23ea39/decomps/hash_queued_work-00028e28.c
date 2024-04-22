
void hash_queued_work(thr_info *mythr)

{
  longlong lVar1;
  cgpu_info *cgpu_00;
  device_drv *drv_00;
  int thr_id_00;
  int64_t iVar2;
  undefined4 in_stack_fffff7b0;
  undefined4 in_stack_fffff7b4;
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
  cgpu_00 = mythr->cgpu;
  drv_00 = cgpu_00->drv;
  thr_id_00 = mythr->id;
  lVar1 = 0;
  do {
    if (cgpu_00->shutdown == true) {
LAB_00029050:
      cgpu_00->deven = DEV_DISABLED;
      return;
    }
    mythr->work_update = false;
    fill_queue(mythr,cgpu_00,drv_00,thr_id_00);
    iVar2 = (*drv_00->scanwork)(mythr);
    mythr->work_restart = false;
    if ((int)((ulonglong)iVar2 >> 0x20) == -1 && (int)iVar2 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s %d failure, disabling!",drv_00->name,cgpu_00->device_id);
        _applog(3,tmp42,false);
      }
      cgpu_00->deven = DEV_DISABLED;
      dev_error(cgpu_00,REASON_THREAD_ZERO_HASH);
      goto LAB_00029050;
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
      hashmeter(thr_id_00,CONCAT44(in_stack_fffff7b4,in_stack_fffff7b0));
      lVar1 = 0;
      copy_time(&tv_start,&tv_end);
    }
    if ((mythr->pause != false) || (cgpu_00->deven != DEV_ENABLED)) {
      mt_disable(mythr,thr_id_00,drv_00);
    }
    if (mythr->work_update != false) {
      (*drv_00->update_work)(cgpu_00);
    }
  } while( true );
}

