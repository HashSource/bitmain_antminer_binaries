
/* WARNING: Unknown calling convention */

int Single_Board_PT1_Test(void)

{
  bool bVar1;
  undefined4 uVar2;
  _Bool _Var3;
  int iVar4;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t asic_num_record [3];
  char lcd_data [16];
  int test_result;
  int32_t thread_ret;
  _Bool temp;
  
  bVar1 = true;
  asic_num_record[0] = 0;
  asic_num_record[1] = 0;
  asic_num_record[2] = 0;
  gPattern_test_counter = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s, gPattern_test_counter = %d\n","Single_Board_PT1_Test",
         "Single_Board_PT1_Test",(uint)gPattern_test_counter);
  snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d","Single_Board_PT1_Test",
           (uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  _Var3 = init_fpga();
  if (_Var3) {
    fan_turn_on(BOTH_SIZE);
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set fan speed as %d\n","Single_Board_PT1_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x800,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var3 = check_chain();
    if (_Var3) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set Chain %d baud: %d\n","Single_Board_PT1_Test",gChain,0x1a);
      snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
      log_to_file(tmp1,time_stamp);
      set_bt8d_chain(gChain,0x1a);
      reset_register_cache_value_to_default((uint8_t)gChain);
      chain_reset_low(gChain);
      sleep(1);
      gStart_show_on_lcd = true;
      iVar4 = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5c6c1,(void *)0x0);
      if (iVar4 == 0) {
        _Var3 = Check_EEPROM(gEEPROM_length);
        if (_Var3) {
          gHistory_Result[gPattern_test_counter].eeprom_ok = true;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: chech EEPROM success\n","Single_Board_PT1_Test");
          builtin_strncpy(tmp1,"chech EEPROM success",0x14);
          tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: check EEPROM fail\n","Single_Board_PT1_Test");
          builtin_strncpy(tmp1,"check EEPROM fai",0x10);
          tmp1[0x10] = 'l';
          tmp1[0x11] = '\0';
          log_to_file(tmp1,time_stamp);
        }
        _Var3 = init_pic();
        if (_Var3) {
          _Var3 = APW_power_on(g_power_version,
                               gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
          if (_Var3) {
            _Var3 = pic_power_on_hashboard(gChain);
            if (_Var3) {
              set_asic_register_stage_1();
              if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic !=
                  false) {
                read_temperature_from_PIC_N_times('\x03');
              }
              gStart_receive = true;
              iVar4 = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8ca5,
                                     (void *)0x0);
              if (iVar4 == 0) {
                get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
                if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
                  get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
                }
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: First: Find %d ASIC\n\n","Single_Board_PT1_Test",gAsic_num);
                snprintf(tmp1,0x800,"First: Find %d ASIC\n",gAsic_num);
                log_to_file(tmp1,time_stamp);
                asic_num_record[0] = gAsic_num;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Set chain inactive\n","Single_Board_PT1_Test");
                uVar2 = tmp1._16_4_;
                builtin_strncpy(tmp1,"Set chain inactive",0x13);
                tmp1[0x13] = SUB41(uVar2,3);
                log_to_file(tmp1,time_stamp);
                set_chain_inactive((uint8_t)gChain);
                usleep(10000);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Set asic address\n","Single_Board_PT1_Test");
                builtin_strncpy(tmp1,"Set asic address",0x10);
                tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
                log_to_file(tmp1,time_stamp);
                set_chain_asic_address((uint8_t)gChain,gAddress_interval);
                usleep(10000);
                set_uart_relay((uint8_t)gAddress_interval);
                usleep(10000);
                set_chain_baud((uint8_t)gChain,
                               (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Set chain baud as %d\n","Single_Board_PT1_Test",
                       (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
                snprintf(tmp1,0x800,"Set chain baud as %d",
                         (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
                log_to_file(tmp1,time_stamp);
                usleep(50000);
                get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
                if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
                   (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
                   (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
                  print_find_asic_result();
                }
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Second: Find %d ASIC\n\n","Single_Board_PT1_Test",gAsic_num);
                snprintf(tmp1,0x800,"Second: Find %d ASIC\n",gAsic_num);
                log_to_file(tmp1,time_stamp);
                asic_num_record[1] = gAsic_num;
                chain_reset_low(gChain);
                usleep(500000);
                chain_reset_high(gChain);
                usleep(500000);
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Set Chain %d baud: %d\n","Single_Board_PT1_Test",gChain,0x1a);
                snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
                log_to_file(tmp1,time_stamp);
                set_bt8d_chain(gChain,0x1a);
                usleep(10000);
                reset_register_cache_value_to_default((uint8_t)gChain);
                usleep(10000);
                set_asic_register_stage_1();
                get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
                if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
                  get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
                }
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Third: Find %d ASIC\n\n","Single_Board_PT1_Test",gAsic_num);
                snprintf(tmp1,0x800,"Third: Find %d ASIC\n",gAsic_num);
                log_to_file(tmp1,time_stamp);
                asic_num_record[2] = gAsic_num;
                if (((asic_num_record[0] == (Local_Config_Information->Hash_Board).Asic_Num) &&
                    (asic_num_record[1] == (Local_Config_Information->Hash_Board).Asic_Num)) &&
                   (gAsic_num == (Local_Config_Information->Hash_Board).Asic_Num)) {
                  gHistory_Result[gPattern_test_counter].asic_ok = true;
                  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic
                      != false) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: Set chain inactive\n","Single_Board_PT1_Test");
                    uVar2 = tmp1._16_4_;
                    builtin_strncpy(tmp1,"Set chain inactive",0x13);
                    tmp1[0x13] = SUB41(uVar2,3);
                    log_to_file(tmp1,time_stamp);
                    set_chain_inactive((uint8_t)gChain);
                    usleep(10000);
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: Set asic address\n","Single_Board_PT1_Test");
                    builtin_strncpy(tmp1,"Set asic address",0x10);
                    tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
                    log_to_file(tmp1,time_stamp);
                    set_chain_asic_address((uint8_t)gChain,gAddress_interval);
                    usleep(10000);
                    read_temperature_from_asic_N_times('\x03');
                  }
                }
                else {
                  gAsic_num = get_min_value_uint32(asic_num_record,'\x03');
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: The MIN ASIC number is %d\n","Single_Board_PT1_Test",gAsic_num);
                  snprintf(tmp1,0x800,"The MIN ASIC number is %d",gAsic_num);
                  log_to_file(tmp1,time_stamp);
                }
                if ((gHistory_Result[gPattern_test_counter].asic_ok != false) &&
                   (gHistory_Result[gPattern_test_counter].eeprom_ok != false)) {
                  if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic
                        != false) &&
                      ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic
                       != false)) &&
                     ((gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true ||
                      (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)))) {
                    bVar1 = false;
                  }
                  if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic
                        != false) &&
                      ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic
                       != true)) &&
                     (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true)) {
                    bVar1 = false;
                  }
                  if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic
                        != true) &&
                      ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic
                       != false)) &&
                     (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)) {
                    bVar1 = false;
                  }
                  if (bVar1) {
                    _Var3 = write_EEPROM_PT1_marker();
                    if (_Var3) {
                      gHistory_Result[gPattern_test_counter].eeprom_ok = true;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: write PT1 EEPROM marker success\n","Single_Board_PT1_Test");
                      builtin_strncpy(tmp1,"write PT1 EEPROM marker success",0x20);
                      log_to_file(tmp1,time_stamp);
                    }
                    else {
                      gHistory_Result[gPattern_test_counter].eeprom_ok = false;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s: write PT1 EEPROM marker fail\n","Single_Board_PT1_Test");
                      builtin_strncpy(tmp1,"write PT1 EEPROM marker fail",0x1c);
                      tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
                      log_to_file(tmp1,time_stamp);
                    }
                  }
                }
                gStart_heart_beat = false;
                gStart_receive = false;
                pthread_join(pic_heart_beat_id,(void **)0x0);
                pthread_join(receive_id,(void **)0x0);
                _power_down(gChain);
                pthread_join(show_id,(void **)0x0);
                iVar4 = PT1_display_result_on_LCD();
                print_history_result((uint)gPattern_test_counter);
              }
              else {
                gStart_heart_beat = false;
                gStart_receive = false;
                _power_down(gChain);
                pthread_join(show_id,(void **)0x0);
                pthread_join(pic_heart_beat_id,(void **)0x0);
                pthread_join(receive_id,(void **)0x0);
                lcd_clear_result();
                lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                lcd_show(1,"Receive thread");
                lcd_show(2,"Creat  fail");
                lcd_show(3,"Start again");
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s:  Receive thread  creat fail, Start again\n","Single_Board_PT1_Test");
                builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
                tmp1[0x28] = '\0';
                log_to_file(tmp1,time_stamp);
                iVar4 = 0xc;
              }
            }
            else {
              gStart_show_on_lcd = false;
              gStart_heart_beat = false;
              _power_down(gChain);
              pthread_join(show_id,(void **)0x0);
              pthread_join(pic_heart_beat_id,(void **)0x0);
              gHistory_Result[gPattern_test_counter].pic_ok = false;
              lcd_common_show("PIC Power on","fail",(char *)0x0);
              iVar4 = 1;
            }
          }
          else {
            gStart_show_on_lcd = false;
            pwm_set(gFan,0);
            pthread_join(show_id,(void **)0x0);
            iVar4 = 0xc;
          }
        }
        else {
          gStart_show_on_lcd = false;
          pwm_set(gFan,0);
          pthread_join(show_id,(void **)0x0);
          iVar4 = 1;
        }
      }
      else {
        gStart_show_on_lcd = false;
        pthread_join(show_id,(void **)0x0);
        pwm_set(gFan,0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Show thread");
        lcd_show(2,"Creat  fail");
        lcd_show(3,"Start again");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Show thread creat fail, Start again\n","Single_Board_PT1_Test");
        builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
        log_to_file(tmp1,time_stamp);
        iVar4 = 0xc;
      }
    }
    else {
      pwm_set(gFan,0);
      iVar4 = 0xc;
    }
  }
  else {
    iVar4 = 0xc;
  }
  return iVar4;
}

