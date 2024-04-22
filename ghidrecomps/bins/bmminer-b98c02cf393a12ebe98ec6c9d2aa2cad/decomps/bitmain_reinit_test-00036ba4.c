
void bitmain_reinit_test(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  pthread_mutex_t *ppVar5;
  undefined2 uVar6;
  char cVar7;
  byte bVar8;
  FILE *pFVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  byte *pbVar17;
  byte *pbVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  double dVar22;
  int local_864;
  char acStack_850 [2052];
  
  uVar15 = 0;
  pthread_mutex_lock(DAT_00036ef0);
  memset(dev,0,0x5470);
  *dev = job_start_address_1;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  puVar10 = dev;
  *(undefined *)(dev + 0x14ff) = 100;
  puVar10[1] = 0x320000;
  set_fan_control(0x320000);
  set_reset_allhashboard(1);
  iVar16 = PHY_MEM_NONCE2_JOBID_ADDRESS;
  *(undefined *)((int)dev + 0x542f) = 0x1a;
  set_nonce2_and_job_id_store_address(iVar16);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  do {
    while (dev[uVar15 + 2] == 1) {
      bVar8 = write_EEPROM_iic(1,1,0x90,uVar15 & 0xff,0);
      DAT_00036ef4[uVar15] = bVar8;
      uVar15 = uVar15 + 1;
      if (uVar15 == 0x10) goto LAB_00036c7c;
    }
    uVar15 = uVar15 + 1;
  } while (uVar15 != 0x10);
LAB_00036c7c:
  piVar14 = DAT_00036ef8;
  pbVar18 = DAT_00036ef4;
  dVar4 = DAT_00036ee8;
  dVar3 = DAT_00036ee0;
  dVar2 = DAT_00036ed8;
  dVar1 = DAT_00036ed0;
  iVar20 = 1;
  iVar16 = 0;
  cgsleep_ms(1000);
  do {
    if (dev[iVar16 + 2] == 1) {
      iVar19 = (int)(longlong)
                    (((dVar2 / ((double)(longlong)(int)(uint)*pbVar18 + dVar1) + dVar3) * dVar4) /
                    4.75) / 10;
      iVar21 = iVar19 * 10;
      if (3 < log_level) {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: Chain[J%d] working voltage=%d value=%d\n","driver-btm-c5.c",
                  0x1c20,DAT_00036f00,iVar20,(uint)*pbVar18,iVar21);
        }
        fclose(pFVar9);
      }
      if ((*(char *)(iVar16 * 0x80 + DAT_00036efc) == '}') &&
         (iVar12 = *piVar14,
         iVar12 != iVar21 && iVar12 + iVar19 * -10 < 0 == SBORROW4(iVar12,iVar21))) {
        dVar22 = dVar2 / (((double)(longlong)iVar12 * 4.75) / dVar4 - dVar3) - dVar1;
        uVar15 = (uint)(0.0 < dVar22) * (int)(longlong)dVar22;
        local_864._0_1_ = (byte)uVar15;
        if (log_level < 4) {
          *pbVar18 = (byte)local_864;
        }
        else {
          pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar9 != (FILE *)0x0) {
            fprintf(pFVar9,"%s:%d:%s: Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",
                    "driver-btm-c5.c",0x1c30,DAT_00036f00,iVar20,*piVar14,uVar15 & 0xff);
          }
          fclose(pFVar9);
          uVar15 = log_level;
          *pbVar18 = (byte)local_864;
          if (3 < uVar15) {
            pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar9 != (FILE *)0x0) {
              fprintf(pFVar9,"%s:%d:%s: Chain[J%d] get working voltage=%d\n","driver-btm-c5.c",
                      0x1c38,DAT_00036f00,iVar20,(uint)*pbVar18);
            }
            fclose(pFVar9);
          }
        }
      }
    }
    iVar16 = iVar16 + 1;
    iVar20 = iVar20 + 1;
    piVar14 = piVar14 + 1;
    pbVar18 = pbVar18 + 1;
  } while (iVar16 != 0x10);
  pthread_mutex_unlock(DAT_00036ef0);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar15 = get_dhash_acc_control();
    set_dhash_acc_control(uVar15 & 0xffff70df | 0x8100);
  }
  cgsleep_ms(10);
  *(undefined *)(dev + 0x150b) = 0x72;
  uVar15 = 0;
  local_864 = 1;
  check_asic_reg();
  cgsleep_ms(10);
  do {
    if (dev[uVar15 + 2] == 1) {
      if (log_level < 4) {
        iVar16 = (int)dev + uVar15;
        if (*(char *)(iVar16 + 0x53ec) == 'T') goto LAB_00036f04;
LAB_00036f36:
        ppVar5 = DAT_0003713c;
        iVar20 = 6;
        do {
          *(undefined *)(iVar16 + 0x53ec) = 0;
          set_reset_hashboard(uVar15,1);
          pthread_mutex_lock(ppVar5);
          disable_pic_dac(uVar15 & 0xff);
          pthread_mutex_unlock(ppVar5);
          sleep(1);
          pthread_mutex_lock(ppVar5);
          enable_pic_dac(uVar15 & 0xff);
          pthread_mutex_unlock(ppVar5);
          sleep(2);
          set_reset_hashboard(uVar15,0);
          sleep(1);
          check_asic_reg_oneChain(uVar15,0);
          iVar16 = (int)dev + uVar15;
          if (*(char *)(iVar16 + 0x53ec) == 'T') goto LAB_00036fb0;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        if (*(char *)(iVar16 + 0x53ec) == '\0') {
          dev[uVar15 + 2] = 0;
        }
      }
      else {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x1c7b,DAT_00037140,
                  local_864,(uint)*(byte *)((int)dev + uVar15 + 0x53ec));
        }
        fclose(pFVar9);
        iVar16 = (int)dev + uVar15;
        if (*(char *)(iVar16 + 0x53ec) != 'T') goto LAB_00036f36;
      }
LAB_00036fb0:
      if (3 < log_level) {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: retry Chain[J%d] has %d asic\n","driver-btm-c5.c",0x1c9c,
                  DAT_00037140,local_864,(uint)*(byte *)((int)dev + uVar15 + 0x53ec));
        }
        fclose(pFVar9);
      }
    }
LAB_00036f04:
    uVar15 = uVar15 + 1;
    local_864 = local_864 + 1;
  } while (uVar15 != 0x10);
  software_set_address();
  cgsleep_ms(10);
  uVar6 = config_parameter._12_2_;
  if ((int)((uint)config_parameter[4] << 0x1c) < 0) {
    *(undefined2 *)((int)dev + 0x5443) = config_parameter._12_2_;
    set_frequency(uVar6);
    sprintf((char *)((int)dev + 0x5445),"%u",(uint)*(ushort *)((int)dev + 0x5443));
  }
  cgsleep_ms(10);
  puVar10 = dev;
  cVar7 = opt_debug;
  bVar8 = config_parameter[10];
  uVar13 = (uint)config_parameter[4];
  uVar15 = (uint)config_parameter[10];
  *(byte *)((int)dev + 0x5441) = (byte)((uVar13 << 0x1e) >> 0x1f);
  *(byte *)((int)puVar10 + 0x5442) = bVar8;
  if ((cVar7 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf(acStack_850,0x800,"%s: fan_eft : %d  fan_pwm : %d\n",DAT_00037140,
             (uVar13 << 0x1e) >> 0x1f,uVar15);
    _applog(7,acStack_850,0);
  }
  if (((int)((uint)config_parameter[4] << 0x1e) < 0) && (config_parameter[10] < 0x65)) {
    set_PWM();
  }
  else {
    set_PWM_according_to_temperature();
  }
  puVar10 = dev;
  if ((int)((uint)config_parameter[4] << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      uVar11 = calculate_core_number(*(undefined *)(dev + 0x150b));
      puVar10 = dev;
      iVar16 = __aeabi_idiv(0x1000000,uVar11);
      iVar16 = __aeabi_idiv((uint)*(byte *)((int)puVar10 + 0x542d) * iVar16,
                            *(undefined2 *)((int)puVar10 + 0x5443));
      cVar7 = opt_debug;
      uVar15 = (iVar16 * 0x5a) / 100;
      puVar10[0x12] = uVar15;
      if ((cVar7 != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_850,0x800,"dev->timeout = %d\n");
        _applog(7,acStack_850,0);
        uVar15 = dev[0x12];
        puVar10 = dev;
      }
    }
    else {
      uVar15 = (uint)config_parameter[18] * 1000 + (uint)config_parameter[19];
      dev[0x12] = uVar15;
    }
    if (0x1ffff < uVar15) {
      puVar10[0x12] = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar16 = 0;
  cgsleep_ms(10);
  uVar11 = extraout_r1;
  puVar10 = dev;
  do {
    while ((puVar10[iVar16 + 2] != 1 || (*(char *)((int)puVar10 + iVar16 + 0x53ec) != 'T'))) {
      iVar16 = iVar16 + 1;
      if (iVar16 == 0x10) goto LAB_00037172;
    }
    calibration_sensor_offset(0x98,iVar16);
    iVar16 = iVar16 + 1;
    cgsleep_ms(10);
    uVar11 = extraout_r1_00;
    puVar10 = dev;
  } while (iVar16 != 0x10);
LAB_00037172:
  set_time_out_control
            ((uint)((int)((ulonglong)(uint)puVar10[0x12] * 0xcccccccd >> 0x20) << 0xc) >> 0xf |
             0x80000000,uVar11,(int)((ulonglong)(uint)puVar10[0x12] * 0xcccccccd));
  puVar10 = dev;
  *(undefined *)(dev + 0x14ff) = 100;
  puVar10[1] = 0x320000;
  set_fan_control(0x320000);
  dVar4 = DAT_00037500;
  dVar3 = DAT_000374f8;
  dVar2 = DAT_000374f0;
  dVar1 = DAT_000374e8;
  puVar10 = dev;
  if (opt_fixed_freq == '\0') {
    iVar16 = 0;
    pbVar18 = DAT_00037508;
    do {
      if (puVar10[iVar16 + 2] != 0) {
        piVar14 = puVar10 + 1;
        iVar20 = 0;
        do {
          piVar14 = piVar14 + 1;
          if (*piVar14 == 1) {
            iVar20 = iVar20 + 1;
          }
        } while (puVar10 + 0x11 != piVar14);
        if (3 < iVar20) {
          iVar20 = (int)(longlong)
                        (((dVar2 / ((double)(longlong)(int)(uint)*pbVar18 + dVar1) + dVar3) * dVar4)
                        / 4.75);
          iVar19 = (iVar20 / 10) * 10;
          if (ENABLE_LIMIT_ON_SINGLE_BOARD == '\0') {
            if (opt_economic_mode != '\0') {
              GetTotalRate_part_12();
            }
            if (3 < log_level) {
              pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar9 != (FILE *)0x0) {
                uVar11 = ideal_total_hash_rate;
                if (opt_economic_mode != '\0') {
                  uVar11 = GetTotalRate_part_12();
                }
                fprintf(pFVar9,"%s:%d:%s: miner rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x1d40,DAT_00037510,uVar11,0x3a2,iVar16);
              }
LAB_0003744a:
              fclose(pFVar9);
              if (3 < log_level) {
                pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar9 != (FILE *)0x0) {
                  fprintf(pFVar9,"%s:%d:%s: get PIC voltage=%d on chain[%d], check: must be < %d\n",
                          "driver-btm-c5.c",0x1d5e,DAT_00037510,iVar19,iVar16,0x3a2);
                }
                fclose(pFVar9);
              }
            }
          }
          else {
            GetRealBoardRate(iVar16,ENABLE_LIMIT_ON_SINGLE_BOARD,iVar20 * 0x66666667);
            if (3 < log_level) {
              pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar9 != (FILE *)0x0) {
                uVar11 = GetRealBoardRate(iVar16);
                fprintf(pFVar9,"%s:%d:%s: single board rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x1d3a,DAT_00037510,uVar11,0x3a2,iVar16);
              }
              goto LAB_0003744a;
            }
          }
          puVar10 = dev;
          if (0x3a2 < iVar19) {
            if (3 < log_level) {
              pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,
                        "%s:%d:%s: will set the voltage limited on chain[%d], change voltage=%d\n",
                        "driver-btm-c5.c",0x1d75,DAT_00037660,iVar16,0x3a2);
              }
              fclose(pFVar9);
              if (3 < log_level) {
                pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
                if (pFVar9 != (FILE *)0x0) {
                  fprintf(pFVar9,"%s:%d:%s: now set pic voltage=%d on chain[%d]\n","driver-btm-c5.c"
                          ,0x1d78,DAT_00037660,1,iVar16);
                }
                fclose(pFVar9);
              }
            }
            puVar10 = dev;
            *pbVar18 = 1;
          }
        }
      }
      iVar16 = iVar16 + 1;
      pbVar18 = pbVar18 + 1;
    } while (iVar16 != 0x10);
  }
  ppVar5 = DAT_00037514;
  pbVar18 = DAT_0003750c;
  dVar4 = DAT_00037500;
  dVar3 = DAT_000374f8;
  dVar2 = DAT_000374f0;
  dVar1 = DAT_000374e8;
  iVar16 = 1;
  pbVar17 = DAT_0003750c + -0x10;
  while( true ) {
    piVar14 = puVar10 + ((int)pbVar17 - (int)DAT_00037508) + 2;
    puVar10 = dev;
    if (*piVar14 == 1) {
      open_core_one_chain((int)pbVar17 - (int)DAT_00037508,1);
      sleep(1);
      pthread_mutex_lock(ppVar5);
      pthread_mutex_unlock(ppVar5);
      puVar10 = dev;
      if (3 < log_level) {
        pFVar9 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar9 != (FILE *)0x0) {
          fprintf(pFVar9,"%s:%d:%s: Chain[J%d] set working voltage=%d [%d]\n","driver-btm-c5.c",
                  0x1ded,DAT_00037510,iVar16,
                  ((int)(longlong)
                        (((dVar2 / ((double)(longlong)(int)(uint)*pbVar17 + dVar1) + dVar3) * dVar4)
                        / 4.75) / 10) * 10,(uint)*pbVar17);
        }
        fclose(pFVar9);
        puVar10 = dev;
      }
    }
    if (pbVar18 == pbVar17 + 1) break;
    iVar16 = iVar16 + 1;
    pbVar17 = pbVar17 + 1;
    dev = puVar10;
  }
  dev = puVar10;
  return;
}

