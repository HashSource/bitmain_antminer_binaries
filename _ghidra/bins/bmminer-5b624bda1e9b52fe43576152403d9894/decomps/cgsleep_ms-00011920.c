
/* WARNING: Unknown calling convention */

void cgsleep_ms(int ms)

{
  cgtimer_t ts_start;
  
  cgtimer_time(&ts_start);
  cgsleep_ms_r(&ts_start,ms);
  return;
}

