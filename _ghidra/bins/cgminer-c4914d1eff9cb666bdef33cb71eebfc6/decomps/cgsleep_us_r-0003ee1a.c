
void cgsleep_us_r(cgtimer_t *ts_start,int64_t us)

{
  int64_t us_local;
  cgtimer_t *ts_start_local;
  timespec ts_end;
  
  us_to_timespec(&ts_end,us);
  timeraddspec(&ts_end,ts_start);
  nanosleep_abstime(&ts_end);
  return;
}

