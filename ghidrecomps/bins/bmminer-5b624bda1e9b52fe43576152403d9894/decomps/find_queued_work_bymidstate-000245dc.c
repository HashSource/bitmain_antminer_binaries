
/* WARNING: Unknown calling convention */

work * find_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  int iVar1;
  work *pwVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rd_lock((pthread_rwlock_t *)"find_queued_work_bymidstate",(char *)0x248e,func,line);
  }
  pwVar2 = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"find_queued_work_bymidstate",(char *)0x2490,func_00,line_00);
  }
  (*selective_yield)();
  return pwVar2;
}

