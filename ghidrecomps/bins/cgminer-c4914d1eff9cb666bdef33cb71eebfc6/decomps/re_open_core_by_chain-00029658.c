
int re_open_core_by_chain(int fan_pwm,int chain,_Bool is_low_temp)

{
  uint8_t chain_00;
  _Bool _Var1;
  uint16_t uVar2;
  FILE *pFVar3;
  uint uVar4;
  char *in_stack_ffffffb0;
  int in_stack_ffffffb4;
  _Bool is_low_temp_local;
  int chain_local;
  int fan_pwm_local;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  float max_freq;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      in_stack_ffffffb0 = "re_open_core_by_chain";
      in_stack_ffffffb4 = fan_pwm;
      fprintf(pFVar3,"%s:%d:%s: \nre_open_core start!PWM %d\n","driver-btm-soc.c",0x1ae2);
    }
    fclose(pFVar3);
  }
  b_is_re_open_core = true;
  startCheckNetworkJob = false;
  pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
  pthread_mutex_lock((pthread_mutex_t *)&reopen_core);
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_Hardware_version(0x40000000);
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_PWM((uchar)fan_pwm);
  dev->baud = '\x1a';
  uVar4 = get_dhash_acc_control();
  set_dhash_acc_control(uVar4 & 0xffff70df | 0x8100);
  cgsleep_ms(10);
  chain_00 = (uint8_t)chain;
  set_highest_voltage_by_chain(chain_00,(double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0));
  set_iic_power_to_highest_voltage_by_chain(chain_00);
  init_address_info();
  set_default_uart_baud();
  set_baud_by_chain('\x1a',chain);
  bring_up_chain(chain,true);
  set_baud_by_chain('\x01',chain);
  set_iic_for_temperature_by_chain(chain);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: set TICKET_MASK\n","driver-btm-soc.c",0x1b04,"re_open_core_by_chain"
             );
    }
    fclose(pFVar3);
  }
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  set_clock_delay_control(chain_00,g_pulse_mode);
  open_core_bm1393(true,chain_00);
  memset(dev->chain_exist,0,0x40);
  dev->chain_exist[chain] = 1;
  dev->chain_num = '\x01';
  _Var1 = is_fixed_mode();
  if (_Var1) {
    if (g_freq_test == false) {
      max_freq = set_target_freq();
    }
    else {
      max_freq = set_adjust_freq();
    }
  }
  else {
    uVar2 = increase_freq_by_eeprom_slowly((int)init_freq,(int)freq_step);
    max_freq = (float)(ulonglong)uVar2;
  }
  set_timeout((int)max_freq,0x32);
  check_chain();
  read_temp_and_get_statistics();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: reopen chain %d finished, chain %d chip temp %d - %d\n",
              "driver-btm-soc.c",0x1b24,"re_open_core_by_chain",chain,chain,
              (int)dev->chain_asic_mintemp[chain][1],(int)dev->chain_asic_maxtemp[chain][1]);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: all chain chip temp %d - %d\n","driver-btm-soc.c",0x1b26,
              "re_open_core_by_chain",last_testpatten_lowest_chip_temp,
              last_testpatten_highest_chip_temp);
    }
    fclose(pFVar3);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  if (!is_low_temp) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: set to working voltage...\n","driver-btm-soc.c",0x1b2c,
                "re_open_core_by_chain");
      }
      fclose(pFVar3);
    }
    slowly_set_iic_power_to_working_voltage_by_chain(chain_00);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  cgtime(&tv_send_job);
  cgtime(&tv_send);
  startCheckNetworkJob = true;
  cgsleep_ms(500);
  b_is_re_open_core = false;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: re_open_core done!\n","driver-btm-soc.c",0x1b3a,
              "re_open_core_by_chain");
    }
    fclose(pFVar3);
  }
  return 0;
}

