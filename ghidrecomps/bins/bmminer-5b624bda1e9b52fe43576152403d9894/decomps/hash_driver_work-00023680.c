
/* WARNING: Unknown calling convention */

void hash_driver_work(thr_info *mythr)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  _func_int64_t_thr_info_ptr *p_Var6;
  device_drv *func;
  int iVar7;
  uint line;
  _func_void_cgpu_info_ptr *line_00;
  device_drv *pdVar8;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv;
  device_drv *drv_00;
  int thr_id;
  int thr_id_00;
  bool bVar9;
  int64_t iVar10;
  undefined4 in_stack_fffff7b8;
  undefined4 in_stack_fffff7bc;
  device_drv *local_83c;
  timeval tv_start;
  timeval tv_end;
  char tmp42 [2048];
  
  iVar3 = DAT_00023808;
  thr_id_00 = mythr->id;
  lVar2 = 0;
  dev = mythr->cgpu;
  tv_start.tv_sec = 0;
  local_83c = (device_drv *)&DAT_00030d40;
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
    p_Var6 = drv_00->scanwork;
    mythr->work_update = false;
    iVar10 = (*p_Var6)(mythr);
    mythr->work_restart = false;
    if ((int)((ulonglong)iVar10 >> 0x20) == -1 && (int)iVar10 == -1) {
      if (((*DAT_000237f4 != '\0') || (*DAT_000237f8 != '\0')) || (2 < *DAT_000237fc)) {
        snprintf(tmp42,0x800,DAT_00023800,drv_00->name,dev->device_id);
        _applog(3,tmp42,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      goto LAB_00023768;
    }
    lVar2 = iVar10 + lVar2;
    pdVar8 = (device_drv *)lVar2;
    cgtime(&tv_end);
    iVar7 = tv_end.tv_usec - tv_start.tv_usec;
    bVar9 = iVar7 < 0;
    if (bVar9) {
      iVar7 = iVar7 + 0xf4000;
    }
    iVar5 = tv_end.tv_sec - tv_start.tv_sec;
    if (bVar9) {
      iVar7 = iVar7 + 0x240;
      iVar5 = iVar5 + -1;
    }
    func = (device_drv *)((uint)pdVar8 | (uint)((ulonglong)lVar2 >> 0x20));
    if (((lVar2 == 0) || ((iVar5 < 1 && (func = local_83c, iVar7 < 0x30d41)))) &&
       (iVar5 < *(int *)(iVar3 + 0x7f8))) {
      lVar4 = lVar2;
      if (mythr->pause != false) goto LAB_0002378c;
LAB_00023728:
      lVar2 = lVar4;
      if (dev->deven != DEV_ENABLED) goto LAB_0002378c;
    }
    else {
      hashmeter(thr_id_00,CONCAT44(in_stack_fffff7bc,in_stack_fffff7b8));
      copy_time(&tv_start,&tv_end);
      lVar2 = 0;
      func = pdVar8;
      lVar4 = 0;
      if (mythr->pause == false) goto LAB_00023728;
LAB_0002378c:
      func = drv_00;
      mt_disable(mythr,thr_id_00,drv_00);
    }
    line = (uint)mythr->work_update;
    if (line == 0) goto LAB_000236ac;
    iVar7 = pthread_mutex_lock(DAT_000237f0);
    if (iVar7 != 0) {
      _mutex_lock(DAT_00023804,(char *)0x259b,(char *)func,line);
    }
    line_00 = drv_00->update_work;
    (*line_00)(dev);
    iVar7 = pthread_mutex_unlock(DAT_000237f0);
    if (iVar7 != 0) {
      _mutex_unlock_noyield(DAT_00023804,(char *)0x259d,(char *)func,(int)line_00);
    }
    (*selective_yield)();
    cVar1 = dev->shutdown;
  } while( true );
}

