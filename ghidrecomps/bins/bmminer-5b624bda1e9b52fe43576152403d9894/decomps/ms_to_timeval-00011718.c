
/* WARNING: Variable defined which should be unmapped: tvdiv */

void ms_to_timeval(timeval *val,int64_t ms)

{
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,1000,CONCAT44(tvdiv.quot._4_4_,(__time_t)tvdiv.quot));
  val->tv_sec = (__time_t)tvdiv.quot;
  val->tv_usec = (int)tvdiv.rem * 1000;
  return;
}

