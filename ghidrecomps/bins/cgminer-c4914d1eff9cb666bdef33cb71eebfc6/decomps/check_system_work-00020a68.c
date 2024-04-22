
/* WARNING: Unknown calling convention */

void * check_system_work(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  STATUS_CODE SVar3;
  int iVar4;
  float env_temp_00;
  char *in_stack_ffffff78;
  undefined4 in_stack_ffffff7c;
  _Bool high_chip_temp_flag;
  timeval tv_diff;
  timeval tv_end;
  timeval tv_start;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  float env_temp;
  double latest_avg_rate;
  char *hash_log;
  uint32_t counter_base;
  uint32_t counter;
  
  counter = 0;
  counter_base = 0x21c;
  high_chip_temp_flag = false;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      in_stack_ffffff78 = "check_system_work";
      fprintf(pFVar2,"%s:%d:%s: check system thread start...\n","driver-btm-soc.c",0xe01);
    }
    fclose(pFVar2);
  }
  do {
    while( true ) {
      while( true ) {
        counter = counter + 1;
        cgtime(&tv_start);
        set_led();
        if (doTestPatten == false) break;
        cgsleep_ms(100);
      }
      SVar3 = get_error_type();
      if (SVar3 == STATUS_OK) break;
      counter = 0;
      cgsleep_ms(1000);
      reCalculateAVG();
    }
    if ((counter == 10) && (_Var1 = is_T11(), !_Var1)) {
      disable_crab_circuit();
    }
    if (counter == 300) {
      _Var1 = need_mode2_startup();
      if (_Var1) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            in_stack_ffffff78 = "check_system_work";
            fprintf(pFVar2,"%s:%d:%s: mode0 startup failed, reopen for mode 2 startup\n",
                    "driver-btm-soc.c",0xe29);
          }
          fclose(pFVar2);
        }
        g_pulse_mode = '\x01';
        g_is_mode2_startup = true;
        iVar4 = get_reopen_pwm();
        re_open_core(iVar4);
        reCalculateAVG();
      }
      else {
        g_is_mode2_startup = false;
        counter_base = counter;
      }
    }
    if ((counter == 0x1a4) && (g_is_mode2_startup != false)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffff78 = "check_system_work";
          fprintf(pFVar2,"%s:%d:%s: reopen for mode 2 startup again\n","driver-btm-soc.c",0xe3a);
        }
        fclose(pFVar2);
      }
      iVar4 = get_reopen_pwm();
      re_open_core(iVar4);
      reCalculateAVG();
    }
    if ((counter == 0x21c) && (g_is_mode2_startup != false)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffff78 = "check_system_work";
          fprintf(pFVar2,"%s:%d:%s: mode 2 startup finished, switch to mode 0\n","driver-btm-soc.c",
                  0xe43);
        }
        fclose(pFVar2);
      }
      switch_to_mode0();
      g_is_mode2_startup = false;
      reCalculateAVG();
      counter_base = counter;
    }
    if ((counter_base < counter) && ((counter - counter_base) % 0x78 == 0)) {
      decrease_voltage_at_high_temp(&high_chip_temp_flag);
    }
    if (counter % 5 == 0) {
      process_test();
    }
    if (counter % 0x78 == 0) {
      if (counter % 0xe10 == 0) {
        copy_log_to_latest("/var/log/hash_rate");
        clear_log("/var/log/hash_rate");
      }
      dump_nonce_info_all_domain();
      dump_nonce_info_all_asic();
    }
    if (counter - counter_base == 0xb4) {
      save_base_domain_nonce_data();
    }
    if ((counter % 0x708 == 0) && (get_30minutes_hashrate(), 3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        get_min_temperature();
        get_max_temperature();
        get_min_chip_temperature();
        get_max_chip_temperature();
        in_stack_ffffff78 = "check_system_work";
        fprintf(pFVar2,
                "%s:%d:%s: 30 mins avg rate [%05.0f], PCB temp [%d - %d], CHIP temp [%d - %d]\n",
                "driver-btm-soc.c",0xe6f);
      }
      fclose(pFVar2);
    }
    _Var1 = aging_is_ongoing();
    if (_Var1) {
      iVar4 = aging_get_time();
      if (iVar4 < 0x1c20) {
        if (counter % 0x3c == 0) {
          aging_update_time(0x3c);
        }
      }
      else {
        aging_stop();
      }
    }
    if (counter % 0x3c == 0) {
      check_asic_status();
    }
    if ((counter_base < counter) && ((counter - counter_base) % 0x708 == 0)) {
      get_30minutes_hashrate();
      env_temp_00 = get_env_temperature();
      hash_rate_guard(true,env_temp_00,(double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),
                      high_chip_temp_flag);
    }
    cgtime(&tv_end);
    tv_diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    tv_diff.tv_usec = tv_end.tv_usec - tv_start.tv_usec;
    if (tv_diff.tv_usec < 0) {
      tv_diff.tv_sec = tv_diff.tv_sec + -1;
      tv_diff.tv_usec = tv_diff.tv_usec + 1000000;
    }
    if (tv_diff.tv_sec < 1) {
      cgsleep_us(CONCAT44(in_stack_ffffff7c,in_stack_ffffff78));
    }
  } while( true );
}

