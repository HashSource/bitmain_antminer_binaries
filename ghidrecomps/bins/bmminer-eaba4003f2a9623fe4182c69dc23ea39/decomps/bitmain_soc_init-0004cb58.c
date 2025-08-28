
int bitmain_soc_init(init_config config)

{
  undefined4 uVar1;
  all_parameters *paVar2;
  undefined4 uVar3;
  char tmp42 [2048];
  char logstr [1024];
  sysinfo si;
  int init_freq;
  int freq_step;
  int hardware_version;
  uchar voltage;
  int testCounter;
  uint data;
  uint16_t crc;
  char ret;
  int offset;
  int retry_count;
  int y;
  int x;
  int i;
  
  uVar3 = config._12_4_;
  bitmain_scan_freq();
  uVar1 = tmp42._28_4_;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"This is user mode for mining\n",0x1e);
    tmp42._30_2_ = SUB42(uVar1,2);
    _applog(5,tmp42,false);
  }
  bitmain_axi_init();
  config._12_4_ = &si;
  sysinfo((sysinfo *)config._12_4_);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"Detect 256MB control board of XILINX",0x24);
        tmp42[0x24] = '\n';
        tmp42[0x25] = '\0';
        _applog(5,tmp42,false);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"Detect 512MB control board of XILINX",0x24);
        tmp42[0x24] = '\n';
        tmp42[0x25] = '\0';
        _applog(5,tmp42,false);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"Detect 1GB control board of XILINX\n",0x24);
      _applog(5,tmp42,false);
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"Miner Type = S11",0x10);
    tmp42[0x10] = '\n';
    tmp42[0x11] = '\0';
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Miner compile time: %s type: %s",g_miner_compiletime,g_miner_type);
    _applog(5,tmp42,false);
  }
  config_parameter._0_4_ = config._0_4_;
  uVar1 = config_parameter._0_4_;
  config_parameter._4_4_ = config._4_4_;
  config_parameter._8_4_ = config._8_4_;
  config_parameter._12_4_ = uVar3;
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
  config_parameter.token_type = config.token_type;
  config_parameter._0_4_ = uVar1;
  if (config_parameter.token_type == 'Q') {
    config._0_2_ = CRC16(&config_parameter.token_type,0x1e);
    if (config._0_2_ == config_parameter.crc) {
      config._0_4_ = calloc(1,0x40);
      read_nonce_reg_id = (thr_info *)config._0_4_;
      config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                     (_func_void_ptr_void_ptr *)0x4345d,(void *)config._0_4_);
      if (config._0_4_ == 0) {
        config._12_4_ = read_nonce_reg_id->pth;
        pthread_detach(config._12_4_);
        if ((config_parameter._4_4_ & 1) != 0) {
          set_QN_write_data_command(0x8080800f);
          sleep(2);
          set_PWM('d');
        }
        set_Hardware_version(0x40000000);
        read_fpga_id(FPGA_ID_str);
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"miner ID : %s\n",FPGA_ID_str);
          _applog(5,tmp42,false);
        }
        config._0_4_ = get_hardware_version();
        config._12_4_ = (int)config._0_4_ >> 0x10;
        config._8_4_ = config._12_4_ & 0x7fff;
        uVar3 = config._8_4_;
        pcb_version._0_1_ = config.chain_num;
        pcb_version._1_1_ = config.asic_num;
        pcb_version._2_1_ = config.fan_pwm_percent;
        pcb_version._3_1_ = config.temperature;
        config._8_4_ = config._0_4_ & 0xff;
        uVar1 = config._8_4_;
        fpga_version._0_1_ = config.chain_num;
        fpga_version._1_1_ = config.asic_num;
        fpga_version._2_1_ = config.fan_pwm_percent;
        fpga_version._3_1_ = config.temperature;
        config._8_4_ = (uint)config._0_4_ >> 8 & 0xff;
        fpga_major_version._0_1_ = config.chain_num;
        fpga_major_version._1_1_ = config.asic_num;
        fpga_major_version._2_1_ = config.fan_pwm_percent;
        fpga_major_version._3_1_ = config.temperature;
        config._12_4_ = config._8_4_ + -0xc5;
        config._8_4_ = config._12_4_ * 0x100;
        config._8_4_ = config._8_4_ + uVar1;
        sprintf(g_miner_version,"%d.%d.%d.%d",config._8_4_,uVar3,1,3);
        config._12_4_ = &dev->baud;
        *(undefined1 *)config._12_4_ = 0x1a;
        set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
        config._12_4_ = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
        set_job_start_address(config._12_4_);
        uVar3 = tmp42._20_4_;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          builtin_strncpy(tmp42,"begin to check chain\n",0x16);
          tmp42._22_2_ = SUB42(uVar3,2);
          _applog(5,tmp42,false);
        }
        check_chain();
        set_PWM('d');
        puts("reset down");
        reset_down_hash_board();
        i = 0;
        while (i < 0x10) {
          config._12_4_ = dev->chain_exist[i];
          if (config._12_4_ == 1) {
            pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
            config.token_type = (uchar)i;
            dsPIC33EP16GS202_reset_pic(config.token_type);
            pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            cgsleep_ms(100);
            pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
            dsPIC33EP16GS202_jump_to_app_from_loader(config.token_type);
            pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            cgsleep_ms(100);
          }
          config._12_4_ = i + 1;
          i = config._12_4_;
        }
        config._0_4_ = calloc(1,0x40);
        pic_heart_beat = (thr_info *)config._0_4_;
        config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                       (_func_void_ptr_void_ptr *)0x42291,(void *)config._0_4_);
        if (config._0_4_ == 0) {
          config._12_4_ = pic_heart_beat->pth;
          pthread_detach(config._12_4_);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"============%s=========%d==========================",
                     "bitmain_soc_init",0x2ac1);
            _applog(5,tmp42,false);
          }
          i = 0;
          while (i < 0x10) {
            config._12_4_ = dev->chain_exist[i];
            if (config._12_4_ == 1) {
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              config.token_type = (uchar)i;
              AT24C02_read_voltage(config.token_type);
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
              printf("Chain[%d] read pic voltage=%d\n",i,0x21);
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              set_voltage_T9_18_into_PIC(config.token_type,'!');
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            }
            config._12_4_ = i + 1;
            i = config._12_4_;
          }
          reset_up_hash_board();
          usleep(200000);
          reset_hash_board();
          puts("reset over, send data");
          if (opt_multi_version != 0) {
            config._0_4_ = get_dhash_acc_control();
            config._12_4_ = config._0_4_ & 0xffff70df;
            config._12_4_ = config._12_4_ | 0x8100;
            set_dhash_acc_control(config._12_4_);
          }
          cgsleep_ms(10);
          config._12_4_ = &dev->corenum;
          *(undefined1 *)config._12_4_ = 0xd0;
          check_asic_reg(0);
          cgsleep_ms(10);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            memcpy(tmp42,
                   "------------------------------------------------------------------------------------"
                   ,0x55);
            _applog(5,tmp42,false);
          }
          i = 0;
          while (i < 0x10) {
            config._12_4_ = dev->chain_exist[i];
            if (config._12_4_ == 1) {
              retry_count = 0;
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                config._13_3_ = 0;
                config.frequency._0_1_ = dev->chain_asic_num[i];
                snprintf(tmp42,0x800,"Chain[J%d] has %d asic\n",i + 1,config._12_4_);
                _applog(5,tmp42,false);
              }
              while( true ) {
                if ((dev->chain_asic_num[i] == 'l') || (5 < retry_count)) break;
                dev->chain_asic_num[i] = '\0';
                set_reset_hashboard(i,1);
                pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
                config.token_type = (uchar)i;
                dsPIC33EP16GS202_enable_pic_dc_dc(config.token_type,'\0');
                pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
                sleep(1);
                pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
                dsPIC33EP16GS202_enable_pic_dc_dc(config.token_type,'\x01');
                pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
                sleep(2);
                set_reset_hashboard(i,0);
                sleep(1);
                check_asic_reg_oneChain(i,0);
                if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
                  config._13_3_ = 0;
                  config.frequency._0_1_ = dev->chain_asic_num[i];
                  snprintf(tmp42,0x800,"retry Chain[J%d] has %d asic\n",i + 1,config._12_4_);
                  _applog(5,tmp42,false);
                }
                config._12_4_ = retry_count + 1;
                retry_count = config._12_4_;
              }
              if (dev->chain_asic_num[i] == '\0') {
                dev->chain_exist[i] = 0;
              }
            }
            config._12_4_ = i + 1;
            i = config._12_4_;
          }
          i = 0;
          while (i < 0x10) {
            config._12_4_ = dev->chain_exist[i];
            if ((config._12_4_ != 0) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              config._13_3_ = 0;
              config.frequency._0_1_ = dev->chain_asic_num[i];
              snprintf(tmp42,0x800,"Chain%d has %d ASICs",i,config._12_4_);
              _applog(5,tmp42,false);
            }
            config._12_4_ = i + 1;
            i = config._12_4_;
          }
          software_set_address(2);
          cgsleep_ms(10);
          if ((config_parameter._4_4_ & 8) != 0) {
            config._12_4_ = &dev->frequency;
            *(uint16_t *)config._12_4_ = config_parameter.frequency;
            config._12_4_ = dev->frequency_t;
            config._8_4_ = &dev->frequency;
            config._8_2_ = *(undefined2 *)config._8_4_;
            config.fan_pwm_percent = '\0';
            config.temperature = '\0';
            sprintf((char *)config._12_4_,"%u",config._8_4_);
          }
          cgsleep_ms(10);
          config._12_4_ = config_parameter._4_4_ << 0x1e;
          uVar3 = config._12_4_;
          config._12_4_ = &dev->fan_eft;
          *(byte *)config._12_4_ = SUB41(uVar3,3) >> 7;
          config._12_4_ = &dev->fan_pwm;
          *(uchar *)config._12_4_ = config_parameter.fan_pwm_percent;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            config._12_4_ = &dev->fan_eft;
            config.frequency._0_1_ = *(byte *)config._12_4_;
            config._13_3_ = 0;
            uVar3 = config._12_4_;
            config._12_4_ = &dev->fan_pwm;
            config.frequency._0_1_ = *(byte *)config._12_4_;
            config._13_3_ = 0;
            snprintf(tmp42,0x800,"%s: fan_eft : %d  fan_pwm : %d\n","bitmain_soc_init",uVar3,
                     config._12_4_);
            _applog(7,tmp42,false);
          }
          if ((config_parameter._4_4_ & 2) == 0) {
            set_PWM_according_to_temperature();
          }
          else if (config_parameter.fan_pwm_percent < 0x65) {
            set_PWM(config_parameter.fan_pwm_percent);
          }
          else {
            set_PWM_according_to_temperature();
          }
          paVar2 = dev;
          if ((config_parameter._4_4_ & 4) != 0) {
            if ((config_parameter.timeout_data_integer == '\0') &&
               (config_parameter.timeout_data_fractions == '\0')) {
              config._12_4_ = &dev->corenum;
              config.frequency._0_1_ = *(byte *)config._12_4_;
              config._13_3_ = 0;
              config._0_4_ = calculate_core_number(config._12_4_);
              config._0_4_ = __aeabi_idiv(0x1000000,config._0_4_);
              config._12_4_ = &dev->addrInterval;
              config.frequency._0_1_ = *(byte *)config._12_4_;
              config._13_3_ = 0;
              config._8_4_ = config._12_4_ * config._0_4_;
              config._12_4_ = &dev->frequency;
              config._0_4_ = __aeabi_idiv(config._8_4_,*(undefined2 *)config._12_4_);
              config._8_4_ = config._0_4_ * 0x5a;
              paVar2->timeout = (int)config._8_4_ / 100;
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                config._12_4_ = dev->timeout;
                snprintf(tmp42,0x800,"dev->timeout = %d\n",config._12_4_);
                _applog(5,tmp42,false);
              }
            }
            else {
              config._13_3_ = 0;
              config.frequency._0_1_ = config_parameter.timeout_data_integer;
              config._4_4_ = config._12_4_ * 1000;
              config._13_3_ = 0;
              config.frequency._0_1_ = config_parameter.timeout_data_fractions;
              config._12_4_ = config._4_4_ + config._12_4_;
              dev->timeout = config._12_4_;
            }
            config._8_4_ = dev->timeout;
            if (0x1ffff < (uint)config._8_4_) {
              dev->timeout = 0x1ffff;
            }
          }
          init_uart_baud();
          cgsleep_ms(10);
          set_clock_delay_control();
          puts("===pre open core===");
          open_core_BM1393_pre_open('\x05','\x01');
          i = 0;
          while (i < 0x10) {
            config._12_4_ = dev->chain_exist[i];
            if (config._12_4_ == 1) {
              if (dev->chain_asic_num[i] == 'l') {
                calibration_sensor_offset(0x98,i);
                cgsleep_ms(10);
              }
            }
            config._12_4_ = i + 1;
            i = config._12_4_;
          }
          if (opt_multi_version == 0) {
            config._8_4_ = dev->timeout;
            config._12_4_ = (uint)config._8_4_ / 10;
            config._12_4_ = config._12_4_ & 0x1ffff;
            config._12_4_ = config._12_4_ | 0x80000000;
            set_time_out_control(config._12_4_);
          }
          else {
            set_time_out_control(0x8000c350);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"set TICKET_MASK",0x10);
            _applog(5,tmp42,false);
          }
          set_asic_ticket_mask(ticket_mask);
          cgsleep_ms(10);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"Start Open Core!",0x10);
            tmp42[0x10] = '!';
            tmp42[0x11] = '\0';
            _applog(5,tmp42,false);
          }
          open_core_bm1393(false);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"End Open Core!!",0x10);
            _applog(5,tmp42,false);
          }
          if (opt_multi_version == 0) {
            config._8_4_ = dev->timeout;
            config._12_4_ = (uint)config._8_4_ / 10;
            config._12_4_ = config._12_4_ & 0x1ffff;
            config._12_4_ = config._12_4_ | 0x80000000;
            set_time_out_control(config._12_4_);
          }
          else {
            config._8_4_ = dev->timeout;
            config._12_4_ = (uint)config._8_4_ / 10;
            config._12_4_ = config._12_4_ & 0x1ffff;
            config._12_4_ = config._12_4_ | 0x80000000;
            set_time_out_control(config._12_4_);
          }
          x = 0;
          while (x < 0x10) {
            config._12_4_ = dev->chain_exist[x];
            if (config._12_4_ != 0) {
              offset = 0;
              y = 0;
              while( true ) {
                config._13_3_ = 0;
                config.frequency._0_1_ = dev->chain_asic_num[x];
                if ((int)config._12_4_ <= y) break;
                config._12_4_ = y & 7;
                if (config._12_4_ == 0) {
                  config._4_4_ = y + offset;
                  dev->chain_asic_status_string[x][config._4_4_] = ' ';
                  config._12_4_ = offset + 1;
                  offset = config._12_4_;
                }
                config._4_4_ = y + offset;
                dev->chain_asic_status_string[x][config._4_4_] = 'o';
                paVar2 = dev;
                *(undefined4 *)(dev->chain_asic_nonce[x] + y) = 0;
                *(undefined4 *)((int)paVar2->chain_asic_nonce[x] + y * 8 + 4) = 0;
                config._12_4_ = y + 1;
                y = config._12_4_;
              }
              config._4_4_ = y + offset;
              dev->chain_asic_status_string[x][config._4_4_] = '\0';
            }
            config._12_4_ = x + 1;
            x = config._12_4_;
          }
          config._0_4_ = calloc(1,0x40);
          read_temp_id = (thr_info *)config._0_4_;
          config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                         (_func_void_ptr_void_ptr *)0x3eb45,(void *)config._0_4_);
          if (config._0_4_ == 0) {
            config._12_4_ = read_temp_id->pth;
            pthread_detach(config._12_4_);
            cgtime(&tv_send_job);
            cgtime(&tv_send);
            startCheckNetworkJob = true;
            config._0_4_ = calloc(1,0x40);
            read_hash_rate = (thr_info *)config._0_4_;
            config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                           (_func_void_ptr_void_ptr *)0x31db5,(void *)config._0_4_);
            if (config._0_4_ == 0) {
              config._12_4_ = read_hash_rate->pth;
              pthread_detach(config._12_4_);
              cgsleep_ms(500);
              setStartTimePoint();
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                builtin_strncpy(tmp42,"Init OK!",8);
                tmp42._8_4_ = tmp42._8_4_ & 0xffffff00;
                _applog(5,tmp42,false);
              }
              config.frequency = 0;
              config.voltage[0] = '\0';
              config.voltage[1] = '\0';
            }
            else {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: create thread for get hashrate from asic failed",
                         "bitmain_soc_init");
                _applog(7,tmp42,false);
              }
              config.frequency = 0xfffa;
              config.voltage[0] = 0xff;
              config.voltage[1] = 0xff;
            }
          }
          else {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: create thread for read temp\n","bitmain_soc_init");
              _applog(7,tmp42,false);
            }
            config.frequency = 0xfff9;
            config.voltage[0] = 0xff;
            config.voltage[1] = 0xff;
          }
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
                     "bitmain_soc_init");
            _applog(7,tmp42,false);
          }
          config.frequency = 0xfffb;
          config.voltage[0] = 0xff;
          config.voltage[1] = 0xff;
        }
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
                   "bitmain_soc_init");
          _applog(7,tmp42,false);
        }
        config.frequency = 0xfffb;
        config.voltage[0] = 0xff;
        config.voltage[1] = 0xff;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        config.voltage[0] = '\0';
        config.voltage[1] = '\0';
        config.frequency = config_parameter.crc;
        config.fan_pwm_percent = '\0';
        config.temperature = '\0';
        config.chain_num = config.token_type;
        config.asic_num = config.version;
        snprintf(tmp42,0x800,"%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                 "bitmain_soc_init",config._12_4_,config._8_4_);
        _applog(7,tmp42,false);
      }
      config.frequency = 0xfffe;
      config.voltage[0] = 0xff;
      config.voltage[1] = 0xff;
    }
  }
  else {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      config._12_4_ = config._0_4_ & 0xff;
      snprintf(tmp42,0x800,"%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
               "bitmain_soc_init",0x51,config._12_4_);
      _applog(7,tmp42,false);
    }
    config.frequency = 0xffff;
    config.voltage[0] = 0xff;
    config.voltage[1] = 0xff;
  }
  config._0_4_ = config._12_4_;
  return config._0_4_;
}

