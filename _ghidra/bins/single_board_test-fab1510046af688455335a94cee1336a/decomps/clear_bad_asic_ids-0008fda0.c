
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_bad_asic_ids(void)

{
  g_sweep_bad_asics.bad_asic_num = 0;
  memset(&g_sweep_bad_asics,0,0x404);
  return;
}

