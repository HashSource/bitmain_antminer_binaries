
double getAVGhashrate(void)

{
  return ((total_mhashes_done - new_total_mhashes_done) / DAT_00019158) /
         (total_secs - new_total_secs);
}

