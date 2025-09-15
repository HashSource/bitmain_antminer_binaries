
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int bitmain_c5_init(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,uint param_8)

{
  longlong lVar1;
  undefined2 uVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  FILE *pFVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar13;
  char *__format;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  int iVar18;
  int iVar19;
  byte *pbVar20;
  int *piVar21;
  undefined1 *puVar22;
  bool bVar23;
  double dVar24;
  uint local_8c8;
  byte *local_8c4;
  undefined4 *local_8c0;
  int local_8bc;
  undefined1 *local_8b8;
  sysinfo sStack_8a0;
  char local_860 [4];
  undefined *puStack_85c;
  
  opt_multi_version = 1;
  check_config_file();
  iVar6 = readRestartNum();
  saveRebootTestNum(0);
  clearInitLogFile();
  if (iVar6 < 1) {
    if (3 < log_level) {
      pFVar9 = fopen(log_file,"a+");
      if (pFVar9 != (FILE *)0x0) {
        fprintf(pFVar9,"%s:%d:%s: This is the first time running after searching freq!\n",
                "driver-btm-c5.c",0x2fd8,"bitmain_c5_init");
      }
      fclose(pFVar9);
    }
    saveRestartNum(2);
  }
  else if (3 < log_level) {
    pFVar9 = fopen(log_file,"a+");
    if (pFVar9 != (FILE *)0x0) {
      fprintf(pFVar9,"%s:%d:%s: This is user mode for mining\n","driver-btm-c5.c",0x2fdd,
              "bitmain_c5_init");
    }
    fclose(pFVar9);
  }
  iVar7 = isC5_Board();
  isC5_CtrlBoard = (undefined1)iVar7;
  if (iVar7 == 0) {
    sysinfo(&sStack_8a0);
    if (sStack_8a0.totalram < 0x3b9aca01) {
      if (sStack_8a0.totalram < 0x1dcd6501) {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
        if (3 < log_level) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Detect 256MB control board of XILINX\n","driver-btm-c5.c",
                    0x3014,"bitmain_c5_init");
          }
          goto LAB_00038690;
        }
      }
      else {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
        if (3 < log_level) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Detect 512MB control board of XILINX\n","driver-btm-c5.c",
                    0x300e,"bitmain_c5_init");
          }
LAB_00038690:
          fclose(pFVar9);
          if (3 < log_level) {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: Miner Type = S9+\n","driver-btm-c5.c",0x3027,
                      "bitmain_c5_init");
            }
            fclose(pFVar9);
            if (3 < log_level) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-c5.c",
                        0x302e,"bitmain_c5_init",g_miner_compiletime,g_miner_type);
              }
              fclose(pFVar9);
            }
          }
        }
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
      if (3 < log_level) {
        pFVar9 = fopen(log_file,"a+");
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: Detect 1GB control board of XILINX\n","driver-btm-c5.c",0x3008,
                  "bitmain_c5_init");
        }
        goto LAB_00038690;
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      pFVar9 = fopen(log_file,"a+");
      if (pFVar9 != (FILE *)0x0) {
        fprintf(pFVar9,"%s:%d:%s: This is C5 board.\n","driver-btm-c5.c",0x2ff2,"bitmain_c5_init");
      }
      goto LAB_00038690;
    }
  }
  puVar22 = config_parameter;
  config_parameter._16_4_ = param_5;
  config_parameter._20_4_ = param_6;
  config_parameter._24_4_ = param_7;
  config_parameter._28_4_ = param_8;
  config_parameter._0_4_ = param_1;
  config_parameter._4_4_ = param_2;
  config_parameter._8_4_ = param_3;
  config_parameter._12_4_ = param_4;
  if ((param_1 & 0xff) != 0x51) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_860,0x800,"%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
               "bitmain_c5_init",0x51,param_1 & 0xff);
      _applog(7,local_860,0);
      return -1;
    }
    return -1;
  }
  uVar13 = 0xff;
  uVar8 = 0xff;
  uVar14 = 0x51;
  while( true ) {
    uVar14 = uVar13 ^ uVar14;
    uVar13 = (byte)chCRCHTalbe[uVar14] ^ uVar8;
    uVar8 = (uint)(byte)chCRCLTalbe[uVar14];
    if (puVar22 == config_parameter + 0x1d) break;
    puVar22 = puVar22 + 1;
    uVar14 = (uint)(byte)*puVar22;
  }
  uVar13 = uVar13 | uVar8 << 8;
  if (param_8 >> 0x10 != uVar13) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_860,0x800,"%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
               "bitmain_c5_init",param_8 >> 0x10,uVar13);
      _applog(7,local_860,0);
      return -2;
    }
    return -2;
  }
  iVar7 = check_pool_worker();
  if (iVar7 != 0) {
    return iVar7;
  }
  iVar7 = check_pool_for_validation();
  if (iVar7 != 0) {
    return iVar7;
  }
  bitmain_axi_init();
  read_nonce_reg_id = calloc(1,0x40);
  iVar7 = thr_info_create(read_nonce_reg_id,0,0x314e9,read_nonce_reg_id);
  if (iVar7 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_860,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
               "bitmain_c5_init");
      _applog(7,local_860,0);
      return -5;
    }
    return -5;
  }
  pthread_detach(*(pthread_t *)((int)read_nonce_reg_id + 0xc));
  if (opt_fixed_freq != '\0') {
    if (3 < log_level) {
      pFVar9 = fopen(log_file,"a+");
      if (pFVar9 != (FILE *)0x0) {
        fprintf(pFVar9,"%s:%d:%s: config voltage = %d, freq = %d\n","driver-btm-c5.c",0x3058,
                "bitmain_c5_init",opt_bitmain_c5_voltage,config_parameter._12_4_ & 0xffff);
      }
      fclose(pFVar9);
    }
    if (999 < opt_bitmain_c5_voltage) {
      set_fixed_voltage(SUB84((double)(longlong)opt_bitmain_c5_voltage / 100.0,0));
    }
  }
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  if ((int)(config_parameter._4_4_ << 0x1f) < 0) {
    set_QN_write_data_command(0x8080800f);
    sleep(2);
    iVar7 = dev;
    if (is_certification == '\0') {
      *(undefined1 *)(dev + 0x53fc) = 100;
      *(undefined4 *)(iVar7 + 4) = 0x320000;
      set_fan_control(0x320000);
    }
    else {
      *(undefined1 *)(dev + 0x53fc) = 0x14;
      *(undefined **)(iVar7 + 4) = &DAT_000a0028;
      set_fan_control(&DAT_000a0028);
    }
  }
  read_fpga_id(FPGA_ID_str);
  if (3 < log_level) {
    pFVar9 = fopen(log_file,"a+");
    if (pFVar9 != (FILE *)0x0) {
      fprintf(pFVar9,"%s:%d:%s: miner ID : %s\n","driver-btm-c5.c",0x3088,"bitmain_c5_init",
              FPGA_ID_str);
    }
    fclose(pFVar9);
  }
  uVar8 = get_hardware_version();
  fpga_version = uVar8 & 0xff;
  pcb_version = (uVar8 << 1) >> 0x11;
  fpga_major_version = (uVar8 << 0x10) >> 0x18;
  local_8c8 = pcb_version;
  if (is7007_ctrl_board == -1) {
    isC5_Board();
    local_8c8 = pcb_version;
  }
  pcb_version = local_8c8;
  if (is7007_ctrl_board == 1) {
    sprintf(g_miner_version,"%d.%d.%d.%d",fpga_version + (fpga_major_version - 0xb0) * 0x100,
            local_8c8,1,3);
  }
  else {
    sprintf(g_miner_version,"%d.%d.%d.%d",fpga_version + (fpga_major_version - 0xc5) * 0x100,
            local_8c8,1,3);
  }
  set_reset_allhashboard(1);
  iVar7 = PHY_MEM_NONCE2_JOBID_ADDRESS;
  *(undefined1 *)(dev + 0x542f) = 0x1a;
  set_nonce2_and_job_id_store_address(iVar7);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  iVar7 = dev;
  if (is_certification != '\0') {
    sleep(1);
    iVar6 = dev;
    *(undefined **)(dev + 4) = &DAT_000a0028;
    uVar8 = 0;
    *(undefined1 *)(iVar6 + 0x53fc) = 0x14;
    set_fan_control(&DAT_000a0028);
    iVar6 = dev;
    *(undefined1 *)(dev + 0x5442) = 0x14;
    do {
      if (*(int *)(iVar6 + (uVar8 + 2) * 4) == 1) {
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        disable_pic_dac(uVar8 & 0xff);
        pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
        iVar6 = dev;
      }
      iVar7 = dev;
      uVar8 = uVar8 + 1;
    } while (uVar8 != 0x10);
    iVar19 = 0;
    do {
      if (*(int *)(iVar6 + (iVar19 + 2) * 4) == 0) {
        *(undefined1 *)(iVar6 + iVar19 + 0x53ec) = 0;
      }
      else {
        iVar12 = 0;
        uVar8 = 0;
        iVar10 = iVar6 + iVar19 * 0x88;
        *(undefined1 *)(iVar6 + iVar19 + 0x53ec) = 0x54;
        do {
          iVar15 = iVar10 + iVar12;
          if ((uVar8 & 7) == 0) {
            iVar12 = iVar12 + 1;
            *(undefined1 *)(iVar15 + uVar8 + 0x4afc) = 0x20;
          }
          iVar15 = iVar19 * 0x80 + uVar8;
          iVar16 = iVar10 + iVar12;
          iVar18 = iVar16 + uVar8;
          uVar8 = uVar8 + 1;
          iVar15 = iVar6 + (iVar15 + 0x15f) * 8;
          *(undefined1 *)(iVar18 + 0x4afc) = 0x6f;
          *(undefined4 *)(iVar15 + 4) = 0;
          *(undefined4 *)(iVar15 + 8) = 0;
        } while (uVar8 != 0x54);
        *(undefined1 *)(iVar16 + 0x4b50) = 0;
      }
      iVar19 = iVar19 + 1;
      iVar6 = iVar7;
    } while (iVar19 != 0x10);
    sleep(2);
    return 0;
  }
  *(undefined1 *)(dev + 0x53fc) = 100;
  *(undefined4 *)(iVar7 + 4) = 0x320000;
  set_fan_control();
  bVar23 = false;
  local_8b8 = (undefined1 *)0;
  while( true ) {
    check_fan_beforeInit();
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      snprintf(local_860,0x800,"Max fan speed: %d, Min fan speed: %d",*(undefined4 *)(dev + 0x5400),
               *(undefined4 *)(dev + 0x5404));
      _applog(5,local_860,0);
    }
    if ((1 < *(byte *)(dev + 0x53fe)) && (1999 < *(uint *)(dev + 0x5404))) break;
    uVar8 = 0;
    do {
      if (*(int *)(dev + (uVar8 + 2) * 4) == 1) {
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        dsPIC33EP16GS202_reset_pic(uVar8 & 0xff);
        pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != 0x10);
    if ((!bVar23) && (3 < log_level)) {
      pFVar9 = fopen(log_file,"a+");
      if (pFVar9 != (FILE *)0x0) {
        fprintf(pFVar9,"%s:%d:%s: Checking fans...\n","driver-btm-c5.c",0x3125,"bitmain_c5_init");
      }
      fclose(pFVar9);
    }
    iVar19 = (int)local_8b8 + 1;
    iVar7 = iVar19;
    if (100 < iVar19) {
      iVar7 = 1;
    }
    if (iVar19 == 100 || (int)local_8b8 + -99 < 0 != SBORROW4(iVar19,100)) {
      iVar7 = 0;
    }
    if (0 < iVar6) {
      iVar7 = 0;
    }
    if (iVar7 != 0) {
      builtin_strncpy(local_860,"F:1",4);
      saveSearchFailedFlagInfo(local_860);
      system("reboot");
    }
    bVar23 = true;
    cgsleep_ms(1000);
    local_8b8 = (undefined1 *)iVar19;
  }
  if ((use_syslog != '\0') || ((opt_log_output != '\0' || (4 < opt_log_level)))) {
    builtin_strncpy(local_860,"Fan ",4);
    puStack_85c = &DAT_00216b6f;
    _applog(5,local_860,0);
  }
  local_8c0 = (undefined4 *)lowest_testOK_temp;
  local_8bc = 1;
  uVar8 = 0;
  puVar22 = chain_voltage_value;
  local_8b8 = chain_voltage_value;
  puVar17 = chain_pic_buf;
  do {
    if (*(int *)(dev + (uVar8 + 2) * 4) == 1) {
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      dsPIC33EP16GS202_reset_pic(uVar8 & 0xff);
      jump_to_app_CheckAndRestorePIC_T9_18(uVar8);
      if (opt_fixed_freq == '\0') {
        AT24C02_read_bytes_part_7(0,puVar17,uVar8 & 0xff,0x80);
        if (3 < log_level) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Chain[%d] read_freq_badcores : ","driver-btm-c5.c",0x32ea,
                    "bitmain_c5_init",uVar8);
          }
          fclose(pFVar9);
        }
        uVar14 = log_level;
        pbVar20 = puVar17;
        do {
          if (3 < uVar14) {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"0x%02x ",(uint)*pbVar20);
            }
            fclose(pFVar9);
            uVar14 = log_level;
          }
          pbVar20 = pbVar20 + 1;
        } while (pbVar20 != puVar17 + 0x80);
        if (uVar14 < 4) {
          if (opt_economic_mode != '\0') {
LAB_0003a034:
            uVar14 = 0;
            puVar17[1] = puVar17[0x5a];
            pbVar20 = puVar17 + 1;
            *(undefined4 *)(puVar17 + 0x56) = *(undefined4 *)(puVar17 + 0x70);
            do {
              iVar6 = (int)uVar14 >> 2;
              uVar13 = uVar14 & 3;
              uVar14 = uVar14 + 1;
              bVar5 = get_pll_index_for_lowpower_mode
                                ((int)(uint)(byte)chain_pic_buf[uVar8 * 0x80 + iVar6 + 0x5b] >>
                                 (uVar13 << 1) & 3);
              pbVar20 = pbVar20 + 1;
              *pbVar20 = bVar5;
            } while (uVar14 != 0x54);
          }
        }
        else {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fputc(10,pFVar9);
          }
          fclose(pFVar9);
          if (opt_economic_mode != '\0') {
            if (3 < log_level) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,"%s:%d:%s: S11 USE LOW POWER MODE!\n","driver-btm-c5.c",0x32f3,
                        "bitmain_c5_init");
              }
              fclose(pFVar9);
            }
            goto LAB_0003a034;
          }
        }
        uVar14 = log_level;
        if (opt_fixed_freq == '\0') {
          if (*puVar17 == 0x7d) {
            *(uint *)puVar22 = (uint)(byte)puVar17[1] * 5;
            if (3 < uVar14) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,"%s:%d:%s: Chain[J%d] has backup chain_voltage=%d\n",
                        "driver-btm-c5.c",0x3311,"bitmain_c5_init",local_8bc,*(int *)puVar22);
              }
              fclose(pFVar9);
            }
            if (opt_economic_mode != '\0') {
              if (is7007_ctrl_board == -1) {
                isC5_Board();
              }
              if (is7007_ctrl_board == 1) {
                set_fixed_voltage(SUB84((double)(longlong)*(int *)puVar22 / 100.0 + 0.18,0));
                goto LAB_00039000;
              }
            }
            set_fixed_voltage(SUB84((double)(longlong)*(int *)puVar22 / 100.0,0));
          }
LAB_00039000:
          ENABLE_LIMIT_ON_SINGLE_BOARD = '\x01';
          if (log_level < 4) {
            *local_8c0 = 0x3c;
          }
          else {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: S9+: use voltage limit rules on single board!\n",
                      "driver-btm-c5.c",0x331c,"bitmain_c5_init");
            }
            fclose(pFVar9);
            uVar14 = log_level;
            *local_8c0 = 0x3c;
            if (3 < uVar14) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,"%s:%d:%s: S9+ fix Chain[J%d] test patten OK temp=%d\n",
                        "driver-btm-c5.c",0x3320,"bitmain_c5_init",local_8bc,*local_8c0);
              }
              fclose(pFVar9);
            }
          }
        }
      }
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    }
    puVar17 = puVar17 + 0x80;
    uVar8 = uVar8 + 1;
    puVar22 = (undefined1 *)((int)puVar22 + 4);
    local_8bc = local_8bc + 1;
    local_8c0 = local_8c0 + 1;
  } while (uVar8 != 0x10);
  pic_heart_beat = calloc(1,0x40);
  iVar6 = thr_info_create(pic_heart_beat,0,0x2cee1,pic_heart_beat);
  if (iVar6 != 0) {
    if (opt_debug == '\0') {
      return -6;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return -6;
    }
    __format = "%s: create thread error for pic_heart_beat_func\n";
    goto LAB_00038f5e;
  }
  pthread_detach(*(pthread_t *)((int)pic_heart_beat + 0xc));
  init_exist_chain_table();
  power_init();
  power_tuning();
  uVar8 = 0;
  do {
    if (*(int *)(dev + (uVar8 + 2) * 4) == 1) {
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      uVar4 = write_EEPROM_iic(1,1,0x90,uVar8 & 0xff,0);
      chain_voltage_pic[uVar8] = uVar4;
      enable_pic_dac(uVar8 & 0xff);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0x10);
  if (opt_fixed_freq == '\0') {
LAB_000390dc:
    iVar7 = 0;
    cgsleep_ms(100);
    puVar22 = chain_voltage_pic;
    iVar6 = 1;
    do {
      if (*(int *)(dev + (iVar7 + 2) * 4) == 1) {
        pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
        iVar19 = __aeabi_idiv((int)(longlong)
                                   (((364.0704 / ((double)(byte)*puVar22 + 30.72) + 32.79) * 100.0)
                                   / 4.75),10);
        if (3 < log_level) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Chain[J%d] orignal chain_voltage_pic=%d value=%d\n",
                    "driver-btm-c5.c",0x3403,"bitmain_c5_init",iVar6,(uint)(byte)*puVar22,
                    iVar19 * 10);
          }
          fclose(pFVar9);
        }
        if ((chain_pic_buf[iVar7 * 0x80] == '}') && (*(int *)local_8b8 != iVar19 * 10)) {
          dVar24 = 364.0704 / (((double)(longlong)*(int *)local_8b8 * 4.75) / 100.0 - 32.79) - 30.72
          ;
          uVar8 = (uint)(0.0 < dVar24) * (int)(longlong)dVar24;
          local_8c0._0_1_ = (byte)uVar8;
          if (3 < log_level) {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",
                      "driver-btm-c5.c",0x3414,"bitmain_c5_init",iVar6,*(int *)local_8b8,
                      uVar8 & 0xff);
            }
            fclose(pFVar9);
          }
          uVar8 = log_level;
          *puVar22 = (byte)local_8c0;
          if (3 < uVar8) {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: Chain[J%d] get working chain_voltage_pic=%d\n",
                      "driver-btm-c5.c",0x341e,"bitmain_c5_init",iVar6,(uint)(byte)*puVar22);
            }
            fclose(pFVar9);
          }
        }
        pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 1;
      puVar22 = puVar22 + 1;
      local_8b8 = (undefined1 *)((int)local_8b8 + 4);
    } while (iVar7 != 0x10);
    cgsleep_ms(1000);
  }
  else {
    puVar22 = chain_voltage_pic;
    iVar6 = 0;
    piVar21 = (int *)local_8b8;
    do {
      if (*(int *)(dev + (iVar6 + 2) * 4) == 1) {
        if (is_using_voltage_from_config == '\0') {
          *piVar21 = 0x35c;
        }
        else {
          *piVar21 = opt_bitmain_c5_voltage;
        }
        uVar8 = log_level;
        dVar24 = 364.0704 / (((double)(longlong)*piVar21 * 4.75) / 100.0 - 32.79) - 30.72;
        *puVar22 = (0.0 < dVar24) * (char)(longlong)dVar24;
        if (3 < uVar8) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Fix freq=%d Chain[%d] voltage_pic=%d value=%d\n",
                    "driver-btm-c5.c",0x33ef,"bitmain_c5_init",config_parameter._12_4_ & 0xffff,
                    iVar6,(uint)(byte)*puVar22,*piVar21);
          }
          fclose(pFVar9);
        }
      }
      iVar6 = iVar6 + 1;
      puVar22 = puVar22 + 1;
      piVar21 = piVar21 + 1;
    } while (iVar6 != 0x10);
    if (opt_fixed_freq == '\0') goto LAB_000390dc;
  }
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control(uVar8 & 0xffff70df | 0x8100);
  }
  cgsleep_ms(10);
  uVar8 = 0;
  *(undefined1 *)(dev + 0x542c) = 0x72;
  local_8c4 = (byte *)0x1;
  check_asic_reg();
  cgsleep_ms(10);
  do {
    if (*(int *)(dev + (uVar8 + 2) * 4) == 1) {
      if (3 < log_level) {
        pFVar9 = fopen(log_file,"a+");
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3479,
                  "bitmain_c5_init",local_8c4,(uint)*(byte *)(dev + uVar8 + 0x53ec));
        }
        fclose(pFVar9);
      }
      iVar6 = dev + uVar8;
      if (*(char *)(iVar6 + 0x53ec) != 'T') {
        iVar7 = 6;
        do {
          *(undefined1 *)(iVar6 + 0x53ec) = 0;
          set_reset_hashboard(uVar8,1);
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          disable_pic_dac(uVar8 & 0xff);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          sleep(1);
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          enable_pic_dac(uVar8 & 0xff);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          sleep(2);
          set_reset_hashboard(uVar8,0);
          sleep(1);
          check_asic_reg_oneChain(uVar8,0);
          if (3 < log_level) {
            pFVar9 = fopen(log_file,"a+");
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: retry Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3495,
                      "bitmain_c5_init",local_8c4,(uint)*(byte *)(dev + uVar8 + 0x53ec));
            }
            fclose(pFVar9);
          }
          iVar6 = dev + uVar8;
          if (*(char *)(iVar6 + 0x53ec) == 'T') goto LAB_00039384;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (*(char *)(iVar6 + 0x53ec) == '\0') {
          *(undefined4 *)(dev + (uVar8 + 2) * 4) = 0;
        }
      }
    }
LAB_00039384:
    uVar8 = uVar8 + 1;
    local_8c4 = (byte *)((int)local_8c4 + 1);
  } while (uVar8 != 0x10);
  software_set_address();
  cgsleep_ms(10);
  if ((int)(config_parameter._4_4_ << 0x1c) < 0) {
    uVar2 = config_parameter._12_2_;
    *(undefined2 *)(dev + 0x5443) = config_parameter._12_2_;
    set_frequency(uVar2);
    sprintf((char *)(dev + 0x5445),"%u",(uint)*(ushort *)(dev + 0x5443));
  }
  cgsleep_ms(10);
  iVar6 = dev;
  cVar3 = opt_debug;
  bVar5 = config_parameter[10];
  uVar8 = (uint)config_parameter[10];
  uVar14 = config_parameter._4_4_ << 0x1e;
  *(byte *)(dev + 0x5441) = (byte)(uVar14 >> 0x1f);
  *(byte *)(iVar6 + 0x5442) = bVar5;
  if ((cVar3 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf(local_860,0x800,"%s: fan_eft : %d  fan_pwm : %d\n","bitmain_c5_init",uVar14 >> 0x1f,
             uVar8);
    _applog(7,local_860,0);
  }
  if (((int)(config_parameter._4_4_ << 0x1e) < 0) && (config_parameter[10] < 0x65)) {
    set_PWM();
  }
  else {
    set_PWM_according_to_temperature();
  }
  if ((int)(config_parameter._4_4_ << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      uVar11 = calculate_core_number(*(undefined1 *)(dev + 0x542c));
      iVar6 = dev;
      iVar7 = __aeabi_idiv(0x1000000,uVar11);
      iVar7 = __aeabi_idiv((uint)*(byte *)(iVar6 + 0x542d) * iVar7,*(undefined2 *)(iVar6 + 0x5443));
      uVar11 = __aeabi_idiv(iVar7 * 0x5a,100);
      *(undefined4 *)(iVar6 + 0x48) = uVar11;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(local_860,0x800,"dev->timeout = %d\n",uVar11);
        _applog(7,local_860,0);
      }
    }
    else {
      *(uint *)(dev + 0x48) =
           ((uint)config_parameter._16_4_ >> 0x10 & 0xff) * 1000 +
           ((uint)config_parameter._16_4_ >> 0x18);
    }
    if (0x1ffff < *(uint *)(dev + 0x48)) {
      *(undefined4 *)(dev + 0x48) = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar7 = 0;
  cgsleep_ms(10);
  uVar11 = extraout_r1;
  iVar6 = dev;
  do {
    if ((*(int *)(iVar6 + (iVar7 + 2) * 4) == 1) && (*(char *)(iVar6 + iVar7 + 0x53ec) == 'T')) {
      calibration_sensor_offset(0x98,iVar7);
      cgsleep_ms(10);
      uVar11 = extraout_r1_00;
      iVar6 = dev;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  lVar1 = (ulonglong)*(uint *)(iVar6 + 0x48) * 0xcccccccd;
  set_time_out_control
            ((uint)((int)((ulonglong)lVar1 >> 0x20) << 0xc) >> 0xf | 0x80000000,uVar11,(int)lVar1);
  iVar6 = dev;
  *(undefined1 *)(dev + 0x53fc) = 100;
  *(undefined4 *)(iVar6 + 4) = 0x320000;
  set_fan_control(0x320000);
  if ((opt_fixed_freq == '\0') && (is_scan_based_on_domain == '\0')) {
    local_8c4 = chain_voltage_pic;
    iVar6 = 0;
    iVar7 = dev;
    do {
      if (*(int *)(iVar7 + (iVar6 + 2) * 4) != 0) {
        piVar21 = (int *)(iVar7 + 4);
        iVar19 = 0;
        do {
          piVar21 = piVar21 + 1;
          if (*piVar21 == 1) {
            iVar19 = iVar19 + 1;
          }
        } while ((int *)(iVar7 + 0x44) != piVar21);
        if (3 < iVar19) {
          iVar7 = (int)(longlong)
                       (((364.0704 / ((double)*local_8c4 + 30.72) + 32.79) * 100.0) / 4.75);
          iVar19 = (iVar7 / 10) * 10;
          if (ENABLE_LIMIT_ON_SINGLE_BOARD == '\0') {
            if (opt_economic_mode != '\0') {
              GetTotalRate_part_12(iVar7 * 0x66666667);
            }
            if (3 < log_level) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                uVar11 = ideal_total_hash_rate;
                if (opt_economic_mode != '\0') {
                  uVar11 = GetTotalRate_part_12();
                }
                fprintf(pFVar9,"%s:%d:%s: miner rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x3565,"bitmain_c5_init",uVar11,0x3a2,iVar6);
              }
LAB_0003988e:
              fclose(pFVar9);
              if (3 < log_level) {
                pFVar9 = fopen(log_file,"a+");
                if (pFVar9 != (FILE *)0x0) {
                  fprintf(pFVar9,"%s:%d:%s: get PIC voltage=%d on chain[%d], check: must be < %d\n",
                          "driver-btm-c5.c",0x3584,"bitmain_c5_init",iVar19,iVar6,0x3a2);
                }
                fclose(pFVar9);
              }
            }
          }
          else {
            GetRealBoardRate(iVar6);
            if (3 < log_level) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                uVar11 = GetRealBoardRate(iVar6);
                fprintf(pFVar9,"%s:%d:%s: single board rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x355f,"bitmain_c5_init",uVar11,0x3a2,iVar6);
              }
              goto LAB_0003988e;
            }
          }
          iVar7 = dev;
          if (0x3a2 < iVar19) {
            if (3 < log_level) {
              pFVar9 = fopen(log_file,"a+");
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,
                        "%s:%d:%s: will set the voltage limited on chain[%d], change voltage=%d\n",
                        "driver-btm-c5.c",0x359b,"bitmain_c5_init",iVar6,0x3a2);
              }
              fclose(pFVar9);
              if (3 < log_level) {
                pFVar9 = fopen(log_file,"a+");
                if (pFVar9 != (FILE *)0x0) {
                  fprintf(pFVar9,"%s:%d:%s: now set pic voltage=%d on chain[%d]\n","driver-btm-c5.c"
                          ,0x359e,"bitmain_c5_init",1,iVar6);
                }
                fclose(pFVar9);
              }
            }
            iVar7 = dev;
            *local_8c4 = 1;
          }
        }
      }
      iVar6 = iVar6 + 1;
      local_8c4 = local_8c4 + 1;
    } while (iVar6 != 0x10);
  }
  iVar6 = 0;
  do {
    if (*(int *)(dev + (iVar6 + 2) * 4) == 1) {
      if (is_scan_based_on_domain != '\0') {
        if (3 < log_level) {
          pFVar9 = fopen(log_file,"a+");
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: open core three times\n","driver-btm-c5.c",0x35c3,
                    "bitmain_c5_init");
          }
          fclose(pFVar9);
        }
        open_core_one_chain(iVar6,1);
        sleep(2);
        open_core_one_chain(iVar6,1);
        sleep(2);
      }
      open_core_one_chain(iVar6,1);
      sleep(1);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  set_working_voltage();
  iVar6 = 0;
  lVar1 = (ulonglong)*(uint *)(dev + 0x48) * 0xcccccccd;
  set_time_out_control
            ((uint)((int)((ulonglong)lVar1 >> 0x20) << 0xc) >> 0xf | 0x80000000,extraout_r1_01,
             (int)lVar1);
  do {
    if ((*(int *)(dev + (iVar6 + 2) * 4) == 1) && ('\0' < *(char *)(dev + iVar6 + 0x458))) {
      uVar8 = 0;
      do {
        set_baud_with_addr(*(undefined1 *)(dev + 0x542f),0,
                           *(undefined1 *)(dev + iVar6 * 8 + uVar8 + 0x4e8),iVar6,1,0,1);
        uVar14 = uVar8 + 1 & 0xff;
        check_asic_reg_with_addr(0x1c,*(undefined1 *)(uVar8 + dev + iVar6 * 8 + 0x4e8),iVar6,1);
        uVar8 = uVar14;
      } while ((int)uVar14 < (int)*(char *)(dev + iVar6 + 0x458));
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  if (3 < log_level) {
    pFVar9 = fopen(log_file,"a+");
    if (pFVar9 != (FILE *)0x0) {
      fprintf(pFVar9,"%s:%d:%s: start thread for read temp\n","driver-btm-c5.c",0x368e,
              "bitmain_c5_init");
    }
    fclose(pFVar9);
  }
  read_temp_id = calloc(1,0x40);
  iVar6 = thr_info_create(read_temp_id,0,0x3d295,read_temp_id);
  if (iVar6 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_860,0x800,"%s: create thread for read temp\n","bitmain_c5_init");
      _applog(7,local_860,0);
      return -7;
    }
    return -7;
  }
  pthread_detach(*(pthread_t *)((int)read_temp_id + 0xc));
  if (opt_fixed_freq == '\0') {
    opt_pre_heat = opt_fixed_freq;
  }
  set_asic_ticket_mask(ticket_mask);
  set_hcnt(0);
  set_sno(0);
  cgsleep_ms(10);
  if (opt_multi_version == 0) {
    set_time_out_control(*(uint *)(dev + 0x48) & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(*(int *)(dev + 0x48) * opt_multi_version & 0x1ffffU | 0x80000000);
  }
  check_system_work_id = calloc(1,0x40);
  iVar6 = thr_info_create(check_system_work_id,0,0x3bcfd,check_system_work_id);
  if (iVar6 == 0) {
    pthread_detach(*(pthread_t *)((int)check_system_work_id + 0xc));
    iVar7 = dev;
    piVar21 = (int *)(dev + 4);
    iVar6 = 0;
    do {
      piVar21 = piVar21 + 1;
      if (*piVar21 != 0) {
        uVar8 = (uint)*(byte *)(iVar7 + iVar6 + 0x53ec);
        if (uVar8 == 0) {
          iVar19 = 0;
        }
        else {
          iVar19 = 0;
          uVar14 = 0;
          iVar10 = iVar7 + iVar6 * 0x88;
          iVar12 = iVar6;
          do {
            uVar4 = (undefined1)iVar12;
            bVar23 = (uVar14 & 7) == 0;
            iVar12 = iVar10 + iVar19;
            if (bVar23) {
              uVar4 = 0x20;
            }
            if (bVar23) {
              iVar19 = iVar19 + 1;
              *(undefined1 *)(iVar12 + uVar14 + 0x4afc) = uVar4;
            }
            iVar12 = iVar6 * 0x80 + uVar14;
            iVar16 = iVar10 + iVar19 + uVar14;
            uVar14 = uVar14 + 1;
            iVar15 = iVar7 + (iVar12 + 0x15f) * 8;
            iVar12 = 0x6f;
            *(undefined1 *)(iVar16 + 0x4afc) = 0x6f;
            *(undefined4 *)(iVar15 + 4) = 0;
            *(undefined4 *)(iVar15 + 8) = 0;
          } while (uVar14 != uVar8);
        }
        *(undefined1 *)(iVar19 + uVar8 + iVar6 * 0x88 + iVar7 + 0x4afc) = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
    cgtime(&tv_send_job);
    cgtime(&tv_send);
    startCheckNetworkJob = 1;
    setStartTimePoint();
    return 0;
  }
  if ((opt_debug == '\0') ||
     (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
    return -6;
  }
  __format = "%s: create thread for check system\n";
LAB_00038f5e:
  snprintf(local_860,0x800,__format,"bitmain_c5_init");
  _applog(7,local_860,0);
  return -6;
}

