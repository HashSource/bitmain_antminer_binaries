
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void freq_tuning_done_mark(void)

{
  system("touch /config/scanfreqdone");
  return;
}

