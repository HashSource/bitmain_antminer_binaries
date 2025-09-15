
void us_to_timespec(timespec *spec,int64_t us)

{
  int64_t us_local;
  timespec *spec_local;
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,us,1000000);
  spec->tv_sec = (__time_t)tvdiv.quot;
  spec->tv_nsec = (int)tvdiv.rem * 1000;
  return;
}

