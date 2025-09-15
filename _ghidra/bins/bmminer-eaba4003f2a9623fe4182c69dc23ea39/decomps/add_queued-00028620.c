
void add_queued(cgpu_info *cgpu,work *work)

{
  work *work_local;
  cgpu_info *cgpu_local;
  
  _wr_lock(&cgpu->qlock,"cgminer.c","add_queued",0x2467);
  __add_queued(cgpu,work);
  _wr_unlock(&cgpu->qlock,"cgminer.c","add_queued",0x2469);
  return;
}

