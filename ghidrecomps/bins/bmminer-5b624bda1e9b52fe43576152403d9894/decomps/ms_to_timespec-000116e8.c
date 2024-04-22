
/* WARNING: Variable defined which should be unmapped: tvdiv */

void ms_to_timespec(timespec *spec,int64_t ms)

{
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,1000,CONCAT44(tvdiv.quot._4_4_,(__time_t)tvdiv.quot));
  spec->tv_sec = (__time_t)tvdiv.quot;
  spec->tv_nsec = (int)tvdiv.rem * 1000000;
  return;
}

