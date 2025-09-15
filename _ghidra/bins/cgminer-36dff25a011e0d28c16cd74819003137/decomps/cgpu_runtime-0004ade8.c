
double cgpu_runtime(cgpu_info *cgpu)

{
  cgpu_info *cgpu_local;
  timeval now;
  double dev_runtime;
  
  if ((cgpu->dev_start_tv).tv_sec == 0) {
    dev_runtime = (double)CONCAT44(total_secs._4_4_,total_secs._0_4_);
  }
  else {
    cgtime(&now);
    dev_runtime = tdiff(&now,&cgpu->dev_start_tv);
  }
  if (dev_runtime < 1.0) {
    dev_runtime = 1.0;
  }
  return dev_runtime;
}

