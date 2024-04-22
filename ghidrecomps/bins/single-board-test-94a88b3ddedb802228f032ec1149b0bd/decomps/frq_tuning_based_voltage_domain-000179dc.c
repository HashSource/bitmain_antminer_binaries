
void frq_tuning_based_voltage_domain(int param_1,undefined4 param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_c;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: single_board_frq_tuning2 loop_num, freq_step:%d, %d\n",
              "board_frq_tuning.c",0x6fc,param_1,param_2);
    }
    fclose(pFVar1);
  }
  uVar2 = create_tuning_info();
  local_c = 0;
  while( true ) {
    if (param_1 <= local_c) break;
    board_init_all_chain(uVar2);
    init_scan_freq_table(uVar2,param_2);
    set_vol_and_frq_all_chain(uVar2);
    uVar3 = get_min_scan_freq(uVar2);
    set_time_control_by_frq(uVar3);
    highest_voltage_open_core_all_chain(uVar2);
    start_send_work_and_check_result_all_chain(uVar2);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: tuning %d times\n","board_frq_tuning.c",0x714,local_c + 1);
      }
      fclose(pFVar1);
    }
    local_c = local_c + 1;
  }
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      set_asic_quality_per_domain(uVar2,local_c);
      set_freq_table(uVar2,local_c);
    }
  }
  print_freq_table(uVar2);
  saving_tunning_result(uVar2);
  destroy_tuning_info(uVar2);
  return;
}

