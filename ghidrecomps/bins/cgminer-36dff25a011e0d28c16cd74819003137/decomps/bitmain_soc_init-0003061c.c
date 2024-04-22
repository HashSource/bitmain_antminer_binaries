
/* WARNING: Variable defined which should be unmapped: pFile_9 */

int bitmain_soc_init(init_config config)

{
  init_config config_00;
  undefined auVar1 [16];
  _Bool _Var2;
  FILE *pFVar3;
  uint uVar4;
  float fVar5;
  undefined4 uStack_50;
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
  
  opt_multi_version = 1;
  opt_bitmain_ab = true;
  set_privite_log_file("/tmp/initlog",&init_log_bak);
  log_init();
  init_freq_mode();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: %s\n","driver-btm-soc.c",0x1d32,"bitmain_soc_init","S17");
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: opt_multi_version=%d\n","driver-btm-soc.c",0x1d33,"bitmain_soc_init"
              ,opt_multi_version);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: opt_bitmain_ab=%d\n","driver-btm-soc.c",0x1d34,"bitmain_soc_init",
              (uint)opt_bitmain_ab);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      if (opt_bitmain_economic_mode == false) {
        uVar4 = 0xd178;
      }
      else {
        uVar4 = 0xd170;
      }
      fprintf(pFVar3,"%s:%d:%s: opt_bitmain_economic_mode=%s\n","driver-btm-soc.c",0x1d35,
              "bitmain_soc_init",uVar4 | 0x90000);
    }
    fclose(pFVar3);
  }
  _show_sn();
  _show_mode();
  init_phy_mem_nonce2_jobid_address();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-soc.c",0x1d3c,
              "bitmain_soc_init",g_miner_compiletime,g_miner_type);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,
              "%s:%d:%s: last commit version: a72fb33 commit time: 2019-01-21 21:17:43 build: 2019-01-22 11:21:49\n"
              ,"driver-btm-soc.c",0x1d3e,"bitmain_soc_init");
    }
    fclose(pFVar3);
  }
  auVar1 = config._0_16_;
  config_00._16_4_ = uStack_50;
  config_00.token_type = auVar1[0];
  config_00.version = auVar1[1];
  config_00.length = auVar1._2_2_;
  config_00._4_2_ = auVar1._4_2_;
  config_00.reserved2[0] = auVar1[6];
  config_00.reserved2[1] = auVar1[7];
  config_00.chain_num = auVar1[8];
  config_00.asic_num = auVar1[9];
  config_00.fan_pwm_percent = auVar1[10];
  config_00.temperature = auVar1[11];
  config_00.frequency = auVar1._12_2_;
  config_00.voltage = auVar1._14_2_;
  config_00.reg_data = (uint32_t)pFile_9;
  config_00._24_4_ = max_freq;
  config_00._28_4_ = pFile_8;
  uVar4 = init_global_config_parameter(config_00);
  if ((char)uVar4 == '\0') {
    init_led();
    bitmain_axi_init();
    check_fan_multi();
    init_dev_frequency();
    start_http_thread();
    if (freq_mode == 0) {
      do_freq_tuning();
    }
    uVar4 = start_read_nonce_reg_thread();
    if ((char)uVar4 == '\0') {
      if ((config_parameter._4_1_ & 1) != 0) {
        reset_fpga_and_hash_board();
      }
      set_pwm('d');
      set_Hardware_version(0x40000000);
      read_fpga_id(FPGA_ID_str);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: miner ID : %s\n","driver-btm-soc.c",0x1d6c,"bitmain_soc_init",
                  FPGA_ID_str);
        }
        fclose(pFVar3);
      }
      init_miner_version();
      dev->baud = 0x1a;
      set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
      set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
      check_chain();
      eeprom_load();
      dump_pcb_bom_version();
      init_pic();
      power_init();
      power_on();
      power_off_hash_board((uint)All_Chain);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: Enter %ds sleep to make sure power release finish.\n",
                  "driver-btm-soc.c",0x1d84,"bitmain_soc_init",0x1e);
        }
        fclose(pFVar3);
      }
      sleep(0x1e);
      init_working_voltage();
      set_iic_power_to_highest_voltage();
      _Var2 = is_fixed_freq_mode();
      if (!_Var2) {
        eeprom_dump();
      }
      if (opt_multi_version != 0) {
        uVar4 = get_dhash_acc_control();
        set_dhash_acc_control(uVar4 & 0xffff701f | 0x8100);
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
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: set TICKET_MASK\n","driver-btm-soc.c",0x1dbf,"bitmain_soc_init")
          ;
        }
        fclose(pFVar3);
      }
      set_asic_ticket_mask(ticket_mask);
      cgsleep_ms(10);
      if ((freq_mode != 2) && (_get_freq_from_eeprom(), g_total_hashrate == 0)) {
        g_total_hashrate = get_fixed_total_hash_rate();
      }
      slowly_set_iic_power_to_working_voltage();
      fVar5 = set_freq_and_get_max_freq();
      set_timeout((int)fVar5,0x5a);
      init_asic_status_and_nonce_count();
      uVar4 = start_read_temp_thread();
      if ((char)uVar4 == '\0') {
        cgtime(&tv_send_job);
        cgtime(&tv_send);
        startCheckNetworkJob = true;
        uVar4 = start_read_hash_rate_thread();
        if ((char)uVar4 == '\0') {
          uVar4 = start_check_system_work_thread();
          if ((char)uVar4 == '\0') {
            cgsleep_ms(500);
            set_start_time_point();
            get_average_voltage();
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar3 = fopen(log_file,"a+");
              if (pFVar3 != (FILE *)0x0) {
                fprintf(pFVar3,"%s:%d:%s: Init done!\n","driver-btm-soc.c",0x1e04,"bitmain_soc_init"
                       );
              }
              fclose(pFVar3);
            }
            restore_syslog_file(&init_log_bak);
            uVar4 = 0;
          }
          else {
            uVar4 = uVar4 & 0xff;
          }
        }
        else {
          uVar4 = uVar4 & 0xff;
        }
      }
      else {
        uVar4 = uVar4 & 0xff;
      }
    }
    else {
      uVar4 = uVar4 & 0xff;
    }
  }
  else {
    uVar4 = uVar4 & 0xff;
  }
  return uVar4;
}

