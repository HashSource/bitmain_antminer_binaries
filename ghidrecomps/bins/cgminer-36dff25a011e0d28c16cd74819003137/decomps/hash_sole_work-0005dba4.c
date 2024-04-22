
void hash_sole_work(thr_info *mythr)

{
  _Bool _Var1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  int thr_id_00;
  cgpu_info *dev;
  device_drv *drv_00;
  int iVar6;
  undefined4 uVar7;
  pool *ppVar8;
  int iVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  int64_t iVar13;
  int in_stack_fffff758;
  undefined4 in_stack_fffff75c;
  thr_info *mythr_local;
  char tmp42 [2048];
  timespec rgtp;
  work *work;
  timeval wdiff;
  timeval diff;
  timeval sdiff;
  timeval tv_lastupdate;
  timeval tv_workstart;
  timeval tv_start;
  timeval getwork_start;
  int mult;
  int64_t hashes;
  cgminer_stats *pool_stats;
  timeval *tv_end;
  _Bool primary;
  long cycle;
  cgminer_stats *dev_stats;
  device_drv *drv;
  cgpu_info *cgpu;
  int thr_id;
  int64_t hashes_done;
  uint32_t max_nonce;
  
  thr_id_00 = mythr->id;
  dev = mythr->cgpu;
  drv_00 = dev->drv;
  iVar6 = opt_log_interval / 5;
  if (iVar6 == 0) {
    iVar6 = 1;
  }
  if ((mythr->device_thread == 0) || (mythr->primary_thread != false)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  wdiff.tv_sec = 0;
  wdiff.tv_usec = 0;
  max_nonce = (*drv_00->can_limit_work)(mythr);
  hashes_done._0_4_ = 0;
  hashes_done._4_4_ = 0;
  cgtime(&getwork_start);
  sdiff.tv_usec = 0;
  sdiff.tv_sec = 0;
  cgtime(&tv_lastupdate);
  do {
    if (dev->shutdown == true) {
LAB_0005e534:
      dev->deven = DEV_DISABLED;
      return;
    }
    work = get_work(mythr,thr_id_00);
    mythr->work_restart = false;
    dev->new_work = true;
    cgtime(&tv_workstart);
    work->nonce = 0;
    *(undefined4 *)&dev->max_hashes = 0;
    *(undefined4 *)((int)&dev->max_hashes + 4) = 0;
    _Var1 = (*drv_00->prepare_work)(mythr,work);
    if (!_Var1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"work prepare failed, exiting mining thread %d",thr_id_00);
        _applog(3,tmp42,false);
      }
      goto LAB_0005e534;
    }
    dVar11 = drv_00->max_diff;
    dVar12 = work->work_difficulty;
    if (dVar11 == dVar12 || dVar11 < dVar12 != (NAN(dVar11) || NAN(dVar12))) {
      uVar4 = *(undefined4 *)&drv_00->max_diff;
      uVar7 = *(undefined4 *)((int)&drv_00->max_diff + 4);
    }
    else {
      uVar4 = *(undefined4 *)&work->work_difficulty;
      uVar7 = *(undefined4 *)((int)&work->work_difficulty + 4);
    }
    *(undefined4 *)&work->device_diff = uVar4;
    *(undefined4 *)((int)&work->device_diff + 4) = uVar7;
    dVar11 = drv_00->min_diff;
    dVar12 = work->device_diff;
    if (dVar11 == dVar12 || dVar11 < dVar12 != (NAN(dVar11) || NAN(dVar12))) {
      uVar4 = *(undefined4 *)&work->device_diff;
      uVar7 = *(undefined4 *)((int)&work->device_diff + 4);
    }
    else {
      uVar4 = *(undefined4 *)&drv_00->min_diff;
      uVar7 = *(undefined4 *)((int)&drv_00->min_diff + 4);
    }
    *(undefined4 *)&work->device_diff = uVar4;
    *(undefined4 *)((int)&work->device_diff + 4) = uVar7;
    while( true ) {
      cgtime(&tv_start);
      subtime(&tv_start,&getwork_start);
      addtime(&getwork_start,&(dev->cgminer_stats).getwork_wait);
      _Var1 = time_more(&getwork_start,&(dev->cgminer_stats).getwork_wait_max);
      if (_Var1) {
        copy_time(&(dev->cgminer_stats).getwork_wait_max,&getwork_start);
      }
      _Var1 = time_less(&getwork_start,&(dev->cgminer_stats).getwork_wait_min);
      if (_Var1) {
        copy_time(&(dev->cgminer_stats).getwork_wait_min,&getwork_start);
      }
      (dev->cgminer_stats).getwork_calls = (dev->cgminer_stats).getwork_calls + 1;
      ppVar8 = work->pool;
      addtime(&getwork_start,&(ppVar8->cgminer_stats).getwork_wait);
      _Var1 = time_more(&getwork_start,&(ppVar8->cgminer_stats).getwork_wait_max);
      if (_Var1) {
        copy_time(&(ppVar8->cgminer_stats).getwork_wait_max,&getwork_start);
      }
      _Var1 = time_less(&getwork_start,&(ppVar8->cgminer_stats).getwork_wait_min);
      if (_Var1) {
        copy_time(&(ppVar8->cgminer_stats).getwork_wait_min,&getwork_start);
      }
      (ppVar8->cgminer_stats).getwork_calls = (ppVar8->cgminer_stats).getwork_calls + 1;
      cgtime(&work->tv_work_start);
      pthread_setcancelstate(1,(int *)0x0);
      thread_reportin(mythr);
      iVar13 = (*drv_00->scanhash)(mythr,work,CONCAT44(in_stack_fffff75c,in_stack_fffff758));
      thread_reportout(mythr);
      pthread_setcancelstate(0,(int *)0x0);
      pthread_testcancel();
      cgtime(&getwork_start);
      hashes._0_4_ = (uint)iVar13;
      hashes._4_4_ = (int)((ulonglong)iVar13 >> 0x20);
      if (hashes._4_4_ == -1 && (uint)hashes == 0xffffffff) break;
      bVar10 = CARRY4((uint)hashes_done,(uint)hashes);
      hashes_done._0_4_ = (uint)hashes_done + (uint)hashes;
      hashes_done._4_4_ = hashes_done._4_4_ + hashes._4_4_ + (uint)bVar10;
      iVar3 = *(int *)((int)&dev->max_hashes + 4);
      bVar10 = *(uint *)&dev->max_hashes < (uint)hashes;
      if ((int)(iVar3 - (hashes._4_4_ + (uint)bVar10)) < 0 !=
          (SBORROW4(iVar3,hashes._4_4_) != SBORROW4(iVar3 - hashes._4_4_,(uint)bVar10))) {
        *(uint *)&dev->max_hashes = (uint)hashes;
        *(int *)((int)&dev->max_hashes + 4) = hashes._4_4_;
      }
      diff.tv_sec = getwork_start.tv_sec - tv_start.tv_sec;
      diff.tv_usec = getwork_start.tv_usec - tv_start.tv_usec;
      if (diff.tv_usec < 0) {
        diff.tv_sec = diff.tv_sec + -1;
        diff.tv_usec = diff.tv_usec + 1000000;
      }
      sdiff.tv_sec = sdiff.tv_sec + diff.tv_sec;
      sdiff.tv_usec = sdiff.tv_usec + diff.tv_usec;
      if (1000000 < sdiff.tv_usec) {
        sdiff.tv_sec = sdiff.tv_sec + 1;
        sdiff.tv_usec = sdiff.tv_usec + -1000000;
      }
      wdiff.tv_sec = getwork_start.tv_sec - tv_workstart.tv_sec;
      wdiff.tv_usec = getwork_start.tv_usec - tv_workstart.tv_usec;
      if (wdiff.tv_usec < 0) {
        wdiff.tv_sec = wdiff.tv_sec + -1;
        wdiff.tv_usec = wdiff.tv_usec + 1000000;
      }
      if (sdiff.tv_sec < iVar6) {
        if (max_nonce != 0xffffffff) {
          iVar3 = sdiff.tv_usec + 0x7ff;
          if (-1 < sdiff.tv_usec + 0x400) {
            iVar3 = sdiff.tv_usec + 0x400;
          }
          iVar3 = __aeabi_idiv(1000000,iVar3 >> 10);
          iVar3 = iVar6 * (iVar3 + 0x10);
          uVar2 = __udivsi3(0xfffffc00,iVar3);
          if (uVar2 < max_nonce) {
            max_nonce = 0xffffffff;
          }
          else {
            max_nonce = max_nonce * iVar3 >> 10;
          }
          goto LAB_0005e36c;
        }
      }
      else {
        if (iVar6 < sdiff.tv_sec) {
          max_nonce = __udivsi3(max_nonce * iVar6,sdiff.tv_sec);
        }
        else if (100000 < sdiff.tv_usec) {
          iVar9 = iVar6 * 1000000;
          iVar3 = iVar9 + 0x3ff;
          if (-1 < iVar9) {
            iVar3 = iVar9;
          }
          uVar4 = __aeabi_idiv(iVar6 * 1000000 + sdiff.tv_usec,iVar3 >> 10);
          max_nonce = __udivsi3(max_nonce << 10,uVar4);
        }
LAB_0005e36c:
        diff.tv_sec = getwork_start.tv_sec - tv_lastupdate.tv_sec;
        diff.tv_usec = getwork_start.tv_usec - tv_lastupdate.tv_usec;
        if (diff.tv_usec < 0) {
          diff.tv_sec = diff.tv_sec + -1;
          diff.tv_usec = diff.tv_usec + 1000000;
        }
        if (((((uint)hashes_done | hashes_done._4_4_) != 0) &&
            ((0 < diff.tv_sec || (200000 < diff.tv_usec)))) || (opt_log_interval <= diff.tv_sec)) {
          hashmeter(thr_id_00,CONCAT44(in_stack_fffff75c,in_stack_fffff758));
          hashes_done._0_4_ = 0;
          hashes_done._4_4_ = 0;
          copy_time(&tv_lastupdate,&getwork_start);
        }
        if (mythr->work_restart != false) {
          if (!bVar5) {
            rgtp.tv_sec = 0;
            rgtp.tv_nsec = mythr->device_thread * 250000000;
            nanosleep((timespec *)&rgtp,(timespec *)0x0);
          }
          goto LAB_0005e4f8;
        }
        if ((mythr->pause != false) || (dev->deven != DEV_ENABLED)) {
          mt_disable(mythr,thr_id_00,drv_00);
        }
        sdiff.tv_usec = 0;
        sdiff.tv_sec = 0;
      }
      _Var1 = abandon_work(work,&wdiff,CONCAT44(in_stack_fffff75c,in_stack_fffff758));
      if (_Var1) goto LAB_0005e4f8;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      in_stack_fffff758 = dev->device_id;
      snprintf(tmp42,0x800,"%s %d failure, disabling!",drv_00->name);
      _applog(3,tmp42,false);
    }
    dev->deven = DEV_DISABLED;
    dev_error(dev,REASON_THREAD_ZERO_HASH);
    dev->shutdown = true;
LAB_0005e4f8:
    _free_work(&work,"cgminer.c","hash_sole_work",0x2453);
  } while( true );
}

