
int pt_before_send_nonce(float *matrix)

{
  undefined4 uVar1;
  _Bool _Var2;
  int32_t iVar3;
  char *pcVar4;
  uint32_t uVar5;
  int iVar6;
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
  int ret;
  int env_temp;
  int test_time;
  int32_t vol_diff;
  
  reset_runtime_info(g_rt.sweep.mode);
  fan_turn_on(BOTH_SIZE);
  iVar3 = pwm_set(g_fan,((g_rt.config)->fan).fan_speed);
  if (iVar3 != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fan %d pwm_set speed %d failed\n","pt_before_send_nonce",g_fan,
           ((g_rt.config)->fan).fan_speed);
    snprintf(tmp1,0x100,"fan %d pwm_set speed %d failed",g_fan,((g_rt.config)->fan).fan_speed);
    log_to_file(tmp1,time_stamp);
  }
  _Var2 = pf_init((g_rt.config)->chain);
  if (_Var2) {
    power_down((g_rt.config)->chain);
    reset_register_cache_value_to_default((uint8_t)(g_rt.config)->chain);
    reset_registoer_buf();
    set_bt8d_chain((g_rt.config)->chain,0x1a);
    iVar6 = start_temp_thread();
    if (iVar6 == 0) {
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
        if (0x1e < env_temp) {
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
      _Var2 = check_is_multiple_ft_version(qr_code.chip_ftversion);
      if (_Var2) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : current ft_version : \n","pt_before_send_nonce");
        builtin_strncpy(tmp1,"current ft_version : ",0x16);
        log_to_file(tmp1,time_stamp);
        log_out_multiple_ft_bin_info(&qr_code.ft_bin_list);
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : current ft_version : %s, bin : %s\n","pt_before_send_nonce",0x21bb9b8,0x21bb9a8
              );
        snprintf(tmp1,0x100,"current ft_version : %s, bin : %s",0x21bb9b8,0x21bb9a8);
        log_to_file(tmp1,time_stamp);
      }
      _Var2 = is_ft("F1V02B5C1-3");
      if (_Var2) {
        ((g_rt.config)->standard).nonce_rate = 0x25e4;
        ((g_rt.config)->standard).asic_nonce_rate = 0x25d0;
      }
      else {
        is_ft("F1V02B5C1-4");
        _Var2 = is_ft("F1V02B3C1-4");
        if (_Var2) {
          ((g_rt.config)->standard).nonce_rate = 0x2602;
          ((g_rt.config)->standard).asic_nonce_rate = 0x25ee;
        }
        else {
          _Var2 = is_ft("F1V02B4C1-2-3_F1V02B5C1-3-4");
          if (_Var2) {
            ((g_rt.config)->standard).nonce_rate = 0x2602;
            ((g_rt.config)->standard).asic_nonce_rate = 0x25ee;
          }
          else {
            _Var2 = is_ft("F1V03B2C1-4");
            if (_Var2) {
              ((g_rt.config)->standard).nonce_rate = 0x2594;
              ((g_rt.config)->standard).asic_nonce_rate = 0x254e;
            }
            else {
              _Var2 = is_ft("F1V03B2C2-1");
              if (_Var2) {
                ((g_rt.config)->standard).nonce_rate = 0x2594;
                ((g_rt.config)->standard).asic_nonce_rate = 0x254e;
              }
              else {
                _Var2 = is_ft("F1V03B3C2-2");
                if ((_Var2) || (_Var2 = is_ft("F1V03B1C1-3"), _Var2)) {
                  ((g_rt.config)->standard).nonce_rate = 0x2580;
                  ((g_rt.config)->standard).asic_nonce_rate = 0x254e;
                }
                else {
                  _Var2 = is_ft("F1V03B3C2-1");
                  if ((_Var2) || (_Var2 = is_ft("F1V03B3C2-3"), _Var2)) {
                    ((g_rt.config)->standard).nonce_rate = 0x25b2;
                    ((g_rt.config)->standard).asic_nonce_rate = 0x2580;
                  }
                  else {
                    ((g_rt.config)->standard).nonce_rate = 0x2616;
                    ((g_rt.config)->standard).asic_nonce_rate = 0x2602;
                  }
                }
              }
            }
          }
        }
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : fix standard nonce rate to %d, fix standard asic nonce rate to %d\n",
             "pt_before_send_nonce",((g_rt.config)->standard).nonce_rate,
             ((g_rt.config)->standard).asic_nonce_rate);
      snprintf(tmp1,0x100,"fix standard nonce rate to %d, fix standard asic nonce rate to %d",
               ((g_rt.config)->standard).nonce_rate,((g_rt.config)->standard).asic_nonce_rate);
      log_to_file(tmp1,time_stamp);
      g_bringup_temp = env_temp;
      vol_diff = get_vol_comp(env_temp);
      _Var2 = is_ft("F1V02B5C1-3");
      if (_Var2) {
        vol_diff = vol_diff + -10;
      }
      else {
        is_ft("F1V02B5C1-4");
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70502");
      if ((pcVar4 != (char *)0x0) &&
         ((_Var2 = is_ft("F1V02B2C1-1"), _Var2 || (_Var2 = is_ft("F1V02B3C1-3"), _Var2)))) {
        vol_diff = 0;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70502 F1V02B2C1-1 F1V02B3C1-3 will sub vol 0\n","pt_before_send_nonce");
        builtin_strncpy(tmp1,"A3HB70502 F1V02B2C1-1 F1V02B3C1-3 will sub vol 0",0x30);
        tmp1[0x30] = '\0';
        log_to_file(tmp1,time_stamp);
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70501");
      if ((pcVar4 != (char *)0x0) &&
         ((((_Var2 = is_ft("F1V02B1C1-1"), _Var2 || (_Var2 = is_ft("F1V02B1C1-2"), _Var2)) ||
           (_Var2 = is_ft("F1V02B3C1-4"), _Var2)) ||
          ((_Var2 = is_ft("F1V02B5C1-2"), _Var2 || (_Var2 = is_ft("F1V02B4C1-4"), _Var2)))))) {
        vol_diff = 0;
        ((g_rt.config)->standard).nonce_rate = 0x25ee;
        ((g_rt.config)->standard).asic_nonce_rate = 0x25d0;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70501 F1V02B1C1-1 will sub vol 0\n","pt_before_send_nonce");
        builtin_strncpy(tmp1,"A3HB70501 F1V02B1C1-1 will sub vol 0",0x24);
        tmp1._36_4_ = tmp1._36_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70503");
      if ((pcVar4 != (char *)0x0) &&
         (((_Var2 = is_ft("E1V07B5C1-3"), _Var2 || (_Var2 = is_ft("E1V07B4C2-1"), _Var2)) ||
          ((_Var2 = is_ft("E1V07B3C2-1"), _Var2 || (_Var2 = is_ft("E1V07B3C1-4"), _Var2)))))) {
        vol_diff = 0;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70501 1370 pf chip test will sub vol 0\n","pt_before_send_nonce");
        uVar1 = tmp1._40_4_;
        builtin_strncpy(tmp1,"A3HB70501 1370 pf chip test will sub vol 0",0x2b);
        tmp1[0x2b] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70503");
      if ((pcVar4 != (char *)0x0) && (_Var2 = is_ft_x("F1V03"), _Var2)) {
        vol_diff = 5;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70501 1370 pf chip test will sub vol 5\n","pt_before_send_nonce");
        uVar1 = tmp1._40_4_;
        builtin_strncpy(tmp1,"A3HB70501 1370 pf chip test will sub vol 5",0x2b);
        tmp1[0x2b] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70503");
      if ((pcVar4 != (char *)0x0) &&
         ((((_Var2 = is_ft("F1V03B3C2-1"), _Var2 ||
            (_Var2 = is_ft("F1V03B3C2-3-4_F1V03B3C1-2-3"), _Var2)) ||
           (_Var2 = is_ft("F1V03B3C2-3-4_F1V03B3C1-1-3"), _Var2)) ||
          (_Var2 = is_ft("F1V03B3C2-3"), _Var2)))) {
        vol_diff = vol_diff + -5;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70503 1370 pf chip test will sub vol -5\n","pt_before_send_nonce");
        builtin_strncpy(tmp1,"A3HB70503 1370 pf chip test will sub vol -5",0x2c);
        log_to_file(tmp1,time_stamp);
      }
      pcVar4 = strstr(((g_rt.config)->board).board_name,"A3HB70503");
      if ((pcVar4 != (char *)0x0) &&
         ((_Var2 = is_ft("F1V03B2C1-4"), _Var2 || (_Var2 = is_ft("F1V03B3C2-1"), _Var2)))) {
        vol_diff = -5;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : A3HB70503 1370 pf chip test will sub vol -5\n","pt_before_send_nonce");
        builtin_strncpy(tmp1,"A3HB70503 1370 pf chip test will sub vol -5",0x2c);
        log_to_file(tmp1,time_stamp);
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : vol diff:%d\n","pt_before_send_nonce",vol_diff);
      snprintf(tmp1,0x100,"vol diff:%d",vol_diff);
      log_to_file(tmp1,time_stamp);
      g_diff = vol_diff;
      pwm_set(g_fan,100);
      chain_reset_low((g_rt.config)->chain);
      lcd_common_show("Power on","Hashboard",(char *)0x0);
      _Var2 = pf_power_on((g_rt.config)->tests[0].pre_open_core_voltage);
      if (_Var2) {
        _Var2 = temp_sensor_check();
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : first sensor check res:%d\n","pt_before_send_nonce",(uint)_Var2);
        snprintf(tmp1,0x100,"first sensor check res:%d",(uint)_Var2);
        log_to_file(tmp1,time_stamp);
        if (_Var2) {
          reset_hash_board((g_rt.config)->chain);
          set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
          print_fan_speed();
          start_recv_thread();
          create_power_heart_beat_thread();
          uVar5 = get_register_info(0,0,true,"BM1370");
          if ((g_rt.config)->asics == uVar5) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : first find asic num %d\n","pt_before_send_nonce",uVar5);
            snprintf(tmp1,0x100,"first find asic num %d",uVar5);
            log_to_file(tmp1,time_stamp);
            set_register_stage_1();
            set_chain_ticketmask((uint8_t)(g_rt.config)->chain,0xffff);
            uart_flush_rx((g_rt.config)->chain);
            set_register_stage_2();
            usleep(1000000);
            do_core_reset((uint8_t *)0x0);
            usleep(1000000);
            pwm_set(g_fan,0x14);
            set_register_stage_3(matrix);
            usleep(1000000);
            g_pwm_enable = true;
            set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : read temp and domain voltage before heating...\n","pt_before_send_nonce");
            uVar1 = tmp1._44_4_;
            builtin_strncpy(tmp1,"read temp and domain voltage before heating...",0x2f);
            tmp1[0x2f] = SUB41(uVar1,3);
            log_to_file(tmp1,time_stamp);
            lcd_common_show("Heating","Hashboard",(char *)0x0);
            iVar6 = wait_board_temp(g_rt.tempval,(int8_t)((g_rt.config)->board).sensor.sensor_num,
                                    0x39);
            if (iVar6 != 0) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : err temp low...\n","pt_before_send_nonce");
              builtin_strncpy(tmp1,"err temp low...",0x10);
              log_to_file(tmp1,time_stamp);
              iVar6 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
              if (iVar6 < 0x35) {
                set_sweep_err_state(0xf,true);
                snprintf(err_str1_1,0x10,"Max %d",iVar6);
                snprintf(err_str2_1,0x10,"Need %d ~ %d",0x35,0x39);
                lcd_common_show("Heating Board",err_str1_1,err_str2_1);
                return -1;
              }
            }
            _Var2 = set_voltage_by_step((g_rt.config)->tests[0].pre_open_core_voltage,
                                        vol_diff + (g_rt.config)->tests[0].voltage,'\n');
            if (_Var2) {
              uVar5 = get_register_info(0,0,true,"BM1370");
              if ((g_rt.config)->asics == uVar5) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : second find asic num %d\n","pt_before_send_nonce",uVar5);
                snprintf(tmp1,0x100,"second find asic num %d",uVar5);
                log_to_file(tmp1,time_stamp);
                set_chain_reg_connect_left_diode_to_temp((uint8_t)(g_rt.config)->chain);
                set_chain_core_nonce_overflow_control((uint8_t)(g_rt.config)->chain,false);
                set_chain_baud((uint8_t)(g_rt.config)->chain,((g_rt.config)->speed).baudrate);
                usleep(200000);
                g_pwm_enable = true;
                iVar6 = 0;
              }
              else {
                set_sweep_err_state(0xd,true);
                power_down((g_rt.config)->chain);
                snprintf(err_str1_2,0x10,"Only %d",uVar5);
                snprintf(err_str2_2,0x10,"Need %d",(g_rt.config)->asics);
                lcd_common_show("Find asics 2",err_str1_2,err_str2_2);
                iVar6 = -1;
              }
            }
            else {
              iVar6 = -1;
            }
          }
          else {
            set_sweep_err_state(0xc,false);
            power_down((g_rt.config)->chain);
            snprintf(err_str1,0x10,"Only %d",uVar5);
            snprintf(err_str2,0x10,"Need %d",(g_rt.config)->asics);
            lcd_common_show("Find asics 1",err_str1,err_str2);
            iVar6 = -1;
          }
        }
        else {
          lcd_common_show("Sensor Check","Err",(char *)0x0);
          bitmain_power_off();
          iVar6 = -1;
        }
      }
      else {
        set_sweep_err_state(0xb,true);
        power_down((g_rt.config)->chain);
        lcd_common_show("Power on","err",(char *)0x0);
        iVar6 = -1;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : create read temp thread failed\n","pt_before_send_nonce");
      builtin_strncpy(tmp1,"create read temp thread failed",0x1f);
      log_to_file(tmp1,time_stamp);
      iVar6 = -1;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s :  init platform failed\n","pt_before_send_nonce");
    builtin_strncpy(tmp1," init platform failed",0x16);
    log_to_file(tmp1,time_stamp);
    iVar6 = -1;
  }
  return iVar6;
}

