
/* WARNING: Unknown calling convention */

work * find_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *pwVar1;
  work *pwVar2;
  int iVar3;
  work *in_r2;
  int in_r3;
  work *line;
  work *work;
  work *tmp;
  work *pwVar4;
  
  iVar3 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar3 != 0) {
    _rd_lock(DAT_000246b0,(char *)0x24bd,(char *)in_r2,in_r3);
  }
  line = cgpu->queued_work;
  pwVar4 = line;
  if (line != (work *)0x0) {
    in_r2 = (work *)line->id;
    pwVar1 = (work *)(line->hh).next;
    pwVar2 = in_r2;
    while (((work *)id != pwVar2 && (pwVar4 = pwVar1, pwVar1 != (work *)0x0))) {
      line = (work *)pwVar1->id;
      in_r2 = (work *)(pwVar1->hh).next;
      pwVar2 = line;
      pwVar1 = in_r2;
    }
  }
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar3 != 0) {
    _rw_unlock(DAT_000246b0,(char *)0x24bf,(char *)in_r2,(int)line);
  }
  (**DAT_000246ac)();
  return pwVar4;
}

