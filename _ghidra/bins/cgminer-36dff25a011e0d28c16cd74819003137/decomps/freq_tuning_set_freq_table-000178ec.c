
void freq_tuning_set_freq_table(freq_tuning_info *freq_info,int chain)

{
  void *__ptr;
  FILE *__stream;
  int iVar1;
  int chain_local;
  freq_tuning_info *freq_info_local;
  int sum [8];
  FILE *pFile;
  int *best_freq_of_asic_quality;
  int max_index;
  int asic;
  int scan_level;
  int col;
  
  memset(sum,0,0x20);
  __ptr = malloc(freq_info->asic_num_per_vol_domain << 2);
  if (__ptr != (void *)0x0) {
    for (col = 0; col < freq_info->asic_num_per_vol_domain; col = col + 1) {
      memset(sum,0,0x20);
      for (scan_level = 0; scan_level < 8; scan_level = scan_level + 1) {
        for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
          if (freq_info->asic_quality_per_vol_domain[chain][asic] == col + 1) {
            sum[scan_level] = sum[scan_level] + freq_info->chip_rate_table[chain][scan_level][asic];
          }
        }
      }
      iVar1 = freq_tuning_get_max_index(sum,8);
      *(int *)((int)__ptr + col * 4) = freq_info->scan_level_table[iVar1];
    }
    for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
      freq_info->freq_table[chain][asic] =
           *(int *)((int)__ptr +
                   (freq_info->asic_quality_per_vol_domain[chain][asic] + 0x3fffffff) * 4);
    }
    free(__ptr);
    return;
  }
  print_crt_time_to_file(log_file,1);
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"Assert fail!! %s:%d: Fail to alloc memory for best freq table.\n",
            "freq_tuning.c",0x5ee);
  }
  fclose(__stream);
                    /* WARNING: Subroutine does not return */
  __assert_fail("best_freq_of_asic_quality","freq_tuning.c",0x5ee,"freq_tuning_set_freq_table");
}

