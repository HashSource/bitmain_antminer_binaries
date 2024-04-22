
undefined1 * create_tuning_info(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  FILE *__stream;
  int local_c;
  
  uVar1 = get_asic_num_per_chain();
  uVar2 = get_asic_num_per_vol_domain();
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: asic_num_per_chain = %d, asic_num_per_vol_domain = %d\n",
              "board_frq_tuning.c",0x2e5,uVar1,uVar2);
    }
    fclose(__stream);
  }
  memset(g_freq_info,0,0x585dc);
  memset(g_freq_info_all_vol_level,0,0x1b9d4c);
  scan_vol_level_num = 0;
  pattern_file_fd = 0;
  g_freq_info[361944] = g_is_low_power_hashrate_scan;
  g_freq_info._0_4_ = uVar1;
  g_freq_info._4_4_ = uVar2;
  memset(g_freq_info + 0x54008,0,0x40);
  memcpy(g_freq_info + 8,last_success_freq,0x4000);
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    *(undefined4 *)(g_freq_info + (local_c + 0x15012) * 4) =
         *(undefined4 *)(g_freq_info + local_c * 0x400 + 8);
    g_freq_info[local_c + 0x58588] = 0;
  }
  return g_freq_info;
}

