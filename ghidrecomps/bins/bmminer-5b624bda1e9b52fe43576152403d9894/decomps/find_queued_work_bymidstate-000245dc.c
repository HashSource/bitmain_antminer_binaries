
/* WARNING: Unknown calling convention */

work * find_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  int iVar1;
  work *pwVar2;
  work *ret;
  char *func;
  char *line;
  
  func = (char *)midstatelen;
  line = data;
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rd_lock(DAT_00024640,(char *)0x248e,func,(int)line);
  }
  pwVar2 = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock(DAT_00024640,(char *)0x2490,(char *)midstatelen,(int)data);
  }
  (**DAT_0002463c)();
  return pwVar2;
}

