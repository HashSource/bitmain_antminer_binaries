
void cgsleep_ms(int ms)

{
  int ms_local;
  cgtimer_t ts_start;
  
  cgtimer_time(&ts_start);
  cgsleep_ms_r(&ts_start,ms);
  return;
}

