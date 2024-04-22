
/* WARNING: Unknown calling convention */

void re_calculate_AVG(void)

{
  double dVar1;
  
  new_total_mhashes_done._0_4_ = total_mhashes_done._0_4_;
  new_total_mhashes_done._4_4_ = total_mhashes_done._4_4_;
  dVar1 = (double)CONCAT44(total_secs._4_4_,total_secs._0_4_);
  if (dVar1 == 0.0 || dVar1 < 0.0 != NAN(dVar1)) {
    new_total_secs = (double)CONCAT44(total_secs._4_4_,total_secs._0_4_);
  }
  else {
    new_total_secs = (double)CONCAT44(total_secs._4_4_,total_secs._0_4_) - 1.0;
  }
  return;
}

