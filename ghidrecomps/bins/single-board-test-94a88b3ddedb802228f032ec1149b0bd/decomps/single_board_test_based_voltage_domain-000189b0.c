
void single_board_test_based_voltage_domain(void)

{
  char cVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined local_11;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: single_board_test_based_voltage_domain enter\n","board_frq_tuning.c",
              0x825);
    }
    fclose(pFVar2);
  }
  uVar3 = create_tuning_info();
  local_c = 0;
  local_11 = 1;
  do {
    if (0x13 < local_c) goto LAB_00018af0;
    board_init_all_chain(uVar3);
    cVar1 = get_next_test_voltage_and_freq(uVar3,local_11);
    if (cVar1 != '\x01') goto LAB_00018af0;
    local_11 = 0;
    set_vol_and_frq_all_chain(uVar3);
    uVar4 = get_min_scan_freq(uVar3);
    set_time_control_by_frq(uVar4);
    highest_voltage_open_core_all_chain(uVar3);
    iVar5 = check_temperature_high();
    if (iVar5 != 0) {
      stop_scan("temp high");
    }
    start_send_work_and_check_result_all_chain(uVar3);
    local_c = local_c + 1;
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: single board test %d times ","board_frq_tuning.c",0x848,local_c);
      }
      fclose(pFVar2);
    }
    iVar5 = check_test_process(uVar3);
  } while (iVar5 == 0);
  push_info_when_new_voltage(uVar3,g_freq_info_all_vol_level,0,0);
LAB_00018af0:
  if (0x13 < local_c) {
    stop_scan("over times");
  }
  for (local_10 = 0; local_10 < scan_vol_level_num; local_10 = local_10 + 1) {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
         ((iVar5 = is_S9_Hydro(), iVar5 == 0 ||
          (iVar5 = get_board_index_S9_Hydro(local_c,0), iVar5 == local_c)))) {
        set_asic_quality_per_domain(g_freq_info_all_vol_level + local_10 * 0x585dc,local_c);
        set_freq_table(g_freq_info_all_vol_level + local_10 * 0x585dc,local_c);
      }
    }
    get_ideal_hash_rate(g_freq_info_all_vol_level + local_10 * 0x585dc);
  }
  get_best_freq_info(uVar3,g_freq_info_all_vol_level,scan_vol_level_num);
  print_chip_rate_table(uVar3);
  print_freq_table(uVar3);
  saving_tunning_result(uVar3);
  return;
}

