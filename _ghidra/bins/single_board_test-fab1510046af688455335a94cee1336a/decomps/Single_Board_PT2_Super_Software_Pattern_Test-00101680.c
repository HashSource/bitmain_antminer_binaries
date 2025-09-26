
/* WARNING: Unknown calling convention */

int Single_Board_PT2_Super_Software_Pattern_Test(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  int8_t iVar3;
  char *pcVar4;
  int iVar5;
  char time_stamp [48];
  char tmp1 [2048];
  char lcd_data [16];
  uint8_t history_result_index;
  int _result_;
  int _result__1;
  int step;
  int test_result;
  _Bool temp;
  int32_t j;
  int k;
  int32_t temp_1;
  int board_comp;
  int32_t env_temp;
  int32_t i;
  int32_t thread_ret;
  
  thread_ret = 0x1e240;
  i = 0;
  j = 0;
  history_result_index = '\0';
  temp = true;
  env_temp = 0xffff;
  test_result = 0;
  gPattern_test_counter = '\0';
  bitmain_power_off();
  chain_reset_low(gChain);
  enable_power_calibration();
  sleep(1);
  while( true ) {
    if (gTest_loop <= gPattern_test_counter) {
      return 0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Start %s, gPattern_test_counter = %d\n",
           "Single_Board_PT2_Super_Software_Pattern_Test",
           "Single_Board_PT2_Super_Software_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d",
             "Single_Board_PT2_Super_Software_Pattern_Test",(uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    _Var2 = init_fpga();
    if (!_Var2) {
      return 0xc;
    }
    reset_global_variables();
    _Var2 = check_chain();
    if (!_Var2) {
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set Chain %d baud: %d\n","Single_Board_PT2_Super_Software_Pattern_Test",gChain,0x1a)
    ;
    snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
    log_to_file(tmp1,time_stamp);
    set_bt8d_chain(gChain,0x1a);
    reset_register_cache_value_to_default((uint8_t)gChain);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: test reset_register_cache_value_to_default end\n",
           "Single_Board_PT2_Super_Software_Pattern_Test");
    uVar1 = tmp1._44_4_;
    builtin_strncpy(tmp1,"test reset_register_cache_value_to_default end",0x2f);
    tmp1[0x2f] = SUB41(uVar1,3);
    log_to_file(tmp1,time_stamp);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      chain_reset_high(gChain);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chain reset high\n","Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"chain reset high",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
    }
    else {
      chain_reset_low(gChain);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chain reset low\n","Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"chain reset low",0x10);
      log_to_file(tmp1,time_stamp);
    }
    sleep(1);
    gStart_show_on_lcd = true;
    thread_ret = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5c8a1,
                                (void *)0x0);
    if (thread_ret != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: start thread PT2_show_status_func failed %d\n",
             "Single_Board_PT2_Super_Software_Pattern_Test",thread_ret);
      snprintf(tmp1,0x800,"start thread PT2_show_status_func failed %d",thread_ret);
      log_to_file(tmp1,time_stamp);
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
             "Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: test pthread_create  PT2_show_status_func end, counter:%d\n",
           "Single_Board_PT2_Super_Software_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x800,"test pthread_create  PT2_show_status_func end, counter:%d",
             (uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    gHistory_Result[gPattern_test_counter].eeprom_ok = true;
    if (((((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) &&
         ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false)) &&
        ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic == false)) &&
       ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false)) {
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
      lcd_show(1,"config error");
      lcd_show(2,"only support");
      lcd_show(3,"pic sensor");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Sensor_Info.Read_Temperature_From_Pic not enabled\n",
             "Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Sensor_Info.Read_Temperature_From_Pic not enable",0x30);
      tmp1[0x30] = 'd';
      tmp1[0x31] = '\0';
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false
           ) {
          gStart_read_temp = true;
          thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                      (__start_routine *)0x7036d,(void *)0x0);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: read_temperature_from_Switch Start\n",
                 "Single_Board_PT2_Super_Software_Pattern_Test");
          uVar1 = tmp1._32_4_;
          builtin_strncpy(tmp1,"read_temperature_from_Switch Start",0x23);
          tmp1[0x23] = SUB41(uVar1,3);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        gStart_read_temp = true;
        thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                    (__start_routine *)0x6f3e5,(void *)0x0);
      }
    }
    else {
      gStart_read_temp_from_pic = true;
      thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                  (__start_routine *)0x61679,(void *)0x0);
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
             "Single_Board_PT2_Super_Software_Pattern_Test");
      uVar1 = tmp1._36_4_;
      builtin_strncpy(tmp1,"Receive thread creat fail, Start again",0x27);
      tmp1[0x27] = SUB41(uVar1,3);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    _Var2 = wait_for_cool_down_x
                      ((Local_Config_Information->Test_Info).Temperature.Max_Wait_Cooling_Down_Time)
    ;
    if (!_Var2) {
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
      lcd_show(1,"cool fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: cool down hashboard failed\n","Single_Board_PT2_Super_Software_Pattern_Test");
      uVar1 = tmp1._24_4_;
      builtin_strncpy(tmp1,"cool down hashboard failed",0x1b);
      tmp1[0x1b] = SUB41(uVar1,3);
      log_to_file(tmp1,time_stamp);
      return 0xd;
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false
           ) {
          iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_switch,'\x02');
          env_temp = (int32_t)iVar3;
        }
      }
      else {
        iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                              sensor_local_temperature_from_ctrlboard,(uint8_t)gCtrlBoard_sensor_num
                             );
        env_temp = (int32_t)iVar3;
      }
    }
    else {
      iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic
                            ,(uint8_t)gPic_sensor_num);
      env_temp = (int32_t)iVar3;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ENV TEMP %d\n","Single_Board_PT2_Super_Software_Pattern_Test",env_temp);
    snprintf(tmp1,0x800,"ENV TEMP %d",env_temp);
    log_to_file(tmp1,time_stamp);
    if (0x23 < env_temp) {
      gStart_read_temp_from_pic = false;
      gStart_heart_beat = false;
      gStart_read_temp = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ENV temperature too high\n","Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"ENV temperature too high",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      _power_down(gChain);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"temperature high");
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"Now %d C",env_temp);
      lcd_show(2,lcd_data);
      lcd_show(3,"cool ENV");
      return 0xd;
    }
    if (env_temp < 0x1e) {
      gStart_read_temp_from_pic = false;
      gStart_heart_beat = false;
      gStart_read_temp = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ENV temperature too low\n","Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"ENV temperature too low",0x18);
      log_to_file(tmp1,time_stamp);
      _power_down(gChain);
      pthread_join(read_temp_from_pic_id,(void **)0x0);
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
        pthread_join(pic_heart_beat_id,(void **)0x0);
      }
      pthread_join(show_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"temperature low");
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"Now %d C",env_temp);
      lcd_show(2,lcd_data);
      lcd_show(3,"hot ENV");
      return 0xd;
    }
    gVol_comp = get_vol_comp(env_temp);
    pcVar4 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"Hyd");
    if ((pcVar4 != (char *)0x0) ||
       (pcVar4 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB"),
       pcVar4 != (char *)0x0)) {
      board_comp = 0;
      pcVar4 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56601");
      if ((pcVar4 != (char *)0x0) ||
         (pcVar4 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56601"),
         pcVar4 != (char *)0x0)) {
        board_comp = 0;
      }
      gVol_comp = gVol_comp + board_comp;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: freq gVol_comp:%d\n","Single_Board_PT2_Super_Software_Pattern_Test",gVol_comp);
      snprintf(tmp1,0x800,"freq gVol_comp:%d",gVol_comp);
      log_to_file(tmp1,time_stamp);
    }
    _Var2 = APW_power_on(g_power_version,
                         gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
    if (!_Var2) break;
    _Var2 = pic_power_on_hashboard(gChain);
    if (!_Var2) {
      gStart_heart_beat = false;
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
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: set work fan speed %d\n","Single_Board_PT2_Super_Software_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    snprintf(tmp1,0x800,"set work fan speed %d",
             (Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_1();
    gStart_receive = true;
    thread_ret = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8ca5,
                                (void *)0x0);
    if (thread_ret != 0) {
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
      printf("%s:  Receive thread  creat fail, Start again\n",
             "Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
      tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    usleep(700000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(100000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(10000);
    set_chain_ticketmask((uint8_t)gChain,0xffff);
    uart_flush_rx(gChain);
    usleep(50000);
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
        printf("%s: get too much error asic address\n",
               "Single_Board_PT2_Super_Software_Pattern_Test");
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Super_Software_Pattern_Test",gAsic_num);
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
    printf("%s: First: find %d ASIC\n\n","Single_Board_PT2_Super_Software_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"First: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_2();
    adc_get_domain_voltage((uint8_t)gChain,0,'\x03');
    set_asic_register_stage_3();
    usleep(1000000);
    set_chain_chip_nonce_offset((uint8_t)gChain,true,0);
    temp_1 = get_ctrlboard_temp_min();
    k = 0;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: wait board temp come to %d\n","Single_Board_PT2_Super_Software_Pattern_Test",
           (Local_Config_Information->Hash_Board).Wait_Board_Temp);
    snprintf(tmp1,0x800,"wait board temp come to %d",
             (Local_Config_Information->Hash_Board).Wait_Board_Temp);
    log_to_file(tmp1,time_stamp);
    if ((Local_Config_Information->Hash_Board).Wait_Board_Temp != 0) {
      while ((uint)temp_1 < (Local_Config_Information->Hash_Board).Wait_Board_Temp) {
        temp_1 = get_ctrlboard_temp_min();
        sleep(1);
        k = k + 1;
        if (k % 5 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: get curr board min temp:%d, loop time %ds\n",
                 "Single_Board_PT2_Super_Software_Pattern_Test",temp_1,k);
          snprintf(tmp1,0x800,"get curr board min temp:%d, loop time %ds",temp_1,k);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
    iVar5 = strcmp((Local_Config_Information->Hash_Board).Board_Name,"NBT2006-36");
    if (iVar5 == 0) {
      _Var2 = set_dac_voltage_step_by_step
                        ((Local_Config_Information->Hash_Board).Board_Name,(uint8_t)gChain,
                         gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
                         gHistory_Result[gPattern_test_counter].voltage,'\x05');
      if (!_Var2) {
        gStart_read_temp_from_asic = false;
        gStart_receive = false;
        gStart_read_temp_from_pic = false;
        gStart_heart_beat = false;
        gStart_read_temp = false;
        _power_down(gChain);
        pthread_join(receive_id,(void **)0x0);
        pthread_join(read_temp_from_pic_id,(void **)0x0);
        pthread_join(read_temp_from_asic_id,(void **)0x0);
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
          pthread_join(pic_heart_beat_id,(void **)0x0);
        }
        pthread_join(show_id,(void **)0x0);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: set dac voltage step by step fail\n",
               "Single_Board_PT2_Super_Software_Pattern_Test");
        uVar1 = tmp1._32_4_;
        builtin_strncpy(tmp1,"set dac voltage step by step fail",0x22);
        tmp1._34_2_ = SUB42(uVar1,2);
        log_to_file(tmp1,time_stamp);
        return 0xc;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: gVol_comp = %d mv\n","Single_Board_PT2_Super_Software_Pattern_Test",gVol_comp * 10
            );
      snprintf(tmp1,0x800,"gVol_comp = %d mv",gVol_comp * 10);
      log_to_file(tmp1,time_stamp);
      if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
        set_pattern_test_voltage_by_step
                  (gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
                   gVol_comp + gHistory_Result[gPattern_test_counter].voltage,'\x05');
      }
      else {
        step = __aeabi_uidiv(gHistory_Result[gPattern_test_counter].pre_open_core_voltage -
                             (gVol_comp + gHistory_Result[gPattern_test_counter].voltage),
                             (Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
        set_pattern_test_voltage_by_step
                  (gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
                   gVol_comp + gHistory_Result[gPattern_test_counter].voltage,(uint8_t)step);
      }
    }
    adc_get_domain_voltage((uint8_t)gChain,0,'\x03');
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       (Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
      gStart_read_temp_from_asic = false;
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
        printf("%s: get too much error asic address\n",
               "Single_Board_PT2_Super_Software_Pattern_Test");
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
        printf("%s: Only find %d ASIC\n","Single_Board_PT2_Super_Software_Pattern_Test",gAsic_num);
        snprintf(tmp1,0x800,"Only find %d ASIC",gAsic_num);
        log_to_file(tmp1,time_stamp);
        print_find_asic_result();
      }
      if (gAsic_num != 0) {
        return gAsic_num << 8 | 3;
      }
      return 2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Second: find %d ASIC\n\n","Single_Board_PT2_Super_Software_Pattern_Test",gAsic_num);
    snprintf(tmp1,0x800,"Second: find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    set_chain_core_nonce_overflow_control((uint8_t)gChain,false);
    set_chain_rosc_pad_disable((uint8_t)gChain);
    if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 4) {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8fc9,
                                  (void *)0x0);
    }
    else if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xf9c79,
                                  (void *)0x0);
    }
    else {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0x106cd1,
                                  (void *)0x0);
    }
    if (thread_ret != 0) {
      pthread_cancel(send_id);
      gStart_read_temp_from_asic = false;
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
      printf("%s: Send thread creat fail, Start again\n",
             "Single_Board_PT2_Super_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Send thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    thread_ret = pthread_join(send_id,(void **)0x0);
    get_register_value(0,0xe,true,(Local_Config_Information->Hash_Board).Asic_Type);
    adc_get_domain_voltage((uint8_t)gChain,0,'\x03');
    gStart_receive = false;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Stop receive thread\n","Single_Board_PT2_Super_Software_Pattern_Test");
    builtin_strncpy(tmp1,"Stop receive thread",0x14);
    log_to_file(tmp1,time_stamp);
    thread_ret = pthread_join(receive_id,(void **)0x0);
    gStart_read_temp_from_pic = false;
    gStart_read_temp_from_asic = false;
    gStart_heart_beat = false;
    gStart_read_temp = false;
    pthread_join(read_temp_from_pic_id,(void **)0x0);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      pthread_join(pic_heart_beat_id,(void **)0x0);
    }
    if (gFind_dummy_data == true) {
      for (i = 0; (uint)i < gPic_sensor_num; i = i + 1) {
        temp_1 = temp_1 & (uint)gHistory_Result[gPattern_test_counter].pic_sensor_OK[i];
      }
      if (temp_1 == 1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: All PIC sensor OK\n","Single_Board_PT2_Super_Software_Pattern_Test");
        builtin_strncpy(tmp1,"All PIC sensor O",0x10);
        tmp1[0x10] = 'K';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
        gHistory_Result[gPattern_test_counter].pic_sensor_all_OK = true;
      }
    }
    else {
      get_result_super_software_pattern();
    }
    _power_down(gChain);
    pthread_join(show_id,(void **)0x0);
    if (gHistory_Result[gPattern_test_counter].test_standard == '\0') {
      _result_ = do_PT2_summary_work(gPattern_test_counter);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: All test done. STRICT_STANDARD: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Super_Software_Pattern_Test",(uint)gPattern_test_counter);
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
             "Single_Board_PT2_Super_Software_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x800,"All test done. Last test loop: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      return _result__1;
    }
    gPattern_test_counter = gPattern_test_counter + '\x01';
    puts("\n\n");
  }
  gStart_show_on_lcd = false;
  pwm_set(gFan,0);
  pthread_join(show_id,(void **)0x0);
  return 0xc;
}

