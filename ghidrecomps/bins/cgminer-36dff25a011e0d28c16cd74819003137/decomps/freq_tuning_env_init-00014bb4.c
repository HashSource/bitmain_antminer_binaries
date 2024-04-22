
void freq_tuning_env_init(_Bool is_need_read_temp,freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  freq_tuning_info *freq_info_local;
  _Bool is_need_read_temp_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_pwm('P');
  set_Hardware_version(0x40000000);
  dev->baud = 0x1c200;
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
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Enter %ds sleep to make sure power release finish.\n",
              "freq_tuning.c",0x2ae,"freq_tuning_env_init",0x1e);
    }
    fclose(pFVar1);
  }
  sleep(0x1e);
  if (is_need_read_temp) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Enter 5 minute sleep to cool down hash board, waiting...\n",
                "freq_tuning.c",0x2b3,"freq_tuning_env_init");
      }
      fclose(pFVar1);
    }
    sleep(300);
  }
  set_iic_power_to_highest_voltage();
  if (opt_multi_version != 0) {
    uVar2 = get_dhash_acc_control();
    set_dhash_acc_control(uVar2 & 0xffff701f | 0x8100);
  }
  cgsleep_ms(10);
  dev->corenum = 0x2a0;
  hash_board_power_on_with_reset();
  check_asic_number();
  if (is_need_read_temp) {
    cgsleep_ms(10);
    software_set_address();
    cgsleep_ms(10);
    do_calibration_temperature_sensor();
    g_env_temp = temp_get_environment_temp();
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: environment temperature: %.2f\n","freq_tuning.c",0x2dc,
                "freq_tuning_env_init");
      }
      fclose(pFVar1);
    }
  }
  cgsleep_ms(10);
  software_set_address();
  cgsleep_ms(10);
  set_pll(init_freq);
  iVar3 = calculate_core_number(dev->corenum);
  iVar3 = __aeabi_idiv(0x1000000,iVar3);
  fVar4 = (((float)(longlong)(int)((uint)dev->addrInterval * iVar3) / init_freq) * DAT_0001501c) /
          DAT_00015020;
  dev->timeout = (uint)(0.0 < fVar4) * (int)fVar4;
  if (0x1ffff < dev->timeout) {
    dev->timeout = 0x1ffff;
  }
  cgsleep_ms(10);
  init_uart_baud();
  cgsleep_ms(10);
  set_time_out_control(0x8000c350);
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  open_core_bm1391(true,All_Chain);
  freq_tuning_pre_test(freq_info);
  return;
}

