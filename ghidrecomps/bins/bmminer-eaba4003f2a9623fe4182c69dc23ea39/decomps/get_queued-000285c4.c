
work * get_queued(cgpu_info *cgpu)

{
  work *pwVar1;
  cgpu_info *cgpu_local;
  work *work;
  
  _wr_lock(&cgpu->qlock,"cgminer.c","get_queued",0x245e);
  pwVar1 = __get_queued(cgpu);
  _wr_unlock(&cgpu->qlock,"cgminer.c","get_queued",0x2460);
  return pwVar1;
}

