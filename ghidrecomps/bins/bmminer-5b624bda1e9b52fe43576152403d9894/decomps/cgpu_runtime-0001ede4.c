
/* WARNING: Unknown calling convention */

double cgpu_runtime(cgpu_info *cgpu)

{
  double dVar1;
  timeval now;
  
  dVar1 = total_secs;
  if ((cgpu->dev_start_tv).tv_sec != 0) {
    cgtime(&now);
    dVar1 = tdiff(&now,&cgpu->dev_start_tv);
  }
  if ((int)((uint)(dVar1 < 1.0) << 0x1f) < 0) {
    dVar1 = 1.0;
  }
  return dVar1;
}

