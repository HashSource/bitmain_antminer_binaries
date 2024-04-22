
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int bitmain_c5_init(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,uint param_8)

{
  longlong lVar1;
  pthread_mutex_t *ppVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined2 uVar7;
  char cVar8;
  undefined uVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  FILE *pFVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar18;
  char *__format;
  uint uVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  byte *pbVar24;
  int iVar25;
  byte *pbVar26;
  int *piVar27;
  undefined1 *puVar28;
  bool bVar29;
  double dVar30;
  uint local_8c8;
  byte *local_8c4;
  undefined4 *local_8c0;
  int local_8bc;
  int local_8b8;
  sysinfo sStack_8a0;
  undefined4 local_860;
  undefined4 uStack_85c;
  
  opt_multi_version = 1;
  check_config_file();
  iVar11 = readRestartNum();
  saveRebootTestNum(0);
  clearInitLogFile();
  if (iVar11 < 1) {
    if (3 < log_level) {
      pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: This is the first time running after searching freq!\n",
                "driver-btm-c5.c",0x2fd8,DAT_00038940);
      }
      fclose(pFVar14);
    }
    saveRestartNum(2);
  }
  else if (3 < log_level) {
    pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar14 != (FILE *)0x0) {
      fprintf(pFVar14,"%s:%d:%s: This is user mode for mining\n","driver-btm-c5.c",0x2fdd,
              DAT_00038940);
    }
    fclose(pFVar14);
  }
  iVar12 = isC5_Board();
  isC5_CtrlBoard = (undefined)iVar12;
  if (iVar12 == 0) {
    sysinfo(&sStack_8a0);
    if (sStack_8a0.totalram < 0x3b9aca01) {
      if (sStack_8a0.totalram < 0x1dcd6501) {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
        if (3 < log_level) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: Detect 256MB control board of XILINX\n","driver-btm-c5.c",
                    0x3014,DAT_00038940);
          }
          goto LAB_00038690;
        }
      }
      else {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
        if (3 < log_level) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: Detect 512MB control board of XILINX\n","driver-btm-c5.c",
                    0x300e,DAT_00038940);
          }
LAB_00038690:
          fclose(pFVar14);
          if (3 < log_level) {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"%s:%d:%s: Miner Type = S9+\n","driver-btm-c5.c",0x3027,DAT_00038940);
            }
            fclose(pFVar14);
            if (3 < log_level) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                fprintf(pFVar14,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-c5.c",
                        0x302e,DAT_00038940,g_miner_compiletime,g_miner_type);
              }
              fclose(pFVar14);
            }
          }
        }
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
      if (3 < log_level) {
        pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: Detect 1GB control board of XILINX\n","driver-btm-c5.c",0x3008,
                  DAT_00038940);
        }
        goto LAB_00038690;
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: This is C5 board.\n","driver-btm-c5.c",0x2ff2,DAT_00038940);
      }
      goto LAB_00038690;
    }
  }
  puVar28 = config_parameter;
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
      snprintf((char *)&local_860,0x800,"%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
               DAT_00038940,0x51,param_1 & 0xff);
      _applog(7,&local_860,0);
      return -1;
    }
    return -1;
  }
  uVar18 = 0xff;
  uVar13 = 0xff;
  uVar19 = 0x51;
  while( true ) {
    uVar19 = uVar18 ^ uVar19;
    uVar18 = (byte)chCRCHTalbe[uVar19] ^ uVar13;
    uVar13 = (uint)(byte)chCRCLTalbe[uVar19];
    if (puVar28 == config_parameter + 0x1d) break;
    puVar28 = puVar28 + 1;
    uVar19 = (uint)(byte)*puVar28;
  }
  uVar18 = uVar18 | uVar13 << 8;
  if (param_8 >> 0x10 != uVar18) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_860,0x800,
               "%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",DAT_00038940,
               param_8 >> 0x10,uVar18);
      _applog(7,&local_860,0);
      return -2;
    }
    return -2;
  }
  iVar12 = check_pool_worker();
  if (iVar12 != 0) {
    return iVar12;
  }
  iVar12 = check_pool_for_validation();
  if (iVar12 != 0) {
    return iVar12;
  }
  bitmain_axi_init();
  read_nonce_reg_id = calloc(1,0x40);
  iVar12 = thr_info_create(read_nonce_reg_id,0,0x314e9,read_nonce_reg_id);
  if (iVar12 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_860,0x800,
               "%s: create thread for get nonce and register from FPGA failed\n",DAT_00038cd4);
      _applog(7,&local_860,0);
      return -5;
    }
    return -5;
  }
  pthread_detach(*(pthread_t *)((int)read_nonce_reg_id + 0xc));
  if (opt_fixed_freq != '\0') {
    if (3 < log_level) {
      pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: config voltage = %d, freq = %d\n","driver-btm-c5.c",0x3058,
                DAT_000393f0,opt_bitmain_c5_voltage,config_parameter._12_4_ & 0xffff);
      }
      fclose(pFVar14);
    }
    if (999 < opt_bitmain_c5_voltage) {
      set_fixed_voltage(SUB84((double)(longlong)opt_bitmain_c5_voltage / DAT_000393e0,0));
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
    iVar12 = dev;
    if (is_certification == '\0') {
      *(undefined *)(dev + 0x53fc) = 100;
      *(undefined4 *)(iVar12 + 4) = 0x320000;
      set_fan_control(0x320000);
    }
    else {
      *(undefined *)(dev + 0x53fc) = 0x14;
      *(undefined **)(iVar12 + 4) = &DAT_000a0028;
      set_fan_control(&DAT_000a0028);
    }
  }
  read_fpga_id(FPGA_ID_str);
  if (3 < log_level) {
    pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar14 != (FILE *)0x0) {
      fprintf(pFVar14,"%s:%d:%s: miner ID : %s\n","driver-btm-c5.c",0x3088,DAT_000390b8,FPGA_ID_str)
      ;
    }
    fclose(pFVar14);
  }
  uVar13 = get_hardware_version();
  fpga_version = uVar13 & 0xff;
  pcb_version = (uVar13 << 1) >> 0x11;
  fpga_major_version = (uVar13 << 0x10) >> 0x18;
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
  iVar12 = PHY_MEM_NONCE2_JOBID_ADDRESS;
  *(undefined *)(dev + 0x542f) = 0x1a;
  set_nonce2_and_job_id_store_address(iVar12);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  iVar12 = dev;
  if (is_certification != '\0') {
    sleep(1);
    iVar11 = dev;
    ppVar2 = DAT_00038cd8;
    *(undefined **)(dev + 4) = &DAT_000a0028;
    uVar13 = 0;
    *(undefined *)(iVar11 + 0x53fc) = 0x14;
    set_fan_control(&DAT_000a0028);
    iVar11 = dev;
    *(undefined *)(dev + 0x5442) = 0x14;
    do {
      if (*(int *)(iVar11 + (uVar13 + 2) * 4) == 1) {
        pthread_mutex_lock(ppVar2);
        disable_pic_dac(uVar13 & 0xff);
        pthread_mutex_unlock(ppVar2);
        iVar11 = dev;
      }
      iVar12 = dev;
      uVar13 = uVar13 + 1;
    } while (uVar13 != 0x10);
    iVar25 = 0;
    do {
      if (*(int *)(iVar11 + (iVar25 + 2) * 4) == 0) {
        *(undefined *)(iVar11 + iVar25 + 0x53ec) = 0;
      }
      else {
        iVar17 = 0;
        uVar13 = 0;
        iVar15 = iVar11 + iVar25 * 0x88;
        *(undefined *)(iVar11 + iVar25 + 0x53ec) = 0x54;
        do {
          iVar20 = iVar15 + iVar17;
          if ((uVar13 & 7) == 0) {
            iVar17 = iVar17 + 1;
            *(undefined *)(iVar20 + uVar13 + 0x4afc) = 0x20;
          }
          iVar20 = iVar25 * 0x80 + uVar13;
          iVar21 = iVar15 + iVar17;
          iVar23 = iVar21 + uVar13;
          uVar13 = uVar13 + 1;
          iVar20 = iVar11 + (iVar20 + 0x15f) * 8;
          *(undefined *)(iVar23 + 0x4afc) = 0x6f;
          *(undefined4 *)(iVar20 + 4) = 0;
          *(undefined4 *)(iVar20 + 8) = 0;
        } while (uVar13 != 0x54);
        *(undefined *)(iVar21 + 0x4b50) = 0;
      }
      iVar25 = iVar25 + 1;
      iVar11 = iVar12;
    } while (iVar25 != 0x10);
    sleep(2);
    return 0;
  }
  *(undefined *)(dev + 0x53fc) = 100;
  *(undefined4 *)(iVar12 + 4) = 0x320000;
  set_fan_control();
  bVar29 = false;
  local_8b8 = 0;
  while( true ) {
    check_fan_beforeInit();
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      snprintf((char *)&local_860,0x800,"Max fan speed: %d, Min fan speed: %d",
               *(undefined4 *)(dev + 0x5400),*(undefined4 *)(dev + 0x5404));
      _applog(5,&local_860,0);
    }
    ppVar2 = DAT_00038cd8;
    if ((1 < *(byte *)(dev + 0x53fe)) && (1999 < *(uint *)(dev + 0x5404))) break;
    uVar13 = 0;
    do {
      if (*(int *)(dev + (uVar13 + 2) * 4) == 1) {
        pthread_mutex_lock(ppVar2);
        dsPIC33EP16GS202_reset_pic(uVar13 & 0xff);
        pthread_mutex_unlock(ppVar2);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != 0x10);
    if ((!bVar29) && (3 < log_level)) {
      pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: Checking fans...\n","driver-btm-c5.c",0x3125,DAT_00038cd4);
      }
      fclose(pFVar14);
    }
    iVar25 = local_8b8 + 1;
    iVar12 = iVar25;
    if (100 < iVar25) {
      iVar12 = 1;
    }
    if (iVar25 == 100 || local_8b8 + -99 < 0 != SBORROW4(iVar25,100)) {
      iVar12 = 0;
    }
    if (0 < iVar11) {
      iVar12 = 0;
    }
    if (iVar12 != 0) {
      local_860 = 0x313a46;
      saveSearchFailedFlagInfo(&local_860);
      system("reboot");
    }
    bVar29 = true;
    cgsleep_ms(1000);
    local_8b8 = iVar25;
  }
  if ((use_syslog != '\0') || ((opt_log_output != '\0' || (4 < opt_log_level)))) {
    local_860 = DAT_00063fb0;
    uStack_85c = DAT_00063fb4;
    _applog(5,&local_860,0);
  }
  piVar27 = DAT_000390c0;
  dVar4 = DAT_000390b0;
  dVar3 = DAT_000390a8;
  local_8c0 = DAT_000390bc;
  local_8bc = 1;
  uVar13 = 0;
  piVar22 = DAT_000390c0;
  pbVar24 = DAT_000390cc;
  do {
    if (*(int *)(dev + (uVar13 + 2) * 4) == 1) {
      pthread_mutex_lock(DAT_000390c4);
      dsPIC33EP16GS202_reset_pic(uVar13 & 0xff);
      jump_to_app_CheckAndRestorePIC_T9_18(uVar13);
      if (opt_fixed_freq == '\0') {
        AT24C02_read_bytes_part_7(0,pbVar24,uVar13 & 0xff,0x80);
        if (3 < log_level) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: Chain[%d] read_freq_badcores : ","driver-btm-c5.c",0x32ea,
                    DAT_000393f0,uVar13);
          }
          fclose(pFVar14);
        }
        uVar19 = log_level;
        pbVar26 = pbVar24;
        do {
          if (3 < uVar19) {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"0x%02x ",(uint)*pbVar26);
            }
            fclose(pFVar14);
            uVar19 = log_level;
          }
          pbVar26 = pbVar26 + 1;
        } while (pbVar26 != pbVar24 + 0x80);
        if (uVar19 < 4) {
          if (opt_economic_mode != '\0') {
LAB_0003a034:
            uVar19 = 0;
            pbVar24[1] = pbVar24[0x5a];
            pbVar26 = pbVar24 + 1;
            *(undefined4 *)(pbVar24 + 0x56) = *(undefined4 *)(pbVar24 + 0x70);
            do {
              iVar11 = (int)uVar19 >> 2;
              uVar18 = uVar19 & 3;
              uVar19 = uVar19 + 1;
              bVar10 = get_pll_index_for_lowpower_mode
                                 ((int)(uint)(byte)chain_pic_buf[uVar13 * 0x80 + iVar11 + 0x5b] >>
                                  (uVar18 << 1) & 3);
              pbVar26 = pbVar26 + 1;
              *pbVar26 = bVar10;
            } while (uVar19 != 0x54);
          }
        }
        else {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fputc(10,pFVar14);
          }
          fclose(pFVar14);
          if (opt_economic_mode != '\0') {
            if (3 < log_level) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                fprintf(pFVar14,"%s:%d:%s: S11 USE LOW POWER MODE!\n","driver-btm-c5.c",0x32f3,
                        DAT_0003a0e4);
              }
              fclose(pFVar14);
            }
            goto LAB_0003a034;
          }
        }
        uVar19 = log_level;
        if (opt_fixed_freq == '\0') {
          if (*pbVar24 == 0x7d) {
            *piVar22 = (uint)pbVar24[1] * 5;
            if (3 < uVar19) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                fprintf(pFVar14,"%s:%d:%s: Chain[J%d] has backup chain_voltage=%d\n",
                        "driver-btm-c5.c",0x3311,DAT_0003a0e4,local_8bc,*piVar22);
              }
              fclose(pFVar14);
            }
            if (opt_economic_mode != '\0') {
              if (is7007_ctrl_board == -1) {
                isC5_Board();
              }
              if (is7007_ctrl_board == 1) {
                set_fixed_voltage(SUB84((double)(longlong)*piVar22 / dVar3 + dVar4,0));
                goto LAB_00039000;
              }
            }
            set_fixed_voltage(SUB84((double)(longlong)*piVar22 / dVar3,0));
          }
LAB_00039000:
          ENABLE_LIMIT_ON_SINGLE_BOARD = '\x01';
          if (log_level < 4) {
            *local_8c0 = 0x3c;
          }
          else {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"%s:%d:%s: S9+: use voltage limit rules on single board!\n",
                      "driver-btm-c5.c",0x331c,DAT_000393f0);
            }
            fclose(pFVar14);
            uVar19 = log_level;
            *local_8c0 = 0x3c;
            if (3 < uVar19) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                fprintf(pFVar14,"%s:%d:%s: S9+ fix Chain[J%d] test patten OK temp=%d\n",
                        "driver-btm-c5.c",0x3320,DAT_000393f0,local_8bc,*local_8c0);
              }
              fclose(pFVar14);
            }
          }
        }
      }
      pthread_mutex_unlock(DAT_000390c4);
    }
    pbVar24 = pbVar24 + 0x80;
    uVar13 = uVar13 + 1;
    piVar22 = piVar22 + 1;
    local_8bc = local_8bc + 1;
    local_8c0 = local_8c0 + 1;
  } while (uVar13 != 0x10);
  pic_heart_beat = calloc(1,0x40);
  iVar11 = thr_info_create(pic_heart_beat,0,0x2cee1,pic_heart_beat);
  ppVar2 = DAT_000390c4;
  if (iVar11 != 0) {
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
  uVar13 = 0;
  do {
    if (*(int *)(dev + (uVar13 + 2) * 4) == 1) {
      pthread_mutex_lock(ppVar2);
      uVar9 = write_EEPROM_iic(1,1,0x90,uVar13 & 0xff,0);
      *(undefined *)(DAT_000390c8 + uVar13) = uVar9;
      enable_pic_dac(uVar13 & 0xff);
      pthread_mutex_unlock(ppVar2);
    }
    dVar6 = DAT_00039ea0;
    dVar5 = DAT_00039e98;
    dVar4 = DAT_00039e90;
    dVar3 = DAT_00039e88;
    uVar13 = uVar13 + 1;
  } while (uVar13 != 0x10);
  if (opt_fixed_freq == '\0') {
LAB_000390dc:
    iVar12 = 0;
    cgsleep_ms(100);
    dVar6 = DAT_000393e0;
    dVar5 = DAT_000393d8;
    dVar4 = DAT_000393d0;
    dVar3 = DAT_000393c8;
    iVar11 = 1;
    pbVar24 = DAT_000393f4;
    do {
      if (*(int *)(dev + (iVar12 + 2) * 4) == 1) {
        pthread_mutex_lock(DAT_000393e8);
        iVar25 = __aeabi_idiv((int)(longlong)
                                   (((dVar4 / ((double)(longlong)(int)(uint)*pbVar24 + dVar3) +
                                     dVar5) * dVar6) / 4.75),10);
        if (3 < log_level) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: Chain[J%d] orignal chain_voltage_pic=%d value=%d\n",
                    "driver-btm-c5.c",0x3403,DAT_0003a0e4,iVar11,(uint)*pbVar24,iVar25 * 10);
          }
          fclose(pFVar14);
        }
        if ((*(char *)(DAT_000393ec + iVar12 * 0x80) == '}') && (*piVar27 != iVar25 * 10)) {
          dVar30 = dVar4 / (((double)(longlong)*piVar27 * 4.75) / dVar6 - dVar5) - dVar3;
          uVar13 = (uint)(0.0 < dVar30) * (int)(longlong)dVar30;
          local_8c0._0_1_ = (byte)uVar13;
          if (3 < log_level) {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"%s:%d:%s: Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",
                      "driver-btm-c5.c",0x3414,DAT_0003a0e4,iVar11,*piVar27,uVar13 & 0xff);
            }
            fclose(pFVar14);
          }
          uVar13 = log_level;
          *pbVar24 = (byte)local_8c0;
          if (3 < uVar13) {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"%s:%d:%s: Chain[J%d] get working chain_voltage_pic=%d\n",
                      "driver-btm-c5.c",0x341e,DAT_0003a0e4,iVar11,(uint)*pbVar24);
            }
            fclose(pFVar14);
          }
        }
        pthread_mutex_unlock(DAT_000393e8);
      }
      iVar12 = iVar12 + 1;
      iVar11 = iVar11 + 1;
      pbVar24 = pbVar24 + 1;
      piVar27 = piVar27 + 1;
    } while (iVar12 != 0x10);
    cgsleep_ms(1000);
  }
  else {
    iVar11 = 0;
    piVar22 = piVar27;
    pbVar24 = DAT_00039eb4;
    do {
      if (*(int *)(dev + (iVar11 + 2) * 4) == 1) {
        if (is_using_voltage_from_config == '\0') {
          *piVar22 = 0x35c;
        }
        else {
          *piVar22 = opt_bitmain_c5_voltage;
        }
        uVar13 = log_level;
        dVar30 = dVar5 / (((double)(longlong)*piVar22 * 4.75) / dVar3 - dVar4) - dVar6;
        *pbVar24 = (0.0 < dVar30) * (char)(longlong)dVar30;
        if (3 < uVar13) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: Fix freq=%d Chain[%d] voltage_pic=%d value=%d\n",
                    "driver-btm-c5.c",0x33ef,DAT_00039eb0,config_parameter._12_4_ & 0xffff,iVar11,
                    (uint)*pbVar24,*piVar22);
          }
          fclose(pFVar14);
        }
      }
      iVar11 = iVar11 + 1;
      pbVar24 = pbVar24 + 1;
      piVar22 = piVar22 + 1;
    } while (iVar11 != 0x10);
    if (opt_fixed_freq == '\0') goto LAB_000390dc;
  }
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar13 = get_dhash_acc_control();
    set_dhash_acc_control(uVar13 & 0xffff70df | 0x8100);
  }
  cgsleep_ms(10);
  uVar13 = 0;
  *(undefined *)(dev + 0x542c) = 0x72;
  local_8c4 = (byte *)0x1;
  check_asic_reg();
  cgsleep_ms(10);
  do {
    if (*(int *)(dev + (uVar13 + 2) * 4) == 1) {
      if (3 < log_level) {
        pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3479,DAT_00039760
                  ,local_8c4,(uint)*(byte *)(dev + uVar13 + 0x53ec));
        }
        fclose(pFVar14);
      }
      iVar11 = dev + uVar13;
      if (*(char *)(iVar11 + 0x53ec) != 'T') {
        iVar12 = 6;
        do {
          *(undefined *)(iVar11 + 0x53ec) = 0;
          set_reset_hashboard(uVar13,1);
          pthread_mutex_lock(DAT_0003975c);
          disable_pic_dac(uVar13 & 0xff);
          pthread_mutex_unlock(DAT_0003975c);
          sleep(1);
          pthread_mutex_lock(DAT_0003975c);
          enable_pic_dac(uVar13 & 0xff);
          pthread_mutex_unlock(DAT_0003975c);
          sleep(2);
          set_reset_hashboard(uVar13,0);
          sleep(1);
          check_asic_reg_oneChain(uVar13,0);
          if (3 < log_level) {
            pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar14 != (FILE *)0x0) {
              fprintf(pFVar14,"%s:%d:%s: retry Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3495,
                      DAT_00039760,local_8c4,(uint)*(byte *)(dev + uVar13 + 0x53ec));
            }
            fclose(pFVar14);
          }
          iVar11 = dev + uVar13;
          if (*(char *)(iVar11 + 0x53ec) == 'T') goto LAB_00039384;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        if (*(char *)(iVar11 + 0x53ec) == '\0') {
          *(undefined4 *)(dev + (uVar13 + 2) * 4) = 0;
        }
      }
    }
LAB_00039384:
    uVar13 = uVar13 + 1;
    local_8c4 = (byte *)((int)local_8c4 + 1);
  } while (uVar13 != 0x10);
  software_set_address();
  cgsleep_ms(10);
  if ((int)(config_parameter._4_4_ << 0x1c) < 0) {
    uVar7 = config_parameter._12_2_;
    *(undefined2 *)(dev + 0x5443) = config_parameter._12_2_;
    set_frequency(uVar7);
    sprintf((char *)(dev + 0x5445),"%u",(uint)*(ushort *)(dev + 0x5443));
  }
  cgsleep_ms(10);
  iVar11 = dev;
  cVar8 = opt_debug;
  bVar10 = config_parameter[10];
  uVar13 = (uint)config_parameter[10];
  uVar19 = config_parameter._4_4_ << 0x1e;
  *(byte *)(dev + 0x5441) = (byte)(uVar19 >> 0x1f);
  *(byte *)(iVar11 + 0x5442) = bVar10;
  if ((cVar8 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf((char *)&local_860,0x800,"%s: fan_eft : %d  fan_pwm : %d\n",DAT_00039760,uVar19 >> 0x1f
             ,uVar13);
    _applog(7,&local_860,0);
  }
  if (((int)(config_parameter._4_4_ << 0x1e) < 0) && (config_parameter[10] < 0x65)) {
    set_PWM();
  }
  else {
    set_PWM_according_to_temperature();
  }
  if ((int)(config_parameter._4_4_ << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      uVar16 = calculate_core_number(*(undefined *)(dev + 0x542c));
      iVar11 = dev;
      iVar12 = __aeabi_idiv(0x1000000,uVar16);
      iVar12 = __aeabi_idiv((uint)*(byte *)(iVar11 + 0x542d) * iVar12,
                            *(undefined2 *)(iVar11 + 0x5443));
      uVar16 = __aeabi_idiv(iVar12 * 0x5a,100);
      *(undefined4 *)(iVar11 + 0x48) = uVar16;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf((char *)&local_860,0x800,"dev->timeout = %d\n",uVar16);
        _applog(7,&local_860,0);
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
  iVar12 = 0;
  cgsleep_ms(10);
  uVar16 = extraout_r1;
  iVar11 = dev;
  do {
    if ((*(int *)(iVar11 + (iVar12 + 2) * 4) == 1) && (*(char *)(iVar11 + iVar12 + 0x53ec) == 'T'))
    {
      calibration_sensor_offset(0x98,iVar12);
      cgsleep_ms(10);
      uVar16 = extraout_r1_00;
      iVar11 = dev;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 != 0x10);
  lVar1 = (ulonglong)*(uint *)(iVar11 + 0x48) * 0xcccccccd;
  set_time_out_control
            ((uint)((int)((ulonglong)lVar1 >> 0x20) << 0xc) >> 0xf | 0x80000000,uVar16,(int)lVar1);
  iVar11 = dev;
  *(undefined *)(dev + 0x53fc) = 100;
  *(undefined4 *)(iVar11 + 4) = 0x320000;
  set_fan_control(0x320000);
  dVar6 = DAT_00039a30;
  dVar5 = DAT_00039a28;
  dVar4 = DAT_00039a20;
  dVar3 = DAT_00039a18;
  if ((opt_fixed_freq == '\0') && (is_scan_based_on_domain == '\0')) {
    local_8c4 = DAT_00039a38;
    iVar11 = 0;
    iVar12 = dev;
    do {
      if (*(int *)(iVar12 + (iVar11 + 2) * 4) != 0) {
        piVar27 = (int *)(iVar12 + 4);
        iVar25 = 0;
        do {
          piVar27 = piVar27 + 1;
          if (*piVar27 == 1) {
            iVar25 = iVar25 + 1;
          }
        } while ((int *)(iVar12 + 0x44) != piVar27);
        if (3 < iVar25) {
          iVar12 = (int)(longlong)
                        (((dVar4 / ((double)(longlong)(int)(uint)*local_8c4 + dVar3) + dVar5) *
                         dVar6) / 4.75);
          iVar25 = (iVar12 / 10) * 10;
          if (ENABLE_LIMIT_ON_SINGLE_BOARD == '\0') {
            if (opt_economic_mode != '\0') {
              GetTotalRate_part_12(iVar12 * 0x66666667);
            }
            if (3 < log_level) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                uVar16 = ideal_total_hash_rate;
                if (opt_economic_mode != '\0') {
                  uVar16 = GetTotalRate_part_12();
                }
                fprintf(pFVar14,"%s:%d:%s: miner rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x3565,DAT_00039eb0,uVar16,0x3a2,iVar11);
              }
LAB_0003988e:
              fclose(pFVar14);
              if (3 < log_level) {
                pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar14 != (FILE *)0x0) {
                  fprintf(pFVar14,"%s:%d:%s: get PIC voltage=%d on chain[%d], check: must be < %d\n"
                          ,"driver-btm-c5.c",0x3584,DAT_00039a3c,iVar25,iVar11,0x3a2);
                }
                fclose(pFVar14);
              }
            }
          }
          else {
            GetRealBoardRate(iVar11);
            if (3 < log_level) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                uVar16 = GetRealBoardRate(iVar11);
                fprintf(pFVar14,"%s:%d:%s: single board rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x355f,DAT_00039a3c,uVar16,0x3a2,iVar11);
              }
              goto LAB_0003988e;
            }
          }
          iVar12 = dev;
          if (0x3a2 < iVar25) {
            if (3 < log_level) {
              pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar14 != (FILE *)0x0) {
                fprintf(pFVar14,
                        "%s:%d:%s: will set the voltage limited on chain[%d], change voltage=%d\n",
                        "driver-btm-c5.c",0x359b,DAT_00039eb0,iVar11,0x3a2);
              }
              fclose(pFVar14);
              if (3 < log_level) {
                pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar14 != (FILE *)0x0) {
                  fprintf(pFVar14,"%s:%d:%s: now set pic voltage=%d on chain[%d]\n",
                          "driver-btm-c5.c",0x359e,DAT_00039eb0,1,iVar11);
                }
                fclose(pFVar14);
              }
            }
            iVar12 = dev;
            *local_8c4 = 1;
          }
        }
      }
      iVar11 = iVar11 + 1;
      local_8c4 = local_8c4 + 1;
    } while (iVar11 != 0x10);
  }
  iVar11 = 0;
  do {
    if (*(int *)(dev + (iVar11 + 2) * 4) == 1) {
      if (is_scan_based_on_domain != '\0') {
        if (3 < log_level) {
          pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar14 != (FILE *)0x0) {
            fprintf(pFVar14,"%s:%d:%s: open core three times\n","driver-btm-c5.c",0x35c3,
                    DAT_00039760);
          }
          fclose(pFVar14);
        }
        open_core_one_chain(iVar11,1);
        sleep(2);
        open_core_one_chain(iVar11,1);
        sleep(2);
      }
      open_core_one_chain(iVar11,1);
      sleep(1);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0x10);
  set_working_voltage();
  iVar11 = 0;
  lVar1 = (ulonglong)*(uint *)(dev + 0x48) * 0xcccccccd;
  set_time_out_control
            ((uint)((int)((ulonglong)lVar1 >> 0x20) << 0xc) >> 0xf | 0x80000000,extraout_r1_01,
             (int)lVar1);
  do {
    if ((*(int *)(dev + (iVar11 + 2) * 4) == 1) && ('\0' < *(char *)(dev + iVar11 + 0x458))) {
      uVar13 = 0;
      do {
        set_baud_with_addr(*(undefined *)(dev + 0x542f),0,
                           *(undefined *)(dev + iVar11 * 8 + uVar13 + 0x4e8),iVar11,1,0,1);
        uVar19 = uVar13 + 1 & 0xff;
        check_asic_reg_with_addr(0x1c,*(undefined *)(uVar13 + dev + iVar11 * 8 + 0x4e8),iVar11,1);
        uVar13 = uVar19;
      } while ((int)uVar19 < (int)*(char *)(dev + iVar11 + 0x458));
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0x10);
  if (3 < log_level) {
    pFVar14 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar14 != (FILE *)0x0) {
      fprintf(pFVar14,"%s:%d:%s: start thread for read temp\n","driver-btm-c5.c",0x368e,DAT_00039eb0
             );
    }
    fclose(pFVar14);
  }
  read_temp_id = calloc(1,0x40);
  iVar11 = thr_info_create(read_temp_id,0,0x3d295,read_temp_id);
  if (iVar11 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_860,0x800,"%s: create thread for read temp\n",DAT_00039a3c);
      _applog(7,&local_860,0);
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
  iVar11 = thr_info_create(check_system_work_id,0,0x3bcfd,check_system_work_id);
  if (iVar11 == 0) {
    pthread_detach(*(pthread_t *)((int)check_system_work_id + 0xc));
    iVar12 = dev;
    piVar27 = (int *)(dev + 4);
    iVar11 = 0;
    do {
      piVar27 = piVar27 + 1;
      if (*piVar27 != 0) {
        uVar13 = (uint)*(byte *)(iVar12 + iVar11 + 0x53ec);
        if (uVar13 == 0) {
          iVar25 = 0;
        }
        else {
          iVar25 = 0;
          uVar19 = 0;
          iVar15 = iVar12 + iVar11 * 0x88;
          iVar17 = iVar11;
          do {
            uVar9 = (undefined)iVar17;
            bVar29 = (uVar19 & 7) == 0;
            iVar17 = iVar15 + iVar25;
            if (bVar29) {
              uVar9 = 0x20;
            }
            if (bVar29) {
              iVar25 = iVar25 + 1;
              *(undefined *)(iVar17 + uVar19 + 0x4afc) = uVar9;
            }
            iVar17 = iVar11 * 0x80 + uVar19;
            iVar21 = iVar15 + iVar25 + uVar19;
            uVar19 = uVar19 + 1;
            iVar20 = iVar12 + (iVar17 + 0x15f) * 8;
            iVar17 = 0x6f;
            *(undefined *)(iVar21 + 0x4afc) = 0x6f;
            *(undefined4 *)(iVar20 + 4) = 0;
            *(undefined4 *)(iVar20 + 8) = 0;
          } while (uVar19 != uVar13);
        }
        *(undefined *)(iVar25 + uVar13 + iVar11 * 0x88 + iVar12 + 0x4afc) = 0;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 != 0x10);
    cgtime(DAT_00039ea8);
    cgtime(DAT_00039eac);
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
  snprintf((char *)&local_860,0x800,__format,DAT_000390b8);
  _applog(7,&local_860,0);
  return -6;
}

