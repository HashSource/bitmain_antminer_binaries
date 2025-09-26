
/* WARNING: Unknown calling convention */

int Single_Board_PT1_Plus_Software_Pattern_Test(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  char time_stamp [48];
  char tmp1 [2048];
  char lcd_data [16];
  int test_result_1;
  int test_result;
  uint8_t history_result_index;
  int32_t j;
  _Bool temp;
  int32_t i;
  int32_t thread_ret;
  
  temp = true;
  gPattern_test_counter = '\0';
  while( true ) {
    if (gTest_loop <= gPattern_test_counter) {
      return 0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Start %s, gPattern_test_counter = %d\n",
           "Single_Board_PT1_Plus_Software_Pattern_Test",
           "Single_Board_PT1_Plus_Software_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d",
             "Single_Board_PT1_Plus_Software_Pattern_Test",(uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    _Var2 = init_fpga();
    if (!_Var2) {
      return 0xc;
    }
    fan_turn_on(BOTH_SIZE);
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set fan speed as %d\n","Single_Board_PT1_Plus_Software_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x800,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var2 = check_chain();
    if (!_Var2) {
      pwm_set(gFan,0);
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set Chain %d baud: %d\n","Single_Board_PT1_Plus_Software_Pattern_Test",gChain,0x1a);
    snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
    log_to_file(tmp1,time_stamp);
    set_bt8d_chain(gChain,0x1a);
    reset_register_cache_value_to_default((uint8_t)gChain);
    gStart_show_on_lcd = true;
    iVar3 = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5c8a1,(void *)0x0);
    if (iVar3 != 0) {
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
      printf("%s: Show thread creat fail, Start again\n",
             "Single_Board_PT1_Plus_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    _Var2 = Check_EEPROM(gEEPROM_length);
    if (!_Var2) {
      gStart_show_on_lcd = false;
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"EEPROM");
      lcd_show(2,"Check fail");
      pwm_set(gFan,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM is not ok\n","Single_Board_PT1_Plus_Software_Pattern_Test");
      builtin_strncpy(tmp1,"EEPROM is not ok",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0xb;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM is ok\n","Single_Board_PT1_Plus_Software_Pattern_Test");
    builtin_strncpy(tmp1,"EEPROM is ok",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    _Var2 = init_pic();
    if (!_Var2) {
      gStart_show_on_lcd = false;
      pwm_set(gFan,0);
      pthread_join(show_id,(void **)0x0);
      return 1;
    }
    _Var2 = APW_power_on(g_power_version,
                         gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
    if (!_Var2) {
      gStart_show_on_lcd = false;
      pwm_set(gFan,0);
      pthread_join(show_id,(void **)0x0);
      return 0xc;
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      gStart_read_temp_from_pic = true;
      iVar3 = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,(__start_routine *)0x61679
                             ,(void *)0x0);
      if (iVar3 != 0) {
        gStart_read_temp_from_pic = false;
        gStart_heart_beat = false;
        _power_down(gChain);
        pthread_join(read_temp_from_pic_id,(void **)0x0);
        pthread_join(pic_heart_beat_id,(void **)0x0);
        pthread_join(show_id,(void **)0x0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Read PIC Temp");
        lcd_show(2,"thread  fail");
        lcd_show(3,"Start again");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Receive thread creat fail, Start again\n",
               "Single_Board_PT1_Plus_Software_Pattern_Test");
        builtin_strncpy(tmp1,"Receive thread creat fail, Start again",0x27);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
      _Var2 = wait_for_cool_down((uint8_t)gPic_sensor_num,
                                 (Local_Config_Information->Test_Info).Temperature.
                                 Max_Wait_Cooling_Down_Time);
      if (!_Var2) {
        gStart_read_temp_from_pic = false;
        gStart_heart_beat = false;
        _power_down(gChain);
        pthread_join(read_temp_from_pic_id,(void **)0x0);
        pthread_join(pic_heart_beat_id,(void **)0x0);
        pthread_join(show_id,(void **)0x0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"cool fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t cool down hashboard fail\n","Single_Board_PT1_Plus_Software_Pattern_Test"
              );
        uVar1 = tmp1._28_4_;
        builtin_strncpy(tmp1,"Can\'t cool down hashboard fail",0x1f);
        tmp1[0x1f] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
    }
    _Var2 = pic_power_on_hashboard(gChain);
    if (!_Var2) {
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(show_id,(void **)0x0);
      pthread_join(pic_heart_beat_id,(void **)0x0);
      gHistory_Result[gPattern_test_counter].pic_ok = false;
      lcd_common_show("PIC Power on","fail",(char *)0x0);
      return 1;
    }
    set_asic_register_stage_1();
    gStart_receive = true;
    iVar3 = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8ca5,(void *)0x0)
    ;
    if (iVar3 != 0) break;
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
      gStart_receive = false;
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        gStart_read_temp_from_pic = false;
      }
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      pthread_join(pic_heart_beat_id,(void **)0x0);
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      if (gAsic_num == 0xffffffff) {
        lcd_show(1,"get too much");
        lcd_show(2,"error asic");
        lcd_show(3,"address");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: get too much error asic address\n","Single_Board_PT1_Plus_Software_Pattern_Test"
              );
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT1_Plus_Software_Pattern_Test",gAsic_num);
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
    printf("%s: First: find %d ASIC\n\n","Single_Board_PT1_Plus_Software_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"First: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_2();
    usleep(1000000);
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
      gStart_receive = false;
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        gStart_read_temp_from_pic = false;
      }
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      pthread_join(pic_heart_beat_id,(void **)0x0);
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      if (gAsic_num == 0xffffffff) {
        lcd_show(1,"get too much");
        lcd_show(2,"error asic");
        lcd_show(3,"address");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: get too much error asic address\n","Single_Board_PT1_Plus_Software_Pattern_Test"
              );
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT1_Plus_Software_Pattern_Test",gAsic_num);
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
    printf("%s: Second: find %d ASIC\n\n","Single_Board_PT1_Plus_Software_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"Second: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 4) {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8fc9,
                                  (void *)0x0);
    }
    else if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xf95d9,
                                  (void *)0x0);
    }
    else {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0x106cd1,
                                  (void *)0x0);
    }
    if (thread_ret != 0) {
      pthread_cancel(send_id);
      gStart_receive = false;
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        gStart_read_temp_from_pic = false;
      }
      gStart_heart_beat = false;
      _power_down(gChain);
      pthread_join(receive_id,(void **)0x0);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      pthread_join(pic_heart_beat_id,(void **)0x0);
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Send  thread");
      lcd_show(2,"Creat  fail");
      lcd_show(3,"Start again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Send thread creat fail, Start again\n",
             "Single_Board_PT1_Plus_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Send thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    pthread_join(send_id,(void **)0x0);
    pthread_join(receive_id,(void **)0x0);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      gStart_read_temp_from_pic = false;
      pthread_join(read_temp_from_pic_id,(void **)0x0);
    }
    gStart_show_on_lcd = false;
    gStart_heart_beat = false;
    pthread_join(show_id,(void **)0x0);
    pthread_join(pic_heart_beat_id,(void **)0x0);
    if (gFind_dummy_data == true) {
      for (i = 0; (uint)i < gPic_sensor_num; i = i + 1) {
        temp = (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] & temp) != 0;
      }
      if (temp != false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: All PIC sensor OK\n","Single_Board_PT1_Plus_Software_Pattern_Test");
        builtin_strncpy(tmp1,"All PIC sensor O",0x10);
        tmp1[0x10] = 'K';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
        gHistory_Result[gPattern_test_counter].pic_sensor_all_OK = true;
      }
    }
    else {
      get_result();
    }
    temp = true;
    if ((gHistory_Result[gPattern_test_counter].asic_ok != false) &&
       (gHistory_Result[gPattern_test_counter].eeprom_ok != false)) {
      if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false)
          && ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false
             )) && ((gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true ||
                    (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)))) {
        temp = false;
      }
      if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false)
          && ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != true)
          ) && (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true)) {
        temp = false;
      }
      if ((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != true) &&
          ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false))
         && (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)) {
        temp = false;
      }
      if (temp != false) {
        _Var2 = write_EEPROM_PT1_marker();
        if (_Var2) {
          gHistory_Result[gPattern_test_counter].eeprom_ok = true;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: write PT1 EEPROM marker success\n",
                 "Single_Board_PT1_Plus_Software_Pattern_Test");
          builtin_strncpy(tmp1,"write PT1 EEPROM marker success",0x20);
          log_to_file(tmp1,time_stamp);
        }
        else {
          gHistory_Result[gPattern_test_counter].eeprom_ok = false;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: write PT1 EEPROM marker fail\n","Single_Board_PT1_Plus_Software_Pattern_Test")
          ;
          builtin_strncpy(tmp1,"write PT1 EEPROM marker fail",0x1c);
          tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
        }
      }
    }
    PT1_plus_display_result_on_LCD();
    sleep((Local_Config_Information->Repair_Mode).Close_Power_Delay);
    _power_down(gChain);
    gPattern_test_counter = gPattern_test_counter + '\x01';
    sleep((Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
    puts("\n\n");
  }
  gStart_receive = false;
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    gStart_read_temp_from_pic = false;
  }
  gStart_heart_beat = false;
  _power_down(gChain);
  pthread_join(receive_id,(void **)0x0);
  pthread_join(read_temp_from_pic_id,(void **)0x0);
  pthread_join(pic_heart_beat_id,(void **)0x0);
  pthread_join(show_id,(void **)0x0);
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
  lcd_show(1,"Receive thread");
  lcd_show(2,"Creat  fail");
  lcd_show(3,"Start again");
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  Receive thread  creat fail, Start again\n",
         "Single_Board_PT1_Plus_Software_Pattern_Test");
  builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
  tmp1[0x28] = '\0';
  log_to_file(tmp1,time_stamp);
  return 0xc;
}

