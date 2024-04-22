
/* WARNING: Variable defined which should be unmapped: ms-local */

void ms_to_timeval(timeval *val,int64_t ms)

{
  undefined4 in_r2;
  undefined4 in_r3;
  int64_t ms_local;
  timeval *val_local;
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,1000,CONCAT44(in_r3,in_r2));
  val->tv_sec = (__time_t)tvdiv.quot;
  val->tv_usec = (int)tvdiv.rem * 1000;
  return;
}

