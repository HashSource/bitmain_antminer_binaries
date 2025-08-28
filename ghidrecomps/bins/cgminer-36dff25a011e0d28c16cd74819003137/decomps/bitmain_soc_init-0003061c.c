
int bitmain_soc_init(init_config config)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  undefined1 auVar5 [20];
  undefined1 auVar6 [12];
  undefined8 uVar7;
  FILE *pFile_9;
  float max_freq;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  char *initlogfile;
  char ret;
  
  uVar3 = config._12_4_;
  uVar2 = config._0_4_;
  config._16_16_ = config._16_16_;
  opt_multi_version = 1;
  opt_bitmain_ab = true;
  set_privite_log_file("/tmp/initlog",&init_log_bak);
  log_init();
  init_freq_mode();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: %s\n","driver-btm-soc.c",0x1d32,"bitmain_soc_init",
              "S17");
    }
    fclose((FILE *)config._0_4_);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: opt_multi_version=%d\n","driver-btm-soc.c",0x1d33,
              "bitmain_soc_init",opt_multi_version);
    }
    fclose((FILE *)config._0_4_);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      config._13_3_ = 0;
      config.frequency._0_1_ = opt_bitmain_ab;
      fprintf((FILE *)config._0_4_,"%s:%d:%s: opt_bitmain_ab=%d\n","driver-btm-soc.c",0x1d34,
              "bitmain_soc_init",config._12_4_);
    }
    fclose((FILE *)config._0_4_);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      if (opt_bitmain_economic_mode == false) {
        uVar1 = 0xd178;
      }
      else {
        uVar1 = 0xd170;
      }
      config._12_4_ = uVar1 | 0x90000;
      fprintf((FILE *)config._0_4_,"%s:%d:%s: opt_bitmain_economic_mode=%s\n","driver-btm-soc.c",
              0x1d35,"bitmain_soc_init",config._12_4_);
    }
    fclose((FILE *)config._0_4_);
  }
  _show_sn();
  _show_mode();
  init_phy_mem_nonce2_jobid_address();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-soc.c",
              0x1d3c,"bitmain_soc_init",g_miner_compiletime,g_miner_type);
    }
    fclose((FILE *)config._0_4_);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,
              "%s:%d:%s: last commit version: a72fb33 commit time: 2019-01-21 21:17:43 build: 2019-01-22 11:21:49\n"
              ,"driver-btm-soc.c",0x1d3e,"bitmain_soc_init");
    }
    fclose((FILE *)config._0_4_);
  }
  config._0_4_ = uVar2;
  uVar7 = CONCAT44(config._4_4_,config._0_4_);
  auVar6 = CONCAT48(config._8_4_,uVar7);
  config._12_4_ = uVar3;
  auVar5 = CONCAT164(config._16_16_,config._12_4_);
  config = (init_config)CONCAT2012(auVar5,auVar6);
  config._0_4_ = init_global_config_parameter(config);
  if (config.token_type == '\0') {
    init_led();
    bitmain_axi_init();
    check_fan_multi();
    init_dev_frequency();
    start_http_thread();
    if (freq_mode == 0) {
      do_freq_tuning();
    }
    config._0_4_ = start_read_nonce_reg_thread();
    if (config.token_type == '\0') {
      if ((config_parameter._4_1_ & 1) != 0) {
        reset_fpga_and_hash_board();
      }
      set_pwm('d');
      set_Hardware_version(0x40000000);
      read_fpga_id(FPGA_ID_str);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        config._0_4_ = fopen(log_file,"a+");
        if (config._0_4_ != 0) {
          fprintf((FILE *)config._0_4_,"%s:%d:%s: miner ID : %s\n","driver-btm-soc.c",0x1d6c,
                  "bitmain_soc_init",FPGA_ID_str);
        }
        fclose((FILE *)config._0_4_);
      }
      init_miner_version();
      dev->baud = 0x1a;
      set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
      config._12_4_ = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
      set_job_start_address(config._12_4_);
      check_chain();
      eeprom_load();
      dump_pcb_bom_version();
      init_pic();
      power_init();
      power_on();
      config._13_3_ = 0;
      config.frequency._0_1_ = All_Chain;
      power_off_hash_board(config._12_4_);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        config._0_4_ = fopen(log_file,"a+");
        if (config._0_4_ != 0) {
          fprintf((FILE *)config._0_4_,
                  "%s:%d:%s: Enter %ds sleep to make sure power release finish.\n",
                  "driver-btm-soc.c",0x1d84,"bitmain_soc_init",0x1e);
        }
        fclose((FILE *)config._0_4_);
      }
      sleep(0x1e);
      init_working_voltage();
      set_iic_power_to_highest_voltage();
      config.token_type = is_fixed_freq_mode();
      if (!(bool)config.token_type) {
        eeprom_dump();
      }
      if (opt_multi_version != 0) {
        config._0_4_ = get_dhash_acc_control();
        config._12_4_ = config._0_4_ & 0xffff701f;
        config._12_4_ = config._12_4_ | 0x8100;
        set_dhash_acc_control(config._12_4_);
      }
      cgsleep_ms(10);
      dev->corenum = 0x2a0;
      hash_board_power_on_with_reset();
      check_asic_number();
      set_order_clock();
      cgsleep_ms(10);
      software_set_address();
      cgsleep_ms(10);
      set_pll(init_freq);
      calculate_timeout();
      cgsleep_ms(10);
      init_uart_baud();
      cgsleep_ms(10);
      set_clock_delay_control(All_Chain);
      cgsleep_ms(5);
      do_calibration_temperature_sensor();
      set_timeout_control();
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        config._0_4_ = fopen(log_file,"a+");
        if (config._0_4_ != 0) {
          fprintf((FILE *)config._0_4_,"%s:%d:%s: set TICKET_MASK\n","driver-btm-soc.c",0x1dbf,
                  "bitmain_soc_init");
        }
        fclose((FILE *)config._0_4_);
      }
      set_asic_ticket_mask(ticket_mask);
      cgsleep_ms(10);
      if (freq_mode != 2) {
        _get_freq_from_eeprom();
        if (g_total_hashrate == 0) {
          config._0_4_ = get_fixed_total_hash_rate();
          g_total_hashrate._0_1_ = config.token_type;
          g_total_hashrate._1_1_ = config.version;
          g_total_hashrate._2_2_ = config.length;
        }
      }
      slowly_set_iic_power_to_working_voltage();
      fVar4 = set_freq_and_get_max_freq();
      set_timeout((int)fVar4,0x5a);
      init_asic_status_and_nonce_count();
      config._0_4_ = start_read_temp_thread();
      if (config.token_type == '\0') {
        cgtime(&tv_send_job);
        cgtime(&tv_send);
        startCheckNetworkJob = true;
        config._0_4_ = start_read_hash_rate_thread();
        if (config.token_type == '\0') {
          config._0_4_ = start_check_system_work_thread();
          if (config.token_type == '\0') {
            cgsleep_ms(500);
            set_start_time_point();
            get_average_voltage();
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              config._0_4_ = fopen(log_file,"a+");
              if (config._0_4_ != 0) {
                fprintf((FILE *)config._0_4_,"%s:%d:%s: Init done!\n","driver-btm-soc.c",0x1e04,
                        "bitmain_soc_init");
              }
              fclose((FILE *)config._0_4_);
            }
            restore_syslog_file(&init_log_bak);
            config.frequency = 0;
            config.voltage = 0;
          }
          else {
            config._12_4_ = config._0_4_ & 0xff;
          }
        }
        else {
          config._12_4_ = config._0_4_ & 0xff;
        }
      }
      else {
        config._12_4_ = config._0_4_ & 0xff;
      }
    }
    else {
      config._12_4_ = config._0_4_ & 0xff;
    }
  }
  else {
    config._12_4_ = config._0_4_ & 0xff;
  }
  config._0_4_ = config._12_4_;
  return config._0_4_;
}

