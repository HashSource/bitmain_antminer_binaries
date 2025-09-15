
void us_to_timeval(timeval *val,int64_t us)

{
  lldiv_t tvdiv;
  
  lldiv((lldiv_t *)&tvdiv,us,1000000);
  val->tv_sec = (__time_t)tvdiv.quot;
  val->tv_usec = (__suseconds_t)tvdiv.rem;
  return;
}

