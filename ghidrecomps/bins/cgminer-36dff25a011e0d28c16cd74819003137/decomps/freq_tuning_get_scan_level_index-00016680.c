
int freq_tuning_get_scan_level_index(freq_tuning_info *freq_info,int freq)

{
  int freq_local;
  freq_tuning_info *freq_info_local;
  int scan_level_index;
  
  scan_level_index = 0;
  while( true ) {
    if (7 < scan_level_index) {
      freq_info->scan_level_table[0] = freq;
      return 0;
    }
    if (freq == freq_info->scan_level_table[scan_level_index]) break;
    if (freq_info->scan_level_table[scan_level_index] == 0) {
      freq_info->scan_level_table[scan_level_index] = freq;
      return scan_level_index;
    }
    scan_level_index = scan_level_index + 1;
  }
  return scan_level_index;
}

