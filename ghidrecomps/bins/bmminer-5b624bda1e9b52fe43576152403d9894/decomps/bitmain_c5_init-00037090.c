
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int bitmain_c5_init(init_config config)

{
  uchar *puVar1;
  uchar uVar2;
  uint *puVar3;
  _Bool _Var4;
  uint16_t frequency;
  undefined4 uVar5;
  uint *logstr_00;
  char *unaff_r7;
  int iVar6;
  int iVar7;
  all_parameters *paVar8;
  int iVar9;
  uint uVar10;
  uchar vol_pic;
  int iVar11;
  all_parameters *paVar12;
  uint uVar13;
  double dVar14;
  int local_9b4;
  int local_9b0;
  sysinfo si;
  char logstr [256];
  char tmp42 [2048];
  uint local_10 [4];
  
  local_10[0] = config._0_4_;
  local_10[1] = config._4_4_;
  local_10[2] = config._8_4_;
  local_10[3] = config._12_4_;
  saveRestartNum(2);
  saveRebootTestNum(0);
  clearInitLogFile();
  config.token_type = isC5_Board();
  isC5_CtrlBoard = (_Bool)config.token_type;
  if ((bool)config.token_type) {
    logstr_00 = (uint *)logstr;
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    builtin_strncpy(logstr,"This is C5 board",0x10);
    logstr[0x10] = '.';
    logstr[0x11] = '\n';
    logstr[0x12] = '\0';
  }
  else {
    sysinfo((sysinfo *)&si);
    if (si.totalram < 0x3b9aca01) {
      if (500000000 < si.totalram) {
        unaff_r7 = "Detect 512MB control board of XILINX\n";
      }
      puVar3 = (uint *)logstr;
      if (si.totalram < 0x1dcd6501) {
        unaff_r7 = "Detect 256MB control board of XILINX\n";
        puVar3 = local_10;
      }
      logstr_00 = (uint *)logstr;
      if (si.totalram < 0x1dcd6501) {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      }
      else {
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
        logstr_00 = puVar3;
      }
      config._0_4_ = *(undefined4 *)unaff_r7;
      config._4_1_ = unaff_r7[4];
      config._5_1_ = unaff_r7[5];
      config.reserved2[0] = unaff_r7[6];
      config.reserved2[1] = unaff_r7[7];
      config.chain_num = unaff_r7[8];
      config.asic_num = unaff_r7[9];
      config.fan_pwm_percent = unaff_r7[10];
      config.temperature = unaff_r7[0xb];
      config._12_4_ = *(undefined4 *)(unaff_r7 + 0xc);
      *logstr_00 = config._0_4_;
      logstr_00[1] = config._4_4_;
      logstr_00[2] = config._8_4_;
      logstr_00[3] = config._12_4_;
      config._0_4_ = *(undefined4 *)(unaff_r7 + 0x10);
      config._4_1_ = unaff_r7[0x14];
      config._5_1_ = unaff_r7[0x15];
      config.reserved2[0] = unaff_r7[0x16];
      config.reserved2[1] = unaff_r7[0x17];
      config.chain_num = unaff_r7[0x18];
      config.asic_num = unaff_r7[0x19];
      config.fan_pwm_percent = unaff_r7[0x1a];
      config.temperature = unaff_r7[0x1b];
      config._12_4_ = *(undefined4 *)(unaff_r7 + 0x1c);
      logstr_00[4] = config._0_4_;
      logstr_00[5] = config._4_4_;
      logstr_00[6] = config._8_4_;
      logstr_00[7] = config._12_4_;
      config._0_4_ = *(undefined4 *)(unaff_r7 + 0x20);
      config._4_1_ = unaff_r7[0x24];
      config._5_1_ = unaff_r7[0x25];
      config.reserved2[0] = unaff_r7[0x26];
      config.reserved2[1] = unaff_r7[0x27];
      logstr_00[8] = config._0_4_;
      *(short *)(logstr_00 + 9) = config._4_2_;
    }
    else {
      logstr_00 = (uint *)logstr;
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
      builtin_strncpy(logstr,"Detect 1GB control board of XILI",0x20);
      logstr[0x20] = 'N';
      logstr[0x21] = 'X';
      logstr[0x22] = '\n';
      logstr[0x23] = '\0';
    }
  }
  writeInitLogFile((char *)logstr_00);
  *logstr_00 = 0x656e694d;
  logstr_00[1] = 0x79542072;
  logstr_00[2] = 0x3d206570;
  logstr_00[3] = 0x2b395420;
  *(undefined2 *)(logstr_00 + 4) = 10;
  writeInitLogFile((char *)logstr_00);
  config_parameter.token_type = (undefined1)local_10[0];
  config_parameter.version = local_10[0]._1_1_;
  config_parameter.length = local_10[0]._2_2_;
  config_parameter._4_4_ = local_10[1];
  config_parameter.chain_num = (undefined1)local_10[2];
  config_parameter.asic_num = local_10[2]._1_1_;
  config_parameter.fan_pwm_percent = local_10[2]._2_1_;
  config_parameter.temperature = local_10[2]._3_1_;
  config_parameter.frequency = (undefined2)local_10[3];
  config_parameter.voltage[0] = local_10[3]._2_1_;
  config_parameter.voltage[1] = local_10[3]._3_1_;
  config._16_4_ = config._16_4_;
  config.reg_data = config.reg_data;
  config._24_4_ = config._24_4_;
  config._28_4_ = config._28_4_;
  config_parameter.chain_check_time_integer = config.chain_check_time_integer;
  config_parameter.chain_check_time_fractions = config.chain_check_time_fractions;
  config_parameter.timeout_data_integer = config.timeout_data_integer;
  config_parameter.timeout_data_fractions = config.timeout_data_fractions;
  config_parameter.reg_data = config.reg_data;
  config_parameter.chip_address = config.chip_address;
  config_parameter.reg_address = config.reg_address;
  config_parameter.chain_min_freq = config.chain_min_freq;
  config_parameter.chain_max_freq = config.chain_max_freq;
  config_parameter.crc = config.crc;
  if ((local_10[0] & 0xff) != 0x51) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: config_parameter.token_type != 0x%x, it is 0x%x\n","bitmain_c5_init"
               ,0x51,local_10[0] & 0xff);
      _applog(7,tmp42,false);
      config.token_type = 0xff;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    config.token_type = 0xff;
    config.version = 0xff;
    config.length = 0xffff;
    config_parameter.token_type = (undefined1)local_10[0];
    config_parameter.version = local_10[0]._1_1_;
    config_parameter.length = local_10[0]._2_2_;
    config_parameter.chain_num = (undefined1)local_10[2];
    config_parameter.asic_num = local_10[2]._1_1_;
    config_parameter.fan_pwm_percent = local_10[2]._2_1_;
    config_parameter.temperature = local_10[2]._3_1_;
    config_parameter.frequency = (undefined2)local_10[3];
    config_parameter.voltage[0] = local_10[3]._2_1_;
    config_parameter.voltage[1] = local_10[3]._3_1_;
    config_parameter.chain_check_time_integer = config.chain_check_time_integer;
    config_parameter.chain_check_time_fractions = config.chain_check_time_fractions;
    config_parameter.timeout_data_integer = config.timeout_data_integer;
    config_parameter.timeout_data_fractions = config.timeout_data_fractions;
    config_parameter.chip_address = config.chip_address;
    config_parameter.reg_address = config.reg_address;
    config_parameter.chain_min_freq = config.chain_min_freq;
    config_parameter.chain_max_freq = config.chain_max_freq;
    config_parameter.crc = config.crc;
    return config._0_4_;
  }
  config._4_2_ = 0xff;
  config.reserved2[0] = '\0';
  config.reserved2[1] = '\0';
  config.token_type = 0xff;
  config.version = '\0';
  config.length = 0;
  config._8_4_ = &config_parameter;
  config.frequency = 0x51;
  config.voltage[0] = '\0';
  config.voltage[1] = '\0';
  while( true ) {
    config._12_4_ = config._12_4_ ^ config._0_4_;
    config.version = '\0';
    config.length = 0;
    config.token_type = ""[config._12_4_];
    config._0_4_ = config._4_4_ ^ config._0_4_;
    config._5_3_ = 0;
    config._4_1_ = ""[config._12_4_];
    if (config._8_4_ == 0x76dfb1) break;
    config._8_4_ = config._8_4_ + 1;
    config._13_3_ = 0;
    config.frequency._0_1_ = *(byte *)config._8_4_;
  }
  config._4_4_ = config._0_4_ | config._4_4_ << 8;
  if ((uint)config._28_4_ >> 0x10 != config._4_4_) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
               "bitmain_c5_init",(uint)config._28_4_ >> 0x10,config._4_4_);
      _applog(7,tmp42,false);
      config.token_type = 0xfe;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    config.token_type = 0xfe;
    config.version = 0xff;
    config.length = 0xffff;
    config_parameter.token_type = (undefined1)local_10[0];
    config_parameter.version = local_10[0]._1_1_;
    config_parameter.length = local_10[0]._2_2_;
    config_parameter.chain_num = (undefined1)local_10[2];
    config_parameter.asic_num = local_10[2]._1_1_;
    config_parameter.fan_pwm_percent = local_10[2]._2_1_;
    config_parameter.temperature = local_10[2]._3_1_;
    config_parameter.frequency = (undefined2)local_10[3];
    config_parameter.voltage[0] = local_10[3]._2_1_;
    config_parameter.voltage[1] = local_10[3]._3_1_;
    config_parameter.chain_check_time_integer = config.chain_check_time_integer;
    config_parameter.chain_check_time_fractions = config.chain_check_time_fractions;
    config_parameter.timeout_data_integer = config.timeout_data_integer;
    config_parameter.timeout_data_fractions = config.timeout_data_fractions;
    config_parameter.chip_address = config.chip_address;
    config_parameter.reg_address = config.reg_address;
    config_parameter.chain_min_freq = config.chain_min_freq;
    config_parameter.chain_max_freq = config.chain_max_freq;
    config_parameter.crc = config.crc;
    return config._0_4_;
  }
  config._0_4_ = calloc(1,0x40);
  read_nonce_reg_id = (thr_info *)config._0_4_;
  config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                 (_func_void_ptr_void_ptr *)0x31cb1,(void *)config._0_4_);
  if (config._0_4_ != 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
               "bitmain_c5_init");
      _applog(7,tmp42,false);
      config.token_type = 0xfb;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    config.token_type = 0xfb;
    config.version = 0xff;
    config.length = 0xffff;
    return config._0_4_;
  }
  config._0_4_ = read_nonce_reg_id->pth;
  pthread_detach(config._0_4_);
  bitmain_axi_init();
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  set_reset_allhashboard(1);
  config._0_4_ = config_parameter._4_4_ << 0x1f;
  if ((int)config._0_4_ < 0) {
    set_QN_write_data_command(0x8080800f);
    sleep(2);
    set_PWM('d');
  }
  iVar9 = 0;
  iVar6 = 0;
  *axi_fpga_addr = 0x80000000;
  config._0_4_ = get_hardware_version();
  config._8_4_ = config._0_4_ & 0xff;
  config._12_4_ = config._0_4_ << 1;
  config._12_4_ = (uint)config._12_4_ >> 0x11;
  fpga_version._0_1_ = config.chain_num;
  fpga_version._1_1_ = config.asic_num;
  fpga_version._2_1_ = config.fan_pwm_percent;
  fpga_version._3_1_ = config.temperature;
  pcb_version._0_2_ = config.frequency;
  pcb_version._2_1_ = config.voltage[0];
  pcb_version._3_1_ = config.voltage[1];
  sprintf(g_miner_version,"%d.%d.%d.%d",config._8_4_,config._12_4_,1,3);
  set_reset_allhashboard(1);
  uVar10 = PHY_MEM_NONCE2_JOBID_ADDRESS;
  dev->baud = '\x1a';
  set_nonce2_and_job_id_store_address(uVar10);
  config._0_4_ = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
  set_job_start_address(config._0_4_);
  check_chain();
  do {
    config._12_4_ = dev->chain_exist[iVar6];
    if (config._12_4_ == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      config.token_type = (uchar)iVar6;
      get_hash_board_id_number(config.token_type,hash_board_id[iVar6]);
      config._0_4_ = bin2hex(hash_board_id[iVar6],0xc);
      uVar5 = config._0_4_;
      config._0_4_ = (int)hash_board_id_string + iVar9 * 0x22;
      iVar9 = iVar9 + 1;
      sprintf((char *)config._0_4_,"{\"ID\":\"%s\"},",uVar5);
      free((void *)uVar5);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  iVar11 = 0;
  iVar7 = 0;
  uVar10 = 0xffffffff;
  *(undefined1 *)((int)hash_board_id + iVar9 * 0x22 + 0xbf) = 0;
  iVar6 = 1;
  do {
    config._12_4_ = dev->chain_exist[iVar7];
    if (config._12_4_ == 1) {
      config.token_type = (uchar)iVar7;
      if (fpga_version < 0xe) {
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        config._8_4_ = iVar7 % 3;
        if (config._8_4_ == 0) {
          reset_iic_pic(config.token_type);
          sleep(1);
          jump_to_app_CheckAndRestorePIC_T9_18(iVar7);
          if (opt_fixed_freq != false) goto LAB_000374da;
          config._4_4_ = chain_pic_buf + (iVar7 / 3) * 3;
          read_freq_badcores(config.token_type,(uchar *)config._4_4_);
        }
        if (opt_fixed_freq == false) {
          iVar9 = iVar7 / 3;
          if (chain_pic_buf[iVar9 * 3][0] == '}') {
            config._13_3_ = 0;
            config.frequency._0_1_ = chain_pic_buf[iVar9 * 3][config._8_4_ * 0x1f + 8];
            config._12_4_ = config._12_4_ * 10;
            *(undefined4 *)((int)chain_voltage_value + iVar11) = config._12_4_;
            sprintf((char *)logstr_00,"Chain[J%d] has backup chain_voltage=%d\n",iVar6);
            writeInitLogFile((char *)logstr_00);
          }
          uVar2 = chain_pic_buf[iVar9 * 3][config._8_4_ * 0x1f + 10];
          goto LAB_00037598;
        }
      }
      else {
        if (uVar10 < 0xd) {
          puVar1 = "" + iVar11 + 0xfc;
          config.chain_num = puVar1[0];
          config.asic_num = puVar1[1];
          config.fan_pwm_percent = puVar1[2];
          config.temperature = puVar1[3];
          config._12_4_ = *(undefined4 *)(CSWTCH_824 + iVar11 + 0x30);
          local_9b0._0_1_ = config.chain_num;
          local_9b0._1_1_ = config.asic_num;
          local_9b0._2_1_ = config.fan_pwm_percent;
          local_9b0._3_1_ = config.temperature;
          local_9b4._0_2_ = config.frequency;
          local_9b4._2_1_ = config.voltage[0];
          local_9b4._3_1_ = config.voltage[1];
          pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
          if (uVar10 < 3) {
            reset_iic_pic(config.token_type);
            jump_to_app_CheckAndRestorePIC_T9_18(iVar7);
            if (opt_fixed_freq != false) goto LAB_000374da;
            config._4_4_ = chain_pic_buf + iVar7;
            read_freq_badcores(config.token_type,(uchar *)config._4_4_);
            sprintf((char *)logstr_00,"Chain[%d] read_freq_badcores : ",iVar7);
            writeInitLogFile((char *)logstr_00);
            uVar13 = 0;
            do {
              config.asic_num = '\0';
              config.fan_pwm_percent = '\0';
              config.temperature = '\0';
              config.chain_num = chain_pic_buf[iVar7][uVar13];
              sprintf((char *)logstr_00,"0x%02x ",config._8_4_);
              writeInitLogFile((char *)logstr_00);
              config._12_4_ = uVar13 + 1;
              uVar13 = config._12_4_ & 0xff;
            } while (uVar13 != 0x80);
            *(undefined2 *)logstr_00 = 10;
            writeInitLogFile((char *)logstr_00);
          }
        }
        else {
          local_9b4 = 0;
          pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
          local_9b0 = 0;
        }
        if (opt_fixed_freq == false) {
          if (chain_pic_buf[local_9b0][0] == '}') {
            config._13_3_ = 0;
            config.frequency._0_1_ = chain_pic_buf[local_9b0][local_9b4 * 0x1f + 8];
            config._12_4_ = config._12_4_ * 10;
            *(undefined4 *)((int)chain_voltage_value + iVar11) = config._12_4_;
            sprintf((char *)logstr_00,"Chain[J%d] has backup chain_voltage=%d\n",iVar6);
            writeInitLogFile((char *)logstr_00);
          }
          uVar2 = chain_pic_buf[local_9b0][local_9b4 * 0x1f + 10];
LAB_00037598:
          *(int *)((int)lowest_testOK_temp + iVar11) = (int)(char)uVar2;
          sprintf((char *)logstr_00,"Chain[J%d] test patten OK temp=%d\n",iVar6,(int)(char)uVar2);
          writeInitLogFile((char *)logstr_00);
        }
      }
LAB_000374da:
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 1;
    iVar11 = iVar11 + 4;
    uVar10 = uVar10 + 1;
  } while (iVar7 != 0x10);
  config._0_4_ = calloc(1,0x40);
  pic_heart_beat = (thr_info *)config._0_4_;
  config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                 (_func_void_ptr_void_ptr *)0x2d125,(void *)config._0_4_);
  if (config._0_4_ != 0) {
    if (opt_debug == false) {
      config.token_type = 0xfa;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
      config.token_type = 0xfa;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    config._8_4_ = s__s__create_thread_error_for_pic__00052ce8;
    goto LAB_000376aa;
  }
  iVar9 = 1;
  config._0_4_ = pic_heart_beat->pth;
  pthread_detach(config._0_4_);
  iVar6 = 0;
  do {
    if (dev->chain_exist[iVar6] == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      config.token_type = (uchar)iVar6;
      uVar2 = config.token_type;
      config.token_type = get_pic_voltage(config.token_type);
      chain_voltage_pic[iVar6] = config.token_type;
      sprintf((char *)logstr_00,"Chain[J%d] will use voltage=%d [%d] to open core\n",iVar9,0x3a2,1);
      writeInitLogFile((char *)logstr_00);
      config._4_4_ = iVar6 + -1;
      if (fpga_version < 0xe) {
        if (iVar6 % 3 == 0) goto LAB_00037872;
      }
      else if ((uint)config._4_4_ < 3) {
LAB_00037872:
        set_voltage_T9_18_into_PIC(uVar2,'\x01');
      }
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
    iVar6 = iVar6 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar6 != 0x10);
  if (opt_fixed_freq == false) {
LAB_000377b0:
    iVar9 = 1;
    iVar6 = 0;
    cgsleep_ms(100);
    do {
      config._12_4_ = dev->chain_exist[iVar6];
      if (config._12_4_ == 1) {
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        iVar7 = ((int)(longlong)
                      (((364.0704 / ((double)(longlong)(int)(uint)chain_voltage_pic[iVar6] + 30.72)
                        + 32.79) * 100.0) / 4.75) / 10) * 10;
        sprintf((char *)logstr_00,"Chain[J%d] orignal chain_voltage_pic=%d value=%d\n",iVar9,
                (uint)chain_voltage_pic[iVar6],iVar7);
        writeInitLogFile((char *)logstr_00);
        config._0_4_ = getChainPICMagicNumber(iVar6);
        if ((config._0_4_ == 0x7d) && (iVar11 = chain_voltage_value[iVar6], iVar11 != iVar7)) {
          dVar14 = 364.0704 / (((double)(longlong)iVar11 * 4.75) / 100.0 - 32.79) - 30.72;
          uVar13 = (uint)(0.0 < dVar14) * (int)(longlong)dVar14;
          uVar10 = uVar13 & 0xff;
          sprintf((char *)logstr_00,"Chain[J%d] will use backup chain_voltage_pic=%d [%d]\n",iVar9,
                  iVar11,uVar10);
          writeInitLogFile((char *)logstr_00);
          chain_voltage_pic[iVar6] = (uchar)uVar13;
          sprintf((char *)logstr_00,"Chain[J%d] get working chain_voltage_pic=%d\n",iVar9,uVar10);
          writeInitLogFile((char *)logstr_00);
        }
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      }
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar6 != 0x10);
    cgsleep_ms(1000);
  }
  else {
    iVar6 = 0;
    do {
      config._12_4_ = dev->chain_exist[iVar6];
      if (config._12_4_ == 1) {
        config._8_4_ = config_parameter._12_4_ & 0xffff;
        if ((uint)config._8_4_ < 0x28a) {
          if ((uint)config._8_4_ < 0x271) {
            if ((uint)config._8_4_ < 600) {
              if ((uint)config._8_4_ < 0x23f) {
                if ((uint)config._8_4_ < 0x21f) {
                  config._4_2_ = 0x3a2;
                  config.reserved2[0] = '\0';
                  config.reserved2[1] = '\0';
                  if (0x203 < (uint)config._8_4_) {
                    config._4_2_ = 0x398;
                    config.reserved2[0] = '\0';
                    config.reserved2[1] = '\0';
                  }
                }
                else {
                  config._4_2_ = 0x37a;
                  config.reserved2[0] = '\0';
                  config.reserved2[1] = '\0';
                }
              }
              else {
                config._4_2_ = 0x366;
                config.reserved2[0] = '\0';
                config.reserved2[1] = '\0';
              }
            }
            else {
              config._4_2_ = 0x352;
              config.reserved2[0] = '\0';
              config.reserved2[1] = '\0';
            }
          }
          else {
            config._4_2_ = 0x33e;
            config.reserved2[0] = '\0';
            config.reserved2[1] = '\0';
          }
        }
        else {
          config._4_2_ = 0x32a;
          config.reserved2[0] = '\0';
          config.reserved2[1] = '\0';
        }
        chain_voltage_value[iVar6] = config._4_4_;
        dVar14 = 364.0704 / (((double)(longlong)(int)config._4_4_ * 4.75) / 100.0 - 32.79) - 30.72;
        uVar10 = (uint)(0.0 < dVar14) * (int)(longlong)dVar14;
        chain_voltage_pic[iVar6] = (uchar)uVar10;
        sprintf((char *)logstr_00,"Fix freq=%d Chain[%d] voltage_pic=%d value=%d\n",config._8_4_,
                iVar6,uVar10 & 0xff,config._4_4_);
        writeInitLogFile((char *)logstr_00);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
    if (opt_fixed_freq == false) goto LAB_000377b0;
  }
  iVar6 = 0;
  do {
    config._12_4_ = dev->chain_exist[iVar6];
    if (config._12_4_ == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      config.token_type = (uchar)iVar6;
      enable_pic_dac(config.token_type);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  sleep(5);
  set_reset_allhashboard(1);
  sleep(3);
  set_reset_allhashboard(0);
  sleep(1);
  if (opt_multi_version != 0) {
    config._0_4_ = get_dhash_acc_control();
    config._0_4_ = config._0_4_ & 0xffff70df;
    config._0_4_ = config._0_4_ | 0x8100;
    set_dhash_acc_control(config._0_4_);
  }
  cgsleep_ms(10);
  dev->corenum = 'r';
  check_asic_reg(0);
  cgsleep_ms(10);
  config.chain_num = '\x01';
  config.asic_num = '\0';
  config.fan_pwm_percent = '\0';
  config.temperature = '\0';
  do {
    iVar6 = config._8_4_ + 1;
    config._4_4_ = dev->chain_exist[config._8_4_ + -1];
    if (config._4_4_ == 1) {
      config._13_3_ = 0;
      config.frequency._0_1_ = *(byte *)((int)dev->temp + config._8_4_ + 0x3f);
      sprintf((char *)logstr_00,"Chain[J%d] has %d asic\n",config._8_4_,config._12_4_);
      writeInitLogFile((char *)logstr_00);
      if (*(char *)((int)dev->temp + config._8_4_ + 0x3f) == '\0') {
        dev->chain_exist[config._8_4_ + -1] = 0;
      }
    }
    config._8_4_ = iVar6;
  } while (iVar6 != 0x11);
  software_set_address();
  cgsleep_ms(10);
  config._4_4_ = config_parameter._4_4_ << 0x1c;
  if ((int)config._4_4_ < 0) {
    frequency = config_parameter.frequency;
    dev->frequency = config_parameter.frequency;
    set_frequency(frequency);
    config._0_4_ = dev->frequency_t;
    config.fan_pwm_percent = '\0';
    config.temperature = '\0';
    config._8_2_ = dev->frequency;
    sprintf((char *)config._0_4_,"%u",config._8_4_);
  }
  cgsleep_ms(10);
  paVar8 = dev;
  _Var4 = opt_debug;
  uVar2 = config_parameter.fan_pwm_percent;
  config._13_3_ = 0;
  config.frequency._0_1_ = config_parameter.fan_pwm_percent;
  config._4_4_ = config_parameter._4_4_ << 0x1e;
  uVar5 = config._4_4_;
  config._4_4_ = (uint)config._4_4_ >> 0x1f;
  dev->fan_eft = SUB41(uVar5,3) >> 7;
  paVar8->fan_pwm = uVar2;
  if ((_Var4 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: fan_eft : %d  fan_pwm : %d\n","bitmain_c5_init",config._4_4_,
             config._12_4_);
    _applog(7,tmp42,false);
  }
  config._8_4_ = config_parameter._4_4_ << 0x1e;
  if (((int)config._8_4_ < 0) && (config_parameter.fan_pwm_percent < 0x65)) {
    set_PWM(config_parameter.fan_pwm_percent);
  }
  else {
    set_PWM_according_to_temperature();
  }
  paVar8 = dev;
  config._12_4_ = config_parameter._4_4_ << 0x1d;
  if ((int)config._12_4_ < 0) {
    if (config_parameter._18_2_ == 0) {
      config.version = '\0';
      config.length = 0;
      config.token_type = dev->corenum;
      config._0_4_ = calculate_core_number(config._0_4_);
      paVar8 = dev;
      config._0_4_ = __aeabi_idiv(0x1000000,config._0_4_);
      config.asic_num = '\0';
      config.fan_pwm_percent = '\0';
      config.temperature = '\0';
      config.chain_num = paVar8->addrInterval;
      config._0_4_ = config._8_4_ * config._0_4_;
      config._0_4_ = __aeabi_idiv(config._0_4_,paVar8->frequency);
      _Var4 = opt_debug;
      config._0_4_ = config._0_4_ * 0x5a;
      config._12_4_ = (int)config._0_4_ / 100;
      paVar8->timeout = config._12_4_;
      if ((_Var4 != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"dev->timeout = %d\n");
        _applog(7,tmp42,false);
        config._12_4_ = dev->timeout;
        paVar8 = dev;
      }
    }
    else {
      config._12_4_ = (uint)config_parameter._16_4_ >> 0x10 & 0xff;
      config._12_4_ = config._12_4_ * 1000 + ((uint)config_parameter._16_4_ >> 0x18);
      dev->timeout = config._12_4_;
    }
    if (0x1ffff < (uint)config._12_4_) {
      paVar8->timeout = 0x1ffff;
    }
  }
  init_uart_baud();
  iVar6 = 0;
  cgsleep_ms(10);
  config._12_4_ = dev;
  do {
    config._8_4_ = iVar6 + 2;
    config._8_4_ = *(undefined4 *)(config._12_4_ + config._8_4_ * 4);
    if ((config._8_4_ == 1) &&
       (config._8_4_ = config._12_4_ + iVar6, *(char *)(config._8_4_ + 0x2faa) == '\x12')) {
      calibration_sensor_offset(0x98,iVar6);
      cgsleep_ms(10);
      config._12_4_ = dev;
    }
    iVar9 = fpga_version;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  config._0_4_ = config._12_4_;
  config._4_2_ = config.frequency;
  config.reserved2[0] = config.voltage[0];
  config.reserved2[1] = config.voltage[1];
  config.chain_num = '\0';
  config.asic_num = '\0';
  config.fan_pwm_percent = '\0';
  config.temperature = '\0';
  iVar6 = config._12_4_;
  do {
    if ((*(int *)(config._0_4_ + 8) == 1) &&
       (*(char *)(config._12_4_ + config._8_4_ + 0x2faa) == '\x12')) {
      if (iVar9 < 0xe) {
        iVar7 = ((int)config._8_4_ / 3) * 3;
        if ((int)config._8_4_ % 3 != 1) {
          iVar11 = iVar7 + 1;
          *(undefined1 *)(iVar6 + 0x458) = *(undefined1 *)(config._12_4_ + iVar11 + 0x458);
          *(undefined1 *)(config._4_4_ + 0x4e8) =
               *(undefined1 *)(config._12_4_ + (iVar7 + 0x9e) * 8);
          *(undefined1 *)(config._4_4_ + 0x4e9) =
               *(undefined1 *)(config._12_4_ + iVar11 * 8 + 0x4e9);
        }
      }
      else if ((uint)config._8_4_ < 0xe) {
        uVar10 = 1 << (config._8_4_ & 0xff);
        if ((uVar10 & 0x2008) == 0) {
          if ((uVar10 & 0x804) == 0) {
            if ((uVar10 & 0x202) != 0) {
              *(undefined1 *)(iVar6 + 0x458) = *(undefined1 *)(config._12_4_ + 0x460);
              *(undefined1 *)(config._4_4_ + 0x4e8) = *(undefined1 *)(config._12_4_ + 0x528);
              *(undefined1 *)(config._4_4_ + 0x4e9) = *(undefined1 *)(config._12_4_ + 0x529);
            }
          }
          else {
            *(undefined1 *)(iVar6 + 0x458) = *(undefined1 *)(config._12_4_ + 0x462);
            *(undefined1 *)(config._4_4_ + 0x4e8) = *(undefined1 *)(config._12_4_ + 0x538);
            *(undefined1 *)(config._4_4_ + 0x4e9) = *(undefined1 *)(config._12_4_ + 0x539);
          }
        }
        else {
          *(undefined1 *)(iVar6 + 0x458) = *(undefined1 *)(config._12_4_ + 0x464);
          *(undefined1 *)(config._4_4_ + 0x4e8) = *(undefined1 *)(config._12_4_ + 0x548);
          *(undefined1 *)(config._4_4_ + 0x4e9) = *(undefined1 *)(config._12_4_ + 0x549);
        }
      }
    }
    config._8_4_ = config._8_4_ + 1;
    config._0_4_ = config._0_4_ + 4;
    iVar6 = iVar6 + 1;
    config._4_4_ = config._4_4_ + 8;
  } while (config._8_4_ != 0x10);
  if (opt_multi_version == 0) {
    config._8_4_ = *(undefined4 *)(config._12_4_ + 0x48);
    config._12_4_ = SUB84((ulonglong)(uint)config._8_4_ * 0xcccccccd >> 0x20,0);
    config._0_4_ = config._12_4_ << 0xc;
    config._0_4_ = (uint)config._0_4_ >> 0xf;
    config._0_4_ = config._0_4_ | 0x80000000;
    set_time_out_control(config._0_4_);
  }
  else {
    config._8_4_ = *(undefined4 *)(config._12_4_ + 0x48);
    config._12_4_ = SUB84((ulonglong)(uint)config._8_4_ * 0xcccccccd >> 0x20,0);
    config._0_4_ = config._12_4_ << 0xc;
    config._0_4_ = (uint)config._0_4_ >> 0xf;
    config._0_4_ = config._0_4_ | 0x80000000;
    set_time_out_control(config._0_4_);
  }
  set_PWM('d');
  iVar9 = 1;
  config._12_4_ = dev;
  iVar6 = 0;
  do {
    config._8_4_ = iVar6 + 2;
    if (*(int *)(config._12_4_ + config._8_4_ * 4) == 1) {
      open_core_one_chain(iVar6,true);
      sleep(1);
      if (fpga_version < 0xe) {
        iVar7 = (iVar6 / 3) * 3;
        config._8_4_ = iVar6 % 3;
        if (config._8_4_ == 2) {
          pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
          uVar2 = chain_voltage_pic[iVar6];
          goto LAB_000381b8;
        }
      }
      else {
        if (iVar6 == 1) {
          *logstr_00 = 0x6e65706f;
          logstr_00[1] = 0x726f6320;
          logstr_00[2] = 0x6e6f2065;
          logstr_00[3] = 0x61686320;
          logstr_00[4] = 0x315b6e69;
          logstr_00[5] = 0x385b205d;
          logstr_00[6] = 0x395b205d;
          logstr_00[7] = 0x2e2e2e5d;
          *(undefined2 *)(logstr_00 + 8) = 10;
          writeInitLogFile((char *)logstr_00);
          open_core_one_chain(8,SUB41(iVar6,0));
          sleep(1);
          open_core_one_chain(9,SUB41(iVar6,0));
          sleep(1);
        }
        else if (iVar6 == 2) {
          *logstr_00 = 0x6e65706f;
          logstr_00[1] = 0x726f6320;
          logstr_00[2] = 0x6e6f2065;
          logstr_00[3] = 0x61686320;
          logstr_00[4] = 0x325b6e69;
          logstr_00[5] = 0x315b205d;
          logstr_00[6] = 0x5b205d30;
          logstr_00[7] = 0x2e5d3131;
          logstr_00[8] = 0xa2e2e;
          writeInitLogFile((char *)logstr_00);
          open_core_one_chain(10,true);
          sleep(1);
          open_core_one_chain(0xb,true);
          sleep(1);
        }
        else {
          if (iVar6 != 3) {
            config._12_4_ = dev;
            break;
          }
          *logstr_00 = 0x6e65706f;
          logstr_00[1] = 0x726f6320;
          logstr_00[2] = 0x6e6f2065;
          logstr_00[3] = 0x61686320;
          logstr_00[4] = 0x335b6e69;
          logstr_00[5] = 0x315b205d;
          logstr_00[6] = 0x5b205d32;
          logstr_00[7] = 0x2e5d3331;
          logstr_00[8] = 0xa2e2e;
          writeInitLogFile((char *)logstr_00);
          open_core_one_chain(0xc,true);
          sleep(1);
          open_core_one_chain(0xd,true);
          sleep(1);
        }
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        uVar2 = chain_voltage_pic[iVar6];
        iVar7 = iVar6;
LAB_000381b8:
        config.token_type = (uchar)iVar7;
        set_pic_voltage(config.token_type,uVar2);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      }
      config._13_3_ = 0;
      config.frequency._0_1_ = chain_voltage_pic[iVar6];
      uVar5 = config._12_4_;
      config._12_4_ =
           ((int)(longlong)
                 (((364.0704 / ((double)(longlong)(int)config._12_4_ + 30.72) + 32.79) * 100.0) /
                 4.75) / 10) * 10;
      sprintf((char *)logstr_00,"Chain[J%d] set working voltage=%d [%d]\n",iVar9,config._12_4_,uVar5
             );
      writeInitLogFile((char *)logstr_00);
      config._12_4_ = dev;
    }
    iVar6 = iVar6 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar6 != 0x10);
  config._8_4_ = *(undefined4 *)(config._12_4_ + 0x48);
  config._12_4_ = SUB84((ulonglong)(uint)config._8_4_ * 0xcccccccd >> 0x20,0);
  config._0_4_ = config._12_4_ << 0xc;
  config._0_4_ = (uint)config._0_4_ >> 0xf;
  config._0_4_ = config._0_4_ | 0x80000000;
  set_time_out_control(config._0_4_);
  config._0_4_ = calloc(1,0x40);
  read_temp_id = (thr_info *)config._0_4_;
  config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                 (_func_void_ptr_void_ptr *)0x39b69,(void *)config._0_4_);
  if (config._0_4_ != 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: create thread for read temp\n","bitmain_c5_init");
      _applog(7,tmp42,false);
      config.token_type = 0xf9;
      config.version = 0xff;
      config.length = 0xffff;
      return config._0_4_;
    }
    config.token_type = 0xf9;
    config.version = 0xff;
    config.length = 0xffff;
    return config._0_4_;
  }
  config._0_4_ = read_temp_id->pth;
  pthread_detach(config._0_4_);
  if ((opt_fixed_freq == false) && (opt_pre_heat != false)) {
    doTestPatten = true;
    sleep(3);
    iVar6 = 0;
    paVar8 = dev;
    do {
      config._12_4_ = paVar8->chain_exist[0];
      paVar8 = (all_parameters *)&paVar8->pwm_value;
      if (config._12_4_ == 1) {
        config._0_4_ = chain_pic_buf + iVar6;
        config._4_4_ = chip_last_freq + iVar6;
        memcpy((void *)config._0_4_,(void *)config._4_4_,0x80);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
    iVar6 = 0;
    someBoardUpVoltage = false;
    clement_doTestBoard(true);
    paVar8 = dev;
    do {
      config._12_4_ = paVar8->chain_exist[0];
      paVar8 = (all_parameters *)&paVar8->pwm_value;
      if (config._12_4_ == 1) {
        config._0_4_ = chain_pic_buf + iVar6;
        config._4_4_ = show_last_freq + iVar6;
        memcpy((void *)config._0_4_,(void *)config._4_4_,0x80);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
    set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
    config._0_4_ = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
    set_job_start_address(config._0_4_);
    doTestPatten = false;
  }
  set_asic_ticket_mask(0x3f);
  set_hcnt(0);
  cgsleep_ms(10);
  if (opt_multi_version == 0) {
    config._0_4_ = dev->timeout;
    config._0_4_ = config._0_4_ & 0x1ffff;
    config._0_4_ = config._0_4_ | 0x80000000;
    set_time_out_control(config._0_4_);
  }
  else {
    config._8_4_ = dev->timeout;
    config._12_4_ = config._8_4_ * opt_multi_version;
    config._0_4_ = config._12_4_ & 0x1ffff;
    config._0_4_ = config._0_4_ | 0x80000000;
    set_time_out_control(config._0_4_);
  }
  config._0_4_ = calloc(1,0x40);
  check_system_work_id = (thr_info *)config._0_4_;
  config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                 (_func_void_ptr_void_ptr *)0x34905,(void *)config._0_4_);
  if (config._0_4_ == 0) {
    config._0_4_ = check_system_work_id->pth;
    pthread_detach(config._0_4_);
    paVar8 = dev;
    iVar6 = 0;
    paVar12 = dev;
    do {
      config._12_4_ = paVar12->chain_exist[0];
      if (config._12_4_ != 0) {
        uVar10 = (uint)paVar8->chain_asic_num[iVar6];
        if (uVar10 == 0) {
          config._8_4_ = iVar6 << 3;
          local_9b4._0_1_ = config.chain_num;
          local_9b4._1_1_ = config.asic_num;
          local_9b4._2_1_ = config.fan_pwm_percent;
          local_9b4._3_1_ = config.temperature;
          iVar9 = 0;
        }
        else {
          config._0_4_ = iVar6 * 8;
          iVar9 = 0;
          config.frequency = 0;
          config.voltage[0] = '\0';
          config.voltage[1] = '\0';
          local_9b4 = config._0_4_;
          do {
            uVar5 = config._12_4_;
            if ((config._12_4_ & 7) == 0) {
              paVar8->chain_asic_status_string[iVar6][config._12_4_ + iVar9] = ' ';
              iVar9 = iVar9 + 1;
            }
            config._12_4_ = config._12_4_ + 1;
            paVar8->chain_asic_status_string[iVar6][uVar5 + iVar9] = 'o';
            *(undefined2 *)(paVar8->chain_asic_nonce[iVar6] + uVar5) = 0;
            *(undefined2 *)((int)paVar8->chain_asic_nonce[iVar6] + uVar5 * 8 + 2) = 0;
            *(undefined2 *)((int)paVar8->chain_asic_nonce[iVar6] + uVar5 * 8 + 4) = 0;
            *(undefined2 *)((int)paVar8->chain_asic_nonce[iVar6] + uVar5 * 8 + 6) = 0;
          } while (uVar10 != config._12_4_);
        }
        config._12_4_ = local_9b4 + iVar6;
        paVar8->chain_asic_status_string[0][uVar10 + iVar9 + config._12_4_ * 8] = '\0';
      }
      iVar6 = iVar6 + 1;
      paVar12 = (all_parameters *)&paVar12->pwm_value;
    } while (iVar6 != 0x10);
    cgtime(&tv_send_job);
    cgtime(&tv_send);
    startCheckNetworkJob = true;
    setStartTimePoint();
    config.token_type = '\0';
    config.version = '\0';
    config.length = 0;
    return config._0_4_;
  }
  if (opt_debug == false) {
    config.token_type = 0xfa;
    config.version = 0xff;
    config.length = 0xffff;
    return config._0_4_;
  }
  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
    config.token_type = 0xfa;
    config.version = 0xff;
    config.length = 0xffff;
    return config._0_4_;
  }
  config._8_4_ = s__s__create_thread_for_check_syst_00052e94;
LAB_000376aa:
  config._0_4_ = tmp42;
  snprintf((char *)config._0_4_,0x800,(char *)config._8_4_,"bitmain_c5_init");
  _applog(7,tmp42,false);
  config.token_type = 0xfa;
  config.version = 0xff;
  config.length = 0xffff;
  return config._0_4_;
}

