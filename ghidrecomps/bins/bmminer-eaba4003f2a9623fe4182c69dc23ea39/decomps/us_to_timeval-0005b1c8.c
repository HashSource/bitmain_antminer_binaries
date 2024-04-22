
/* WARNING: Variable defined which should be unmapped: us-local */

void us_to_timeval(timeval *val,int64_t us)

{
  undefined4 in_r2;
  undefined4 in_r3;
  int64_t us_local;
  timeval *val_local;
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,1000000,CONCAT44(in_r3,in_r2));
  val->tv_sec = (__time_t)tvdiv.quot;
  val->tv_usec = (__suseconds_t)tvdiv.rem;
  return;
}

