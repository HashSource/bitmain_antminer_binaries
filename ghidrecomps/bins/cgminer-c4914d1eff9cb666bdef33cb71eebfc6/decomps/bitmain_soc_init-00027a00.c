
int bitmain_soc_init(init_config config)

{
  byte bVar1;
  undefined4 uVar2;
  all_parameters *paVar3;
  undefined2 uVar4;
  undefined4 __stream;
  undefined4 uVar5;
  sysinfo si;
  FILE *pFile_9;
  FILE *pFile_10;
  FILE *pFile_11;
  FILE *pFile_18;
  FILE *pFile_19;
  FILE *pFile_20;
  FILE *pFile_21;
  FILE *pFile_22;
  FILE *pFile_17;
  FILE *pFile_16;
  FILE *pFile_15;
  FILE *pFile_14;
  FILE *pFile_13;
  FILE *pFile_12;
  FILE *pFile_8;
  FILE *pFile_5;
  FILE *pFile_6;
  FILE *pFile_7;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile;
  char *initlogfile;
  int ret;
  uint16_t crc;
  int offset;
  float max_freq;
  int y;
  int x;
  
  uVar5 = config._12_4_;
  uVar2 = config._0_4_;
  opt_multi_version = 1;
  set_privite_log_file("/tmp/initlog",&init_log_bak);
  log_init();
  aging_get_info();
  freq_mode = 2;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: This is %s fix freq version\n","driver-btm-soc.c",
              0x1904,"bitmain_soc_init",g_miner_type);
    }
    fclose((FILE *)config._0_4_);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    __stream = config._0_4_;
    if (config._0_4_ != 0) {
      config.token_type = is_special_mode();
      if ((bool)config.token_type) {
        config._12_4_ = s_enabled_00083694;
      }
      else {
        config._12_4_ = s_disabled_0008369c;
      }
      fprintf((FILE *)__stream,"%s:%d:%s: special mode: %s\n","driver-btm-soc.c",0x1907,
              "bitmain_soc_init",config._12_4_);
    }
    fclose((FILE *)__stream);
  }
  config.token_type = is_economic_mode();
  if ((bool)config.token_type) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      config._0_4_ = fopen(log_file,"a+");
      if (config._0_4_ != 0) {
        fprintf((FILE *)config._0_4_,"%s:%d:%s: This is economic mode\n","driver-btm-soc.c",0x190a,
                "bitmain_soc_init");
      }
      fclose((FILE *)config._0_4_);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: This is high performance mode\n","driver-btm-soc.c",
              0x190e,"bitmain_soc_init");
    }
    fclose((FILE *)config._0_4_);
  }
  show_mode();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,
              "%s:%d:%s: last commit version: 2f40e5d commit time: 2019-06-25 15:53:07 build: 2019-06-25 16:07:18\n"
              ,"driver-btm-soc.c",0x1913,"bitmain_soc_init");
    }
    fclose((FILE *)config._0_4_);
  }
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        config._0_4_ = fopen(log_file,"a+");
        if (config._0_4_ != 0) {
          fprintf((FILE *)config._0_4_,"%s:%d:%s: Detect 256MB control board of XILINX\n",
                  "driver-btm-soc.c",0x1928,"bitmain_soc_init");
        }
        fclose((FILE *)config._0_4_);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        config._0_4_ = fopen(log_file,"a+");
        if (config._0_4_ != 0) {
          fprintf((FILE *)config._0_4_,"%s:%d:%s: Detect 512MB control board of XILINX\n",
                  "driver-btm-soc.c",0x1922,"bitmain_soc_init");
        }
        fclose((FILE *)config._0_4_);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      config._0_4_ = fopen(log_file,"a+");
      if (config._0_4_ != 0) {
        fprintf((FILE *)config._0_4_,"%s:%d:%s: Detect 1GB control board of XILINX\n",
                "driver-btm-soc.c",0x191c,"bitmain_soc_init");
      }
      fclose((FILE *)config._0_4_);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    config._0_4_ = fopen(log_file,"a+");
    if (config._0_4_ != 0) {
      fprintf((FILE *)config._0_4_,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-soc.c",
              0x192b,"bitmain_soc_init",g_miner_compiletime,g_miner_type);
    }
    fclose((FILE *)config._0_4_);
  }
  config_parameter._0_4_ = uVar2;
  config_parameter._4_4_ = config._4_4_;
  config_parameter._8_4_ = config._8_4_;
  config_parameter._12_4_ = uVar5;
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
  config_parameter.token_type = (uint8_t)uVar2;
  config_parameter._0_4_ = uVar2;
  if (config_parameter.token_type == 'Q') {
    config._0_2_ = CRC16(&config_parameter.token_type,0x1e);
    uVar4 = config._0_2_;
    if (config._0_2_ == config_parameter.crc) {
      config._0_4_ = bitmain_axi_init();
      if (config._0_4_ == 0) {
        config._0_4_ = check_pool_worker();
        if (config._0_4_ == 0) {
          config._0_4_ = check_pool_for_validation();
          if (config._0_4_ == 0) {
            StartHttpThread();
            config._0_4_ = check_fan_num();
            if (config._0_4_ == 0) {
              config._0_4_ = check_chain();
              if ((config._0_4_ != 0) &&
                 (((config._12_4_ = &dev->chain_num, *(char *)config._12_4_ == '\0' ||
                   (freq_mode == 0)) || (freq_mode == 2)))) {
                return config._0_4_;
              }
              config._0_4_ = eeprom_date_check();
              if ((config._0_4_ != 0) &&
                 (((config._12_4_ = &dev->chain_num, *(char *)config._12_4_ == '\0' ||
                   (freq_mode == 0)) || (freq_mode == 2)))) {
                return config._0_4_;
              }
              config._0_4_ = check_hashboard_hardware_info();
              if (config._0_4_ == 0) {
                init_sweep_config();
                init_pulse_mode();
                config.token_type = is_force_mode();
                if ((bool)config.token_type) {
                  config.token_type = is_column_sweep();
                  if ((bool)config.token_type) {
                    config._0_4_ = sweep_freq_by_column();
                    if (config._0_4_ != 0) {
                      return config._0_4_;
                    }
                  }
                  else {
                    config.token_type = is_board_sweep();
                    if ((bool)config.token_type) {
                      boardsweep_task();
                    }
                    else {
                      scan_freq_scan_by_column();
                    }
                  }
                  config.token_type = is_scan_freq_trigged_and_succeeded();
                  if ((bool)config.token_type) {
                    clear_probability_file();
                    remove("/nvdata/high_temp_assert_history");
                  }
                }
                else {
                  scan_freq_mark_success();
                }
                config.token_type = is_fixed_mode();
                if (!(bool)config.token_type) {
                  if (enable_get_freq_from_eeprom == false) {
                    config._12_4_ = config_parameter._12_4_ & 0xffff;
                    get_freq_result(config._12_4_);
                  }
                  else {
                    get_freq_result_from_eeprom();
                  }
                }
                config._0_4_ = calloc(1,0x40);
                read_nonce_reg_id = (thr_info *)config._0_4_;
                config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                               (_func_void_ptr_void_ptr *)0x222db,
                                               (void *)config._0_4_);
                if (config._0_4_ == 0) {
                  config._12_4_ = read_nonce_reg_id->pth;
                  pthread_detach(config._12_4_);
                  if ((config_parameter._4_4_ & 1) != 0) {
                    if (3 < log_level) {
                      print_crt_time_to_file(log_file,3);
                      config._0_4_ = fopen(log_file,"a+");
                      if (config._0_4_ != 0) {
                        fprintf((FILE *)config._0_4_,"%s:%d:%s: reset all...\n","driver-btm-soc.c",
                                0x1986,"bitmain_soc_init");
                      }
                      fclose((FILE *)config._0_4_);
                    }
                    set_QN_write_data_command(0x8080800f);
                    sleep(2);
                    set_PWM('d');
                  }
                  set_Hardware_version(0x40000000);
                  read_fpga_id(FPGA_ID_str);
                  if (3 < log_level) {
                    print_crt_time_to_file(log_file,3);
                    config._0_4_ = fopen(log_file,"a+");
                    if (config._0_4_ != 0) {
                      fprintf((FILE *)config._0_4_,"%s:%d:%s: miner ID : %s\n","driver-btm-soc.c",
                              0x198e,"bitmain_soc_init",FPGA_ID_str);
                    }
                    fclose((FILE *)config._0_4_);
                  }
                  init_miner_version();
                  config._12_4_ = &dev->baud;
                  *(undefined1 *)config._12_4_ = 0x1a;
                  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
                  config._12_4_ = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
                  set_job_start_address(config._12_4_);
                  set_PWM('d');
                  sleep(1);
                  config._0_4_ = init_pic();
                  if ((config._0_4_ != 0) &&
                     (((config._12_4_ = &dev->chain_num, *(char *)config._12_4_ == '\0' ||
                       (freq_mode == 0)) || (freq_mode == 2)))) {
                    return config._0_4_;
                  }
                  get_pic_software_version_all_chain();
                  power_init();
                  init_working_voltage();
                  update_highest_voltage();
                  config._0_4_ = _set_iic_power_to_highest_voltage();
                  if (config._0_4_ == 0) {
                    get_ideal_hash_rate();
                    config.token_type = is_fixed_mode();
                    if (!(bool)config.token_type) {
                      eeprom_dump();
                    }
                    config.token_type = is_T11();
                    if ((!(bool)config.token_type) && (3 < log_level)) {
                      print_crt_time_to_file(log_file,3);
                      config._0_4_ = fopen(log_file,"a+");
                      if (config._0_4_ != 0) {
                        get_average_voltage();
                        fprintf((FILE *)config._0_4_,"%s:%d:%s: the current avg vol is %5.2f\n",
                                "driver-btm-soc.c",0x19ae,"bitmain_soc_init");
                      }
                      fclose((FILE *)config._0_4_);
                    }
                    if ((config_parameter._4_4_ & 8) != 0) {
                      config._12_4_ = &dev->frequency;
                      *(uint16_t *)config._12_4_ = config_parameter.frequency;
                      config._0_4_ = dev->frequency_t;
                      config._12_4_ = &dev->frequency;
                      config.frequency = *(uint16_t *)config._12_4_;
                      config.voltage = 0;
                      sprintf((char *)config._0_4_,"%u",config._12_4_);
                    }
                    config._12_4_ = config_parameter._4_4_ << 0x1e;
                    bVar1 = config.voltage._1_1_;
                    config._12_4_ = &dev->fan_eft;
                    *(byte *)config._12_4_ = bVar1 >> 7;
                    config._12_4_ = &dev->fan_pwm;
                    *(uint8_t *)config._12_4_ = config_parameter.fan_pwm_percent;
                    if (3 < log_level) {
                      print_crt_time_to_file(log_file,3);
                      config._0_4_ = fopen(log_file,"a+");
                      if (config._0_4_ != 0) {
                        config._12_4_ = &dev->fan_eft;
                        config.frequency._0_1_ = *(byte *)config._12_4_;
                        config._13_3_ = 0;
                        uVar2 = config._12_4_;
                        config._12_4_ = &dev->fan_pwm;
                        config.frequency._0_1_ = *(byte *)config._12_4_;
                        config._13_3_ = 0;
                        fprintf((FILE *)config._0_4_,"%s:%d:%s: fan_eft : %d  fan_pwm : %d\n",
                                "driver-btm-soc.c",0x19b9,"bitmain_soc_init",uVar2,config._12_4_);
                      }
                      fclose((FILE *)config._0_4_);
                    }
                    if (opt_multi_version != 0) {
                      config._0_4_ = get_dhash_acc_control();
                      config._12_4_ = config._0_4_ & 0xffff70df;
                      config._12_4_ = config._12_4_ | 0x8100;
                      set_dhash_acc_control(config._12_4_);
                    }
                    cgsleep_ms(10);
                    init_address_info();
                    set_default_uart_baud();
                    config._0_4_ = bring_up_all_chain();
                    if ((config._0_4_ != 0) &&
                       (((config._12_4_ = &dev->chain_num, *(char *)config._12_4_ == '\0' ||
                         (freq_mode == 0)) || (freq_mode == 2)))) {
                      return config._0_4_;
                    }
                    set_working_uart_baud();
                    set_iic_for_temperature();
                    if (3 < log_level) {
                      print_crt_time_to_file(log_file,3);
                      config._0_4_ = fopen(log_file,"a+");
                      if (config._0_4_ != 0) {
                        fprintf((FILE *)config._0_4_,"%s:%d:%s: set TICKET_MASK\n",
                                "driver-btm-soc.c",0x19c8,"bitmain_soc_init");
                      }
                      fclose((FILE *)config._0_4_);
                    }
                    set_asic_ticket_mask(ticket_mask);
                    cgsleep_ms(10);
                    detect_environment_temperature();
                    set_clock_delay_control(All_Chain,g_pulse_mode);
                    open_core_bm1393(true,All_Chain);
                    config.token_type = is_fixed_mode();
                    if ((bool)config.token_type) {
                      if (g_freq_test == false) {
                        max_freq = set_target_freq();
                      }
                      else {
                        max_freq = set_adjust_freq();
                      }
                    }
                    else {
                      config._0_2_ = increase_freq_by_eeprom_slowly((int)init_freq,(int)freq_step);
                      max_freq = (float)(ushort)config._0_2_;
                    }
                    if (3 < log_level) {
                      print_crt_time_to_file(log_file,3);
                      config._0_4_ = fopen(log_file,"a+");
                      if (config._0_4_ != 0) {
                        fprintf((FILE *)config._0_4_,"%s:%d:%s: set to working voltage...\n",
                                "driver-btm-soc.c",0x19e1,"bitmain_soc_init");
                      }
                      fclose((FILE *)config._0_4_);
                    }
                    _slowly_set_iic_power_to_working_voltage();
                    set_timeout((int)max_freq,0x32);
                    x = 0;
                    while (x < 0x10) {
                      config._12_4_ = dev->chain_exist[x];
                      if (config._12_4_ != 0) {
                        offset = 0;
                        y = 0;
                        while( true ) {
                          config._12_4_ = (int)dev->chain_asic_num + x;
                          config.frequency._0_1_ = *(byte *)config._12_4_;
                          config._13_3_ = 0;
                          if ((int)config._12_4_ <= y) break;
                          config._12_4_ = y & 7;
                          if (config._12_4_ == 0) {
                            config._4_4_ = y + offset;
                            config._12_4_ = (int)dev->chain_asic_status_string[x] + config._4_4_;
                            *(undefined1 *)config._12_4_ = 0x20;
                            config._12_4_ = offset + 1;
                            offset = config._12_4_;
                          }
                          config._4_4_ = y + offset;
                          config._12_4_ = (int)dev->chain_asic_status_string[x] + config._4_4_;
                          *(undefined1 *)config._12_4_ = 0x6f;
                          paVar3 = dev;
                          *(undefined4 *)(dev->chain_asic_nonce[x] + y) = 0;
                          *(undefined4 *)((int)paVar3->chain_asic_nonce[x] + y * 8 + 4) = 0;
                          config._12_4_ = y + 1;
                          y = config._12_4_;
                        }
                        config._4_4_ = y + offset;
                        config._12_4_ = (int)dev->chain_asic_status_string[x] + config._4_4_;
                        *(undefined1 *)config._12_4_ = 0;
                      }
                      config._12_4_ = x + 1;
                      x = config._12_4_;
                    }
                    low_temp_process_parm_init();
                    config._0_4_ = calloc(1,0x40);
                    read_temp_id = (thr_info *)config._0_4_;
                    config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                                   (_func_void_ptr_void_ptr *)0x193ab,
                                                   (void *)config._0_4_);
                    if (config._0_4_ == 0) {
                      config._12_4_ = read_temp_id->pth;
                      pthread_detach(config._12_4_);
                      cgtime(&tv_send_job);
                      cgtime(&tv_send);
                      startCheckNetworkJob = true;
                      config._0_4_ = calloc(1,0x40);
                      read_hash_rate = (thr_info *)config._0_4_;
                      config._0_4_ = thr_info_create((thr_info *)config._0_4_,(pthread_attr_t *)0x0,
                                                     (_func_void_ptr_void_ptr *)0x1af99,
                                                     (void *)config._0_4_);
                      if (config._0_4_ == 0) {
                        config._12_4_ = read_hash_rate->pth;
                        pthread_detach(config._12_4_);
                        config._0_4_ = calloc(1,0x40);
                        check_system_work_id = (thr_info *)config._0_4_;
                        config._0_4_ = thr_info_create((thr_info *)config._0_4_,
                                                       (pthread_attr_t *)0x0,
                                                       (_func_void_ptr_void_ptr *)0x20a69,
                                                       (void *)config._0_4_);
                        if (config._0_4_ == 0) {
                          config._12_4_ = check_system_work_id->pth;
                          pthread_detach(config._12_4_);
                          config._0_4_ = calloc(1,0x40);
                          store_hash_rate_id = (thr_info *)config._0_4_;
                          config._0_4_ = thr_info_create((thr_info *)config._0_4_,
                                                         (pthread_attr_t *)0x0,
                                                         (_func_void_ptr_void_ptr *)0x60ac1,
                                                         (void *)config._0_4_);
                          if (config._0_4_ == 0) {
                            config._12_4_ = store_hash_rate_id->pth;
                            pthread_detach(config._12_4_);
                            cgsleep_ms(500);
                            setStartTimePoint();
                            if (3 < log_level) {
                              print_crt_time_to_file(log_file,3);
                              config._0_4_ = fopen(log_file,"a+");
                              if (config._0_4_ != 0) {
                                fprintf((FILE *)config._0_4_,"%s:%d:%s: Init done!\n",
                                        "driver-btm-soc.c",0x1a26,"bitmain_soc_init");
                              }
                              fclose((FILE *)config._0_4_);
                            }
                            restore_syslog_file(&init_log_bak);
                            config.frequency = 0;
                            config.voltage = 0;
                          }
                          else {
                            if (3 < log_level) {
                              print_crt_time_to_file(log_file,3);
                              config._0_4_ = fopen(log_file,"a+");
                              if (config._0_4_ != 0) {
                                fprintf((FILE *)config._0_4_,
                                        "%s:%d:%s: create thread for store hashrate history\n",
                                        "driver-btm-soc.c",0x1a1f,"bitmain_soc_init");
                              }
                              fclose((FILE *)config._0_4_);
                            }
                            config.frequency = 0xfffa;
                            config.voltage = 0xffff;
                          }
                        }
                        else {
                          if (3 < log_level) {
                            print_crt_time_to_file(log_file,3);
                            config._0_4_ = fopen(log_file,"a+");
                            if (config._0_4_ != 0) {
                              fprintf((FILE *)config._0_4_,
                                      "%s:%d:%s: create thread for check system\n",
                                      "driver-btm-soc.c",0x1a16,"bitmain_soc_init");
                            }
                            fclose((FILE *)config._0_4_);
                          }
                          config.frequency = 0xfffa;
                          config.voltage = 0xffff;
                        }
                      }
                      else {
                        if (3 < log_level) {
                          print_crt_time_to_file(log_file,3);
                          config._0_4_ = fopen(log_file,"a+");
                          if (config._0_4_ != 0) {
                            fprintf((FILE *)config._0_4_,
                                    "%s:%d:%s: create thread for get hashrate from asic failed\n",
                                    "driver-btm-soc.c",0x1a0e,"bitmain_soc_init");
                          }
                          fclose((FILE *)config._0_4_);
                        }
                        config.frequency = 0xfffa;
                        config.voltage = 0xffff;
                      }
                    }
                    else {
                      if (3 < log_level) {
                        print_crt_time_to_file(log_file,3);
                        config._0_4_ = fopen(log_file,"a+");
                        if (config._0_4_ != 0) {
                          fprintf((FILE *)config._0_4_,"%s:%d:%s: create thread for read temp\n",
                                  "driver-btm-soc.c",0x1a03,"bitmain_soc_init");
                        }
                        fclose((FILE *)config._0_4_);
                      }
                      config.frequency = 0xfff9;
                      config.voltage = 0xffff;
                    }
                  }
                  else {
                    config._12_4_ = config._0_4_;
                  }
                }
                else {
                  if (4 < log_level) {
                    print_crt_time_to_file(log_file,4);
                    config._0_4_ = fopen(log_file,"a+");
                    if (config._0_4_ != 0) {
                      fprintf((FILE *)config._0_4_,
                              "%s:%d:%s: create thread for get nonce and register from FPGA failed\n"
                              ,"driver-btm-soc.c",0x197e,"bitmain_soc_init");
                    }
                    fclose((FILE *)config._0_4_);
                  }
                  config.frequency = 0xfffb;
                  config.voltage = 0xffff;
                }
              }
              else {
                config._12_4_ = config._0_4_;
              }
            }
            else {
              config._12_4_ = config._0_4_;
            }
          }
          else {
            config._12_4_ = config._0_4_;
          }
        }
        else {
          config._12_4_ = config._0_4_;
        }
      }
      else {
        config._12_4_ = config._0_4_;
      }
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        config._0_4_ = fopen(log_file,"a+");
        uVar2 = config._0_4_;
        if (config._0_4_ != 0) {
          config.voltage = 0;
          config.token_type = (uint8_t)uVar4;
          config.version = SUB21(uVar4,1);
          config.frequency._0_1_ = config.token_type;
          config.frequency._1_1_ = config.version;
          fprintf((FILE *)uVar2,
                  "%s:%d:%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                  "driver-btm-soc.c",0x1936,"bitmain_soc_init",(uint)config_parameter._28_4_ >> 0x10
                  ,config._12_4_);
        }
        fclose((FILE *)uVar2);
      }
      config.frequency = 0xfffe;
      config.voltage = 0xffff;
    }
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      config._0_4_ = fopen(log_file,"a+");
      if (config._0_4_ != 0) {
        config._12_4_ = config_parameter._0_4_ & 0xff;
        fprintf((FILE *)config._0_4_,"%s:%d:%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
                "driver-btm-soc.c",0x192f,"bitmain_soc_init",0x51,config._12_4_);
      }
      fclose((FILE *)config._0_4_);
    }
    config.frequency = 0xffff;
    config.voltage = 0xffff;
  }
  config._0_4_ = config._12_4_;
  return config._0_4_;
}

