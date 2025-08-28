
/* WARNING: Unknown calling convention */

work * find_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *pwVar1;
  int iVar2;
  char *func;
  uint uVar3;
  char *func_00;
  int line;
  work *pwVar4;
  int line_00;
  
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rd_lock((pthread_rwlock_t *)"find_queued_work_byid",(char *)0x24bd,func,line);
  }
  pwVar4 = cgpu->queued_work;
  if (pwVar4 != (work *)0x0) {
    uVar3 = pwVar4->id;
    for (pwVar1 = (work *)(pwVar4->hh).next;
        (id != uVar3 && (pwVar4 = pwVar1, pwVar1 != (work *)0x0));
        pwVar1 = (work *)(pwVar1->hh).next) {
      uVar3 = pwVar1->id;
    }
  }
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"find_queued_work_byid",(char *)0x24bf,func_00,line_00);
  }
  (*selective_yield)();
  return pwVar4;
}

