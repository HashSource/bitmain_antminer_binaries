
void freq_tuning_pattern_test(freq_tuning_info *freq_info,int sub_proj_index)

{
  bool bVar1;
  _Bool _Var2;
  FILE *pFVar3;
  int freq;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile_1;
  FILE *pFile;
  _Bool all_done;
  int serial_level_count;
  int chain;
  int scan_level;
  _Bool reset_test_level;
  
  reset_test_level = true;
  scan_level = 0;
  serial_level_count = g_BHB91602_proj.conf_list[sub_proj_index].serial_level_count;
  bVar1 = false;
  if ((8 < serial_level_count) && (serial_level_count = 0, 3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Note: serial_level_count > MAX_SCAN_LEVEL.\n","freq_tuning.c",0xa6f,
              "freq_tuning_pattern_test");
    }
    fclose(pFVar3);
  }
  freq_tuning_set_vol_all_chain(sub_proj_index);
  do {
    if (8 - serial_level_count <= scan_level) goto LAB_0001c0e8;
    freq_tuning_reset_global_arg();
    _Var2 = freq_tuning_get_next_test_voltage_and_freq(freq_info,reset_test_level,sub_proj_index);
    if (!_Var2) goto LAB_0001c0e8;
    reset_test_level = false;
    freq_tuning_set_freq_all_chain(freq_info);
    freq = freq_tuning_get_min_freq(freq_info);
    freq_tuning_set_time_control_by_freq(freq);
    freq_tuning_send_work_and_check_result_all_chain(freq_info);
    if ((((sub_proj_index == 0) && (scan_level == 0)) &&
        ((g_BHB91602_proj.conf_list)->base_voltage < (g_BHB91602_proj.conf_list)->max_voltage)) &&
       (_Var2 = freq_tuning_check_domain_unbalance(), _Var2)) {
      freq_info->is_unbalance_happened = true;
      return;
    }
    scan_level = scan_level + 1;
    _Var2 = freq_tuning_check_if_test_done(freq_info);
  } while (!_Var2);
  bVar1 = true;
LAB_0001c0e8:
  if ((!bVar1) && (serial_level_count != 0)) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] != true)) {
        freq_tuning_pattern_test_serial
                  (freq_info,chain,scan_level,serial_level_count,sub_proj_index);
      }
    }
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      freq_tuning_set_asic_quality_per_domain(freq_info,chain);
      freq_tuning_set_freq_table(freq_info,chain);
    }
  }
  freq_tuning_print_chip_rate_table(freq_info);
  freq_tuning_print_freq_table(freq_info);
  freq_tuning_adjust_result_for_low_temperature(freq_info,sub_proj_index);
  freq_tuning_adjust_result_for_high_temperature(freq_info,sub_proj_index);
  freq_tuning_adjust_result_for_J_TH(freq_info,sub_proj_index);
  freq_tuning_adjust_result_for_poor_heat_dissipation(freq_info,sub_proj_index);
  freq_tuning_adjust_result_for_hash_rate_threshold(freq_info,sub_proj_index);
  freq_tuning_set_pass_or_not(freq_info,sub_proj_index);
  if (freq_info->is_pass == true) {
    freq_tuning_get_ideal_hash_rate(freq_info,sub_proj_index);
    freq_tuning_save_result(freq_info,sub_proj_index);
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,
                "%s:%d:%s: Not pass. High frequency may make chip unstable, try to balance domain.\n"
                ,"freq_tuning.c",0xabe,"freq_tuning_pattern_test");
      }
      fclose(pFVar3);
    }
    freq_tuning_pre_open_core(freq_info);
  }
  return;
}

