
void singleBoardTest(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_124;
  undefined4 local_120;
  FILE *local_11c;
  FILE *local_118;
  FILE *local_114;
  FILE *local_110;
  FILE *local_10c;
  FILE *local_108;
  FILE *local_104;
  FILE *local_100;
  FILE *local_fc;
  FILE *local_f8;
  FILE *local_f4;
  FILE *local_f0;
  FILE *local_ec;
  FILE *local_e8;
  FILE *local_e4;
  FILE *local_e0;
  FILE *local_dc;
  FILE *local_d8;
  FILE *local_d4;
  FILE *local_d0;
  FILE *local_cc;
  FILE *local_c8;
  FILE *local_c4;
  FILE *local_c0;
  int local_bc;
  FILE *local_b8;
  FILE *local_b4;
  FILE *local_b0;
  undefined local_a9;
  FILE *local_a8;
  FILE *local_a4;
  undefined4 local_a0;
  FILE *local_9c;
  FILE *local_98;
  FILE *local_94;
  FILE *local_90;
  FILE *local_8c;
  FILE *local_88;
  FILE *local_84;
  FILE *local_80;
  FILE *local_7c;
  FILE *local_78;
  FILE *local_74;
  FILE *local_70;
  FILE *local_6c;
  FILE *local_68;
  FILE *local_64;
  FILE *local_60;
  FILE *local_5c;
  FILE *local_58;
  FILE *local_54;
  FILE *local_50;
  FILE *local_4c;
  undefined local_45;
  FILE *local_44;
  FILE *local_40;
  undefined4 local_3c;
  char local_35;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_1c = 0;
  local_3c = 0;
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if (search_over[local_14] == '\0') {
      testDone[local_14] = 0;
    }
    else {
      testDone[local_14] = 1;
    }
  }
  start_pic_heart = 0;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  puts("clement2 init_fpga");
  reset_fpga();
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  send_pic_heart_once();
  start_pic_heart = 1;
  reset_global_arg();
  start_receive = 1;
  gStartTest = 0;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  reset_crc_count(0);
  if (3 < log_level) {
    local_40 = fopen(log_file,"a+");
    if (local_40 != (FILE *)0x0) {
      uVar2 = get_crc_count();
      fprintf(local_40,"%s:%d: CRC error counter=%d\n","main.c",0x250a,uVar2);
    }
    fclose(local_40);
  }
  puts("\n--- set command mode");
  if (conf._40_4_ == 0) {
    puts("clement2 set_dhash_acc_control vil");
    uVar4 = get_dhash_acc_control();
    set_dhash_acc_control(uVar4 & 0xffff7edf | 0x8100);
    cgpu._2562268_4_ = 0;
    if (3 < log_level) {
      local_44 = fopen(log_file,"a+");
      if (local_44 != (FILE *)0x0) {
        fprintf(local_44,"%s:%d: set command mode to VIL\n","main.c",0x2519);
      }
      fclose(local_44);
    }
  }
  else {
    cgpu._2562268_4_ = 1;
    puts("set command mode to FIL");
  }
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
      local_45 = getPICvoltageFromValue(0x3a2);
      set_pic_voltage(local_14 & 0xff,local_45);
    }
  }
  if (Conf._124_4_ != 0) {
    if (3 < log_level) {
      local_4c = fopen(log_file,"a+");
      if (local_4c != (FILE *)0x0) {
        fprintf(local_4c,"%s:%d: \n--- check asic number\n","main.c",0x2561);
      }
      fclose(local_4c);
    }
    for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
      if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) == 1) && (testDone[local_14] != '\x01')) {
        local_2c = 0;
        check_asic_reg_oneChain(local_14,CHIP_ADDRESS & 0xff);
        if (3 < log_level) {
          local_50 = fopen(log_file,"a+");
          if (local_50 != (FILE *)0x0) {
            fprintf(local_50,"%s:%d: check chain[%d]: asicNum = %d\n","main.c",0x2570,local_14,
                    (uint)(byte)cgpu[local_14 + 0x271924]);
          }
          fclose(local_50);
        }
        while (cgpu[local_14 + 0x271924] != 'T') {
          local_2c = local_2c + 1;
          if (6 < local_2c) {
            local_3c = get_crc_count();
            if (3 < log_level) {
              local_58 = fopen(log_file,"a+");
              if (local_58 != (FILE *)0x0) {
                fprintf(local_58,"%s:%d: After Get ASIC NUM CRC error counter=%d\n","main.c",0x2587,
                        local_3c);
              }
              fclose(local_58);
            }
            isNoBoardError = 1;
            if (3 < log_level) {
              local_5c = fopen(log_file,"a+");
              if (local_5c != (FILE *)0x0) {
                fprintf(local_5c,"%s:%d: The AsicNum=%d on chain[%d]\n","main.c",0x258b,
                        (uint)(byte)cgpu[local_14 + 0x271924],local_14);
              }
              fclose(local_5c);
            }
            testDone[local_14] = 1;
            search_over[local_14] = 1;
            *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
            search_freq_result[local_14] = 0;
            if (isChipNumOK_Once == '\0') {
              sprintf(search_failed_info,"J%d:2",local_14 + 1);
            }
            else {
              sprintf(search_failed_info,"J%d:3",local_14 + 1);
            }
            saveSearchFailedFlagInfo();
            searchStatus = 2;
            do {
              processTEST();
              sleep(1);
            } while( true );
          }
          set_reset_hashboard(local_14,1);
          disable_pic_dac(local_14 & 0xff);
          sleep(1);
          enable_pic_dac(local_14 & 0xff);
          sleep(1);
          set_reset_hashboard(local_14,1);
          sleep(3);
          set_reset_hashboard(local_14,0);
          sleep(1);
          cgpu[local_14 + 0x271924] = 0;
          check_asic_reg_oneChain(local_14,CHIP_ADDRESS & 0xff);
          if (3 < log_level) {
            local_54 = fopen(log_file,"a+");
            if (local_54 != (FILE *)0x0) {
              fprintf(local_54,"%s:%d: retry check chain[%d]: asicNum = %d\n","main.c",0x25b7,
                      local_14,(uint)(byte)cgpu[local_14 + 0x271924]);
            }
            fclose(local_54);
          }
        }
      }
    }
  }
  local_3c = get_crc_count();
  if (3 < log_level) {
    local_60 = fopen(log_file,"a+");
    if (local_60 != (FILE *)0x0) {
      fprintf(local_60,"%s:%d: After Get ASIC NUM CRC error counter=%d\n","main.c",0x25c1,local_3c);
    }
    fclose(local_60);
  }
  isChipNumOK_Once = 1;
  puts("clement software_set_address");
  software_set_address();
  conf._24_4_ = 0;
  if (3 < log_level) {
    local_64 = fopen(log_file,"a+");
    if (local_64 != (FILE *)0x0) {
      fprintf(local_64,"%s:%d: set_baud=%d\n","main.c",0x25d8,conf._24_4_);
    }
    fclose(local_64);
  }
  set_baud(conf._24_4_ & 0xff);
  if (7 < log_level) {
    local_68 = fopen(log_file,"a+");
    if (local_68 != (FILE *)0x0) {
      fprintf(local_68,"%s:%d: checking MISC_CONTROL\n","main.c",0x25db);
    }
    fclose(local_68);
  }
  check_asic_reg(MISC_CONTROL & 0xff);
  local_20 = 700;
  local_24 = 300;
  local_14 = 0;
  do {
    if (0xf < (int)local_14) {
      if (first_freq != '\0') {
        first_freq = '\0';
      }
      local_a0 = calculate_core_number(0x72);
      iVar3 = __aeabi_idiv(0x1000000,local_a0);
      iVar3 = __aeabi_idiv(iVar3 << 1,local_20);
      conf._20_4_ = (iVar3 * 7) / 100;
      if (3 < log_level) {
        local_a4 = fopen(log_file,"a+");
        if (local_a4 != (FILE *)0x0) {
          fprintf(local_a4,"%s:%d: The min freq=%d\n","main.c",0x2975,local_20);
        }
        fclose(local_a4);
      }
      if (3 < log_level) {
        local_a8 = fopen(log_file,"a+");
        if (local_a8 != (FILE *)0x0) {
          fprintf(local_a8,"%s:%d: set real timeout %d, need sleep=%d\n","main.c",0x2977,conf._20_4_
                  ,(conf._4_4_ + conf._44_4_) * conf._20_4_);
        }
        fclose(local_a8);
      }
      set_time_out_control(conf._20_4_);
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
          open_core_onChain(local_14,0x72,0x72,1);
          local_a9 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + local_14 * 4));
          set_pic_voltage(local_14 & 0xff,local_a9);
        }
      }
      reset_work_data();
      if (gBegin_get_nonce != '\x01') {
        puts("clement2 set_nonce_fifo_interrupt");
        uVar4 = get_nonce_fifo_interrupt();
        set_nonce_fifo_interrupt(uVar4 | 0x10000);
        gBegin_get_nonce = '\x01';
      }
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
          if (3 < log_level) {
            local_b0 = fopen(log_file,"a+");
            if (local_b0 != (FILE *)0x0) {
              fprintf(local_b0,"%s:%d: start send works on chain[%d]\n","main.c",0x2a1a,local_14);
            }
            fclose(local_b0);
          }
          StartSendFlag[local_14] = 1;
        }
      }
      send_func_all();
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
          if (3 < log_level) {
            local_b4 = fopen(log_file,"a+");
            if (local_b4 != (FILE *)0x0) {
              fprintf(local_b4,"%s:%d: wait recv nonce on chain[%d]\n","main.c",0x2a44,local_14);
            }
            fclose(local_b4);
          }
          local_28 = 0;
          local_1c = 0;
          while ((local_1c < 0x14 &&
                 (*(int *)(valid_nonce_num + local_14 * 4) <
                  *(int *)(chain_ValidNonce + local_14 * 4)))) {
            if (*(int *)(valid_nonce_num + local_14 * 4) == local_28) {
              local_1c = local_1c + 1;
            }
            else {
              local_1c = 0;
              local_28 = *(int *)(valid_nonce_num + local_14 * 4);
            }
            usleep(100000);
          }
        }
      }
      gBegin_get_nonce = 0;
      start_receive = 0;
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
          if (3 < log_level) {
            local_b8 = fopen(log_file,"a+");
            if (local_b8 != (FILE *)0x0) {
              fprintf(local_b8,"%s:%d: get nonces on chain[%d]\n","main.c",0x2a6a,local_14);
            }
            fclose(local_b8);
          }
          get_result(local_14,*(undefined4 *)(chain_PassCount + local_14 * 4),
                     *(undefined4 *)(chain_ValidNonce + local_14 * 4));
        }
      }
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
          switch(*(undefined4 *)(searchFreqMode + local_14 * 4)) {
          case 0:
            SaveAsicCoreEnabledFlagByResultToTempRecord(local_14);
            local_bc = checkBoardState(local_14,*(undefined4 *)(Fmax + local_14 * 4));
            if (local_bc == 0) {
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 1;
              SaveAsicCoreEnabledFlagByResultToLastRecord(local_14);
              CheckRateAndSaveHighestRateRecord(local_14,*(undefined4 *)(Fmax + local_14 * 4));
            }
            else if (local_bc == 1) {
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0;
              *(int *)(chain_Test_Level + local_14 * 4) =
                   *(int *)(chain_Test_Level + local_14 * 4) + 1;
              iVar3 = getBoardTestVoltageAndFreq
                                (*(undefined4 *)(chain_Test_Level + local_14 * 4),&local_124,
                                 &local_120);
              if (iVar3 == -1) {
                if (*(int *)(highest_rate_voltage_value + local_14 * 4) < 1) {
                  if (3 < log_level) {
                    local_c4 = fopen(log_file,"a+");
                    if (local_c4 != (FILE *)0x0) {
                      fprintf(local_c4,
                              "%s:%d: SEARCH_FREQ_TEST_LEVEL level=%d on chain[%d], Error: no highest rate record!\n"
                              ,"main.c",0x300e,*(undefined4 *)(chain_Test_Level + local_14 * 4),
                              local_14);
                    }
                    fclose(local_c4);
                  }
                  search_freq_result[local_14] = 0;
                  sprintf(search_failed_info,"T%d:1",local_14 + 1);
                  saveSearchFailedFlagInfo();
                  searchStatus = 2;
                  do {
                    processTEST();
                    sleep(1);
                  } while( true );
                }
                if (3 < log_level) {
                  local_c0 = fopen(log_file,"a+");
                  if (local_c0 != (FILE *)0x0) {
                    fprintf(local_c0,
                            "%s:%d: SEARCH_FREQ_TEST_LEVEL level=%d on chain[%d], Finished searching freq!\n"
                            ,"main.c",0x2ff8,*(undefined4 *)(chain_Test_Level + local_14 * 4),
                            local_14);
                  }
                  fclose(local_c0);
                }
                copyAsicCoreEnabledFlagFromHighestRateRecord(local_14);
                *(undefined4 *)(chain_vol_value + local_14 * 4) =
                     *(undefined4 *)(highest_rate_voltage_value + local_14 * 4);
                *(undefined4 *)(base_freq_index + local_14 * 4) =
                     *(undefined4 *)(highest_rate_freq + local_14 * 4);
                for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
                  *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4) =
                       *(undefined4 *)(highest_rate_freq + local_14 * 4);
                  *(undefined4 *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) =
                       *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4);
                }
                save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
                search_over[local_14] = 1;
                *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
                testDone[local_14] = 1;
              }
            }
            else if (local_bc == 2) {
              if (3 < log_level) {
                local_c8 = fopen(log_file,"a+");
                if (local_c8 != (FILE *)0x0) {
                  fprintf(local_c8,"%s:%d: SEARCH_FREQ_TEST_LEVEL get BOARD_FREQ_OK on chain[%d]\n",
                          "main.c",0x301f,local_14);
                }
                fclose(local_c8);
              }
              copyAsicCoreEnabledFlagFromTemp(local_14);
              *(undefined4 *)(base_freq_index + local_14 * 4) = *(undefined4 *)(Fmax + local_14 * 4)
              ;
              for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
                *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4) =
                     *(undefined4 *)(Fmax + local_14 * 4);
                *(undefined4 *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) =
                     *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4);
              }
              save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
              search_over[local_14] = 1;
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
              testDone[local_14] = 1;
            }
            else if (3 < log_level) {
              local_cc = fopen(log_file,"a+");
              if (local_cc != (FILE *)0x0) {
                fprintf(local_cc,
                        "%s:%d: Fatal Error: SEARCH_FREQ_TEST_LEVEL mode get wrong state=%d on chain[%d]\n"
                        ,"main.c",0x3031,local_bc,local_14);
              }
              fclose(local_cc);
            }
            break;
          case 1:
            SaveAsicCoreEnabledFlagByResultToTempRecord(local_14);
            local_bc = checkBoardState(local_14,*(undefined4 *)(Fmax + local_14 * 4));
            if (local_bc == 0) {
              if (3 < log_level) {
                local_d0 = fopen(log_file,"a+");
                if (local_d0 != (FILE *)0x0) {
                  fprintf(local_d0,
                          "%s:%d: SEARCH_FREQ_TEST_UPONESTEP get BOARD_NEED_UP_FREQ on chain[%d] to freq=%s\n"
                          ,"main.c",0x303c,local_14,
                          *(undefined4 *)
                           (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10));
                }
                fclose(local_d0);
              }
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 1;
              SaveAsicCoreEnabledFlagByResultToLastRecord(local_14);
              CheckRateAndSaveHighestRateRecord(local_14,*(undefined4 *)(Fmax + local_14 * 4));
            }
            else if (local_bc == 1) {
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0;
              *(int *)(chain_Test_Level + local_14 * 4) =
                   *(int *)(chain_Test_Level + local_14 * 4) + 1;
              iVar3 = getBoardTestVoltageAndFreq
                                (*(undefined4 *)(chain_Test_Level + local_14 * 4),&local_124,
                                 &local_120);
              if (iVar3 == -1) {
                if (*(int *)(highest_rate_voltage_value + local_14 * 4) < 1) {
                  if (3 < log_level) {
                    local_d8 = fopen(log_file,"a+");
                    if (local_d8 != (FILE *)0x0) {
                      fprintf(local_d8,
                              "%s:%d: SEARCH_FREQ_TEST_UPONESTEP level=%d on chain[%d], Error: no highest rate record!\n"
                              ,"main.c",0x3063,*(undefined4 *)(chain_Test_Level + local_14 * 4),
                              local_14);
                    }
                    fclose(local_d8);
                  }
                  search_freq_result[local_14] = 0;
                  sprintf(search_failed_info,"T%d:1",local_14 + 1);
                  saveSearchFailedFlagInfo();
                  searchStatus = 2;
                  do {
                    processTEST();
                    sleep(1);
                  } while( true );
                }
                if (3 < log_level) {
                  local_d4 = fopen(log_file,"a+");
                  if (local_d4 != (FILE *)0x0) {
                    fprintf(local_d4,
                            "%s:%d: SEARCH_FREQ_TEST_UPONESTEP level=%d on chain[%d], Finished searching freq!\n"
                            ,"main.c",0x304e,*(undefined4 *)(chain_Test_Level + local_14 * 4),
                            local_14);
                  }
                  fclose(local_d4);
                }
                copyAsicCoreEnabledFlagFromHighestRateRecord(local_14);
                *(undefined4 *)(chain_vol_value + local_14 * 4) =
                     *(undefined4 *)(highest_rate_voltage_value + local_14 * 4);
                *(undefined4 *)(base_freq_index + local_14 * 4) =
                     *(undefined4 *)(highest_rate_freq + local_14 * 4);
                for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
                  *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4) =
                       *(undefined4 *)(highest_rate_freq + local_14 * 4);
                  *(undefined4 *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) =
                       *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4);
                }
                save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
                search_over[local_14] = 1;
                *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
                testDone[local_14] = 1;
              }
              else if (3 < log_level) {
                local_dc = fopen(log_file,"a+");
                if (local_dc != (FILE *)0x0) {
                  fprintf(local_dc,
                          "%s:%d: SEARCH_FREQ_TEST_UPONESTEP get SEARCH_FREQ_TEST_LEVEL on chain[%d] level=%d\n"
                          ,"main.c",0x3073,local_14,*(undefined4 *)(chain_Test_Level + local_14 * 4)
                         );
                }
                fclose(local_dc);
              }
            }
            else if (local_bc == 2) {
              if (3 < log_level) {
                local_e0 = fopen(log_file,"a+");
                if (local_e0 != (FILE *)0x0) {
                  fprintf(local_e0,
                          "%s:%d: SEARCH_FREQ_TEST_UPONESTEP get BOARD_FREQ_OK on chain[%d]\n",
                          "main.c",0x3078,local_14);
                }
                fclose(local_e0);
              }
              copyAsicCoreEnabledFlagFromTemp(local_14);
              *(undefined4 *)(base_freq_index + local_14 * 4) = *(undefined4 *)(Fmax + local_14 * 4)
              ;
              for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
                *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4) =
                     *(undefined4 *)(Fmax + local_14 * 4);
                *(undefined4 *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) =
                     *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4);
              }
              save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
              search_over[local_14] = 1;
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
              testDone[local_14] = 1;
            }
            else if (3 < log_level) {
              local_e4 = fopen(log_file,"a+");
              if (local_e4 != (FILE *)0x0) {
                fprintf(local_e4,
                        "%s:%d: Fatal Error: SEARCH_FREQ_TEST_UPONESTEP mode get wrong state=%d on chain[%d]\n"
                        ,"main.c",0x308a,local_bc,local_14);
              }
              fclose(local_e4);
            }
            break;
          default:
            *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
            search_over[local_14] = 1;
            testDone[local_14] = 1;
            if (3 < log_level) {
              local_110 = fopen(log_file,"a+");
              if (local_110 != (FILE *)0x0) {
                fprintf(local_110,"%s:%d: Fatal Error: unkown search mode=%d on chain[%d]\n",
                        "main.c",0x319f,*(undefined4 *)(searchFreqMode + local_14 * 4),local_14);
              }
              fclose(local_110);
            }
            break;
          case 0x14:
            iVar3 = last_all_pass(local_14);
            if (iVar3 == 0) {
              if ((*(int *)(Fmax + local_14 * 4) < 0x56) ||
                 (0x379 < *(int *)(chain_vol_value + local_14 * 4))) {
                iVar3 = tryFixAsicCoreEnabledFlagByResult_searchMode
                                  (local_14,*(undefined4 *)(Fmax + local_14 * 4));
                if (iVar3 == 0) {
                  *(undefined4 *)(base_freq_index + local_14 * 4) =
                       *(undefined4 *)(Fmax + local_14 * 4);
                  if (3 < log_level) {
                    local_f4 = fopen(log_file,"a+");
                    if (local_f4 != (FILE *)0x0) {
                      fprintf(local_f4,
                              "%s:%d: ALLCHIP_FREQ_UP freq=%s on chain[%d]: FAILED! will Enter FAILED_CHIP_DOWN\n"
                              ,"main.c",0x3162,
                              *(undefined4 *)
                               (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14
                             );
                    }
                    fclose(local_f4);
                  }
                  *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x15;
                }
                else {
                  UpdateTestResultFlag(local_14,0x390);
                  if (3 < log_level) {
                    local_f0 = fopen(log_file,"a+");
                    if (local_f0 != (FILE *)0x0) {
                      fprintf(local_f0,
                              "%s:%d: ALLCHIP_FREQ_UP freq=%s on chain[%d]: FAILED! will fix bad core num and continue ALLCHIP_FREQ_UP\n"
                              ,"main.c",0x3157,
                              *(undefined4 *)
                               (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14
                             );
                    }
                    fclose(local_f0);
                  }
                  PrintAsicCoreEnabledFlag(local_14);
                  *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
                  *(undefined4 *)(base_freq_index + local_14 * 4) =
                       *(undefined4 *)(Fmax + local_14 * 4);
                }
              }
              else {
                *(undefined4 *)(base_freq_index + local_14 * 4) =
                     *(undefined4 *)(Fmax + local_14 * 4);
                if (3 < log_level) {
                  local_ec = fopen(log_file,"a+");
                  if (local_ec != (FILE *)0x0) {
                    fprintf(local_ec,
                            "%s:%d: ALLCHIP_FREQ_UP freq=%s on chain[%d]: FAILED! will Enter FAILED_CHIP_DOWN\n"
                            ,"main.c",0x316b,
                            *(undefined4 *)
                             (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14);
                  }
                  fclose(local_ec);
                }
                *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x15;
              }
            }
            else {
              if (3 < log_level) {
                local_e8 = fopen(log_file,"a+");
                if (local_e8 != (FILE *)0x0) {
                  fprintf(local_e8,
                          "%s:%d: ALLCHIP_FREQ_UP freq=%s on chain[%d]: OK! will up one step\n",
                          "main.c",0x314a,
                          *(undefined4 *)
                           (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14);
                }
                fclose(local_e8);
              }
              *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
              *(undefined4 *)(base_freq_index + local_14 * 4) = *(undefined4 *)(Fmax + local_14 * 4)
              ;
            }
            break;
          case 0x15:
            iVar3 = last_all_pass(local_14);
            if (iVar3 == 0) {
              if (3 < log_level) {
                local_fc = fopen(log_file,"a+");
                if (local_fc != (FILE *)0x0) {
                  fprintf(local_fc,
                          "%s:%d: FAILED_CHIP_DOWN Fmax=%s on chain[%d]: FAILED! will Enter DOWN_CHIP_ONEBYONE\n"
                          ,"main.c",0x317b,
                          *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                          local_14);
                }
                fclose(local_fc);
              }
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x16;
            }
            else {
              if (3 < log_level) {
                local_f8 = fopen(log_file,"a+");
                if (local_f8 != (FILE *)0x0) {
                  fprintf(local_f8,
                          "%s:%d: FAILED_CHIP_DOWN Fmax=%s on chain[%d]: OK! will Enter SUCCESS_CHIP_UP!\n"
                          ,"main.c",0x3174,
                          *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                          local_14);
                }
                fclose(local_f8);
              }
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x17;
              *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
            }
            break;
          case 0x16:
            iVar3 = last_all_pass(local_14);
            if (iVar3 == 0) {
              if (3 < log_level) {
                local_104 = fopen(log_file,"a+");
                if (local_104 != (FILE *)0x0) {
                  fprintf(local_104,
                          "%s:%d: DOWN_CHIP_ONEBYONE Fmax=%s on chain[%d]: FAILED! will continue down\n"
                          ,"main.c",0x318a,
                          *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                          local_14);
                }
                fclose(local_104);
              }
            }
            else {
              if (3 < log_level) {
                local_100 = fopen(log_file,"a+");
                if (local_100 != (FILE *)0x0) {
                  fprintf(local_100,
                          "%s:%d: DOWN_CHIP_ONEBYONE Fmax=%s on chain[%d]: OK! will Enter SUCCESS_CHIP_UP!\n"
                          ,"main.c",0x3183,
                          *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                          local_14);
                }
                fclose(local_100);
              }
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x17;
              *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
            }
            break;
          case 0x17:
            iVar3 = last_all_pass(local_14);
            if (iVar3 == 0) {
              if (3 < log_level) {
                local_10c = fopen(log_file,"a+");
                if (local_10c != (FILE *)0x0) {
                  fprintf(local_10c,
                          "%s:%d: SUCCESS_CHIP_UP Fmax=%s on chain[%d]: FAILED! will Enter FAILED_CHIP_DOWN\n"
                          ,"main.c",0x3196,
                          *(undefined4 *)
                           (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14);
                }
                fclose(local_10c);
              }
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x15;
            }
            else {
              if (3 < log_level) {
                local_108 = fopen(log_file,"a+");
                if (local_108 != (FILE *)0x0) {
                  fprintf(local_108,
                          "%s:%d: SUCCESS_CHIP_UP freq=%s on chain[%d]: OK! will continue up!\n",
                          "main.c",0x3190,
                          *(undefined4 *)
                           (freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),local_14);
                }
                fclose(local_108);
              }
              *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
            }
          }
          iVar3 = last_all_pass(local_14);
          if ((iVar3 != 0) && (testDone[local_14] != '\x01')) {
            for (local_18 = 0; local_18 < 0x100; local_18 = local_18 + 1) {
              *(undefined4 *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) =
                   *(undefined4 *)(last_freq + (local_18 + local_14 * 0x100) * 4);
            }
            if (3 < log_level) {
              local_114 = fopen(log_file,"a+");
              if (local_114 != (FILE *)0x0) {
                fprintf(local_114,"%s:%d: Record: success freq records on Chain[%d]\n","main.c",
                        0x31ab,local_14);
              }
              fclose(local_114);
            }
            if (0x54 < *(int *)(Fmax + local_14 * 4)) {
              if (3 < log_level) {
                local_118 = fopen(log_file,"a+");
                if (local_118 != (FILE *)0x0) {
                  fprintf(local_118,"%s:%d: Search Freq > %sM on Chain[%d], stop and record freq\n",
                          "main.c",0x31bd,
                          *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                          local_14);
                }
                fclose(local_118);
              }
              save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
              search_over[local_14] = 1;
              *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
              testDone[local_14] = 1;
            }
          }
        }
      }
      local_3c = get_crc_count();
      if (3 < log_level) {
        local_11c = fopen(log_file,"a+");
        if (local_11c != (FILE *)0x0) {
          fprintf(local_11c,"%s:%d: After TEST CRC error counter=%d\n","main.c",0x31c9,local_3c);
        }
        fclose(local_11c);
      }
      if ((conf._144_4_ != 0) && (cVar1 = check_fan(), cVar1 != '\x01')) {
        search_failed_info._0_4_ = DAT_001320d4;
        saveSearchFailedFlagInfo();
        searchStatus = 2;
        do {
          processTEST();
          sleep(1);
        } while( true );
      }
      set_reset_allhashboard(1);
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
          disable_pic_dac(local_14 & 0xff);
        }
      }
      sleep(1);
      for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
        if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
          enable_pic_dac(local_14 & 0xff);
        }
      }
      sleep(1);
      set_reset_allhashboard(0);
      return;
    }
    local_30 = 0;
    local_34 = 0;
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (testDone[local_14] == '\0')) {
      switch(*(undefined4 *)(searchFreqMode + local_14 * 4)) {
      case 0:
        getBoardTestVoltageAndFreq
                  (*(undefined4 *)(chain_Test_Level + local_14 * 4),&local_124,&local_120);
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x390;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x12b40;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x390;
        *(undefined4 *)(Fmax + local_14 * 4) = local_120;
        *(undefined4 *)(chain_vol_value + local_14 * 4) = local_124;
        *(undefined4 *)(chain_vol_added + local_14 * 4) = 0;
        local_45 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + local_14 * 4));
        if (3 < log_level) {
          local_6c = fopen(log_file,"a+");
          if (local_6c != (FILE *)0x0) {
            fprintf(local_6c,
                    "%s:%d: SEARCH_FREQ_TEST_LEVEL mode set freq=%s voltage=%d on chain[%d]\n",
                    "main.c",0x2690,
                    *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                    *(undefined4 *)(chain_vol_value + local_14 * 4),local_14);
          }
          fclose(local_6c);
        }
        for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
          *(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4) =
               *(undefined4 *)(Fmax + local_14 * 4);
          set_frequency_with_addr_plldatai
                    (*(undefined4 *)(Fmax + local_14 * 4),0,(local_30 & 0x7f) << 1,local_14 & 0xff);
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (iVar3 < local_20) {
            local_20 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (local_24 < iVar3) {
            local_24 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
        }
        break;
      case 1:
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x390;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x12b40;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x390;
        *(int *)(Fmax + local_14 * 4) = *(int *)(Fmax + local_14 * 4) + 1;
        local_45 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + local_14 * 4));
        if (3 < log_level) {
          local_70 = fopen(log_file,"a+");
          if (local_70 != (FILE *)0x0) {
            fprintf(local_70,
                    "%s:%d: SEARCH_FREQ_TEST_UPONESTEP mode set freq=%s voltage=%d on chain[%d]\n",
                    "main.c",0x26ab,
                    *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),
                    *(undefined4 *)(chain_vol_value + local_14 * 4),local_14);
          }
          fclose(local_70);
        }
        for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
          *(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4) =
               *(undefined4 *)(Fmax + local_14 * 4);
          set_frequency_with_addr_plldatai
                    (*(undefined4 *)(Fmax + local_14 * 4),0,(local_30 & 0x7f) << 1,local_14 & 0xff);
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (iVar3 < local_20) {
            local_20 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (local_24 < iVar3) {
            local_24 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
        }
        break;
      default:
        *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
        search_over[local_14] = 1;
        testDone[local_14] = 1;
        if (3 < log_level) {
          local_9c = fopen(log_file,"a+");
          if (local_9c != (FILE *)0x0) {
            fprintf(local_9c,"%s:%d: Fatal Error: unkown search mode=%d on chain[%d]\n","main.c",
                    0x2962,*(undefined4 *)(searchFreqMode + local_14 * 4),local_14);
          }
          fclose(local_9c);
        }
        break;
      case 0x14:
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x390;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x12b40;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x390;
        if (3 < log_level) {
          local_74 = fopen(log_file,"a+");
          if (local_74 != (FILE *)0x0) {
            fprintf(local_74,"%s:%d: ALLCHIP_FREQ_UP mode Fmax+1=%s on chain[%d]\n","main.c",0x28a9,
                    *(undefined4 *)(freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),
                    local_14);
          }
          fclose(local_74);
        }
        for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
          *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) =
               *(int *)(Fmax + local_14 * 4) + 1;
          set_frequency_with_addr_plldatai
                    (*(int *)(Fmax + local_14 * 4) + 1,0,(local_30 & 0x7f) << 1,local_14 & 0xff);
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (iVar3 < local_20) {
            local_20 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (local_24 < iVar3) {
            local_24 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
        }
        break;
      case 0x15:
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x72;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x2568;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x72;
        if (3 < log_level) {
          local_78 = fopen(log_file,"a+");
          if (local_78 != (FILE *)0x0) {
            fprintf(local_78,"%s:%d: FAILED_CHIP_DOWN mode Fmax+1=%s on chain[%d]\n","main.c",0x28bc
                    ,*(undefined4 *)(freq_pll_1385 + (*(int *)(Fmax + local_14 * 4) + 1) * 0x10),
                    local_14);
          }
          fclose(local_78);
        }
        local_35 = '\0';
        for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
          if ((*(int *)(last_result + (local_30 + local_14 * 0x100) * 4) == 0) &&
             (*(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) ==
              *(int *)(Fmax + local_14 * 4) + 1)) {
            local_35 = '\x01';
            *(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4) =
                 *(undefined4 *)(Fmax + local_14 * 4);
          }
        }
        if (local_35 == '\0') {
          if (3 < log_level) {
            local_7c = fopen(log_file,"a+");
            if (local_7c != (FILE *)0x0) {
              fprintf(local_7c,
                      "%s:%d: FAILED_CHIP_DOWN mode Fmax=%s There is no chip can down on chain[%d], Will enter DOWN_CHIP_ONEBYONE\n"
                      ,"main.c",0x28db,
                      *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),local_14
                     );
            }
            fclose(local_7c);
          }
          *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x16;
          testDone[local_14] = 1;
        }
        else {
          for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
            set_frequency_with_addr_plldatai
                      (*(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4),0,
                       (local_30 & 0x7f) << 1,local_14 & 0xff);
            iVar3 = atoi(*(char **)(freq_pll_1385 +
                                   *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
            if (iVar3 < local_20) {
              local_20 = atoi(*(char **)(freq_pll_1385 +
                                        *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) *
                                        0x10));
            }
            iVar3 = atoi(*(char **)(freq_pll_1385 +
                                   *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
            if (local_24 < iVar3) {
              local_24 = atoi(*(char **)(freq_pll_1385 +
                                        *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) *
                                        0x10));
            }
          }
        }
        break;
      case 0x16:
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x72;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x2568;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x72;
        if (3 < log_level) {
          local_80 = fopen(log_file,"a+");
          if (local_80 != (FILE *)0x0) {
            fprintf(local_80,"%s:%d: DOWN_CHIP_ONEBYONE mode Fmax=%s on chain[%d]\n","main.c",0x28e7
                    ,*(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),local_14)
            ;
          }
          fclose(local_80);
        }
        local_35 = '\0';
        for (local_30 = 0; (int)local_30 < 3; local_30 = local_30 + 1) {
          for (local_34 = 0; local_34 < 0x1c; local_34 = local_34 + 1) {
            if (*(int *)(last_freq + (local_34 * 3 + local_30 + local_14 * 0x100) * 4) ==
                *(int *)(Fmax + local_14 * 4) + 1) {
              *(undefined4 *)(last_freq + (local_34 * 3 + local_30 + local_14 * 0x100) * 4) =
                   *(undefined4 *)(Fmax + local_14 * 4);
              local_35 = '\x01';
              break;
            }
          }
          if (local_35 != '\0') break;
        }
        if (local_35 == '\x01') {
          for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
            set_frequency_with_addr_plldatai
                      (*(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4),0,
                       (local_30 & 0x7f) << 1,local_14 & 0xff);
            iVar3 = atoi(*(char **)(freq_pll_1385 +
                                   *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
            if (iVar3 < local_20) {
              local_20 = atoi(*(char **)(freq_pll_1385 +
                                        *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) *
                                        0x10));
            }
            iVar3 = atoi(*(char **)(freq_pll_1385 +
                                   *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
            if (local_24 < iVar3) {
              local_24 = atoi(*(char **)(freq_pll_1385 +
                                        *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) *
                                        0x10));
            }
          }
        }
        else if (*(int *)(last_success_freq + local_14 * 0x400) < 1) {
          if (3 < log_level) {
            local_88 = fopen(log_file,"a+");
            if (local_88 != (FILE *)0x0) {
              fprintf(local_88,
                      "%s:%d: DOWN_CHIP_ONEBYONE Fatal Error: there is no Fmax+1 chip on chain[%d], and no last successful freq, and exit!\n"
                      ,"main.c",0x290c,local_14);
            }
            fclose(local_88);
          }
          search_freq_result[local_14] = 0;
          *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
          search_over[local_14] = 1;
          testDone[local_14] = 1;
        }
        else {
          if (3 < log_level) {
            local_84 = fopen(log_file,"a+");
            if (local_84 != (FILE *)0x0) {
              fprintf(local_84,
                      "%s:%d: DOWN_CHIP_ONEBYONE there is no Fmax+1 chip on chain[%d], record last successful freq, and exit!\n"
                      ,"main.c",0x2902,local_14);
            }
            fclose(local_84);
          }
          save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
          search_over[local_14] = 1;
          *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
          testDone[local_14] = 1;
        }
        break;
      case 0x17:
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x72;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x2568;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x72;
        if (3 < log_level) {
          local_8c = fopen(log_file,"a+");
          if (local_8c != (FILE *)0x0) {
            fprintf(local_8c,"%s:%d: SUCCESS_CHIP_UP mode Fmax=%s on chain[%d]\n","main.c",0x292a,
                    *(undefined4 *)(freq_pll_1385 + *(int *)(Fmax + local_14 * 4) * 0x10),local_14);
          }
          fclose(local_8c);
        }
        local_35 = '\0';
        for (local_30 = 0; (int)local_30 < 0x54; local_30 = local_30 + 1) {
          if (*(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) ==
              *(int *)(Fmax + local_14 * 4)) {
            *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) =
                 *(int *)(Fmax + local_14 * 4) + 1;
            local_35 = '\x01';
          }
          set_frequency_with_addr_plldatai
                    (*(undefined4 *)(last_freq + (local_30 + local_14 * 0x100) * 4),0,
                     (local_30 & 0x7f) << 1,local_14 & 0xff);
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (iVar3 < local_20) {
            local_20 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
          iVar3 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10));
          if (local_24 < iVar3) {
            local_24 = atoi(*(char **)(freq_pll_1385 +
                                      *(int *)(last_freq + (local_30 + local_14 * 0x100) * 4) * 0x10
                                      ));
          }
        }
        if (local_35 != '\x01') {
          if (*(int *)(last_success_freq + local_14 * 0x400) < 1) {
            if (3 < log_level) {
              local_94 = fopen(log_file,"a+");
              if (local_94 != (FILE *)0x0) {
                fprintf(local_94,
                        "%s:%d: SUCCESS_CHIP_UP Fatal Error: there is no chip can up on chain[%d], and no last successful freq, and exit!\n"
                        ,"main.c",0x294f,local_14);
              }
              fclose(local_94);
            }
            search_freq_result[local_14] = 0;
            *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
            search_over[local_14] = 1;
            testDone[local_14] = 1;
          }
          else {
            if (3 < log_level) {
              local_90 = fopen(log_file,"a+");
              if (local_90 != (FILE *)0x0) {
                fprintf(local_90,
                        "%s:%d: SUCCESS_CHIP_UP there is no chip can up on chain[%d], record last successful freq, and exit!\n"
                        ,"main.c",0x2946,local_14);
              }
              fclose(local_90);
            }
            save_freq_toPIC(local_14,last_success_freq + local_14 * 0x400);
            search_over[local_14] = 1;
            *(undefined4 *)(searchFreqMode + local_14 * 4) = 0x19;
            testDone[local_14] = 1;
          }
        }
        break;
      case 0x19:
        testDone[local_14] = 1;
        if (3 < log_level) {
          local_98 = fopen(log_file,"a+");
          if (local_98 != (FILE *)0x0) {
            fprintf(local_98,"%s:%d: search over on chain[%d]\n","main.c",0x295c,local_14);
          }
          fclose(local_98);
        }
      }
    }
    local_14 = local_14 + 1;
  } while( true );
}

