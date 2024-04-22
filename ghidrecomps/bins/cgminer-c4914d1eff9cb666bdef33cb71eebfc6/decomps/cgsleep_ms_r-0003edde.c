
/* WARNING: Variable defined which should be unmapped: ms-local */

void cgsleep_ms_r(cgtimer_t *ts_start,int ms)

{
  int ms_local;
  cgtimer_t *ts_start_local;
  timespec ts_end;
  
  ms_to_timespec(&ts_end,CONCAT44(ts_start,ms));
  timeraddspec(&ts_end,ts_start);
  nanosleep_abstime(&ts_end);
  return;
}

