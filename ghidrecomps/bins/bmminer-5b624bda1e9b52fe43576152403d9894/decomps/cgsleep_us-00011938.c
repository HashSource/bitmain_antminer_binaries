
/* WARNING: Variable defined which should be unmapped: ts_start */

void cgsleep_us(int64_t us)

{
  cgtimer_t ts_start;
  
  cgtimer_time(&ts_start);
  cgsleep_us_r(&ts_start,(int64_t)ts_start);
  return;
}

