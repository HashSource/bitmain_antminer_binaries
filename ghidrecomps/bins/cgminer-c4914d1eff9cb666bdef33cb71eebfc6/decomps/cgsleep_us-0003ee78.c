
/* WARNING: Variable defined which should be unmapped: us-local */

void cgsleep_us(int64_t us)

{
  undefined4 in_r0;
  undefined4 in_r1;
  int64_t us_local;
  cgtimer_t ts_start;
  
  cgtimer_time(&ts_start);
  cgsleep_us_r(&ts_start,CONCAT44(in_r1,in_r0));
  return;
}

