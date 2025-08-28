
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scan_freq_done_mark(void)

{
  system("touch /config/scanfreqdone");
  return;
}

