
/* WARNING: Unknown calling convention */

int Single_Board_PT2_Hardware_Pattern_Test(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [2048];
  pll_userdivider_t user_divider;
  returned_nonce_counter_t returned_nonce_counter_reg;
  char lcd_data [16];
  uint8_t history_result_index;
  int _result_;
  int _result__1;
  int32_t j;
  int32_t i;
  int32_t timeout;
  int32_t fail_counter;
  int32_t triger_counter;
  int32_t thread_ret;
  
  thread_ret = 0x1e240;
  timeout = 0;
  triger_counter = 0;
  fail_counter = 0;
  i = 0;
  j = 0;
  history_result_index = '\0';
  gPattern_test_counter = '\0';
  do {
    if (gTest_loop <= gPattern_test_counter) {
      return 0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Start %s, gPattern_test_counter = %d\n","Single_Board_PT2_Hardware_Pattern_Test",
           "Single_Board_PT2_Hardware_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d",
             "Single_Board_PT2_Hardware_Pattern_Test",(uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    _Var1 = init_fpga();
    if (!_Var1) {
      return 0xc;
    }
    fan_turn_on(BOTH_SIZE);
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set fan speed as %d\n","Single_Board_PT2_Hardware_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x800,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var1 = check_chain();
    if (!_Var1) {
      pwm_set(gFan,0);
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set Chain %d baud: %d\n","Single_Board_PT2_Hardware_Pattern_Test",gChain,0x1a);
    snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
    log_to_file(tmp1,time_stamp);
    set_bt8d_chain(gChain,0x1a);
    reset_register_cache_value_to_default((uint8_t)gChain);
    gStart_show_on_lcd = true;
    thread_ret = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5be19,
                                (void *)0x0);
    if (thread_ret != 0) {
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
      printf("%s: Show thread creat fail, Start again\n","Single_Board_PT2_Hardware_Pattern_Test");
      builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    _Var1 = check_PT1_EEPROM_marker();
    if (!_Var1) {
      gStart_show_on_lcd = false;
      pthread_join(show_id,(void **)0x0);
      pwm_set(gFan,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM is not ok\n","Single_Board_PT2_Hardware_Pattern_Test");
      builtin_strncpy(tmp1,"EEPROM is not ok",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 5;
    }
    _Var1 = Check_EEPROM(gEEPROM_length - 1);
    if (!_Var1) {
      gStart_show_on_lcd = false;
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"EEPROM");
      lcd_show(2,"Check fail");
      pwm_set(gFan,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM is not ok\n","Single_Board_PT2_Hardware_Pattern_Test");
      builtin_strncpy(tmp1,"EEPROM is not ok",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0xb;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM is ok\n","Single_Board_PT2_Hardware_Pattern_Test");
    builtin_strncpy(tmp1,"EEPROM is ok",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
       (_Var1 = init_pic(), !_Var1)) {
      gStart_show_on_lcd = false;
      pwm_set(gFan,0);
      pthread_join(show_id,(void **)0x0);
      return 1;
    }
    _Var1 = APW_power_on(g_power_version,
                         gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
    if (!_Var1) {
      gStart_show_on_lcd = false;
      pwm_set(gFan,0);
      pthread_join(show_id,(void **)0x0);
      return 0xc;
    }
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) ||
       ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false)
       ) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard !=
            false) {
          gStart_read_temp = true;
          thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                      (__start_routine *)0x6e7fd,(void *)0x0);
        }
      }
      else {
        gStart_read_temp_from_pic = true;
        thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                    (__start_routine *)0x60ac1,(void *)0x0);
      }
      if (thread_ret != 0) {
        gStart_read_temp_from_pic = false;
        gStart_heart_beat = false;
        gStart_read_temp = false;
        _power_down(gChain);
        pthread_join(read_temp_from_pic_id,(void **)0x0);
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
          pthread_join(pic_heart_beat_id,(void **)0x0);
        }
        pthread_join(show_id,(void **)0x0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Read PIC Temp");
        lcd_show(2,"thread  fail");
        lcd_show(3,"Start again");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Receive thread creat fail, Start again\n",
               "Single_Board_PT2_Hardware_Pattern_Test");
        builtin_strncpy(tmp1,"Receive thread creat fail, Start again",0x27);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
      _Var1 = wait_for_cool_down_x
                        ((Local_Config_Information->Test_Info).Temperature.
                         Max_Wait_Cooling_Down_Time);
      if (!_Var1) {
        gStart_read_temp_from_pic = false;
        gStart_heart_beat = false;
        gStart_read_temp = false;
        _power_down(gChain);
        pthread_join(read_temp_from_pic_id,(void **)0x0);
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
          pthread_join(pic_heart_beat_id,(void **)0x0);
        }
        pthread_join(show_id,(void **)0x0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"cool fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t cool down hashboard fail\n","Single_Board_PT2_Hardware_Pattern_Test");
        builtin_strncpy(tmp1,"Can\'t cool down hashboard fail",0x1f);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
    }
    _Var1 = pic_power_on_hashboard(gChain);
    if (!_Var1) {
      gStart_heart_beat = false;
      gStart_read_temp_from_pic = false;
      gStart_read_temp = false;
      _power_down(gChain);
      pthread_join(show_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      gHistory_Result[gPattern_test_counter].pic_ok = false;
      lcd_common_show("PIC Power on","fail",(char *)0x0);
      return 1;
    }
    uart_flush_rx(gChain);
    gStart_receive = true;
    thread_ret = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf6095,
                                (void *)0x0);
    if (thread_ret != 0) {
      gStart_receive = false;
      gStart_read_temp_from_pic = false;
      gStart_read_temp = false;
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Receive thread");
      lcd_show(2,"Creat  fail");
      lcd_show(3,"Start again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s:  Receive thread  creat fail, Start again\n",
             "Single_Board_PT2_Hardware_Pattern_Test");
      builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
      tmp1[0x28] = '\0';
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
      gStart_receive = false;
      gStart_read_temp_from_pic = false;
      gStart_heart_beat = false;
      gStart_read_temp = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      if (gAsic_num == 0xffffffff) {
        lcd_show(1,"get too much");
        lcd_show(2,"error asic");
        lcd_show(3,"address");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: get too much error asic address\n","Single_Board_PT2_Hardware_Pattern_Test");
        builtin_strncpy(tmp1,"get too much error asic address",0x20);
        log_to_file(tmp1,time_stamp);
      }
      else {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"%2d",gAsic_num);
        lcd_show(1,"Only find");
        lcd_show(2,lcd_data);
        lcd_show(3,"ASIC");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Hardware_Pattern_Test",gAsic_num);
        snprintf(tmp1,0x800,"Only find %d ASIC",gAsic_num);
        log_to_file(tmp1,time_stamp);
      }
      if (gAsic_num != 0) {
        return gAsic_num << 8 | 3;
      }
      return 2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: First: find %d ASIC\n\n","Single_Board_PT2_Hardware_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"First: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    set_chain_inactive((uint8_t)gChain);
    usleep(10000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set asic address\n","Single_Board_PT2_Hardware_Pattern_Test");
    builtin_strncpy(tmp1,"Set asic address",0x10);
    tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    set_chain_asic_address((uint8_t)gChain,gAddress_interval);
    usleep(10000);
    set_chain_clock_select_control
              ((uint8_t)gChain,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set pulse_mode = 0x%02x, clk_sel = 0x%02x\n",
           "Single_Board_PT2_Hardware_Pattern_Test",
           (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,
           (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
    snprintf(tmp1,0x800,"Set pulse_mode = 0x%02x, clk_sel = 0x%02x",
             (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,
             (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
    log_to_file(tmp1,time_stamp);
    usleep(10000);
    set_chain_clock_delay_control
              ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel
               ,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x\n",
           "Single_Board_PT2_Hardware_Pattern_Test",
           (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
           (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
           (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
    snprintf(tmp1,0x800,"Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x",
             (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
             (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
             (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
    log_to_file(tmp1,time_stamp);
    usleep(10000);
    set_uart_relay((uint8_t)gAddress_interval);
    usleep(10000);
    set_pattern_test_voltage_by_step
              (gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
               gHistory_Result[gPattern_test_counter].voltage,'\x05');
    usleep(1000000);
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
      gStart_receive = false;
      gStart_read_temp_from_pic = false;
      gStart_read_temp = false;
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      if (gAsic_num == 0xffffffff) {
        lcd_show(1,"get too much");
        lcd_show(2,"error asic");
        lcd_show(3,"address");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: get too much error asic address\n","Single_Board_PT2_Hardware_Pattern_Test");
        builtin_strncpy(tmp1,"get too much error asic address",0x20);
        log_to_file(tmp1,time_stamp);
      }
      else {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"%2d",gAsic_num);
        lcd_show(1,"Only find");
        lcd_show(2,lcd_data);
        lcd_show(3,"ASIC");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Hardware_Pattern_Test",gAsic_num);
        snprintf(tmp1,0x800,"Only find %d ASIC",gAsic_num);
        log_to_file(tmp1,time_stamp);
      }
      if (gAsic_num != 0) {
        return gAsic_num << 8 | 3;
      }
      return 2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Second: find %d ASIC\n\n","Single_Board_PT2_Hardware_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"Second: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    memset(&user_divider,0,4);
    set_chain_pllparameter_userdivider((uint8_t)gChain,'\0',user_divider);
    usleep(100000);
    set_chain_frequency((uint8_t)gChain,'\0',
                        (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                        [gPattern_test_counter].Frequence);
    usleep(100000);
    set_chain_chip_nonce_offset((uint8_t)gChain,true,0);
    usleep(10000);
    usleep(10000);
    set_chain_clock_delay_control((uint8_t)gChain,'\0','\0','\x01');
    usleep(10000);
    set_chain_core_srst((uint8_t)gChain,false);
    usleep(10000);
    timeout = calculate_hardware_sweep_timeout
                        ((Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                         [gPattern_test_counter].Frequence,gMax_Nonce,gTimeout_Clock);
    usleep(10000);
    for (triger_counter = 0;
        (uint)triger_counter < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
        triger_counter = triger_counter + 1) {
      gHardware_sweep_done_asic_num = 0;
      usleep(150000);
      while (get_register_value(0,4,true,(Local_Config_Information->Hash_Board).Asic_Type),
            (Local_Config_Information->Hash_Board).Asic_Num != gHardware_sweep_done_asic_num) {
        fail_counter = fail_counter + 1;
        if (9 < fail_counter) {
          fail_counter = 0;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Hardware sweep: triger_counter %d fail\n",
                 "Single_Board_PT2_Hardware_Pattern_Test",triger_counter);
          snprintf(tmp1,0x800,"Hardware sweep: triger_counter %d fail",triger_counter);
          log_to_file(tmp1,time_stamp);
          goto LAB_00102464;
        }
        usleep(1000);
      }
      fail_counter = 0;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Hardware sweep: triger_counter %d done\n","Single_Board_PT2_Hardware_Pattern_Test"
             ,triger_counter);
      snprintf(tmp1,0x800,"Hardware sweep: triger_counter %d done",triger_counter);
      log_to_file(tmp1,time_stamp);
LAB_00102464:
      usleep(1000);
    }
    get_register_value(0,5,true,(Local_Config_Information->Hash_Board).Asic_Type);
    set_chain_clock_delay_control((uint8_t)gChain,'\0','\0','\0');
    usleep(1000);
    usleep(1000);
    usleep(1000);
    gStart_receive = false;
    thread_ret = pthread_join(receive_id,(void **)0x0);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      gStart_read_temp_from_pic = false;
      pthread_join(read_temp_from_pic_id,(void **)0x0);
    }
    gStart_heart_beat = false;
    gStart_read_temp = false;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      pthread_join(pic_heart_beat_id,(void **)0x0);
    }
    get_result_hw_sweep();
    _power_down(gChain);
    pthread_join(show_id,(void **)0x0);
    if (gHistory_Result[gPattern_test_counter].test_standard == '\0') {
      _result_ = do_PT2_summary_work(gPattern_test_counter);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: All test done. STRICT_STANDARD: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Hardware_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x800,"All test done. STRICT_STANDARD: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      return _result_;
    }
    if (gTest_loop - 1 <= (uint)gPattern_test_counter) {
      find_submit_history_result_index(&history_result_index);
      _result__1 = do_PT2_summary_work(history_result_index);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: All test done. Last test loop: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Hardware_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x800,"All test done. Last test loop: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      return _result__1;
    }
    puts("\n\n");
  } while( true );
}

