
work * take_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  work *work_00;
  char *data_local;
  size_t midstatelen_local;
  char *midstate_local;
  cgpu_info *cgpu_local;
  work *work;
  
  _wr_lock(&cgpu->qlock,"cgminer.c","take_queued_work_bymidstate",0x250c);
  work_00 = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  if (work_00 != (work *)0x0) {
    __work_completed(cgpu,work_00);
  }
  _wr_unlock(&cgpu->qlock,"cgminer.c","take_queued_work_bymidstate",0x2510);
  return work_00;
}

