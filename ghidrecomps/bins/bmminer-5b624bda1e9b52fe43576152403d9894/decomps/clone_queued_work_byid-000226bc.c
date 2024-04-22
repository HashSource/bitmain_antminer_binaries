
/* WARNING: Unknown calling convention */

work * clone_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *pwVar1;
  int iVar2;
  work *tmp;
  char *in_r2;
  int in_r3;
  work *base_work;
  work *work;
  
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rd_lock(DAT_00022730,(char *)0x24c9,in_r2,in_r3);
  }
  base_work = cgpu->queued_work;
  if (base_work != (work *)0x0) {
    in_r2 = (char *)base_work->id;
    pwVar1 = (work *)(base_work->hh).next;
    while ((char *)id != in_r2) {
      if (pwVar1 == (work *)0x0) {
        base_work = (work *)0x0;
        goto LAB_000226f6;
      }
      in_r2 = (char *)pwVar1->id;
      base_work = pwVar1;
      pwVar1 = (work *)(pwVar1->hh).next;
    }
    base_work = copy_work_noffset(base_work,0);
  }
LAB_000226f6:
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar2 != 0) {
    _rw_unlock(DAT_00022730,(char *)0x24cd,in_r2,in_r3);
  }
  (**DAT_0002272c)();
  return base_work;
}

