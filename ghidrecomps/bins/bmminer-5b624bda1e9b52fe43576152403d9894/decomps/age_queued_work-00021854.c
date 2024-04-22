
int age_queued_work(cgpu_info *cgpu,double secs)

{
  int iVar1;
  int iVar2;
  work *in_r2;
  int in_r3;
  work *line;
  work *pwVar3;
  work *tmp;
  double in_d0;
  double dVar4;
  work *work;
  timeval tv_now;
  
  cgtime(&tv_now);
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock(DAT_000218fc,(char *)0x24e3,(char *)in_r2,in_r3);
  }
  line = cgpu->queued_work;
  pwVar3 = line;
  if (line != (work *)0x0) {
    pwVar3 = (work *)(line->hh).next;
  }
  iVar1 = 0;
  while( true ) {
    work = line;
    if (line == (work *)0x0) break;
    dVar4 = tdiff(&tv_now,&line->tv_work_start);
    if (dVar4 != in_d0 && dVar4 < in_d0 == (NAN(dVar4) || NAN(in_d0))) {
      __work_completed(cgpu,work);
      iVar1 = iVar1 + 1;
      _free_work(&work,DAT_000218f8,DAT_000218fc->__size,0x24e9);
    }
    in_r2 = pwVar3;
    line = pwVar3;
    if (pwVar3 != (work *)0x0) {
      in_r2 = (work *)(pwVar3->hh).next;
      pwVar3 = in_r2;
    }
  }
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rw_unlock(DAT_000218fc,(char *)0x24ee,(char *)in_r2,(int)line);
  }
  (**DAT_00021900)();
  return iVar1;
}

