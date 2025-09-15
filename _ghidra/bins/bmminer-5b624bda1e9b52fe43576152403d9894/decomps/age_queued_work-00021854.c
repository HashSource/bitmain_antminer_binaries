
int age_queued_work(cgpu_info *cgpu,double secs)

{
  int iVar1;
  int iVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  work *pwVar3;
  double dVar4;
  work *local_2c;
  timeval tv_now;
  
  cgtime(&tv_now);
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock((pthread_rwlock_t *)"age_queued_work",(char *)0x24e3,func,line);
  }
  local_2c = cgpu->queued_work;
  pwVar3 = local_2c;
  if (local_2c != (work *)0x0) {
    pwVar3 = (work *)(local_2c->hh).next;
  }
  iVar1 = 0;
  while( true ) {
    if (local_2c == (work *)0x0) break;
    dVar4 = tdiff(&tv_now,&local_2c->tv_work_start);
    if (secs < dVar4) {
      __work_completed(cgpu,local_2c);
      iVar1 = iVar1 + 1;
      _free_work(&local_2c,"cgminer.c","age_queued_work",0x24e9);
    }
    local_2c = pwVar3;
    if (pwVar3 != (work *)0x0) {
      pwVar3 = (work *)(pwVar3->hh).next;
    }
  }
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"age_queued_work",(char *)0x24ee,func_00,line_00);
  }
  (*selective_yield)();
  return iVar1;
}

