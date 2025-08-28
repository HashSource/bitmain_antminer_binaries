
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void re_calculate_AVG(void)

{
  new_total_mhashes_done._0_4_ = total_mhashes_done._0_4_;
  new_total_mhashes_done._4_4_ = total_mhashes_done._4_4_;
  if (total_secs <= 0.0) {
    new_total_secs = total_secs;
  }
  else {
    new_total_secs = total_secs - 1.0;
  }
  return;
}

