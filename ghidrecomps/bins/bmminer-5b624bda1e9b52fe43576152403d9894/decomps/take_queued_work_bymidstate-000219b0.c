
/* WARNING: Unknown calling convention */

work * take_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  int iVar1;
  work *work_00;
  work *work;
  char *func;
  char *line;
  
  func = (char *)midstatelen;
  line = data;
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _wr_lock(DAT_00021a20,(char *)0x2505,func,(int)line);
  }
  work_00 = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  if (work_00 != (work *)0x0) {
    __work_completed(cgpu,work_00);
  }
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00021a20,(char *)0x2509,(char *)midstatelen,(int)data);
  }
  (**DAT_00021a1c)();
  return work_00;
}

