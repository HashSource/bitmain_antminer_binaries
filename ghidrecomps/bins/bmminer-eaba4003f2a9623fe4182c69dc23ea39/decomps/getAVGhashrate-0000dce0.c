
/* WARNING: Unknown calling convention */

double getAVGhashrate(void)

{
  return ((total_mhashes_done - new_total_mhashes_done) / DAT_0000dd38) /
         (total_secs - new_total_secs);
}

