
int main(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  sysinfo sStack_d4;
  FILE *local_94;
  FILE *local_90;
  FILE *local_8c;
  FILE *local_88;
  FILE *local_84;
  undefined4 local_80;
  FILE *local_7c;
  FILE *local_78;
  FILE *local_74;
  int local_70;
  FILE *local_6c;
  FILE *local_68;
  int local_64;
  FILE *local_60;
  FILE *local_5c;
  FILE *local_58;
  undefined4 local_54;
  FILE *local_50;
  FILE *local_4c;
  FILE *local_48;
  FILE *local_44;
  FILE *local_40;
  int local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  FILE *local_20;
  char local_19;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  curl_global_init(3);
  setStartTimePoint();
  signal(0x11,(__sighandler_t)0x1);
  local_20 = fopen("/tmp/search","w");
  if (local_20 != (FILE *)0x0) {
    fclose(local_20);
  }
  local_20 = fopen("/tmp/freq","w");
  if (local_20 != (FILE *)0x0) {
    fclose(local_20);
  }
  local_20 = fopen("/tmp/lasttemp","w");
  if (local_20 != (FILE *)0x0) {
    fclose(local_20);
  }
  if (param_1 == 2) {
    log_level = atoi(*(char **)(param_2 + 4));
  }
  if (1 < log_level) {
    local_24 = fopen(log_file,"a+");
    if (local_24 != (FILE *)0x0) {
      fprintf(local_24,"%s:%d: log_level = %d\n","main.c",13999,log_level);
    }
    fclose(local_24);
  }
  iVar2 = isC5_Board();
  if (iVar2 == 0) {
    sysinfo(&sStack_d4);
    if (3 < log_level) {
      local_2c = fopen(log_file,"a+");
      if (local_2c != (FILE *)0x0) {
        fprintf(local_2c,"%s:%d: This is XILINX board. Totalram:       %ld\n","main.c",0x36ca,
                sStack_d4.totalram);
      }
      fclose(local_2c);
    }
    if (sStack_d4.totalram < 0x3b9aca01) {
      if (sStack_d4.totalram < 0x1dcd6501) {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
        if (3 < log_level) {
          local_38 = fopen(log_file,"a+");
          if (local_38 != (FILE *)0x0) {
            fprintf(local_38,"%s:%d: Detect 256MB control board of XILINX\n","main.c",0x36dc);
          }
          fclose(local_38);
        }
      }
      else {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
        if (3 < log_level) {
          local_34 = fopen(log_file,"a+");
          if (local_34 != (FILE *)0x0) {
            fprintf(local_34,"%s:%d: Detect 512MB control board of XILINX\n","main.c",0x36d6);
          }
          fclose(local_34);
        }
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
      if (3 < log_level) {
        local_30 = fopen(log_file,"a+");
        if (local_30 != (FILE *)0x0) {
          fprintf(local_30,"%s:%d: Detect 1GB control board of XILINX\n","main.c",0x36d0);
        }
        fclose(local_30);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      local_28 = fopen(log_file,"a+");
      if (local_28 != (FILE *)0x0) {
        fprintf(local_28,"%s:%d: This is C5 board.\n","main.c",0x36bd);
      }
      fclose(local_28);
    }
  }
  local_3c = cgpu_init();
  if (local_3c < 0) {
    puts("cgpu_init Error!");
  }
  else {
    local_3c = configMiner();
    if (-1 < local_3c) {
      detectFPGAversion();
      read_fpga_id(FPGA_ID_str);
      if (3 < log_level) {
        local_40 = fopen(log_file,"a+");
        if (local_40 != (FILE *)0x0) {
          fprintf(local_40,"%s:%d: miner ID : %s\n","main.c",0x36f7,FPGA_ID_str);
        }
        fclose(local_40);
      }
      if (conf._144_4_ != 0) {
        system(
              "cp /www/pages/cgi-bin/minerConfiguration2.cgi /www/pages/cgi-bin/minerConfiguration.cgi -f"
              );
        system("sync");
        if (3 < log_level) {
          local_44 = fopen(log_file,"a+");
          if (local_44 != (FILE *)0x0) {
            fprintf(local_44,"%s:%d: config file found, will disable freq setting.\n","main.c",
                    0x3702);
          }
          fclose(local_44);
        }
      }
      puts("single board test start");
      if (3 < log_level) {
        local_48 = fopen(log_file,"a+");
        if (local_48 != (FILE *)0x0) {
          fprintf(local_48,"%s:%d: Miner Type = S9+\n","main.c",0x3714);
        }
        fclose(local_48);
      }
      if (3 < log_level) {
        local_4c = fopen(log_file,"a+");
        if (local_4c != (FILE *)0x0) {
          fprintf(local_4c,"%s:%d: AsicType = %d\n","main.c",0x371c,0x56b);
        }
        fclose(local_4c);
      }
      if (3 < log_level) {
        local_50 = fopen(log_file,"a+");
        if (local_50 != (FILE *)0x0) {
          fprintf(local_50,"%s:%d: real AsicNum = %d\n","main.c",0x371f,0x54);
        }
        fclose(local_50);
      }
      local_54 = get_plldata_i(0x56b,conf._16_4_);
      conf._0_4_ = 0x72;
      Conf._72_4_ = 0x72;
      conf._4_4_ = 0x72;
      Conf._76_4_ = 0x72;
      conf._8_4_ = 0x72;
      Conf._80_4_ = 0x72;
      conf._12_4_ = 0x72;
      Conf._84_4_ = 0x72;
      conf._44_4_ = 0x1c0e;
      Conf._132_4_ = 0x1c0e;
      conf._48_4_ = 0x1c0e;
      Conf._136_4_ = 0x1c0e;
      conf._52_4_ = 0x1c0e;
      Conf._140_4_ = 0x1c0e;
      for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          *(undefined4 *)(last_result + (local_14 + local_10 * 0x100) * 4) = 0;
          *(undefined4 *)(last_freq + (local_14 + local_10 * 0x100) * 4) = local_54;
          *(undefined4 *)(last_success_freq + (local_14 + local_10 * 0x100) * 4) = 0;
        }
        *(undefined4 *)(search_freq_chances + local_10 * 4) = 2;
        search_over[local_10] = 0;
        search_freq_result[local_10] = 1;
        *(undefined4 *)(chain_Test_Level + local_10 * 4) = 0;
        *(undefined4 *)(searchFreqMode + local_10 * 4) = 0;
        *(undefined4 *)(Fmax + local_10 * 4) = local_54;
        *(undefined4 *)(base_freq_index + local_10 * 4) = 0;
        testDone[local_10] = 0;
        *(undefined4 *)(chain_vol_value + local_10 * 4) = 0;
        *(undefined4 *)(chain_vol_added + local_10 * 4) = 0;
        *(undefined4 *)(testModeOKCounter + local_10 * 4) = 0;
        *(undefined4 *)(chain_DataCount + local_10 * 4) = 0x390;
        *(undefined4 *)(chain_ValidNonce + local_10 * 4) = 0x12b40;
        *(undefined4 *)(chain_PassCount + local_10 * 4) = 0x390;
        chip_temp_offset[local_10] = 0xba;
      }
      cgpu._2562260_4_ = 0;
      first_freq = 1;
      searchStatus = 0;
      ExitServer = 0;
      StartHttpThread();
      checkSearchFailedFlagInfo();
      Conf._120_4_ = 0;
      ExitFlag = 0;
      receiveExit = '\0';
      pthread_create(DAT_0003361c,(pthread_attr_t *)0x0,receive_func + 1,cgpu);
      if (3 < log_level) {
        local_58 = fopen(log_file,"a+");
        if (local_58 != (FILE *)0x0) {
          fprintf(local_58,"%s:%d: use critical mode to search freq...\n","main.c",0x377c);
        }
        fclose(local_58);
      }
      for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
        StartSendFlag[local_10] = 0;
      }
      picheartExit = '\0';
      pthread_create(DAT_00033620,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,cgpu);
      InitAsicCoreEnabledFlag();
      PreparePICandVoltage();
      init_exist_chain_table();
      if (conf._144_4_ != 0) {
        power_init();
        power_tuning();
      }
      cVar1 = is_S9_plus();
      if (cVar1 != '\x01') {
        cVar1 = is_S9_Hydro();
        if ((cVar1 != '\x01') && (cVar1 = is_S9i(), cVar1 != '\x01')) {
          do {
            local_c = local_c + 1;
            singleBoardTest();
            if (3 < log_level) {
              local_5c = fopen(log_file,"a+");
              if (local_5c != (FILE *)0x0) {
                uVar3 = numSearchCompleted();
                fprintf(local_5c,
                        "%s:%d: search freq for %d times, completed chain = %d, total chain num = %d \n"
                        ,"main.c",0x37a3,local_c,uVar3,cgpu._2562260_4_);
              }
              fclose(local_5c);
            }
            cVar1 = isAllSearchOver();
          } while (cVar1 != '\x01');
          cVar1 = isAllSearchSuccess();
          if (cVar1 != '\x01') {
            if (3 < log_level) {
              local_60 = fopen(log_file,"a+");
              if (local_60 != (FILE *)0x0) {
                fprintf(local_60,"%s:%d: \nMode B Process Over! Result: FAILED!\n","main.c",0x37a9);
              }
              fclose(local_60);
            }
            searchStatus = 2;
            do {
              processTEST();
              sleep(1);
            } while( true );
          }
        }
      }
      local_19 = '\x01';
      iVar2 = is_S9();
      if ((iVar2 != 0) && (iVar2 = single_board_frq_tuning(0x35e8,14000,0x370), iVar2 != 0)) {
        local_19 = '\0';
      }
      iVar2 = is_S9_plus();
      if ((((iVar2 != 0) || (iVar2 = is_S9_Hydro(), iVar2 != 0)) || (iVar2 = is_S9i(), iVar2 != 0))
         && (conf._144_4_ != 0)) {
        cVar1 = check_fan();
        if (cVar1 != '\x01') {
          stop_scan(&DAT_001320d4);
        }
        iVar2 = is_S9_Hydro();
        if ((iVar2 == 0) && (iVar2 = is_S9i(), iVar2 == 0)) {
          multi_test_based_voltage_domain();
        }
        else {
          single_board_test_based_voltage_domain();
        }
        local_19 = '\0';
      }
      if (conf._144_4_ != 0) {
        uVar3 = getSearchCostTime();
        PostSearchTimeToServer(uVar3);
        set_PWM(100);
        setStartTimePoint();
        if (local_19 != '\0') {
          DownFreqAccordingToHashrate();
        }
        PostRateVoltageToServer();
        save_fixed_FreqAndCoreNum_toPIC();
        ClearForceFreq();
        uVar3 = getSearchCostTime();
        PostTestPattenTimeToServer(uVar3);
        local_64 = GetTotalRate();
        if (3 < log_level) {
          local_68 = fopen(log_file,"a+");
          if (local_68 != (FILE *)0x0) {
            fprintf(local_68,"%s:%d: Total rate = %d\n","main.c",0x37f6,local_64);
          }
          fclose(local_68);
        }
        if (local_64 < 1000) {
          if (3 < log_level) {
            local_6c = fopen(log_file,"a+");
            if (local_6c != (FILE *)0x0) {
              uVar3 = GetTotalRate();
              fprintf(local_6c,"%s:%d: Failed: Hashrate is too low, hashrate = %d < %d \n","main.c",
                      0x37fa,uVar3,1000);
            }
            fclose(local_6c);
          }
          search_failed_info._0_4_ = DAT_00132c78;
          saveSearchFailedFlagInfo();
          searchStatus = 2;
          do {
            processTEST();
            sleep(1);
          } while( true );
        }
      }
      local_70 = readRebootTestNum();
      if (local_70 == 0xd05) {
        if (3 < log_level) {
          local_74 = fopen(log_file,"a+");
          if (local_74 != (FILE *)0x0) {
            fprintf(local_74,
                    "%s:%d: \n Hashrate too Low : < 98%% ideal rate, BIMMINER TEST Result: FAILED!\n"
                    ,"main.c",0x3907);
          }
          fclose(local_74);
        }
        search_failed_info._0_4_ = DAT_00132880;
        saveSearchFailedFlagInfo();
        searchStatus = 2;
        do {
          processTEST();
          sleep(1);
        } while( true );
      }
      if (local_70 < 1) {
        set_reset_allhashboard(1);
        sleep(3);
        set_reset_allhashboard(0);
        sleep(1);
        local_80 = readRestartNum();
        if (3 < log_level) {
          local_84 = fopen(log_file,"a+");
          if (local_84 != (FILE *)0x0) {
            fprintf(local_84,"%s:%d: restart Miner chance num=%d\n","main.c",0x3935,local_80);
          }
          fclose(local_84);
        }
        isFailedOnTestPatten = '\0';
      }
      else {
        set_reset_allhashboard(1);
        sleep(3);
        set_reset_allhashboard(0);
        sleep(1);
        set_PWM(100);
        if (conf._144_4_ == 0) {
          if (3 < log_level) {
            local_7c = fopen(log_file,"a+");
            if (local_7c != (FILE *)0x0) {
              fprintf(local_7c,"%s:%d: rebootTestNum=%d, start bmminer.\n","main.c",0x3928,local_70)
              ;
            }
            fclose(local_7c);
          }
        }
        else if (3 < log_level) {
          local_78 = fopen(log_file,"a+");
          if (local_78 != (FILE *)0x0) {
            fprintf(local_78,"%s:%d: rebootTestNum=%d, reboot system.\n","main.c",0x3923,local_70);
          }
          fclose(local_78);
        }
      }
      set_PWM(100);
      close(cgpu._600_4_);
      cgpu._600_4_ = 0xffffffff;
      ExitFlag = 1;
      for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
        StartSendFlag[local_10] = 0;
      }
      if (3 < log_level) {
        local_88 = fopen(log_file,"a+");
        if (local_88 != (FILE *)0x0) {
          fprintf(local_88,"%s:%d: waiting for receive_func to exit!\n","main.c",0x395d);
        }
        fclose(local_88);
      }
      local_18 = 0;
      do {
        if (receiveExit == '\x01') goto LAB_00033a4a;
        local_18 = local_18 + 1;
        usleep(1000000);
      } while (local_18 < 4);
      pthread_cancel(cgpu._512_4_);
LAB_00033a4a:
      if (3 < log_level) {
        local_8c = fopen(log_file,"a+");
        if (local_8c != (FILE *)0x0) {
          fprintf(local_8c,"%s:%d: waiting for pic heart to exit!\n","main.c",0x396b);
        }
        fclose(local_8c);
      }
      local_18 = 0;
      do {
        if (picheartExit == '\x01') goto LAB_00033ae6;
        local_18 = local_18 + 1;
        usleep(1000000);
      } while (local_18 < 4);
      pthread_cancel(cgpu._520_4_);
LAB_00033ae6:
      if (isFailedOnTestPatten != '\x01') {
        if (IsSomeBoardHasNoFreq == '\0') {
          searchStatus = 1;
        }
        else {
          searchStatus = 2;
        }
        freeWorks();
        do {
          cVar1 = check_bmminer("bmminer");
          if (cVar1 != '\x01') {
            if (3 < log_level) {
              local_90 = fopen(log_file,"a+");
              if (local_90 != (FILE *)0x0) {
                fprintf(local_90,"%s:%d: bmminer not found, restart bmminer ...\n","main.c",0x3997);
              }
              fclose(local_90);
            }
            system("/usr/bin/killall -9 bmminer");
            sleep(1);
            system(
                  "/usr/bin/bmminer --version-file /usr/bin/compile_time --api-listen --default-config /config/bmminer.conf &"
                  );
          }
          sleep(3);
        } while( true );
      }
      if (3 < log_level) {
        local_94 = fopen(log_file,"a+");
        if (local_94 != (FILE *)0x0) {
          fprintf(local_94,"%s:%d: \nMode B : After searchfreq, TestPatten Result: FAILED!\n",
                  "main.c",0x39a8);
        }
        fclose(local_94);
      }
      searchStatus = 2;
      do {
        processTEST();
        sleep(1);
      } while( true );
    }
    puts("configMiner Error!");
  }
  return local_3c;
}

