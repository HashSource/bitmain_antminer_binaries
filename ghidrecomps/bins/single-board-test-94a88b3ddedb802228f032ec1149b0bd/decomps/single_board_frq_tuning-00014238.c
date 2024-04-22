
undefined single_board_frq_tuning(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  FILE *local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  FILE *local_28;
  void *local_24;
  FILE *local_20;
  FILE *local_1c;
  FILE *local_18;
  undefined local_11;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    local_18 = fopen(log_file,"a+");
    if (local_18 != (FILE *)0x0) {
      fprintf(local_18,"%s:%d: single_board_frq_tuning enter\n","board_frq_tuning.c",0x277);
    }
    fclose(local_18);
  }
  if (3 < log_level) {
    local_1c = fopen(log_file,"a+");
    if (local_1c != (FILE *)0x0) {
      fprintf(local_1c,"%s:%d: min_rate, des_rate, fix_volt:%d, %d, %d\n","board_frq_tuning.c",0x278
              ,param_1,param_2,param_3);
    }
    fclose(local_1c);
  }
  local_40 = 0;
  local_44 = 0;
  cVar1 = is_need_tuning(param_1,param_2,&local_40,&local_44);
  if (cVar1 == '\x01') {
    if (3 < log_level) {
      local_20 = fopen(log_file,"a+");
      if (local_20 != (FILE *)0x0) {
        fprintf(local_20,"%s:%d: chain_index, board_rate : %d, %d\n","board_frq_tuning.c",0x281,
                local_40,local_44);
      }
      fclose(local_20);
    }
    local_24 = malloc(0x404040);
    if (local_24 == (void *)0x0) {
      local_28 = fopen(log_file,"a+");
      if (local_28 != (FILE *)0x0) {
        fprintf(local_28,"Assert fail!! %s:%d: malloc fail!\n","board_frq_tuning.c",0x285);
      }
      fclose(local_28);
      if (local_24 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("handle != ((void *)0)","board_frq_tuning.c",0x285,"single_board_frq_tuning");
      }
    }
    tuning_backup(local_24);
    local_48 = *(int *)(last_success_freq + local_40 * 0x400);
    if (3 < log_level) {
      local_2c = fopen(log_file,"a+");
      if (local_2c != (FILE *)0x0) {
        fprintf(local_2c,"%s:%d: current board frq : %s\n","board_frq_tuning.c",0x289,
                *(undefined4 *)(freq_pll_1385 + local_48 * 0x10));
      }
      fclose(local_2c);
    }
    local_10 = 0;
    local_4c = param_3;
    while( true ) {
      board_init(local_40);
      cVar1 = get_next_level_vol_and_frq(local_44,&local_4c,&local_48);
      if (cVar1 != '\x01') break;
      if (3 < log_level) {
        local_30 = fopen(log_file,"a+");
        if (local_30 != (FILE *)0x0) {
          fprintf(local_30,"%s:%d: current board frq : %s\n","board_frq_tuning.c",0x29b,
                  *(undefined4 *)(freq_pll_1385 + local_48 * 0x10));
        }
        fclose(local_30);
      }
      set_vol_and_frq(local_40,local_4c,local_48);
      iVar2 = atoi(*(char **)(freq_pll_1385 + local_48 * 0x10));
      set_time_control_by_frq(iVar2);
      highest_voltage_open_core_on_chain(local_40,local_4c);
      start_send_work_and_get_result(local_40);
      local_c = check_result(local_40,local_44);
      local_10 = local_10 + 1;
      if (3 < log_level) {
        local_34 = fopen(log_file,"a+");
        if (local_34 != (FILE *)0x0) {
          fprintf(local_34,"%s:%d: test %d times for chain %d, status = %d\n","board_frq_tuning.c",
                  0x2ab,local_10,local_40,local_c);
        }
        fclose(local_34);
      }
      if ((local_c == 0) || (local_c == 1)) goto LAB_000145fe;
    }
    local_c = 3;
    if (1 < log_level) {
      local_38 = fopen(log_file,"a+");
      if (local_38 != (FILE *)0x0) {
        fprintf(local_38,"%s:%d: cannot get next level of voltage or freqency.","board_frq_tuning.c"
                ,0x297);
      }
      fclose(local_38);
    }
LAB_000145fe:
    local_11 = 1;
    bVar4 = local_c != 0;
    if (bVar4) {
      tuning_restore(local_24,local_40);
    }
    local_11 = !bVar4;
    free(local_24);
    saving_status_after_test(local_40);
    if (3 < log_level) {
      local_3c = fopen(log_file,"a+");
      if (local_3c != (FILE *)0x0) {
        uVar3 = GetTotalRate();
        fprintf(local_3c,"%s:%d: Total rate = %d\n","board_frq_tuning.c",0x2c4,uVar3);
      }
      fclose(local_3c);
    }
  }
  else {
    local_11 = 0;
  }
  return local_11;
}

