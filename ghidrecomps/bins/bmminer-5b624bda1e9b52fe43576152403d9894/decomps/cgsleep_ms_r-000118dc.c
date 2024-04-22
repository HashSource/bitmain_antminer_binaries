
/* WARNING: Variable defined which should be unmapped: ts_end */
/* WARNING: Unknown calling convention */

void cgsleep_ms_r(cgtimer_t *ts_start,int ms)

{
  timespec ts_end;
  
  ms_to_timespec(&ts_end,(int64_t)ts_end);
  timeraddspec(&ts_end,ts_start);
  nanosleep_abstime(&ts_end);
  return;
}

