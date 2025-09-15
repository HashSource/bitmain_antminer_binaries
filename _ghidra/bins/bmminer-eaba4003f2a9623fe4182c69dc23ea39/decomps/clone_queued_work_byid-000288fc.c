
work * clone_queued_work_byid(cgpu_info *cgpu,uint id)

{
  work *base_work;
  uint id_local;
  cgpu_info *cgpu_local;
  work *work;
  work *ret;
  
  ret = (work *)0x0;
  _rd_lock(&cgpu->qlock,"cgminer.c","clone_queued_work_byid",0x24d0);
  base_work = __find_work_byid(cgpu->queued_work,id);
  if (base_work != (work *)0x0) {
    ret = copy_work_noffset(base_work,0);
  }
  _rd_unlock(&cgpu->qlock,"cgminer.c","clone_queued_work_byid",0x24d4);
  return ret;
}

