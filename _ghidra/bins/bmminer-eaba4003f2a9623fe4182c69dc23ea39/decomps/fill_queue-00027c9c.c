
void fill_queue(thr_info *mythr,cgpu_info *cgpu,device_drv *drv,int thr_id)

{
  _Bool _Var1;
  work *pwVar2;
  bool bVar3;
  int thr_id_local;
  device_drv *drv_local;
  cgpu_info *cgpu_local;
  thr_info *mythr_local;
  work *work;
  _Bool need_work;
  
  do {
    pwVar2 = cgpu->unqueued_work;
    bVar3 = pwVar2 != (work *)0x0;
    if (bVar3) {
      pwVar2 = (work *)0x0;
    }
    need_work = SUB41(pwVar2,0);
    if (!bVar3) {
      need_work = true;
    }
    if (need_work != false) {
      work = get_work(mythr,thr_id);
      _wr_lock(&cgpu->qlock,"cgminer.c","fill_queue",0x241e);
      if (cgpu->unqueued_work == (work *)0x0) {
        cgpu->unqueued_work = work;
      }
      else {
        need_work = false;
      }
      _wr_unlock(&cgpu->qlock,"cgminer.c","fill_queue",0x2429);
      if (need_work != true) {
        _discard_work(&work,"cgminer.c","fill_queue",0x242d);
      }
    }
    _Var1 = (*drv->queue_full)(cgpu);
  } while (!_Var1);
  return;
}

