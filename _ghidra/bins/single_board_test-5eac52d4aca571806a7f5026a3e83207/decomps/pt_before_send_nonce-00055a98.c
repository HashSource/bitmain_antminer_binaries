
int pt_before_send_nonce(float *matrix)

{
  _Bool _Var1;
  int32_t iVar2;
  int iVar3;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  char err_str2_2 [16];
  char err_str1_2 [16];
  char err_str2_1 [16];
  char err_str1_1 [16];
  char err_str2 [16];
  char err_str1 [16];
  int sensor_id;
  _Bool vol_res;
  int max_temp;
  _Bool res;
  int32_t vol_diff;
  int ret;
  int env_temp;
  int test_time;
  
  ret = 0;
  vol_diff = 0;
  reset_runtime_info(g_rt.sweep.mode);
  fan_turn_on(BOTH_SIZE);
  iVar2 = pwm_set(g_fan,((g_rt.config)->fan).fan_speed);
  if (iVar2 != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fan %d pwm_set speed %d failed\n","pt_before_send_nonce",g_fan,
           ((g_rt.config)->fan).fan_speed);
    snprintf(tmp1,0x100,"fan %d pwm_set speed %d failed",g_fan,((g_rt.config)->fan).fan_speed);
    log_to_file(tmp1,time_stamp);
  }
  _Var1 = pf_init((g_rt.config)->chain);
  if (_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : interval:%d\n","pt_before_send_nonce",(g_rt.config)->interval);
    snprintf(tmp1,0x100,"interval:%d",(g_rt.config)->interval);
    log_to_file(tmp1,time_stamp);
    power_down((g_rt.config)->chain);
    reset_register_cache_value_to_default((uint8_t)(g_rt.config)->chain);
    reset_registoer_buf();
    set_bt8d_chain((g_rt.config)->chain,0x1a);
    iVar3 = start_temp_thread();
    if (iVar3 == 0) {
      lcd_common_show("Cool down","Hashboard",(char *)0x0);
      waiting_cool_down(((g_rt.config)->temp).wait_cool_time,g_rt.tempval,
                        (int8_t)((g_rt.config)->board).sensor.sensor_num,
                        ((g_rt.config)->temp).temp_gap);
      print_fan_speed();
      test_time = 0xf;
      while (test_time != 0) {
        test_time = test_time + -1;
        sleep(1);
      }
      test_time = test_time + -1;
      env_temp = get_env_temp();
      if (env_temp == 0xffff) {
        env_temp = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        set_env_temp(env_temp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : env temp: %d\n","pt_before_send_nonce",env_temp);
        snprintf(tmp1,0x100,"env temp: %d",env_temp);
        log_to_file(tmp1,time_stamp);
        if (env_temp < 0x14) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : env temp %d is too low, pattern text exit\n","pt_before_send_nonce",env_temp)
          ;
          snprintf(tmp1,0x100,"env temp %d is too low, pattern text exit",env_temp);
          log_to_file(tmp1,time_stamp);
          return -1;
        }
        if (0x28 < env_temp) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : env temp %d is too high, pattern text exit\n","pt_before_send_nonce",env_temp
                );
          snprintf(tmp1,0x100,"env temp %d is too high, pattern text exit",env_temp);
          log_to_file(tmp1,time_stamp);
          return -1;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : env temp have exist:%d\n","pt_before_send_nonce",env_temp);
        snprintf(tmp1,0x100,"env temp have exist:%d",env_temp);
        log_to_file(tmp1,time_stamp);
      }
      g_bringup_temp = env_temp;
      vol_diff = get_vol_comp(env_temp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : vol diff:%d\n","pt_before_send_nonce",vol_diff);
      snprintf(tmp1,0x100,"vol diff:%d",vol_diff);
      log_to_file(tmp1,time_stamp);
      g_diff = vol_diff;
      pwm_set(g_fan,100);
      chain_reset_low((g_rt.config)->chain);
      lcd_common_show("Power on","Hashboard",(char *)0x0);
      res = pf_power_on((g_rt.config)->tests[0].pre_open_core_voltage);
      if (res) {
        reset_hash_board((g_rt.config)->chain);
        set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
        print_fan_speed();
        sensor_id = 0;
        _Var1 = read_temperature_from_CtrlBoard_N_times('\x03',&sensor_id);
        if (_Var1) {
          start_recv_thread();
          create_power_heart_beat_thread();
          ret = get_register_info(0,0,true,"BM1370");
          if ((g_rt.config)->asics == ret) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : first find asic num %d\n","pt_before_send_nonce",ret);
            snprintf(tmp1,0x100,"first find asic num %d",ret);
            log_to_file(tmp1,time_stamp);
            set_register_stage_1();
            set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffff);
            uart_flush_rx((g_rt.config)->chain);
            set_register_stage_2();
            usleep(1000000);
            do_core_reset((uint8_t *)0x0);
            usleep(1000000);
            pwm_set(g_fan,0x1e);
            g_pwm_enable = true;
            sleep(5);
            set_register_stage_3(matrix);
            usleep(1000000);
            set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
            g_rt.read_sensor_power_by_hashboard = 1;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : read temp and domain voltage before heating...\n","pt_before_send_nonce");
            builtin_strncpy(tmp1,"read temp and domain voltage before heating.",0x2c);
            tmp1[0x2c] = '.';
            tmp1[0x2d] = '.';
            tmp1[0x2e] = '\0';
            log_to_file(tmp1,time_stamp);
            lcd_common_show("Heating","Hashboard",(char *)0x0);
            iVar3 = wait_board_temp(g_rt.tempval,(int8_t)((g_rt.config)->board).sensor.sensor_num,
                                    0x38);
            if (iVar3 != 0) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : err temp low...\n","pt_before_send_nonce");
              builtin_strncpy(tmp1,"err temp low...",0x10);
              log_to_file(tmp1,time_stamp);
              max_temp = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
              if (max_temp < 0x34) {
                set_sweep_err_state(0xf,true);
                snprintf(err_str1_1,0x10,"Max %d",max_temp);
                snprintf(err_str2_1,0x10,"Need %d ~ %d",0x34,0x38);
                lcd_common_show("Heating Board",err_str1_1,err_str2_1);
                return -1;
              }
            }
            vol_res = set_voltage_by_step((g_rt.config)->tests[0].pre_open_core_voltage,
                                          vol_diff + (g_rt.config)->tests[0].voltage,'\n');
            if (vol_res) {
              ret = get_register_info(0,0,true,"BM1370");
              if ((g_rt.config)->asics == ret) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : second find asic num %d\n","pt_before_send_nonce",ret);
                snprintf(tmp1,0x100,"second find asic num %d",ret);
                log_to_file(tmp1,time_stamp);
                set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
                set_chain_core_nonce_overflow_control((uint8_t)(g_rt.config)->chain,false);
                set_chain_baud((uint8_t)(g_rt.config)->chain,((g_rt.config)->speed).baudrate);
                usleep(200000);
                g_pwm_enable = true;
                iVar3 = 0;
              }
              else {
                set_sweep_err_state(0xd,true);
                power_down((g_rt.config)->chain);
                snprintf(err_str1_2,0x10,"Only %d",ret);
                snprintf(err_str2_2,0x10,"Need %d",(g_rt.config)->asics);
                lcd_common_show("Find asics 2",err_str1_2,err_str2_2);
                iVar3 = -1;
              }
            }
            else {
              iVar3 = -1;
            }
          }
          else {
            set_sweep_err_state(0xc,false);
            power_down((g_rt.config)->chain);
            snprintf(err_str1,0x10,"Only %d",ret);
            snprintf(err_str2,0x10,"Need %d",(g_rt.config)->asics);
            lcd_common_show("Find asics 1",err_str1,err_str2);
            iVar3 = -1;
          }
        }
        else {
          memset(tmp1,0,0x40);
          sprintf(tmp1,"sensor[%d] err",sensor_id);
          err_exit(tmp1);
          iVar3 = 0xc;
        }
      }
      else {
        set_sweep_err_state(0xb,true);
        power_down((g_rt.config)->chain);
        lcd_common_show("Power on","err",(char *)0x0);
        iVar3 = -1;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : create read temp thread failed\n","pt_before_send_nonce");
      builtin_strncpy(tmp1,"create read temp thread failed",0x1f);
      log_to_file(tmp1,time_stamp);
      iVar3 = -1;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s :  init platform failed\n","pt_before_send_nonce");
    builtin_strncpy(tmp1," init platform failed",0x16);
    log_to_file(tmp1,time_stamp);
    iVar3 = -1;
  }
  return iVar3;
}

