
void cgsleep_us(int64_t us)

{
  int64_t us_local;
  cgtimer_t ts_start;
  
  cgtimer_time(&ts_start);
  cgsleep_us_r(&ts_start,us);
  return;
}

