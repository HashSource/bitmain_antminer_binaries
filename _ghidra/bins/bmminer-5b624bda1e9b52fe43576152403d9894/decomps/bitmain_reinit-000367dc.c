
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bitmain_reinit(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint16_t frequency;
  uchar uVar4;
  int iVar5;
  all_parameters *paVar6;
  _Bool _Var7;
  uint uVar8;
  all_parameters *paVar9;
  uint uVar10;
  all_parameters *paVar11;
  all_parameters *paVar12;
  int iVar13;
  int iVar14;
  uchar vol_pic;
  int iVar15;
  double dVar16;
  char logstr [256];
  char tmp42 [2048];
  uchar chain;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  memset(dev,0,0x301c);
  dev->current_job_start_address = job_start_address_1;
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_PWM('d');
  paVar12 = dev;
  *axi_fpga_addr = 0x80000000;
  paVar12->baud = '\x1a';
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  check_chain();
  set_reset_allhashboard(1);
  iVar14 = 0;
  do {
    while (dev->chain_exist[iVar14] != 1) {
      iVar14 = iVar14 + 1;
      if (iVar14 == 0x10) goto LAB_0003689e;
    }
    reset_iic_pic((uchar)iVar14);
    iVar13 = iVar14 + 1;
    jump_to_app_CheckAndRestorePIC_T9_18(iVar14);
    iVar14 = iVar13;
  } while (iVar13 != 0x10);
LAB_0003689e:
  iVar14 = 0;
  sleep(1);
  do {
    while (dev->chain_exist[iVar14] != 1) {
      iVar14 = iVar14 + 1;
      if (iVar14 == 0x10) goto LAB_000368fa;
    }
    chain = (uchar)iVar14;
    uVar4 = get_pic_voltage(chain);
    iVar13 = fpga_version;
    chain_voltage_pic[iVar14] = uVar4;
    if (iVar13 < 0xe) {
      if (iVar14 % 3 == 0) goto LAB_00036c54;
    }
    else if (iVar14 - 1U < 3) {
LAB_00036c54:
      set_voltage_T9_18_into_PIC(chain,'\x01');
    }
    iVar14 = iVar14 + 1;
    disable_pic_dac(chain);
  } while (iVar14 != 0x10);
LAB_000368fa:
  cgsleep_ms(1000);
  iVar13 = 1;
  iVar14 = 0;
  paVar12 = dev;
  do {
    while (paVar12->chain_exist[iVar14] != 1) {
      iVar14 = iVar14 + 1;
      iVar13 = iVar13 + 1;
      if (iVar14 == 0x10) goto LAB_000369a6;
    }
    iVar2 = (int)(longlong)
                 (((364.0704 / ((double)(longlong)(int)(uint)chain_voltage_pic[iVar14] + 30.72) +
                   32.79) * 100.0) / 4.75) / 10;
    iVar15 = iVar2 * 10;
    sprintf(logstr,"Chain[J%d] working voltage=%d value=%d\n",iVar13,(uint)chain_voltage_pic[iVar14]
            ,iVar15);
    writeInitLogFile(logstr);
    iVar5 = getChainPICMagicNumber(iVar14);
    if ((iVar5 == 0x7d) &&
       (iVar5 = chain_voltage_value[iVar14],
       iVar5 != iVar15 && iVar5 + iVar2 * -10 < 0 == SBORROW4(iVar5,iVar15))) {
      dVar16 = 364.0704 / (((double)(longlong)iVar5 * 4.75) / 100.0 - 32.79) - 30.72;
      uVar10 = (uint)(0.0 < dVar16) * (int)(longlong)dVar16;
      uVar8 = uVar10 & 0xff;
      sprintf(logstr,"Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",iVar13,iVar5,uVar8);
      writeInitLogFile(logstr);
      chain_voltage_pic[iVar14] = (uchar)uVar10;
      sprintf(logstr,"Chain[J%d] get working voltage=%d\n",iVar13,uVar8);
      writeInitLogFile(logstr);
    }
    iVar14 = iVar14 + 1;
    iVar13 = iVar13 + 1;
    paVar12 = dev;
  } while (iVar14 != 0x10);
LAB_000369a6:
  iVar14 = 0;
  while( true ) {
    puVar3 = paVar12->chain_exist;
    paVar12 = dev;
    if (puVar3[iVar14] == 1) {
      enable_pic_dac((uchar)iVar14);
      paVar12 = dev;
    }
    dev = paVar12;
    if (iVar14 == 0xf) break;
    iVar14 = iVar14 + 1;
  }
  sleep(5);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  cgsleep_ms(2000);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | 0x8000 | uVar8 & 0xffff7fdf);
  }
  cgsleep_ms(10);
  dev->corenum = 'r';
  check_asic_reg(0);
  cgsleep_ms(10);
  iVar14 = 1;
  do {
    while (iVar13 = iVar14 + 1, dev->chain_exist[iVar14 + -1] != 1) {
LAB_00036a6c:
      iVar14 = iVar13;
      if (iVar13 == 0x11) goto LAB_00036ab6;
    }
    sprintf(logstr,"Chain[J%d] has %d asic\n",iVar14,(uint)*(byte *)((int)dev->temp + iVar14 + 0x3f)
           );
    writeInitLogFile(logstr);
    if (*(char *)((int)dev->temp + iVar14 + 0x3f) != '\0') goto LAB_00036a6c;
    dev->chain_exist[iVar14 + -1] = 0;
    iVar14 = iVar13;
  } while (iVar13 != 0x11);
LAB_00036ab6:
  software_set_address();
  cgsleep_ms(10);
  frequency = config_parameter.frequency;
  if ((int)((uint)(byte)config_parameter._4_1_ << 0x1c) < 0) {
    dev->frequency = config_parameter.frequency;
    set_frequency(frequency);
    sprintf(dev->frequency_t,"%u",(uint)dev->frequency);
  }
  cgsleep_ms(10);
  paVar12 = dev;
  uVar4 = config_parameter.fan_pwm_percent;
  _Var7 = opt_debug;
  uVar10 = (uint)(byte)config_parameter._4_1_;
  uVar8 = (uint)config_parameter.fan_pwm_percent;
  dev->fan_eft = (byte)((uVar10 << 0x1e) >> 0x1f);
  paVar12->fan_pwm = uVar4;
  if ((_Var7 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: fan_eft : %d\tfan_pwm : %d\n","bitmain_reinit",
             (uVar10 << 0x1e) >> 0x1f,uVar8);
    _applog(7,tmp42,false);
  }
  if (((int)((uint)(byte)config_parameter._4_1_ << 0x1e) < 0) &&
     (config_parameter.fan_pwm_percent < 0x65)) {
    set_PWM(config_parameter.fan_pwm_percent);
  }
  else {
    set_PWM_according_to_temperature();
  }
  paVar12 = dev;
  if ((int)((uint)(byte)config_parameter._4_1_ << 0x1d) < 0) {
    if (config_parameter._18_2_ == 0) {
      iVar14 = calculate_core_number((uint)dev->corenum);
      paVar12 = dev;
      iVar14 = __aeabi_idiv(0x1000000,iVar14);
      iVar14 = __aeabi_idiv((uint)paVar12->addrInterval * iVar14,paVar12->frequency);
      _Var7 = opt_debug;
      uVar8 = (iVar14 * 0x5a) / 100;
      paVar12->timeout = uVar8;
      if ((_Var7 != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"dev->timeout = %d\n");
        _applog(7,tmp42,false);
        uVar8 = dev->timeout;
        paVar12 = dev;
      }
    }
    else {
      uVar8 = (uint)config_parameter.timeout_data_integer * 1000 +
              (uint)config_parameter.timeout_data_fractions;
      dev->timeout = uVar8;
    }
    if (0x1ffff < uVar8) {
      paVar12->timeout = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar14 = 0;
  cgsleep_ms(10);
  paVar12 = dev;
  do {
    while ((paVar12->chain_exist[iVar14] != 1 || (paVar12->chain_asic_num[iVar14] != '\x12'))) {
      iVar14 = iVar14 + 1;
      if (iVar14 == 0x10) goto LAB_00036bbc;
    }
    calibration_sensor_offset(0x98,iVar14);
    iVar14 = iVar14 + 1;
    cgsleep_ms(10);
    paVar12 = dev;
  } while (iVar14 != 0x10);
LAB_00036bbc:
  iVar14 = fpga_version;
  uVar8 = 0;
  paVar6 = paVar12;
  paVar9 = paVar12;
  paVar11 = paVar12;
  do {
    if ((paVar11->chain_exist[0] == 1) && (paVar12->chain_asic_num[uVar8] == '\x12')) {
      if (iVar14 < 0xe) {
        iVar13 = (int)uVar8 / 3;
        if ((int)uVar8 % 3 != 1) {
          paVar6->chain_asic_temp_num[0] = paVar12->chain_asic_temp_num[iVar13 * 3 + 1];
          paVar9->TempChipAddr[0][0] = paVar12->TempChipAddr[iVar13 * 3 + 1][0];
          paVar9->TempChipAddr[0][1] = paVar12->TempChipAddr[iVar13 * 3 + 1][1];
        }
      }
      else if (uVar8 < 0xe) {
        uVar10 = 1 << (uVar8 & 0xff);
        if ((uVar10 & 0x2008) == 0) {
          if ((uVar10 & 0x804) == 0) {
            if ((uVar10 & 0x202) != 0) {
              paVar6->chain_asic_temp_num[0] = paVar12->chain_asic_temp_num[8];
              paVar9->TempChipAddr[0][0] = paVar12->TempChipAddr[8][0];
              paVar9->TempChipAddr[0][1] = paVar12->TempChipAddr[8][1];
            }
          }
          else {
            paVar6->chain_asic_temp_num[0] = paVar12->chain_asic_temp_num[10];
            paVar9->TempChipAddr[0][0] = paVar12->TempChipAddr[10][0];
            paVar9->TempChipAddr[0][1] = paVar12->TempChipAddr[10][1];
          }
        }
        else {
          paVar6->chain_asic_temp_num[0] = paVar12->chain_asic_temp_num[0xc];
          paVar9->TempChipAddr[0][0] = paVar12->TempChipAddr[0xc][0];
          paVar9->TempChipAddr[0][1] = paVar12->TempChipAddr[0xc][1];
        }
      }
    }
    uVar8 = uVar8 + 1;
    paVar11 = (all_parameters *)&paVar11->pwm_value;
    paVar6 = (all_parameters *)((int)&paVar6->current_job_start_address + 1);
    paVar9 = (all_parameters *)paVar9->chain_exist;
  } while (uVar8 != 0x10);
  if (opt_multi_version == 0) {
    set_time_out_control(paVar12->timeout & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(paVar12->timeout * opt_multi_version & 0x1ffff | 0x80000000);
  }
  iVar13 = 1;
  iVar14 = 0;
  set_PWM('d');
  do {
    if (dev->chain_exist[iVar14] == 1) {
      open_core_one_chain(iVar14,true);
      sleep(1);
      _Var7 = SUB41(iVar14,0);
      if (fpga_version < 0xe) {
        if (iVar14 % 3 == 2) {
          pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
          set_pic_voltage(_Var7,chain_voltage_pic[iVar14]);
          pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        }
        bVar1 = chain_voltage_pic[iVar14];
      }
      else {
        if (iVar14 == 1) {
          open_core_one_chain(8,_Var7);
          sleep(1);
          open_core_one_chain(9,_Var7);
          sleep(1);
        }
        else if (iVar14 == 2) {
          open_core_one_chain(10,true);
          sleep(1);
          open_core_one_chain(0xb,true);
          sleep(1);
        }
        else {
          if (iVar14 != 3) {
            return;
          }
          open_core_one_chain(0xc,true);
          sleep(1);
          open_core_one_chain(0xd,true);
          sleep(1);
        }
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        set_pic_voltage(_Var7,chain_voltage_pic[iVar14]);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        bVar1 = chain_voltage_pic[iVar14];
      }
      sprintf(logstr,"Chain[J%d] set working voltage=%d [%d]\n",iVar13,
              ((int)(longlong)
                    (((364.0704 / ((double)(longlong)(int)(uint)bVar1 + 30.72) + 32.79) * 100.0) /
                    4.75) / 10) * 10,(uint)bVar1);
      writeInitLogFile(logstr);
    }
    iVar14 = iVar14 + 1;
    iVar13 = iVar13 + 1;
  } while (iVar14 != 0x10);
  return;
}

