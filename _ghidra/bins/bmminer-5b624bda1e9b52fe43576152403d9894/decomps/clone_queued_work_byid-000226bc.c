
/* WARNING: Unknown calling convention */

work * clone_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *pwVar1;
  int iVar2;
  char *func;
  uint uVar3;
  char *func_00;
  int line;
  int line_00;
  work *base_work;
  
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rd_lock((pthread_rwlock_t *)"clone_queued_work_byid",(char *)0x24c9,func,line);
  }
  base_work = cgpu->queued_work;
  if (base_work != (work *)0x0) {
    uVar3 = base_work->id;
    pwVar1 = (work *)(base_work->hh).next;
    while (id != uVar3) {
      if (pwVar1 == (work *)0x0) {
        base_work = (work *)0x0;
        goto LAB_000226f6;
      }
      uVar3 = pwVar1->id;
      base_work = pwVar1;
      pwVar1 = (work *)(pwVar1->hh).next;
    }
    base_work = copy_work_noffset(base_work,0);
  }
LAB_000226f6:
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"clone_queued_work_byid",(char *)0x24cd,func_00,line_00);
  }
  (*selective_yield)();
  return base_work;
}

