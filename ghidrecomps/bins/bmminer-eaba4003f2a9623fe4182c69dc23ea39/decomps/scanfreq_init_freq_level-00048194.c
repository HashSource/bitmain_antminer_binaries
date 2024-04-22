
/* WARNING: Unknown calling convention */

int scanfreq_init_freq_level(void)

{
  int scan_index [14];
  int chain;
  
  scanfreq_info.MAX_INDEX = 0xd;
  scanfreq_info.MIN_INDEX = 0;
  scanfreq_info.scan_index[0] = 0x12;
  scanfreq_info.scan_index[1] = 0x11;
  scanfreq_info.scan_index[2] = 0x10;
  scanfreq_info.scan_index[3] = 0xf;
  scanfreq_info.scan_index[4] = 0xe;
  scanfreq_info.scan_index[5] = 0xd;
  scanfreq_info.scan_index[6] = 0;
  scanfreq_info.scan_index[7] = 0;
  scanfreq_info.scan_index[8] = 0;
  scanfreq_info.scan_index[9] = 0;
  scanfreq_info.scan_index[10] = 0;
  scanfreq_info.scan_index[11] = 0;
  scanfreq_info.scan_index[12] = 0;
  scanfreq_info.scan_index[13] = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    scanfreq_info.freq_index_max[chain] = scanfreq_info.MAX_INDEX;
    scanfreq_info.freq_index_min[chain] = scanfreq_info.MIN_INDEX;
    scanfreq_info.current_index[chain] = -1;
  }
  return chain;
}

