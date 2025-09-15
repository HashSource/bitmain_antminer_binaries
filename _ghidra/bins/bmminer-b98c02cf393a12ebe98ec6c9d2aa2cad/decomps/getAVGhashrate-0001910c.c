
undefined4 getAVGhashrate(void)

{
  return SUB84(((total_mhashes_done - new_total_mhashes_done) / 1000.0) /
               (total_secs - new_total_secs),0);
}

