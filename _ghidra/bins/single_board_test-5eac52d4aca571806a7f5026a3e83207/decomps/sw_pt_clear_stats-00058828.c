
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sw_pt_clear_stats(void)

{
  memset(&g_rt.stats,0,0xc54);
  return;
}

