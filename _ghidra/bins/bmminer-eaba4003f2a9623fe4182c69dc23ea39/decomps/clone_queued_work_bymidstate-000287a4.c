
work * clone_queued_work_bymidstate
                 (cgpu_info *cgpu,char *midstate,size_t midstatelen,char *data,int offset,
                 size_t datalen)

{
  work *base_work;
  char *data_local;
  size_t midstatelen_local;
  char *midstate_local;
  cgpu_info *cgpu_local;
  work *work;
  work *ret;
  
  ret = (work *)0x0;
  _rd_lock(&cgpu->qlock,"cgminer.c","clone_queued_work_bymidstate",0x24a1);
  base_work = __find_work_bymidstate(cgpu->queued_work,midstate,midstatelen,data,offset,datalen);
  if (base_work != (work *)0x0) {
    ret = copy_work_noffset(base_work,0);
  }
  _rd_unlock(&cgpu->qlock,"cgminer.c","clone_queued_work_bymidstate",0x24a5);
  return ret;
}

