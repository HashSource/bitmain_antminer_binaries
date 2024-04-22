
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void re_open_core(int param_1)

{
  pthread_mutex_t *__mutex;
  undefined2 uVar1;
  char cVar2;
  undefined uVar3;
  uint uVar4;
  FILE *pFVar5;
  undefined4 uVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar7;
  undefined4 *puVar8;
  void *__dest;
  void *pvVar9;
  void *__src;
  uint uVar10;
  int *piVar11;
  int iVar12;
  void *pvVar13;
  int local_850;
  char acStack_828 [2052];
  
  if (3 < log_level) {
    pFVar5 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: re_open_core enter\n","driver-btm-c5.c",0x3d1a,DAT_0003bc44);
    }
    fclose(pFVar5);
  }
  startCheckNetworkJob = 0;
  enable_read_temp = 0;
  doTestPatten = 1;
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  puVar8 = dev;
  __dest = DAT_0003b8b8;
  *(undefined *)(dev + 0x14ff) = 0x14;
  puVar8[1] = &DAT_000a0028;
  set_fan_control(&DAT_000a0028);
  uVar4 = get_dhash_acc_control();
  __src = DAT_0003b8bc;
  set_dhash_acc_control(uVar4 & 0xffffffbf);
  pvVar13 = (void *)((int)__dest + 0x800);
  sleep(3);
  uVar4 = get_dhash_acc_control();
  set_dhash_acc_control(uVar4 & 0xffffffbf);
  sleep(2);
  piVar11 = dev + 1;
  do {
    while (piVar11 = piVar11 + 1, *piVar11 != 1) {
      __dest = (void *)((int)__dest + 0x80);
      __src = (void *)((int)__src + 0x100);
      if (pvVar13 == __dest) goto LAB_0003b5f0;
    }
    pvVar9 = (void *)((int)__dest + 0x80);
    memcpy(__dest,__src,0x80);
    __src = (void *)((int)__src + 0x100);
    __dest = pvVar9;
  } while (pvVar13 != pvVar9);
LAB_0003b5f0:
  uVar4 = 0;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  doTestPatten = 0;
  pthread_mutex_lock(DAT_0003b8c0);
  memset(dev,0,0x5470);
  *dev = job_start_address_1;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  puVar8 = dev;
  *(undefined *)(dev + 0x14ff) = 100;
  puVar8[1] = 0x320000;
  set_fan_control(0x320000);
  set_reset_allhashboard(1);
  *(undefined *)((int)dev + 0x542f) = 0x1a;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  do {
    while (dev[uVar4 + 2] != 1) {
      uVar4 = uVar4 + 1;
      if (uVar4 == 0x10) goto LAB_0003b6da;
    }
    uVar3 = write_EEPROM_iic(1,1,0x90,uVar4 & 0xff,0);
    chain_voltage_pic[uVar4] = uVar3;
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x10);
LAB_0003b6da:
  pthread_mutex_unlock(DAT_0003b8c0);
  quickly_set_to_highest_voltage();
  sleep(1);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar4 = get_dhash_acc_control();
    set_dhash_acc_control(uVar4 & 0xffff70df | 0x8100);
  }
  __mutex = DAT_0003b8c0;
  cgsleep_ms(10);
  *(undefined *)(dev + 0x150b) = 0x72;
  local_850 = 1;
  uVar4 = 0;
  check_asic_reg();
  cgsleep_ms(10);
  do {
    if (dev[uVar4 + 2] == 1) {
      if (3 < log_level) {
        pFVar5 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3dbb,DAT_0003bc44,
                  local_850,(uint)*(byte *)((int)dev + uVar4 + 0x53ec));
        }
        fclose(pFVar5);
      }
      iVar12 = 0;
      while( true ) {
        iVar7 = (int)dev + uVar4;
        if (*(char *)(iVar7 + 0x53ec) == 'T') break;
        if (iVar12 == 0x14) {
          if (*(char *)(iVar7 + 0x53ec) == '\0') {
            dev[uVar4 + 2] = 0;
          }
          break;
        }
        if (3 < log_level) {
          pFVar5 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: i = %d, retry_count = %d, dev->chain_asic_num[i] = %d\n",
                    "driver-btm-c5.c",0x3dbf,DAT_0003b8c4,uVar4,iVar12,
                    (uint)*(byte *)((int)dev + uVar4 + 0x53ec));
          }
          fclose(pFVar5);
          iVar7 = (int)dev + uVar4;
        }
        *(undefined *)(iVar7 + 0x53ec) = 0;
        iVar12 = iVar12 + 1;
        set_reset_hashboard(uVar4);
        sleep(1);
        pthread_mutex_lock(__mutex);
        disable_pic_dac(uVar4 & 0xff);
        pthread_mutex_unlock(__mutex);
        sleep(1);
        pthread_mutex_lock(__mutex);
        enable_pic_dac(uVar4 & 0xff);
        pthread_mutex_unlock(__mutex);
        sleep(2);
        set_reset_hashboard(uVar4,0);
        sleep(2);
        check_asic_reg_oneChain(uVar4,0);
        if (3 < log_level) {
          pFVar5 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: retry Chain[J%d] has %d asic\n","driver-btm-c5.c",0x3dd6,
                    DAT_0003b8c4,local_850,(uint)*(byte *)((int)dev + uVar4 + 0x53ec));
          }
          fclose(pFVar5);
        }
      }
    }
    uVar4 = uVar4 + 1;
    local_850 = local_850 + 1;
  } while (uVar4 != 0x10);
  software_set_address();
  cgsleep_ms(10);
  uVar1 = config_parameter._12_2_;
  if ((int)((uint)config_parameter[4] << 0x1c) < 0) {
    *(undefined2 *)((int)dev + 0x5443) = config_parameter._12_2_;
    set_frequency(uVar1);
    sprintf((char *)((int)dev + 0x5445),"%u",(uint)*(ushort *)((int)dev + 0x5443));
  }
  cgsleep_ms(10);
  puVar8 = dev;
  uVar3 = config_parameter[10];
  uVar4 = (uint)config_parameter[4];
  *(byte *)((int)dev + 0x5441) = (byte)((uVar4 << 0x1e) >> 0x1f);
  *(undefined *)((int)puVar8 + 0x5442) = uVar3;
  if ((int)(uVar4 << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      uVar6 = calculate_core_number(*(undefined *)(puVar8 + 0x150b));
      puVar8 = dev;
      iVar12 = __aeabi_idiv(0x1000000,uVar6);
      iVar12 = __aeabi_idiv((uint)*(byte *)((int)puVar8 + 0x542d) * iVar12,
                            *(undefined2 *)((int)puVar8 + 0x5443));
      cVar2 = opt_debug;
      uVar4 = (iVar12 * 0x5a) / 100;
      puVar8[0x12] = uVar4;
      if ((cVar2 != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"dev->timeout = %d\n");
        _applog(7,acStack_828,0);
        uVar4 = dev[0x12];
        puVar8 = dev;
      }
    }
    else {
      uVar4 = (uint)config_parameter[18] * 1000 + (uint)config_parameter[19];
      puVar8[0x12] = uVar4;
    }
    if (0x1ffff < uVar4) {
      puVar8[0x12] = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar12 = 0;
  cgsleep_ms(10);
  uVar6 = extraout_r1;
  puVar8 = dev;
  do {
    while ((puVar8[iVar12 + 2] != 1 || (*(char *)((int)puVar8 + iVar12 + 0x53ec) != 'T'))) {
      iVar12 = iVar12 + 1;
      if (iVar12 == 0x10) goto LAB_0003b9ba;
    }
    calibration_sensor_offset(0x98,iVar12);
    iVar12 = iVar12 + 1;
    cgsleep_ms(10);
    uVar6 = extraout_r1_00;
    puVar8 = dev;
  } while (iVar12 != 0x10);
LAB_0003b9ba:
  iVar12 = 0;
  set_time_out_control
            ((uint)((int)((ulonglong)(uint)puVar8[0x12] * 0xcccccccd >> 0x20) << 0xc) >> 0xf |
             0x80000000,uVar6,(int)((ulonglong)(uint)puVar8[0x12] * 0xcccccccd));
  puVar8 = dev;
  *(undefined *)(dev + 0x14ff) = 100;
  puVar8[1] = 0x320000;
  set_fan_control(0x320000);
  do {
    while (dev[iVar12 + 2] == 1) {
      open_core_one_chain(iVar12,1);
      iVar12 = iVar12 + 1;
      sleep(1);
      if (iVar12 == 0x10) goto LAB_0003ba14;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 != 0x10);
LAB_0003ba14:
  doTestPatten = 1;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  uVar4 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar4 | 0x10000);
  if (opt_multi_version == 0) {
    set_time_out_control(dev[0x12] & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(dev[0x12] * opt_multi_version & 0x1ffffU | 0x80000000);
  }
  iVar12 = 0;
  do {
    while ((dev[iVar12 + 2] == 1 && ('\0' < *(char *)((int)dev + iVar12 + 0x458)))) {
      uVar4 = 0;
      do {
        uVar10 = uVar4 + 1 & 0xff;
        set_baud_with_addr(*(undefined *)((int)dev + 0x542f),0,
                           *(undefined *)((int)dev + uVar4 + iVar12 * 8 + 0x4e8),iVar12,1,0,1);
        check_asic_reg_with_addr
                  (0x1c,*(undefined *)((int)dev + uVar4 + iVar12 * 8 + 0x4e8),iVar12,1);
        uVar4 = uVar10;
      } while ((int)uVar10 < (int)*(char *)((int)dev + iVar12 + 0x458));
      iVar12 = iVar12 + 1;
      if (iVar12 == 0x10) goto LAB_0003bae8;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 != 0x10);
LAB_0003bae8:
  doTestPatten = 0;
  pthread_mutex_unlock(DAT_0003bc48);
  clear_nonce_fifo();
  if (last_job_buffer[0] != '\x17') {
    re_send_last_job_part_15();
  }
  cgtime(DAT_0003bc4c);
  cgtime(DAT_0003bc50);
  puVar8 = dev;
  *(undefined *)(dev + 0x14ff) = 0x14;
  puVar8[1] = &DAT_000a0028;
  startCheckNetworkJob = 1;
  enable_read_temp = 1;
  set_fan_control(&DAT_000a0028);
  if (param_1 == 0) {
    set_working_voltage();
  }
  else if (opt_fixed_freq == '\0') {
    set_iic_power_to_higher_voltage();
  }
  reCalculateAVG();
  if (3 < log_level) {
    pFVar5 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: reopen core end\n","driver-btm-c5.c",0x3ede,DAT_0003bc44);
    }
    fclose(pFVar5);
    return;
  }
  return;
}

