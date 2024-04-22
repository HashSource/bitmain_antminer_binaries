
/* WARNING: Unknown calling convention */

void scan_freq_reset_scan_info(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      scanfreq_info.test_done[chain] = false;
      scanfreq_info.current_column[chain] = '\0';
      scanfreq_info.need_init = false;
      memset(scanfreq_info.domain_freq_level + chain,0,10);
      memset(scanfreq_info.current_column_finish + chain,0,10);
      memset(scanfreq_info.chip_max_freq + chain,0,0x400);
      memset(scanfreq_info.final_chip_freq + chain,0,0x400);
      memset(scanfreq_info.chip_rate + chain,0,0x400);
      memset(scanfreq_info.chip_sweep_failed + chain,0,0x100);
    }
  }
  return;
}

