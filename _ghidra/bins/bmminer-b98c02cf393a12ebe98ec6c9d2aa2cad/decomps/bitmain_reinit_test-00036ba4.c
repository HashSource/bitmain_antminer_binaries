
void bitmain_reinit_test(void)

{
  byte bVar1;
  undefined2 uVar2;
  char cVar3;
  undefined1 uVar4;
  FILE *pFVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int iVar15;
  int iVar16;
  double dVar17;
  int iVar18;
  int local_864;
  char acStack_850 [2052];
  
  uVar11 = 0;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  memset(dev,0,0x5470);
  *dev = job_start_address_1;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  puVar6 = dev;
  *(undefined1 *)(dev + 0x14ff) = 100;
  puVar6[1] = 0x320000;
  set_fan_control(0x320000);
  set_reset_allhashboard(1);
  iVar12 = PHY_MEM_NONCE2_JOBID_ADDRESS;
  *(undefined1 *)((int)dev + 0x542f) = 0x1a;
  set_nonce2_and_job_id_store_address(iVar12);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  do {
    while (dev[uVar11 + 2] == 1) {
      uVar4 = write_EEPROM_iic(1,1,0x90,uVar11 & 0xff,0);
      chain_voltage_pic[uVar11] = uVar4;
      uVar11 = uVar11 + 1;
      if (uVar11 == 0x10) goto LAB_00036c7c;
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 != 0x10);
LAB_00036c7c:
  puVar14 = chain_voltage_value;
  puVar13 = chain_voltage_pic;
  iVar15 = 1;
  iVar12 = 0;
  cgsleep_ms(1000);
  do {
    if (dev[iVar12 + 2] == 1) {
      iVar18 = (int)(longlong)
                    (((364.0704 / ((double)(byte)*puVar13 + 30.72) + 32.79) * 100.0) / 4.75) / 10;
      iVar16 = iVar18 * 10;
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Chain[J%d] working voltage=%d value=%d\n","driver-btm-c5.c",
                  0x1c20,"bitmain_reinit_test",iVar15,(uint)(byte)*puVar13,iVar16);
        }
        fclose(pFVar5);
      }
      if ((chain_pic_buf[iVar12 * 0x80] == '}') &&
         (iVar8 = *(int *)puVar14,
         iVar8 != iVar16 && iVar8 + iVar18 * -10 < 0 == SBORROW4(iVar8,iVar16))) {
        dVar17 = 364.0704 / (((double)(longlong)iVar8 * 4.75) / 100.0 - 32.79) - 30.72;
        uVar11 = (uint)(0.0 < dVar17) * (int)(longlong)dVar17;
        local_864._0_1_ = (byte)uVar11;
        if (log_level < 4) {
          *puVar13 = (byte)local_864;
        }
        else {
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",
                    "driver-btm-c5.c",0x1c30,"bitmain_reinit_test",iVar15,*(int *)puVar14,
                    uVar11 & 0xff);
          }
          fclose(pFVar5);
          uVar11 = log_level;
          *puVar13 = (byte)local_864;
          if (3 < uVar11) {
            pFVar5 = fopen(log_file,"a+");
            if (pFVar5 != (FILE *)0x0) {
              fprintf(pFVar5,"%s:%d:%s: Chain[J%d] get working voltage=%d\n","driver-btm-c5.c",
                      0x1c38,"bitmain_reinit_test",iVar15,(uint)(byte)*puVar13);
            }
            fclose(pFVar5);
          }
        }
      }
    }
    iVar12 = iVar12 + 1;
    iVar15 = iVar15 + 1;
    puVar14 = (undefined1 *)((int)puVar14 + 4);
    puVar13 = puVar13 + 1;
  } while (iVar12 != 0x10);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar11 = get_dhash_acc_control();
    set_dhash_acc_control(uVar11 & 0xffff70df | 0x8100);
  }
  cgsleep_ms(10);
  *(undefined1 *)(dev + 0x150b) = 0x72;
  uVar11 = 0;
  local_864 = 1;
  check_asic_reg();
  cgsleep_ms(10);
  do {
    if (dev[uVar11 + 2] == 1) {
      if (log_level < 4) {
        iVar12 = (int)dev + uVar11;
        if (*(char *)(iVar12 + 0x53ec) == 'T') goto LAB_00036f04;
LAB_00036f36:
        iVar15 = 6;
        do {
          *(undefined1 *)(iVar12 + 0x53ec) = 0;
          set_reset_hashboard(uVar11,1);
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          disable_pic_dac(uVar11 & 0xff);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          sleep(1);
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          enable_pic_dac(uVar11 & 0xff);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          sleep(2);
          set_reset_hashboard(uVar11,0);
          sleep(1);
          check_asic_reg_oneChain(uVar11,0);
          iVar12 = (int)dev + uVar11;
          if (*(char *)(iVar12 + 0x53ec) == 'T') goto LAB_00036fb0;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        if (*(char *)(iVar12 + 0x53ec) == '\0') {
          dev[uVar11 + 2] = 0;
        }
      }
      else {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x1c7b,
                  "bitmain_reinit_test",local_864,(uint)*(byte *)((int)dev + uVar11 + 0x53ec));
        }
        fclose(pFVar5);
        iVar12 = (int)dev + uVar11;
        if (*(char *)(iVar12 + 0x53ec) != 'T') goto LAB_00036f36;
      }
LAB_00036fb0:
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: retry Chain[J%d] has %d asic\n","driver-btm-c5.c",0x1c9c,
                  "bitmain_reinit_test",local_864,(uint)*(byte *)((int)dev + uVar11 + 0x53ec));
        }
        fclose(pFVar5);
      }
    }
LAB_00036f04:
    uVar11 = uVar11 + 1;
    local_864 = local_864 + 1;
  } while (uVar11 != 0x10);
  software_set_address();
  cgsleep_ms(10);
  uVar2 = config_parameter._12_2_;
  if ((int)((uint)config_parameter[4] << 0x1c) < 0) {
    *(undefined2 *)((int)dev + 0x5443) = config_parameter._12_2_;
    set_frequency(uVar2);
    sprintf((char *)((int)dev + 0x5445),"%u",(uint)*(ushort *)((int)dev + 0x5443));
  }
  cgsleep_ms(10);
  puVar6 = dev;
  cVar3 = opt_debug;
  bVar1 = config_parameter[10];
  uVar9 = (uint)config_parameter[4];
  uVar11 = (uint)config_parameter[10];
  *(byte *)((int)dev + 0x5441) = (byte)((uVar9 << 0x1e) >> 0x1f);
  *(byte *)((int)puVar6 + 0x5442) = bVar1;
  if ((cVar3 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf(acStack_850,0x800,"%s: fan_eft : %d  fan_pwm : %d\n","bitmain_reinit_test",
             (uVar9 << 0x1e) >> 0x1f,uVar11);
    _applog(7,acStack_850,0);
  }
  if (((int)((uint)config_parameter[4] << 0x1e) < 0) && (config_parameter[10] < 0x65)) {
    set_PWM();
  }
  else {
    set_PWM_according_to_temperature();
  }
  puVar6 = dev;
  if ((int)((uint)config_parameter[4] << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      uVar7 = calculate_core_number(*(undefined1 *)(dev + 0x150b));
      puVar6 = dev;
      iVar12 = __aeabi_idiv(0x1000000,uVar7);
      iVar12 = __aeabi_idiv((uint)*(byte *)((int)puVar6 + 0x542d) * iVar12,
                            *(undefined2 *)((int)puVar6 + 0x5443));
      cVar3 = opt_debug;
      uVar11 = (iVar12 * 0x5a) / 100;
      puVar6[0x12] = uVar11;
      if ((cVar3 != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_850,0x800,"dev->timeout = %d\n");
        _applog(7,acStack_850,0);
        uVar11 = dev[0x12];
        puVar6 = dev;
      }
    }
    else {
      uVar11 = (uint)config_parameter[0x12] * 1000 + (uint)config_parameter[0x13];
      dev[0x12] = uVar11;
    }
    if (0x1ffff < uVar11) {
      puVar6[0x12] = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar12 = 0;
  cgsleep_ms(10);
  uVar7 = extraout_r1;
  puVar6 = dev;
  do {
    while ((puVar6[iVar12 + 2] != 1 || (*(char *)((int)puVar6 + iVar12 + 0x53ec) != 'T'))) {
      iVar12 = iVar12 + 1;
      if (iVar12 == 0x10) goto LAB_00037172;
    }
    calibration_sensor_offset(0x98,iVar12);
    iVar12 = iVar12 + 1;
    cgsleep_ms(10);
    uVar7 = extraout_r1_00;
    puVar6 = dev;
  } while (iVar12 != 0x10);
LAB_00037172:
  set_time_out_control
            ((uint)((int)((ulonglong)(uint)puVar6[0x12] * 0xcccccccd >> 0x20) << 0xc) >> 0xf |
             0x80000000,uVar7,(int)((ulonglong)(uint)puVar6[0x12] * 0xcccccccd));
  puVar6 = dev;
  *(undefined1 *)(dev + 0x14ff) = 100;
  puVar6[1] = 0x320000;
  set_fan_control(0x320000);
  puVar6 = dev;
  if (opt_fixed_freq == '\0') {
    puVar13 = chain_voltage_pic;
    iVar12 = 0;
    do {
      if (puVar6[iVar12 + 2] != 0) {
        piVar10 = puVar6 + 1;
        iVar15 = 0;
        do {
          piVar10 = piVar10 + 1;
          if (*piVar10 == 1) {
            iVar15 = iVar15 + 1;
          }
        } while (puVar6 + 0x11 != piVar10);
        if (3 < iVar15) {
          iVar18 = (int)(longlong)
                        (((364.0704 / ((double)(byte)*puVar13 + 30.72) + 32.79) * 100.0) / 4.75);
          iVar15 = (iVar18 / 10) * 10;
          if (ENABLE_LIMIT_ON_SINGLE_BOARD == '\0') {
            if (opt_economic_mode != '\0') {
              GetTotalRate_part_12();
            }
            if (3 < log_level) {
              pFVar5 = fopen(log_file,"a+");
              if (pFVar5 != (FILE *)0x0) {
                uVar7 = ideal_total_hash_rate;
                if (opt_economic_mode != '\0') {
                  uVar7 = GetTotalRate_part_12();
                }
                fprintf(pFVar5,"%s:%d:%s: miner rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x1d40,"bitmain_reinit_test",uVar7,0x3a2,iVar12);
              }
LAB_0003744a:
              fclose(pFVar5);
              if (3 < log_level) {
                pFVar5 = fopen(log_file,"a+");
                if (pFVar5 != (FILE *)0x0) {
                  fprintf(pFVar5,"%s:%d:%s: get PIC voltage=%d on chain[%d], check: must be < %d\n",
                          "driver-btm-c5.c",0x1d5e,"bitmain_reinit_test",iVar15,iVar12,0x3a2);
                }
                fclose(pFVar5);
              }
            }
          }
          else {
            GetRealBoardRate(iVar12,ENABLE_LIMIT_ON_SINGLE_BOARD,iVar18 * 0x66666667);
            if (3 < log_level) {
              pFVar5 = fopen(log_file,"a+");
              if (pFVar5 != (FILE *)0x0) {
                uVar7 = GetRealBoardRate(iVar12);
                fprintf(pFVar5,"%s:%d:%s: single board rate=%d voltage limit=%d on chain[%d]\n",
                        "driver-btm-c5.c",0x1d3a,"bitmain_reinit_test",uVar7,0x3a2,iVar12);
              }
              goto LAB_0003744a;
            }
          }
          puVar6 = dev;
          if (0x3a2 < iVar15) {
            if (3 < log_level) {
              pFVar5 = fopen(log_file,"a+");
              if (pFVar5 != (FILE *)0x0) {
                fprintf(pFVar5,
                        "%s:%d:%s: will set the voltage limited on chain[%d], change voltage=%d\n",
                        "driver-btm-c5.c",0x1d75,"bitmain_reinit_test",iVar12,0x3a2);
              }
              fclose(pFVar5);
              if (3 < log_level) {
                pFVar5 = fopen(log_file,"a+");
                if (pFVar5 != (FILE *)0x0) {
                  fprintf(pFVar5,"%s:%d:%s: now set pic voltage=%d on chain[%d]\n","driver-btm-c5.c"
                          ,0x1d78,"bitmain_reinit_test",1,iVar12);
                }
                fclose(pFVar5);
              }
            }
            puVar6 = dev;
            *puVar13 = 1;
          }
        }
      }
      iVar12 = iVar12 + 1;
      puVar13 = puVar13 + 1;
    } while (iVar12 != 0x10);
  }
  iVar12 = 1;
  puVar13 = chain_voltage_pic;
  while( true ) {
    piVar10 = puVar6 + (int)(puVar13 + -0x7e566);
    puVar6 = dev;
    if (*piVar10 == 1) {
      open_core_one_chain(puVar13 + -0x7e568,1);
      sleep(1);
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      puVar6 = dev;
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Chain[J%d] set working voltage=%d [%d]\n","driver-btm-c5.c",
                  0x1ded,"bitmain_reinit_test",iVar12,
                  ((int)(longlong)
                        (((364.0704 / ((double)(longlong)(int)(uint)(byte)*puVar13 + 30.72) + 32.79)
                         * 100.0) / 4.75) / 10) * 10,(uint)(byte)*puVar13);
        }
        fclose(pFVar5);
        puVar6 = dev;
      }
    }
    if (puVar13 == chain_voltage_pic + 0xf) break;
    iVar12 = iVar12 + 1;
    puVar13 = puVar13 + 1;
    dev = puVar6;
  }
  dev = puVar6;
  return;
}

