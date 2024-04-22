
void freq_tuning_adjust_result_for_low_temperature(freq_tuning_info *freq_info,int sub_proj_index)

{
  FILE *__stream;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int freq_diff;
  int asic;
  int chain;
  
  freq_diff = 5;
  if (g_env_temp < 30.0 == NAN(g_env_temp)) {
    freq_diff = 0x19;
  }
  else if (((double)g_env_temp < DAT_00019628 != (NAN((double)g_env_temp) || NAN(DAT_00019628))) ||
          (30.0 <= g_env_temp)) {
    if (((double)g_env_temp < DAT_00019630 != (NAN((double)g_env_temp) || NAN(DAT_00019630))) ||
       (DAT_00019628 <= (double)g_env_temp)) {
      if ((g_env_temp < 20.0 != NAN(g_env_temp)) || (DAT_00019630 <= (double)g_env_temp)) {
        if (g_env_temp < 20.0) {
          freq_diff = 5;
        }
      }
      else {
        freq_diff = 10;
      }
    }
    else {
      freq_diff = 0xf;
    }
  }
  else {
    freq_diff = 0x14;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: environment_temp = %.2f, decrease_freq = %d\n","freq_tuning.c",
              0x800,"freq_tuning_adjust_result_for_low_temperature");
    }
    fclose(__stream);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        freq_info->freq_table[chain][asic] = freq_info->freq_table[chain][asic] - freq_diff;
      }
    }
  }
  return;
}

