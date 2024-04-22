
void freq_tuning_pattern_test_serial
               (freq_tuning_info *freq_info,int chain,int level_start,int level_cnt,
               int sub_proj_index)

{
  int iVar1;
  int level_cnt_local;
  int level_start_local;
  int chain_local;
  freq_tuning_info *freq_info_local;
  int freq;
  int voltage;
  FILE *pFile_1;
  FILE *pFile;
  int level_end;
  int init_freq;
  int curr_scan_level;
  
  level_end = level_start + level_cnt;
  init_freq = g_init_freq;
  curr_scan_level = level_start;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: serial pattern test start: chain[%d]\n","freq_tuning.c",0xa1f
              ,"freq_tuning_pattern_test_serial",chain);
    }
    fclose((FILE *)pFile);
  }
  freq_tuning_set_fake_done_for_other_chain(freq_info,chain);
  do {
    if (level_end <= curr_scan_level) break;
    freq_tuning_reset_global_arg();
    iVar1 = freq_tuning_get_board_test_voltage_and_freq
                      (curr_scan_level,&voltage,&freq,sub_proj_index);
    if (iVar1 == -1) break;
    freq_info->vol_value_table[chain] = voltage;
    freq_info->scan_freq[chain] = freq;
    increase_freq_slowly
              ((float)(longlong)init_freq,(float)(longlong)freq_info->scan_freq[chain],
               (float)(longlong)DAT_0001bd2c,(uint8_t)chain);
    init_freq = freq_info->scan_freq[chain];
    freq_tuning_set_time_control_by_freq(freq_info->scan_freq[chain]);
    freq_tuning_send_work_and_check_result_all_chain(freq_info);
    curr_scan_level = curr_scan_level + 1;
  } while (freq_info->test_done[chain] == false);
  change_high_pll_test((uint8_t)chain,(float)(longlong)g_init_freq,0);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile_1 = (FILE *)fopen(log_file,"a+");
    if (pFile_1 != (FILE *)0x0) {
      fprintf((FILE *)pFile_1,
              "%s:%d:%s: Down to low freq %dM to keep total power under threshold.\n",
              "freq_tuning.c",0xa40,"freq_tuning_pattern_test_serial",g_init_freq);
    }
    fclose((FILE *)pFile_1);
  }
  freq_tuning_clear_fake_done(freq_info);
  return;
}

