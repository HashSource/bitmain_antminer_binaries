
void work_completed(cgpu_info *cgpu,work *work)

{
  work *work_local;
  cgpu_info *cgpu_local;
  
  work_local = work;
  cgpu_local = cgpu;
  _wr_lock(&cgpu->qlock,"cgminer.c","work_completed",0x24ff);
  __work_completed(cgpu_local,work_local);
  _wr_unlock(&cgpu_local->qlock,"cgminer.c","work_completed",0x2501);
  _free_work(&work_local,"cgminer.c","work_completed",0x2503);
  return;
}

