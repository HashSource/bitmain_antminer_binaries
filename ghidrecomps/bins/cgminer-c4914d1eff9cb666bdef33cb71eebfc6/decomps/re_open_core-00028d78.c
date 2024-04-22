
int re_open_core(int fan_pwm)

{
  all_parameters *paVar1;
  uchar pwm_percent;
  _Bool _Var2;
  uint16_t uVar3;
  FILE *pFVar4;
  uint uVar5;
  int fan_pwm_local;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int offset;
  float max_freq;
  int retry_count;
  int y;
  int x;
  
  retry_count = 0;
  while( true ) {
    if (3 < log_level) {
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fputc(10,pFVar4);
      }
      fclose(pFVar4);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: re_open_core start!PWM %d\n","driver-btm-soc.c",0x1a34,
                "re_open_core",fan_pwm);
      }
      fclose(pFVar4);
    }
    b_is_re_open_core = true;
    startCheckNetworkJob = false;
    pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
    pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
    pwm_percent = (uchar)fan_pwm;
    set_PWM(pwm_percent);
    if (freq_mode != 2) {
      get_freq_result_from_eeprom();
    }
    get_ideal_hash_rate();
    if ((config_parameter._4_1_ & 1) != 0) {
      set_QN_write_data_command(0x8080800f);
      sleep(2);
      set_PWM(pwm_percent);
    }
    set_Hardware_version(0x40000000);
    read_fpga_id(FPGA_ID_str);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: miner ID : %s\n","driver-btm-soc.c",0x1a4f,"re_open_core",
                FPGA_ID_str);
      }
      fclose(pFVar4);
    }
    init_miner_version();
    set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
    set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
    dev->baud = '\x1a';
    check_chain();
    set_PWM(pwm_percent);
    init_pic();
    update_highest_voltage();
    _set_iic_power_to_highest_voltage();
    _Var2 = is_T11();
    if (!_Var2) {
      enable_crab_circuit();
      sleep(1);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          get_average_voltage();
          get_crc_count();
          fprintf(pFVar4,"%s:%d:%s: the current avg vol is %5.2f, crc = %d\n","driver-btm-soc.c",
                  0x1a64,"re_open_core");
        }
        fclose(pFVar4);
      }
    }
    if (opt_multi_version != 0) {
      uVar5 = get_dhash_acc_control();
      set_dhash_acc_control(uVar5 & 0xffff70df | 0x8100);
    }
    cgsleep_ms(10);
    init_address_info();
    set_default_uart_baud();
    set_baud('\x1a',0);
    bring_up_all_chain();
    set_working_uart_baud();
    set_iic_for_temperature();
    if (dev->chain_num != '\0') break;
    if (2 < retry_count) {
      print_crt_time_to_file(log_file,1);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"Assert fail!! %s:%d: Cannot find all asic.","driver-btm-soc.c",0x1a7f);
      }
      fclose(pFVar4);
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","driver-btm-soc.c",0x1a7f,"re_open_core");
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: chain num is 0, retry for %d times\n","driver-btm-soc.c",0x1a77,
                "re_open_core",retry_count);
      }
      fclose(pFVar4);
    }
    retry_count = retry_count + 1;
    pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
    pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  }
  if ((0 < retry_count) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: find asic success after retry for %d times\n","driver-btm-soc.c",
              0x1a86,"re_open_core",retry_count);
    }
    fclose(pFVar4);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: set TICKET_MASK\n","driver-btm-soc.c",0x1a8c,"re_open_core");
    }
    fclose(pFVar4);
  }
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  set_clock_delay_control(All_Chain,g_pulse_mode);
  open_core_bm1393(true,All_Chain);
  _Var2 = is_economic_mode();
  if ((((_Var2) && (fan_pwm == 0)) && (_Var2 = is_column_sweep(), !_Var2)) &&
     (_Var2 = is_board_sweep(), !_Var2)) {
    low_temperature_freq_handler();
  }
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
  set_timeout((int)max_freq,0x32);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: set to working voltage...\n","driver-btm-soc.c",0x1aa7,
              "re_open_core");
    }
    fclose(pFVar4);
  }
  _slowly_set_iic_power_to_working_voltage();
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
  read_temp_and_get_statistics();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: reopen finished pcb temp is %d - %d, chip temp %d - %d\n",
              "driver-btm-soc.c",0x1ac5,"re_open_core",last_testpatten_lowest_pcb_temp,
              last_testpatten_highest_pcb_temp,last_testpatten_lowest_chip_temp,
              last_testpatten_highest_chip_temp);
    }
    fclose(pFVar4);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  re_send_last_job();
  cgtime(&tv_send_job);
  cgtime(&tv_send);
  startCheckNetworkJob = true;
  cgsleep_ms(500);
  b_is_re_open_core = false;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"%s:%d:%s: re_open_core done!\n","driver-btm-soc.c",0x1ad6,"re_open_core");
    }
    fclose(pFVar4);
  }
  _Var2 = is_T11();
  if (!_Var2) {
    disable_crab_circuit();
  }
  return 0;
}

