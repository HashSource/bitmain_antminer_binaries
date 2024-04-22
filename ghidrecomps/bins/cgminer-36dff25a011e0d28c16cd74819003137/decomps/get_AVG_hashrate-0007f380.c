
/* WARNING: Unknown calling convention */

double get_AVG_hashrate(void)

{
  return ((total_mhashes_done - new_total_mhashes_done) / DAT_0007f3e0) /
         (total_secs - new_total_secs);
}

