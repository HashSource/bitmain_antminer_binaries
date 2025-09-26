
/* WARNING: Unknown calling convention */

int Single_Board_PT2_Autogen_Pattern_Test(void)

{
  uint32_t uVar1;
  undefined4 uVar2;
  _Bool _Var3;
  uint32_t hash_counting_num;
  char time_stamp [48];
  char tmp1 [2048];
  returned_nonce_counter_t returned_nonce_counter_reg;
  char lcd_data [16];
  uint8_t history_result_index;
  int _result_;
  int _result__1;
  int32_t j;
  int32_t i;
  int32_t thread_ret;
  
  thread_ret = 0x1e240;
  i = 0;
  j = 0;
  history_result_index = '\0';
  gPattern_test_counter = '\0';
  while( true ) {
    if (gTest_loop <= gPattern_test_counter) {
      return 0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Start %s, gPattern_test_counter = %d\n","Single_Board_PT2_Autogen_Pattern_Test",
           "Single_Board_PT2_Autogen_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d",
             "Single_Board_PT2_Autogen_Pattern_Test",(uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    _Var3 = init_fpga();
    if (!_Var3) {
      return 0xc;
    }
    fan_turn_on(BOTH_SIZE);
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set fan speed as %d\n","Single_Board_PT2_Autogen_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x800,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var3 = check_chain();
    if (!_Var3) {
      pwm_set(gFan,0);
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set Chain %d baud: %d\n","Single_Board_PT2_Autogen_Pattern_Test",gChain,0x1a);
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
      printf("%s: Show thread creat fail, Start again\n","Single_Board_PT2_Autogen_Pattern_Test");
      builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    _Var3 = check_PT1_EEPROM_marker();
    if (!_Var3) {
      gStart_show_on_lcd = false;
      pthread_join(show_id,(void **)0x0);
      pwm_set(gFan,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM is not ok\n","Single_Board_PT2_Autogen_Pattern_Test");
      builtin_strncpy(tmp1,"EEPROM is not ok",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 5;
    }
    _Var3 = Check_EEPROM(gEEPROM_length - 1);
    if (!_Var3) {
      gStart_show_on_lcd = false;
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"EEPROM");
      lcd_show(2,"Check fail");
      pwm_set(gFan,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM is not ok\n","Single_Board_PT2_Autogen_Pattern_Test");
      builtin_strncpy(tmp1,"EEPROM is not ok",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0xb;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM is ok\n","Single_Board_PT2_Autogen_Pattern_Test");
    builtin_strncpy(tmp1,"EEPROM is ok",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
       (_Var3 = init_pic(), !_Var3)) {
      gStart_show_on_lcd = false;
      pwm_set(gFan,0);
      pthread_join(show_id,(void **)0x0);
      return 1;
    }
    _Var3 = APW_power_on(g_power_version,
                         gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
    if (!_Var3) {
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
        gStart_read_temp = false;
        gStart_heart_beat = false;
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
               "Single_Board_PT2_Autogen_Pattern_Test");
        uVar2 = tmp1._36_4_;
        builtin_strncpy(tmp1,"Receive thread creat fail, Start again",0x27);
        tmp1[0x27] = SUB41(uVar2,3);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
      _Var3 = wait_for_cool_down_x
                        ((Local_Config_Information->Test_Info).Temperature.
                         Max_Wait_Cooling_Down_Time);
      if (!_Var3) {
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
        printf("%s: Can\'t cool down hashboard fail\n","Single_Board_PT2_Autogen_Pattern_Test");
        uVar2 = tmp1._28_4_;
        builtin_strncpy(tmp1,"Can\'t cool down hashboard fail",0x1f);
        tmp1[0x1f] = SUB41(uVar2,3);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
    }
    _Var3 = pic_power_on_hashboard(gChain);
    if (!_Var3) {
      gStart_read_temp_from_pic = false;
      gStart_heart_beat = false;
      gStart_read_temp = false;
      _power_down(gChain);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      pthread_join(show_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      gHistory_Result[gPattern_test_counter].pic_ok = false;
      lcd_common_show("PIC Power on","fail",(char *)0x0);
      return 1;
    }
    set_asic_register_stage_1();
    set_chain_core_srst((uint8_t)gChain,false);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: set core_srst in MISC_CONTROL register as false\n",
           "Single_Board_PT2_Autogen_Pattern_Test");
    builtin_strncpy(tmp1,"set core_srst in MISC_CONTROL register as false",0x30);
    log_to_file(tmp1,time_stamp);
    usleep(10000);
    gStart_receive = true;
    thread_ret = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf6095,
                                (void *)0x0);
    if (thread_ret != 0) break;
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
        printf("%s: get too much error asic address\n","Single_Board_PT2_Autogen_Pattern_Test");
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Autogen_Pattern_Test",gAsic_num);
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
    printf("%s: First: find %d ASIC\n\n","Single_Board_PT2_Autogen_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"First: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_2();
    uVar1 = gChain;
    hash_counting_num = calculate_hcn();
    set_chain_hash_counting_number((uint8_t)uVar1,hash_counting_num);
    set_chain_auto_gen_midstate
              ((uint8_t)gChain,true,
               (uint8_t)(Local_Config_Information->Test_Info).Test_Method.Midstate_Number,0x700);
    enable_dhash_midstate_autogen();
    usleep(3000);
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
        printf("%s: get too much error asic address\n","Single_Board_PT2_Autogen_Pattern_Test");
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Autogen_Pattern_Test",gAsic_num);
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
    printf("%s: Second: find %d ASIC\n\n","Single_Board_PT2_Autogen_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"Second: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xf7485,
                                (void *)0x0);
    if (thread_ret != 0) {
      pthread_cancel(send_id);
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
      lcd_show(1,"Send  thread");
      lcd_show(2,"Creat  fail");
      lcd_show(3,"Start again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Send thread creat fail, Start again\n","Single_Board_PT2_Autogen_Pattern_Test");
      builtin_strncpy(tmp1,"Send thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    thread_ret = pthread_join(send_id,(void **)0x0);
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
    get_result();
    _power_down(gChain);
    pthread_join(show_id,(void **)0x0);
    if (gHistory_Result[gPattern_test_counter].test_standard == '\0') {
      _result_ = do_PT2_summary_work(gPattern_test_counter);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: All test done. STRICT_STANDARD: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Autogen_Pattern_Test",(uint)gPattern_test_counter);
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
             "Single_Board_PT2_Autogen_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x800,"All test done. Last test loop: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      return _result__1;
    }
    gPattern_test_counter = gPattern_test_counter + '\x01';
    puts("\n\n");
  }
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
  lcd_show(1,"Receive thread");
  lcd_show(2,"Creat  fail");
  lcd_show(3,"Start again");
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  Receive thread  creat fail, Start again\n","Single_Board_PT2_Autogen_Pattern_Test");
  builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
  tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  return 0xc;
}

