
int bitmain_soc_init(init_config config)

{
  all_parameters *paVar1;
  _Bool _Var2;
  uint16_t uVar3;
  undefined4 in_r0;
  FILE *pFVar4;
  uint uVar5;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  char *pcVar6;
  int iVar7;
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
  
  opt_multi_version = 1;
  set_privite_log_file("/tmp/initlog",&init_log_bak);
  log_init();
  aging_get_info();
  freq_mode = 2;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: This is %s fix freq version\n","driver-btm-soc.c",0x1904,
              "bitmain_soc_init",g_miner_type);
    }
    fclose(pFVar4);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      _Var2 = is_special_mode();
      if (_Var2) {
        pcVar6 = "enabled";
      }
      else {
        pcVar6 = "disabled";
      }
      fprintf(pFVar4,"%s:%d:%s: special mode: %s\n","driver-btm-soc.c",0x1907,"bitmain_soc_init",
              pcVar6);
    }
    fclose(pFVar4);
  }
  _Var2 = is_economic_mode();
  if (_Var2) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: This is economic mode\n","driver-btm-soc.c",0x190a,
                "bitmain_soc_init");
      }
      fclose(pFVar4);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: This is high performance mode\n","driver-btm-soc.c",0x190e,
              "bitmain_soc_init");
    }
    fclose(pFVar4);
  }
  show_mode();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,
              "%s:%d:%s: last commit version: 2f40e5d commit time: 2019-06-25 15:53:07 build: 2019-06-25 16:07:18\n"
              ,"driver-btm-soc.c",0x1913,"bitmain_soc_init");
    }
    fclose(pFVar4);
  }
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: Detect 256MB control board of XILINX\n","driver-btm-soc.c",
                  0x1928,"bitmain_soc_init");
        }
        fclose(pFVar4);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: Detect 512MB control board of XILINX\n","driver-btm-soc.c",
                  0x1922,"bitmain_soc_init");
        }
        fclose(pFVar4);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: Detect 1GB control board of XILINX\n","driver-btm-soc.c",0x191c,
                "bitmain_soc_init");
      }
      fclose(pFVar4);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: Miner compile time: %s type: %s\n","driver-btm-soc.c",0x192b,
              "bitmain_soc_init",g_miner_compiletime,g_miner_type);
    }
    fclose(pFVar4);
  }
  config_parameter._16_4_ = config._0_4_;
  config_parameter.reg_data = config._4_4_;
  config_parameter._24_4_ = config._8_4_;
  config_parameter.chain_max_freq = config.frequency;
  config_parameter.crc = config.voltage;
  config_parameter.token_type = (uint8_t)in_r0;
  config_parameter._0_4_ = in_r0;
  config_parameter._4_4_ = in_r1;
  config_parameter._8_4_ = in_r2;
  config_parameter._12_4_ = in_r3;
  if (config_parameter.token_type == 'Q') {
    uVar3 = CRC16(&config_parameter.token_type,0x1e);
    if (uVar3 == config_parameter.crc) {
      iVar7 = bitmain_axi_init();
      if (((iVar7 == 0) && (iVar7 = check_pool_worker(), iVar7 == 0)) &&
         (iVar7 = check_pool_for_validation(), iVar7 == 0)) {
        StartHttpThread();
        iVar7 = check_fan_num();
        if ((((iVar7 == 0) &&
             ((iVar7 = check_chain(), iVar7 == 0 ||
              (((dev->chain_num != '\0' && (freq_mode != 0)) && (freq_mode != 2)))))) &&
            ((iVar7 = eeprom_date_check(), iVar7 == 0 ||
             (((dev->chain_num != '\0' && (freq_mode != 0)) && (freq_mode != 2)))))) &&
           (iVar7 = check_hashboard_hardware_info(), iVar7 == 0)) {
          init_sweep_config();
          init_pulse_mode();
          _Var2 = is_force_mode();
          if (_Var2) {
            _Var2 = is_column_sweep();
            if (_Var2) {
              iVar7 = sweep_freq_by_column();
              if (iVar7 != 0) {
                return iVar7;
              }
            }
            else {
              _Var2 = is_board_sweep();
              if (_Var2) {
                boardsweep_task();
              }
              else {
                scan_freq_scan_by_column();
              }
            }
            _Var2 = is_scan_freq_trigged_and_succeeded();
            if (_Var2) {
              clear_probability_file();
              remove("/nvdata/high_temp_assert_history");
            }
          }
          else {
            scan_freq_mark_success();
          }
          _Var2 = is_fixed_mode();
          if (!_Var2) {
            if (enable_get_freq_from_eeprom == false) {
              get_freq_result(config_parameter._12_4_ & 0xffff);
            }
            else {
              get_freq_result_from_eeprom();
            }
          }
          read_nonce_reg_id = (thr_info *)calloc(1,0x40);
          iVar7 = thr_info_create(read_nonce_reg_id,(pthread_attr_t *)0x0,get_nonce_and_register + 1
                                  ,read_nonce_reg_id);
          if (iVar7 == 0) {
            pthread_detach(read_nonce_reg_id->pth);
            if ((config_parameter._4_4_ & 1) != 0) {
              if (3 < log_level) {
                print_crt_time_to_file(log_file,3);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,"%s:%d:%s: reset all...\n","driver-btm-soc.c",0x1986,
                          "bitmain_soc_init");
                }
                fclose(pFVar4);
              }
              set_QN_write_data_command(0x8080800f);
              sleep(2);
              set_PWM('d');
            }
            set_Hardware_version(0x40000000);
            read_fpga_id(FPGA_ID_str);
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar4 = fopen(log_file,"a+");
              if (pFVar4 != (FILE *)0x0) {
                fprintf(pFVar4,"%s:%d:%s: miner ID : %s\n","driver-btm-soc.c",0x198e,
                        "bitmain_soc_init",FPGA_ID_str);
              }
              fclose(pFVar4);
            }
            init_miner_version();
            dev->baud = '\x1a';
            set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
            set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
            set_PWM('d');
            sleep(1);
            iVar7 = init_pic();
            if ((iVar7 == 0) || (((dev->chain_num != '\0' && (freq_mode != 0)) && (freq_mode != 2)))
               ) {
              get_pic_software_version_all_chain();
              power_init();
              init_working_voltage();
              update_highest_voltage();
              iVar7 = _set_iic_power_to_highest_voltage();
              if (iVar7 == 0) {
                get_ideal_hash_rate();
                _Var2 = is_fixed_mode();
                if (!_Var2) {
                  eeprom_dump();
                }
                _Var2 = is_T11();
                if ((!_Var2) && (3 < log_level)) {
                  print_crt_time_to_file(log_file,3);
                  pFVar4 = fopen(log_file,"a+");
                  if (pFVar4 != (FILE *)0x0) {
                    get_average_voltage();
                    fprintf(pFVar4,"%s:%d:%s: the current avg vol is %5.2f\n","driver-btm-soc.c",
                            0x19ae,"bitmain_soc_init");
                  }
                  fclose(pFVar4);
                }
                if ((config_parameter._4_4_ & 8) != 0) {
                  dev->frequency = config_parameter.frequency;
                  sprintf(dev->frequency_t,"%u",(uint)dev->frequency);
                }
                dev->fan_eft = (byte)((uint)(config_parameter._4_4_ << 0x1e) >> 0x1f);
                dev->fan_pwm = config_parameter.fan_pwm_percent;
                if (3 < log_level) {
                  print_crt_time_to_file(log_file,3);
                  pFVar4 = fopen(log_file,"a+");
                  if (pFVar4 != (FILE *)0x0) {
                    fprintf(pFVar4,"%s:%d:%s: fan_eft : %d  fan_pwm : %d\n","driver-btm-soc.c",
                            0x19b9,"bitmain_soc_init",(uint)dev->fan_eft,(uint)dev->fan_pwm);
                  }
                  fclose(pFVar4);
                }
                if (opt_multi_version != 0) {
                  uVar5 = get_dhash_acc_control();
                  set_dhash_acc_control(uVar5 & 0xffff70df | 0x8100);
                }
                cgsleep_ms(10);
                init_address_info();
                set_default_uart_baud();
                iVar7 = bring_up_all_chain();
                if ((iVar7 == 0) ||
                   (((dev->chain_num != '\0' && (freq_mode != 0)) && (freq_mode != 2)))) {
                  set_working_uart_baud();
                  set_iic_for_temperature();
                  if (3 < log_level) {
                    print_crt_time_to_file(log_file,3);
                    pFVar4 = fopen(log_file,"a+");
                    if (pFVar4 != (FILE *)0x0) {
                      fprintf(pFVar4,"%s:%d:%s: set TICKET_MASK\n","driver-btm-soc.c",0x19c8,
                              "bitmain_soc_init");
                    }
                    fclose(pFVar4);
                  }
                  set_asic_ticket_mask(ticket_mask);
                  cgsleep_ms(10);
                  detect_environment_temperature();
                  set_clock_delay_control(All_Chain,g_pulse_mode);
                  open_core_bm1393(true,All_Chain);
                  _Var2 = is_fixed_mode();
                  if (_Var2) {
                    if (g_freq_test == false) {
                      max_freq = set_target_freq();
                    }
                    else {
                      max_freq = set_adjust_freq();
                    }
                  }
                  else {
                    uVar3 = increase_freq_by_eeprom_slowly((int)init_freq,(int)freq_step);
                    max_freq = (float)(ulonglong)uVar3;
                  }
                  if (3 < log_level) {
                    print_crt_time_to_file(log_file,3);
                    pFVar4 = fopen(log_file,"a+");
                    if (pFVar4 != (FILE *)0x0) {
                      fprintf(pFVar4,"%s:%d:%s: set to working voltage...\n","driver-btm-soc.c",
                              0x19e1,"bitmain_soc_init");
                    }
                    fclose(pFVar4);
                  }
                  _slowly_set_iic_power_to_working_voltage();
                  set_timeout((int)max_freq,0x32);
                  for (x = 0; x < 0x10; x = x + 1) {
                    if (dev->chain_exist[x] != 0) {
                      offset = 0;
                      for (y = 0; y < (int)(uint)dev->chain_asic_num[x]; y = y + 1) {
                        if ((y & 7U) == 0) {
                          dev->chain_asic_status_string[x][y + offset] = ' ';
                          offset = offset + 1;
                        }
                        dev->chain_asic_status_string[x][y + offset] = 'o';
                        paVar1 = dev;
                        *(undefined4 *)(dev->chain_asic_nonce[x] + y) = 0;
                        *(undefined4 *)((int)paVar1->chain_asic_nonce[x] + y * 8 + 4) = 0;
                      }
                      dev->chain_asic_status_string[x][y + offset] = '\0';
                    }
                  }
                  low_temp_process_parm_init();
                  read_temp_id = (thr_info *)calloc(1,0x40);
                  iVar7 = thr_info_create(read_temp_id,(pthread_attr_t *)0x0,read_temp_func + 1,
                                          read_temp_id);
                  if (iVar7 == 0) {
                    pthread_detach(read_temp_id->pth);
                    cgtime(&tv_send_job);
                    cgtime(&tv_send);
                    startCheckNetworkJob = true;
                    read_hash_rate = (thr_info *)calloc(1,0x40);
                    iVar7 = thr_info_create(read_hash_rate,(pthread_attr_t *)0x0,get_hash_rate + 1,
                                            read_hash_rate);
                    if (iVar7 == 0) {
                      pthread_detach(read_hash_rate->pth);
                      check_system_work_id = (thr_info *)calloc(1,0x40);
                      iVar7 = thr_info_create(check_system_work_id,(pthread_attr_t *)0x0,
                                              check_system_work + 1,check_system_work_id);
                      if (iVar7 == 0) {
                        pthread_detach(check_system_work_id->pth);
                        store_hash_rate_id = (thr_info *)calloc(1,0x40);
                        iVar7 = thr_info_create(store_hash_rate_id,(pthread_attr_t *)0x0,
                                                store_hash_rate + 1,store_hash_rate_id);
                        if (iVar7 == 0) {
                          pthread_detach(store_hash_rate_id->pth);
                          cgsleep_ms(500);
                          setStartTimePoint();
                          if (3 < log_level) {
                            print_crt_time_to_file(log_file,3);
                            pFVar4 = fopen(log_file,"a+");
                            if (pFVar4 != (FILE *)0x0) {
                              fprintf(pFVar4,"%s:%d:%s: Init done!\n","driver-btm-soc.c",0x1a26,
                                      "bitmain_soc_init");
                            }
                            fclose(pFVar4);
                          }
                          restore_syslog_file(&init_log_bak);
                          iVar7 = 0;
                        }
                        else {
                          if (3 < log_level) {
                            print_crt_time_to_file(log_file,3);
                            pFVar4 = fopen(log_file,"a+");
                            if (pFVar4 != (FILE *)0x0) {
                              fprintf(pFVar4,"%s:%d:%s: create thread for store hashrate history\n",
                                      "driver-btm-soc.c",0x1a1f,"bitmain_soc_init");
                            }
                            fclose(pFVar4);
                          }
                          iVar7 = -6;
                        }
                      }
                      else {
                        if (3 < log_level) {
                          print_crt_time_to_file(log_file,3);
                          pFVar4 = fopen(log_file,"a+");
                          if (pFVar4 != (FILE *)0x0) {
                            fprintf(pFVar4,"%s:%d:%s: create thread for check system\n",
                                    "driver-btm-soc.c",0x1a16,"bitmain_soc_init");
                          }
                          fclose(pFVar4);
                        }
                        iVar7 = -6;
                      }
                    }
                    else {
                      if (3 < log_level) {
                        print_crt_time_to_file(log_file,3);
                        pFVar4 = fopen(log_file,"a+");
                        if (pFVar4 != (FILE *)0x0) {
                          fprintf(pFVar4,
                                  "%s:%d:%s: create thread for get hashrate from asic failed\n",
                                  "driver-btm-soc.c",0x1a0e,"bitmain_soc_init");
                        }
                        fclose(pFVar4);
                      }
                      iVar7 = -6;
                    }
                  }
                  else {
                    if (3 < log_level) {
                      print_crt_time_to_file(log_file,3);
                      pFVar4 = fopen(log_file,"a+");
                      if (pFVar4 != (FILE *)0x0) {
                        fprintf(pFVar4,"%s:%d:%s: create thread for read temp\n","driver-btm-soc.c",
                                0x1a03,"bitmain_soc_init");
                      }
                      fclose(pFVar4);
                    }
                    iVar7 = -7;
                  }
                }
              }
            }
          }
          else {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar4 = fopen(log_file,"a+");
              if (pFVar4 != (FILE *)0x0) {
                fprintf(pFVar4,
                        "%s:%d:%s: create thread for get nonce and register from FPGA failed\n",
                        "driver-btm-soc.c",0x197e,"bitmain_soc_init");
              }
              fclose(pFVar4);
            }
            iVar7 = -5;
          }
        }
      }
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                  "driver-btm-soc.c",0x1936,"bitmain_soc_init",(uint)config_parameter._28_4_ >> 0x10
                  ,(uint)uVar3);
        }
        fclose(pFVar4);
      }
      iVar7 = -2;
    }
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
                "driver-btm-soc.c",0x192f,"bitmain_soc_init",0x51,config_parameter._0_4_ & 0xff);
      }
      fclose(pFVar4);
    }
    iVar7 = -1;
  }
  return iVar7;
}

