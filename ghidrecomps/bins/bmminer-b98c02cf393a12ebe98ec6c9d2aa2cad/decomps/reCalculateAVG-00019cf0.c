
void reCalculateAVG(void)

{
  new_total_mhashes_done._0_4_ = (undefined4)total_mhashes_done;
  new_total_mhashes_done._4_4_ = total_mhashes_done._4_4_;
  if (total_secs != 0.0 && total_secs < 0.0 == NAN(total_secs)) {
    new_total_secs = total_secs - 1.0;
    return;
  }
  new_total_secs = total_secs;
  return;
}

