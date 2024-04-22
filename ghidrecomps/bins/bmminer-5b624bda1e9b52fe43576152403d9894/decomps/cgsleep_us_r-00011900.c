
/* WARNING: Variable defined which should be unmapped: ts_end */

void cgsleep_us_r(cgtimer_t *ts_start,int64_t us)

{
  timespec ts_end;
  
  us_to_timespec(&ts_end,(int64_t)ts_end);
  timeraddspec(&ts_end,ts_start);
  nanosleep_abstime(&ts_end);
  return;
}

