
work * find_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *pwVar1;
  uint id_local;
  cgpu_info *cgpu_local;
  work *ret;
  
  _rd_lock(&cgpu->qlock,"cgminer.c","find_queued_work_byid",0x24c4);
  pwVar1 = __find_work_byid(cgpu->queued_work,id);
  _rd_unlock(&cgpu->qlock,"cgminer.c","find_queued_work_byid",0x24c6);
  return pwVar1;
}

