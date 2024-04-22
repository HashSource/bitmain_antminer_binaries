
int age_queued_work(cgpu_info *cgpu,double secs)

{
  double in_d0;
  double dVar1;
  double secs_local;
  cgpu_info *cgpu_local;
  timeval tv_now;
  work *work;
  int aged;
  work *tmp;
  
  aged = 0;
  cgtime(&tv_now);
  _wr_lock(&cgpu->qlock,"cgminer.c","age_queued_work",0x24ea);
  work = cgpu->queued_work;
  if (cgpu->queued_work == (work *)0x0) {
    tmp = (work *)0x0;
  }
  else {
    tmp = (work *)(cgpu->queued_work->hh).next;
  }
  while (work != (work *)0x0) {
    dVar1 = tdiff(&tv_now,&work->tv_work_start);
    if (dVar1 != in_d0 && dVar1 < in_d0 == (NAN(dVar1) || NAN(in_d0))) {
      __work_completed(cgpu,work);
      _free_work(&work,"cgminer.c","age_queued_work",0x24f0);
      aged = aged + 1;
    }
    work = tmp;
    if (tmp == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(tmp->hh).next;
    }
  }
  _wr_unlock(&cgpu->qlock,"cgminer.c","age_queued_work",0x24f5);
  return aged;
}

