
/* WARNING: Variable defined which should be unmapped: us-local */

void cgsleep_us_r(cgtimer_t *ts_start,int64_t us)

{
  undefined4 in_r2;
  undefined4 in_r3;
  int64_t us_local;
  cgtimer_t *ts_start_local;
  timespec ts_end;
  
  us_to_timespec(&ts_end,CONCAT44(in_r3,in_r2));
  timeraddspec(&ts_end,ts_start);
  nanosleep_abstime(&ts_end);
  return;
}

