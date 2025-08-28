
/* WARNING: Unknown calling convention */

work * take_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  int iVar1;
  work *work;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock((pthread_rwlock_t *)"take_queued_work_bymidstate",(char *)0x2505,func,line);
  }
  work = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  if (work != (work *)0x0) {
    __work_completed(cgpu,work);
  }
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"take_queued_work_bymidstate",(char *)0x2509,func_00,line_00);
  }
  (*selective_yield)();
  return work;
}

