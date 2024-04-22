
work * find_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  work *pwVar1;
  char *data_local;
  size_t midstatelen_local;
  char *midstate_local;
  cgpu_info *cgpu_local;
  work *ret;
  
  _rd_lock(&cgpu->qlock,"cgminer.c","find_queued_work_bymidstate",0x2495);
  pwVar1 = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  _rd_unlock(&cgpu->qlock,"cgminer.c","find_queued_work_bymidstate",0x2497);
  return pwVar1;
}

