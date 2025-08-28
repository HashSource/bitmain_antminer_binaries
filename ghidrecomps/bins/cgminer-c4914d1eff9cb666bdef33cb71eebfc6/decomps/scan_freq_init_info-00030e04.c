
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scan_freq_init_info(void)

{
  int column;
  int chain;
  
  memset(&scanfreq_info,0,0x88d7f0);
  scanfreq_info.AsicNum = 0x3c;
  scanfreq_info.CoreNum = 0xd0;
  if (test_8pattern == false) {
    scanfreq_info.AsicWorkCount = 0xd0;
  }
  else {
    scanfreq_info.AsicWorkCount = 0x680;
  }
  if (check_column_nonce == false) {
    scanfreq_info.RequiredChainNonce = scanfreq_info.AsicWorkCount * 0x3c;
  }
  else {
    scanfreq_info.RequiredChainNonce = (uint)(scanfreq_info.AsicWorkCount * 0x3c) / 10;
  }
  scanfreq_info.RequiredAsicNonce = scanfreq_info.AsicWorkCount;
  scanfreq_info.PassNonceRate = 0.99;
  builtin_strncpy(scanfreq_info.workdataPathPrefix,"/log/minertest64-BM1393/btc-asic",0x20);
  scanfreq_info.workdataPathPrefix[0x20] = '-';
  scanfreq_info.workdataPathPrefix[0x21] = '\0';
  builtin_strncpy(scanfreq_info.workdataFilePrefix,"/btc-cor",8);
  scanfreq_info.workdataFilePrefix[8] = 'e';
  scanfreq_info.workdataFilePrefix[9] = '-';
  scanfreq_info.workdataFilePrefix[10] = '\0';
  scanfreq_info.freq_step = 5;
  scan_base_freq[0] = g_sweep_config_eco.sweep_max_freq;
  scan_base_freq[1] = g_sweep_config_hpf.sweep_max_freq;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    for (column = 0; column < 10; column = column + 1) {
      scanfreq_info.base_freq_index[chain] = 0;
      scanfreq_info.base_freq[chain] = scan_base_freq[scanfreq_info.base_freq_index[chain]];
      scanfreq_info.freq_index_min[chain][column] = '\0';
      scanfreq_info.freq_index_max[chain][column] = '(';
      scanfreq_info.domain_last_freq_level[chain][column] = '\0';
      scanfreq_info.current_is_pass[chain][column] = true;
    }
  }
  return;
}

