
void board_init_all_chain(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  FILE *pFVar4;
  int local_10;
  int local_c;
  
LAB_00014be4:
  start_pic_heart = 0;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  puts("clement2 init_fpga");
  reset_fpga();
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  send_pic_heart_once();
  start_pic_heart = 1;
  reset_global_arg();
  start_receive = 1;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  reset_crc_count(0);
  puts("\n--- set command mode");
  if (conf._40_4_ == 0) {
    puts("clement2 set_dhash_acc_control vil");
    uVar2 = get_dhash_acc_control();
    set_dhash_acc_control(uVar2 & 0xffff7edf | 0x8100);
    cgpu._2562268_4_ = 0;
    if (3 < log_level) {
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d: set command mode to VIL\n","board_frq_tuning.c",0x38a);
      }
      fclose(pFVar4);
    }
  }
  else {
    cgpu._2562268_4_ = 1;
    puts("set command mode to FIL");
  }
  iVar3 = is_S9_Hydro();
  if (iVar3 != 0) {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      if ((((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
           (iVar3 = get_board_index_S9_Hydro(local_c,0),
           *(char *)(param_1 + iVar3 + 0x58588) == '\0')) &&
          (bVar1 = getPICvoltageFromValue(0x3a2), T9_18_noboard_retry_count < 1)) && (3 < log_level)
         ) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d: set voltage=%d[%d] on chain[%d] to init ...\n","board_frq_tuning.c"
                  ,0x397,0x3a2,(uint)bVar1,local_c);
        }
        fclose(pFVar4);
      }
    }
  }
  local_c = 0;
  do {
    if (0xf < local_c) {
LAB_00015122:
      check_asic_num_flag_7504 = 1;
      isChipNumOK_Once = 1;
      puts("clement software_set_address");
      software_set_address();
      conf._24_4_ = 0;
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d: set_baud=%d\n","board_frq_tuning.c",0x3e4,conf._24_4_);
        }
        fclose(pFVar4);
      }
      set_baud(conf._24_4_ & 0xff);
      return;
    }
    iVar3 = is_S9_Hydro();
    if (iVar3 == 0) {
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
         (*(char *)(local_c + param_1 + 0x58588) == '\0')) {
        board_init(local_c);
      }
    }
    else {
      if (check_asic_num_flag_7504 != '\0') goto LAB_00015122;
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
         (iVar3 = get_board_index_S9_Hydro(local_c,0), *(char *)(param_1 + iVar3 + 0x58588) == '\0')
         ) {
        check_asic_reg_oneChain(local_c,CHIP_ADDRESS & 0xff);
        if (3 < log_level) {
          pFVar4 = fopen(log_file,"a+");
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d: check chain[%d]: asicNum = %d\n","board_frq_tuning.c",0x3aa,
                    local_c,(uint)(byte)cgpu[local_c + 0x271924]);
          }
          fclose(pFVar4);
        }
        if (cgpu[local_c + 0x271924] != 'T') break;
      }
    }
    local_c = local_c + 1;
  } while( true );
  T9_18_noboard_retry_count = T9_18_noboard_retry_count + 1;
  if (6 < T9_18_noboard_retry_count) {
    isNoBoardError = 1;
    if (3 < log_level) {
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d: The AsicNum=%d on chain[%d]\n","board_frq_tuning.c",0x3bc,
                (uint)(byte)cgpu[local_c + 0x271924],local_c);
      }
      fclose(pFVar4);
    }
    testDone[local_c] = 1;
    search_over[local_c] = 1;
    *(undefined4 *)(searchFreqMode + local_c * 4) = 0x19;
    search_freq_result[local_c] = 0;
    if (isChipNumOK_Once == '\0') {
      sprintf(search_failed_info,"J%d:2",local_c + 1);
    }
    else {
      sprintf(search_failed_info,"J%d:3",local_c + 1);
    }
    saveSearchFailedFlagInfo();
    searchStatus = 2;
    do {
      processTEST();
      sleep(1);
    } while( true );
  }
  if (3 < log_level) {
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d: The AsicNum=%d on chain[%d], retrycounter=%d\n","board_frq_tuning.c",
              0x3b2,(uint)(byte)cgpu[local_c + 0x271924],local_c,T9_18_noboard_retry_count);
    }
    fclose(pFVar4);
  }
  for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
    cgpu[local_10 + 0x271924] = 0;
  }
  goto LAB_00014be4;
}

