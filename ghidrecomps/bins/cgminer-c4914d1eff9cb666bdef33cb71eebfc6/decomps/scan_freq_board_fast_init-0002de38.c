
int scan_freq_board_fast_init(working_mode_e working_mode)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  char *in_stack_ffffffb8;
  int in_stack_ffffffbc;
  working_mode_e working_mode_local;
  FILE *pFile_1;
  FILE *pFile_5;
  float min_freq;
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile;
  int ret;
  int chain;
  
  ret = 0;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      in_stack_ffffffb8 = "scan_freq_board_fast_init";
      fprintf(pFVar2,"%s:%d:%s: board init ..\n","driver-btm-soc.c",0x2000);
    }
    fclose(pFVar2);
  }
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_Hardware_version(0x40000000);
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_PWM('d');
  _set_iic_power_to_highest_voltage();
  if (opt_multi_version != 0) {
    uVar3 = get_dhash_acc_control();
    set_dhash_acc_control(uVar3 & 0xffff70df | 0x8100);
  }
  cgsleep_ms(10);
  init_address_info();
  set_default_uart_baud();
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] == 1) && (scanfreq_info.test_done[chain] != true)) &&
       (iVar4 = bring_up_chain(chain,false), iVar4 != 0)) {
      disable_pic_dac((uint8_t)chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      ret = -1;
    }
  }
  if (ret == 0) {
    set_working_uart_baud();
    set_iic_for_temperature();
    if (scan_freq_board_fast_init::is_env_temp_detected != true) {
      detect_environment_temperature();
      scan_freq_board_fast_init::is_env_temp_detected = true;
    }
    set_clock_delay_control(All_Chain,g_pulse_mode);
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] == 1) && (scanfreq_info.test_done[chain] != true)) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            in_stack_ffffffb8 = "scan_freq_board_fast_init";
            in_stack_ffffffbc = chain;
            fprintf(pFVar2,"%s:%d:%s: open core for chain[%d]\n","driver-btm-soc.c",0x2032);
          }
          fclose(pFVar2);
        }
        open_core_bm1393(true,(uint8_t)chain);
      }
    }
    cgsleep_ms(100);
    _Var1 = is_column_sweep();
    if ((_Var1) || (_Var1 = is_board_sweep(), _Var1)) {
      if (need_set_final_freq == false) {
        increase_to_base_freq(init_freq,freq_step);
        _slowly_set_iic_power_to_working_voltage();
      }
      else {
        increase_freq_by_eeprom_slowly_new((int)init_freq,(int)freq_step);
        for (chain = 0; chain < 0x10; chain = chain + 1) {
          if (dev->chain_exist[chain] == 1) {
            _Var1 = slowly_set_iic_power_to_custom_voltage_by_chain
                              ((uint8_t)chain,(double)CONCAT44(in_stack_ffffffbc,in_stack_ffffffb8))
            ;
            if (_Var1) {
              ret = 0;
            }
            else {
              ret = -1;
            }
          }
          if (ret != 0) {
            return ret;
          }
        }
      }
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: set to working voltage...\n","driver-btm-soc.c",0x204c,
                  "scan_freq_board_fast_init");
        }
        fclose(pFVar2);
      }
      _slowly_set_iic_power_to_working_voltage();
      if (first_time_init == false) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: increase to adjust freq...\n","driver-btm-soc.c",0x2057,
                    "scan_freq_board_fast_init");
          }
          fclose(pFVar2);
        }
        set_adjust_freq();
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: increase to base freq...\n","driver-btm-soc.c",0x2052,
                    "scan_freq_board_fast_init");
          }
          fclose(pFVar2);
        }
        increase_to_base_freq(init_freq,freq_step);
      }
    }
    iVar4 = scan_freq_get_min_base_freq();
    iVar5 = calculate_core_number((uint)dev->corenum);
    iVar5 = __aeabi_idiv(0x1000000,iVar5);
    fVar6 = (((float)(longlong)(int)((uint)dev->addrInterval * iVar5) / (float)(longlong)iVar4) *
            DAT_0002e490) / DAT_0002e494;
    dev->timeout = (uint)(0.0 < fVar6) * (int)fVar6;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: final timeout=%d, min_freq=%.2f\n","driver-btm-soc.c",0x205f,
                "scan_freq_board_fast_init",dev->timeout,(double)(longlong)iVar4);
      }
      fclose(pFVar2);
    }
    if (opt_multi_version == 0) {
      set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
    }
    else {
      set_time_out_control(opt_multi_version * dev->timeout & 0x1ffff | 0x80000000);
    }
    ret = 0;
  }
  return ret;
}

