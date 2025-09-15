
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reCalculateAVG(void)

{
  new_total_mhashes_done = total_mhashes_done;
  if (0.0 < total_secs) {
    new_total_secs = total_secs - 1.0;
    return;
  }
  new_total_secs = total_secs;
  return;
}

