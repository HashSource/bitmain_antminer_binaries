
int pt_before_send_nonce(float *matrix)

{
  _Bool _Var1;
  int8_t iVar2;
  int32_t iVar3;
  int iVar4;
  float fVar5;
  float *matrix_local;
  char time_stamp [48];
  char tmp42 [256];
  char lcd_data [16];
  _Bool vol_res;
  int32_t env_temp;
  int comp;
  
  reset_register_cache_value_to_default((uint8_t)(g_rt.config)->chain);
  reset_runtime_info(g_rt.sweep.mode);
  iVar3 = pwm_set(g_fan,((g_rt.config)->fan).fan_speed);
  if (iVar3 != 0) {
    snprintf(tmp42,0x100,"fan %d pwm_set speed %d failed",g_fan,((g_rt.config)->fan).fan_speed);
    puts(tmp42);
  }
  builtin_strncpy(tmp42," pf_init",8);
  tmp42[8] = '\n';
  tmp42[9] = '\0';
  puts(tmp42);
  _Var1 = pf_init((g_rt.config)->chain);
  if (_Var1) {
    enable_power_calibration();
    set_bt8d_chain((g_rt.config)->chain,0x1a);
    reset_register_buf();
    chain_reset_high((g_rt.config)->chain);
    builtin_strncpy(tmp42,"chain reset high",0x10);
    tmp42._16_4_ = tmp42._16_4_ & 0xffffff00;
    puts(tmp42);
    sleep(1);
    iVar4 = start_temp_thread();
    if (iVar4 == 0) {
      waiting_cool_down(((g_rt.config)->temp).wait_cool_time,(int8_t *)g_rt.tempval,
                        (int8_t)((g_rt.config)->board).sensor.sensor_num,
                        ((g_rt.config)->temp).temp_gap);
      iVar2 = pf_get_min_value((int8_t *)g_rt.tempval,
                               (uint8_t)((g_rt.config)->board).sensor.sensor_num);
      iVar4 = (int)iVar2;
      if (iVar4 < 0x24) {
        if (iVar4 < 0x1e) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: ENV temperature too low\n","pt_before_send_nonce");
          builtin_strncpy(tmp42,"ENV temperature too low",0x18);
          log_to_file(tmp42,time_stamp);
          if (g_sweep_err_code == 0) {
            g_sweep_err_code = iVar4 << 8 | 2;
          }
          iVar4 = -1;
        }
        else {
          g_diff = get_vol_comp(iVar4);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: g_diff:%d\n","pt_before_send_nonce",g_diff);
          snprintf(tmp42,0x800,"g_diff:%d",g_diff);
          log_to_file(tmp42,time_stamp);
          _Var1 = APW_power_on(g_power_version,(g_rt.config)->tests[0].pre_open_core_voltage);
          if (_Var1) {
            _Var1 = pic_power_on_hashboard((g_rt.config)->chain);
            if (_Var1) {
              set_register_stage_1();
              iVar4 = start_recv_thread();
              if (iVar4 == 0) {
                reset_hash_board((g_rt.config)->chain);
                gAsic_num = get_register_info(0,0,true,"BM1370");
                if ((g_rt.config)->asics == gAsic_num) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: first find asic num %d\n\n","pt_before_send_nonce",gAsic_num);
                  snprintf(tmp42,0x800,"first find asic num %d\n",gAsic_num);
                  log_to_file(tmp42,time_stamp);
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\0');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x01');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x02');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x03');
                  set_register_stage_2();
                  set_register_stage_3(matrix);
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\0');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x01');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x02');
                  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x03');
                  usleep(1000000);
                  if ((g_rt.config)->is_super != false) {
                    set_chain_chip_nonce_offset((uint8_t)(g_rt.config)->chain,true,0);
                  }
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: wait board temp come to %d\n","pt_before_send_nonce",
                         ((g_rt.config)->board).wait_temp);
                  snprintf(tmp42,0x800,"wait board temp come to %d",((g_rt.config)->board).wait_temp
                          );
                  log_to_file(tmp42,time_stamp);
                  iVar4 = wait_board_temp((int8_t *)g_rt.tempval,
                                          (int8_t)((g_rt.config)->board).sensor.sensor_num,
                                          ((g_rt.config)->board).wait_temp);
                  if (iVar4 == 0) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: set vol:%d\n","pt_before_send_nonce",(g_rt.config)->tests[0].voltage
                          );
                    snprintf(tmp42,0x800,"set vol:%d",(g_rt.config)->tests[0].voltage);
                    log_to_file(tmp42,time_stamp);
                    _Var1 = set_pattern_test_voltage_by_step
                                      ((g_rt.config)->tests[0].pre_open_core_voltage,
                                       (g_rt.config)->tests[0].voltage,'\x05');
                    if (_Var1) {
                      usleep(4000000);
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      fVar5 = get_miner_power();
                      printf("%s: power = %f \n","pt_before_send_nonce",SUB84((double)fVar5,0),
                             (int)((ulonglong)(double)fVar5 >> 0x20));
                      fVar5 = get_miner_power();
                      snprintf(tmp42,0x800,"power = %f ",tmp42,(double)fVar5);
                      log_to_file(tmp42,time_stamp);
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: g_diff = %d mv\n","pt_before_send_nonce",g_diff);
                      snprintf(tmp42,0x800,"g_diff = %d mv",g_diff);
                      log_to_file(tmp42,time_stamp);
                      set_pattern_test_voltage_by_step
                                ((g_rt.config)->tests[0].voltage,
                                 g_diff + (g_rt.config)->tests[0].voltage,'\x01');
                      adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x03');
                      gAsic_num = get_register_info(0,0,true,"BM1370");
                      if ((g_rt.config)->asics == gAsic_num) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: second find asic num %d\n\n","pt_before_send_nonce",gAsic_num);
                        snprintf(tmp42,0x800,"second find asic num %d\n",gAsic_num);
                        log_to_file(tmp42,time_stamp);
                        g_pwm_enable = true;
                        iVar4 = 0;
                      }
                      else {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s: only find asic num %d\n\n","pt_before_send_nonce",gAsic_num);
                        snprintf(tmp42,0x800,"only find asic num %d\n",gAsic_num);
                        log_to_file(tmp42,time_stamp);
                        if (g_sweep_err_code == 0) {
                          g_sweep_err_code = gAsic_num << 8 | 7;
                        }
                        iVar4 = -1;
                      }
                    }
                    else {
                      iVar4 = -1;
                    }
                  }
                  else {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: wait_board_temp timeout\n","pt_before_send_nonce");
                    builtin_strncpy(tmp42,"wait_board_temp timeout",0x18);
                    log_to_file(tmp42,time_stamp);
                    iVar4 = -1;
                  }
                }
                else {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: only find asic num %d\n\n","pt_before_send_nonce",gAsic_num);
                  snprintf(tmp42,0x800,"only find asic num %d\n",gAsic_num);
                  log_to_file(tmp42,time_stamp);
                  if (g_sweep_err_code == 0) {
                    g_sweep_err_code = gAsic_num << 8 | 7;
                  }
                  iVar4 = -1;
                }
              }
              else {
                builtin_strncpy(tmp42,"start recv thread fail",0x17);
                puts(tmp42);
                iVar4 = -1;
              }
            }
            else {
              iVar4 = -1;
            }
          }
          else {
            iVar4 = -1;
          }
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: env temp %d is too high, pattern text exit\n\n","pt_before_send_nonce",iVar4);
        snprintf(tmp42,0x800,"env temp %d is too high, pattern text exit\n",iVar4);
        log_to_file(tmp42,time_stamp);
        if (g_sweep_err_code == 0) {
          g_sweep_err_code = iVar4 << 8 | 1;
        }
        iVar4 = -1;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: create read temp thread failed\n","pt_before_send_nonce");
      builtin_strncpy(tmp42,"create read temp thread fail",0x1c);
      tmp42[0x1c] = 'e';
      tmp42[0x1d] = 'd';
      tmp42[0x1e] = '\0';
      log_to_file(tmp42,time_stamp);
      iVar4 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42," init platform failed\n",0x17);
    puts(tmp42);
    iVar4 = -1;
  }
  return iVar4;
}

