
/* WARNING: Unknown calling convention */

work * clone_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  int iVar1;
  work *base_work;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rd_lock((pthread_rwlock_t *)"clone_queued_work_bymidstate",(char *)0x249a,func,line);
  }
  base_work = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  if (base_work != (work *)0x0) {
    base_work = copy_work_noffset(base_work,0);
  }
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"clone_queued_work_bymidstate",(char *)0x249e,func_00,line_00);
  }
  (*selective_yield)();
  return base_work;
}

