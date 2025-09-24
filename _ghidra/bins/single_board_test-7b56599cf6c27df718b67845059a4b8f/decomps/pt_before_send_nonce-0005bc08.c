
int pt_before_send_nonce(float *matrix)

{
  _Bool _Var1;
  int32_t iVar2;
  uint32_t uVar3;
  int iVar4;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  char err_str2_2 [16];
  char err_str1_2 [16];
  char err_str2_1 [16];
  char err_str1_1 [16];
  char err_str2 [16];
  char err_str1 [16];
  _Bool vol_res;
  int max_temp;
  _Bool res;
  int32_t vol_diff;
  int ret;
  int env_temp;
  int test_time;
  
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
    power_down((g_rt.config)->chain);
    reset_register_cache_value_to_default((uint8_t)(g_rt.config)->chain);
    reset_registoer_buf();
    set_bt8d_chain((g_rt.config)->chain,0x1a);
    iVar4 = start_temp_thread();
    if (iVar4 == 0) {
      lcd_common_show("Cool down","Hashboard",(char *)0x0);
      waiting_cool_down(((g_rt.config)->temp).wait_cool_time,g_rt.tempval,
                        (int8_t)((g_rt.config)->board).sensor.sensor_num,
                        ((g_rt.config)->temp).temp_gap);
      print_fan_speed();
      test_time = 0xf;
      while (test_time != 0) {
        sleep(1);
        test_time = test_time + -1;
      }
      env_temp = get_env_temp();
      if (env_temp == 0xffff) {
        env_temp = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        set_env_temp(env_temp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : env temp: %d\n","pt_before_send_nonce",env_temp);
        snprintf(tmp1,0x100,"env temp: %d",env_temp);
        log_to_file(tmp1,time_stamp);
        if (env_temp < 0x18) {
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
      iVar2 = get_vol_comp(env_temp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : vol diff:%d\n","pt_before_send_nonce",iVar2);
      snprintf(tmp1,0x100,"vol diff:%d",iVar2);
      log_to_file(tmp1,time_stamp);
      g_diff = iVar2;
      pwm_set(g_fan,100);
      chain_reset_low((g_rt.config)->chain);
      lcd_common_show("Power on","Hashboard",(char *)0x0);
      _Var1 = pf_power_on((g_rt.config)->tests[0].pre_open_core_voltage);
      if (_Var1) {
        reset_hash_board((g_rt.config)->chain);
        print_fan_speed();
        start_recv_thread();
        create_power_heart_beat_thread();
        uVar3 = get_register_info(0,0,true,"BM1368");
        if ((g_rt.config)->asics == uVar3) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : first find asic num %d\n","pt_before_send_nonce",uVar3);
          snprintf(tmp1,0x100,"first find asic num %d",uVar3);
          log_to_file(tmp1,time_stamp);
          set_register_stage_1();
          set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffff);
          uart_flush_rx((g_rt.config)->chain);
          set_register_stage_2();
          usleep(1000000);
          do_core_reset((uint8_t *)0x0);
          usleep(1000000);
          set_register_stage_3(matrix);
          usleep(1000000);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : read temp and domain voltage before heating...\n","pt_before_send_nonce");
          builtin_strncpy(tmp1,"read temp and domain voltage before heating.",0x2c);
          tmp1[0x2c] = '.';
          tmp1[0x2d] = '.';
          tmp1[0x2e] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var1 = read_temp_from_asic_once(false);
          if (!_Var1) {
            err_exit("asic temp outof range");
          }
          _Var1 = read_chain_domain_voltage(false);
          if (!_Var1) {
            err_exit("asic vol outof range");
          }
          lcd_common_show("Heating","Hashboard",(char *)0x0);
          pwm_set(g_fan,0x32);
          iVar4 = wait_board_temp(g_rt.tempval,(int8_t)((g_rt.config)->board).sensor.sensor_num,0x38
                                 );
          if (iVar4 != 0) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : err temp low...\n","pt_before_send_nonce");
            builtin_strncpy(tmp1,"err temp low...",0x10);
            log_to_file(tmp1,time_stamp);
            iVar4 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
            if (iVar4 < 0x34) {
              set_sweep_err_state(0xf,true);
              snprintf(err_str1_1,0x10,"Max %d",iVar4);
              snprintf(err_str2_1,0x10,"Need %d ~ %d",0x34,0x38);
              lcd_common_show("Heating Board",err_str1_1,err_str2_1);
              return -1;
            }
          }
          pwm_set(g_fan,((g_rt.config)->fan).fan_speed);
          _Var1 = set_voltage_by_step((g_rt.config)->tests[0].pre_open_core_voltage,
                                      iVar2 + (g_rt.config)->tests[0].voltage,'\n');
          if (_Var1) {
            set_pwth();
            uVar3 = get_register_info(0,0,true,"BM1368");
            if ((g_rt.config)->asics == uVar3) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : second find asic num %d\n","pt_before_send_nonce",uVar3);
              snprintf(tmp1,0x100,"second find asic num %d",uVar3);
              log_to_file(tmp1,time_stamp);
              set_chain_core_nonce_overflow_control((uint8_t)(g_rt.config)->chain,false);
              set_chain_rosc_pad_disable((uint8_t)(g_rt.config)->chain);
              set_chain_baud((uint8_t)(g_rt.config)->chain,((g_rt.config)->speed).baudrate);
              usleep(200000);
              g_pwm_enable = true;
              iVar4 = 0;
            }
            else {
              set_sweep_err_state(0xd,true);
              power_down((g_rt.config)->chain);
              snprintf(err_str1_2,0x10,"Only %d",uVar3);
              snprintf(err_str2_2,0x10,"Need %d",(g_rt.config)->asics);
              lcd_common_show("Find asics 2",err_str1_2,err_str2_2);
              iVar4 = -1;
            }
          }
          else {
            iVar4 = -1;
          }
        }
        else {
          set_sweep_err_state(0xc,false);
          power_down((g_rt.config)->chain);
          snprintf(err_str1,0x10,"Only %d",uVar3);
          snprintf(err_str2,0x10,"Need %d",(g_rt.config)->asics);
          lcd_common_show("Find asics 1",err_str1,err_str2);
          iVar4 = -1;
        }
      }
      else {
        set_sweep_err_state(0xb,true);
        power_down((g_rt.config)->chain);
        lcd_common_show("Power on","err",(char *)0x0);
        iVar4 = -1;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : create read temp thread failed\n","pt_before_send_nonce");
      builtin_strncpy(tmp1,"create read temp thread failed",0x1f);
      log_to_file(tmp1,time_stamp);
      iVar4 = -1;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s :  init platform failed\n","pt_before_send_nonce");
    builtin_strncpy(tmp1," init platform failed",0x16);
    log_to_file(tmp1,time_stamp);
    iVar4 = -1;
  }
  return iVar4;
}

