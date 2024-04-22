
/* WARNING: Unknown calling convention */

void hash_queued_work(thr_info *mythr)

{
  longlong lVar1;
  code **ppcVar2;
  int iVar3;
  longlong lVar4;
  _Bool _Var5;
  int iVar6;
  int iVar7;
  device_drv *in_r2;
  work *pwVar8;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv_00;
  device_drv *drv;
  int thr_id;
  int thr_id_00;
  bool bVar9;
  int64_t iVar10;
  undefined4 in_stack_fffff7a8;
  undefined4 in_stack_fffff7ac;
  work *work;
  timeval tv_start;
  timeval tv_end;
  char tmp42 [2048];
  
  iVar3 = DAT_00028e24;
  ppcVar2 = DAT_00028e20;
  thr_id_00 = mythr->id;
  dev = mythr->cgpu;
  tv_start.tv_sec = 0;
  drv_00 = dev->drv;
  lVar1 = 0;
  tv_start.tv_usec = 0;
  do {
    if (dev->shutdown != false) {
LAB_00028ddc:
      dev->deven = DEV_DISABLED;
      return;
    }
    mythr->work_update = false;
    do {
      while (pwVar8 = dev->unqueued_work, pwVar8 != (work *)0x0) {
LAB_00028c8a:
        _Var5 = (*drv_00->queue_full)(dev);
        if (_Var5 != false) goto LAB_00028cf6;
      }
      work = get_work(mythr,thr_id_00);
      iVar6 = pthread_rwlock_wrlock((pthread_rwlock_t *)&dev->qlock);
      if (iVar6 != 0) {
        _wr_lock((pthread_rwlock_t *)DAT_00028e0c,(char *)0x2417,(char *)in_r2,(int)pwVar8);
      }
      pwVar8 = dev->unqueued_work;
      bVar9 = pwVar8 == (work *)0x0;
      if (bVar9) {
        dev->unqueued_work = work;
        pwVar8 = work;
      }
      iVar6 = pthread_rwlock_unlock((pthread_rwlock_t *)&dev->qlock);
      if (iVar6 != 0) {
        _rw_unlock((pthread_rwlock_t *)DAT_00028e0c,(char *)0x2422,(char *)in_r2,(int)pwVar8);
      }
      (**ppcVar2)();
      if (bVar9) goto LAB_00028c8a;
      in_r2 = DAT_00028e0c;
      _discard_work(&work,DAT_00028e08,(char *)DAT_00028e0c,0x2426);
      _Var5 = (*drv_00->queue_full)(dev);
    } while (_Var5 == false);
LAB_00028cf6:
    iVar10 = (*drv_00->scanwork)(mythr);
    mythr->work_restart = false;
    if ((int)((ulonglong)iVar10 >> 0x20) == -1 && (int)iVar10 == -1) {
      if (((*DAT_00028e10 != '\0') || (*DAT_00028e14 != '\0')) || (2 < *DAT_00028e18)) {
        snprintf(tmp42,0x800,DAT_00028e1c,drv_00->name,dev->device_id);
        _applog(3,tmp42,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      goto LAB_00028ddc;
    }
    lVar1 = iVar10 + lVar1;
    in_r2 = (device_drv *)lVar1;
    cgtime(&tv_end);
    iVar6 = tv_end.tv_sec - tv_start.tv_sec;
    iVar7 = tv_end.tv_usec - tv_start.tv_usec;
    if (iVar7 < 0) {
      iVar6 = iVar6 + -1;
      iVar7 = iVar7 + 1000000;
    }
    if (((lVar1 == 0) || ((iVar6 < 1 && (in_r2 = (device_drv *)&DAT_00030d40, iVar7 < 0x30d41)))) &&
       (iVar6 < *(int *)(iVar3 + 0x7f8))) {
      lVar4 = lVar1;
      if (mythr->pause != false) goto LAB_00028d96;
LAB_00028d6a:
      lVar4 = lVar1;
      if (dev->deven != DEV_ENABLED) goto LAB_00028d96;
    }
    else {
      hashmeter(thr_id_00,CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
      in_r2 = (device_drv *)0x0;
      lVar1 = 0;
      copy_time(&tv_start,&tv_end);
      lVar4 = 0;
      if (mythr->pause == false) goto LAB_00028d6a;
LAB_00028d96:
      lVar1 = lVar4;
      in_r2 = drv_00;
      mt_disable(mythr,thr_id_00,drv_00);
    }
    if (mythr->work_update != false) {
      (*drv_00->update_work)(dev);
    }
  } while( true );
}

