
/* WARNING: Unknown calling convention */

void freq_tuning_done_mark(void)

{
  system("touch /config/scanfreqdone");
  return;
}

