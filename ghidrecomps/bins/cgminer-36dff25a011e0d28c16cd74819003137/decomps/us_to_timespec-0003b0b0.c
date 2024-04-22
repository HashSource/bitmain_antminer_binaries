
/* WARNING: Variable defined which should be unmapped: us-local */

void us_to_timespec(timespec *spec,int64_t us)

{
  undefined4 in_r2;
  undefined4 in_r3;
  int64_t us_local;
  timespec *spec_local;
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,1000000,CONCAT44(in_r3,in_r2));
  spec->tv_sec = (__time_t)tvdiv.quot;
  spec->tv_nsec = (int)tvdiv.rem * 1000;
  return;
}

