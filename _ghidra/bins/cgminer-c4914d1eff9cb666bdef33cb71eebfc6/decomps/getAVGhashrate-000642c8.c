
/* WARNING: Unknown calling convention */

double getAVGhashrate(void)

{
  return ((total_mhashes_done - new_total_mhashes_done) / 1000.0) / (total_secs - new_total_secs);
}

