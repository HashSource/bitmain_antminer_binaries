
void ms_to_timespec(timespec *spec,int64_t ms)

{
  int64_t ms_local;
  timespec *spec_local;
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,ms,1000);
  spec->tv_sec = (__time_t)tvdiv.quot;
  spec->tv_nsec = (int)tvdiv.rem * 1000000;
  return;
}

