
/* WARNING: Unknown calling convention */

double get_AVG_hashrate(void)

{
  return ((total_mhashes_done - new_total_mhashes_done) / 1000.0) / (total_secs - new_total_secs);
}

