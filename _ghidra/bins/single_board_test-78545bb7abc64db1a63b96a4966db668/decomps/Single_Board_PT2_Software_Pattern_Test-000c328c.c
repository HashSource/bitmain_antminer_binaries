
/* WARNING: Unknown calling convention */

int Single_Board_PT2_Software_Pattern_Test(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  int8_t iVar3;
  int32_t iVar4;
  int32_t iVar5;
  int iVar6;
  char time_stamp [48];
  char tmp1 [256];
  char err_str2 [16];
  char err_str1 [16];
  char lcd_data [16];
  uint8_t history_result_index;
  int _result_;
  int _result__1;
  int step;
  uint32_t target_vol;
  int first_find_asics;
  int32_t j;
  int32_t i;
  int temp_fix;
  int i_1;
  int second_find_asics;
  _Bool set_vol_ret;
  int heat_time;
  int cool_time;
  int bad_asic_index;
  int32_t env_temp;
  int32_t thread_ret;
  
  thread_ret = 0x1e240;
  i = 0;
  j = 0;
  history_result_index = '\0';
  env_temp = get_env_temp();
  gPattern_test_counter = '\0';
  bad_asic_index = -1;
  lcd_common_show("Check sensor","waiting...",(char *)0x0);
  bitmain_power_off();
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Freq_Flex:%d\n","Single_Board_PT2_Software_Pattern_Test",
         (Local_Config_Information->Test_Info).Freq_Flex);
  snprintf(tmp1,0x100,"Freq_Flex:%d",(Local_Config_Information->Test_Info).Freq_Flex);
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != false) {
    init_spuer_pattern();
  }
  _power_down(gChain,false);
  do {
    if (gTest_loop <= gPattern_test_counter) {
      return 0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Start %s, gPattern_test_counter = %d\n","Single_Board_PT2_Software_Pattern_Test",
           "Single_Board_PT2_Software_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x100,"Start %s, gPattern_test_counter = %d",
             "Single_Board_PT2_Software_Pattern_Test",(uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    bad_asic_index = -1;
    _Var2 = init_fpga();
    if (!_Var2) {
      return 0x800;
    }
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    lcd_common_show("Context init","waiting...",(char *)0x0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set fan speed as %d\n","Single_Board_PT2_Software_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x100,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var2 = check_chain();
    if (!_Var2) {
      pwm_set(gFan,100);
      return 0x800;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set Chain %d baud: %d\n","Single_Board_PT2_Software_Pattern_Test",gChain,0x1a);
    snprintf(tmp1,0x100,"Set Chain %d baud: %d",gChain,0x1a);
    log_to_file(tmp1,time_stamp);
    set_bt8d_chain(gChain,0x1a);
    reset_register_cache_value_to_default((uint8_t)gChain);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : test reset_register_cache_value_to_default end\n",
           "Single_Board_PT2_Software_Pattern_Test");
    builtin_strncpy(tmp1,"test reset_register_cache_value_to_default e",0x2c);
    tmp1[0x2c] = 'n';
    tmp1[0x2d] = 'd';
    tmp1[0x2e] = '\0';
    log_to_file(tmp1,time_stamp);
    chain_reset_low(gChain);
    sleep(1);
    gStart_show_on_lcd = true;
    thread_ret = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x29135,
                                (void *)0x0);
    if (thread_ret != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : start thread PT2_show_status_func failed %d\n",
             "Single_Board_PT2_Software_Pattern_Test",thread_ret);
      snprintf(tmp1,0x100,"start thread PT2_show_status_func failed %d",thread_ret);
      log_to_file(tmp1,time_stamp);
      save_exit();
      return 0x800;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : test pthread_create  PT2_show_status_func end, counter:%d\n",
           "Single_Board_PT2_Software_Pattern_Test",(uint)gPattern_test_counter);
    snprintf(tmp1,0x100,"test pthread_create  PT2_show_status_func end, counter:%d",
             (uint)gPattern_test_counter);
    log_to_file(tmp1,time_stamp);
    gHistory_Result[gPattern_test_counter].eeprom_ok = true;
    gStart_read_temp = true;
    thread_ret = pthread_create(&read_temp_from_pic_id,(pthread_attr_t *)0x0,
                                (__start_routine *)0x39995,(void *)0x0);
    if (thread_ret != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Receive thread creat fail, Start again\n",
             "Single_Board_PT2_Software_Pattern_Test");
      uVar1 = tmp1._36_4_;
      builtin_strncpy(tmp1,"Receive thread creat fail, Start again",0x27);
      tmp1[0x27] = SUB41(uVar1,3);
      log_to_file(tmp1,time_stamp);
      save_exit();
      return 0x800;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : wait for reading temp from ctrl board.\n","Single_Board_PT2_Software_Pattern_Test")
    ;
    uVar1 = tmp1._36_4_;
    builtin_strncpy(tmp1,"wait for reading temp from ctrl board.",0x27);
    tmp1[0x27] = SUB41(uVar1,3);
    log_to_file(tmp1,time_stamp);
    while (gTemp_first_read_flag != true) {
      sleep(1);
    }
    get_all_fan_speed();
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    iVar4 = get_ctrlboard_temp_min();
    iVar5 = get_ctrlboard_temp_max();
    printf("%s : env temp,min temp:%d,max temp:%d\n","Single_Board_PT2_Software_Pattern_Test",iVar4,
           iVar5);
    iVar4 = get_ctrlboard_temp_min();
    iVar5 = get_ctrlboard_temp_max();
    snprintf(tmp1,0x100,"env temp,min temp:%d,max temp:%d",iVar4,iVar5);
    log_to_file(tmp1,time_stamp);
    gCooling = true;
    cool_time = 0;
    pwm_set(gFan,100);
    while (iVar4 = get_ctrlboard_temp_max(), 0x39 < iVar4) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar4 = get_ctrlboard_temp_max();
      printf("%s : wait temp down,max:%d,target:%d\n","Single_Board_PT2_Software_Pattern_Test",iVar4
             ,0x39);
      iVar4 = get_ctrlboard_temp_max();
      snprintf(tmp1,0x100,"wait temp down,max:%d,target:%d",iVar4,0x39);
      log_to_file(tmp1,time_stamp);
      sleep(1);
      cool_time = cool_time + 1;
      if (300 < cool_time) {
        lcd_common_show("Cooldown","Hashboard","Failed");
        return 0x800;
      }
    }
    if (env_temp == 0xffff) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar4 = get_ctrlboard_temp_min();
      iVar5 = get_ctrlboard_temp_max();
      printf("%s : cur env,min temp:%d,max temp:%d\n","Single_Board_PT2_Software_Pattern_Test",iVar4
             ,iVar5);
      iVar4 = get_ctrlboard_temp_min();
      iVar5 = get_ctrlboard_temp_max();
      snprintf(tmp1,0x100,"cur env,min temp:%d,max temp:%d",iVar4,iVar5);
      log_to_file(tmp1,time_stamp);
      pwm_set(gFan,100);
      _Var2 = wait_for_cool_down_x
                        ((Local_Config_Information->Test_Info).Temperature.
                         Max_Wait_Cooling_Down_Time);
      if (!_Var2) {
        _power_down(gChain,true);
        clear_all_thread();
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"cool fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Can\'t cool down hashboard fail\n","Single_Board_PT2_Software_Pattern_Test");
        uVar1 = tmp1._28_4_;
        builtin_strncpy(tmp1,"Can\'t cool down hashboard fail",0x1f);
        tmp1[0x1f] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
        return 0x800;
      }
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
            false) {
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch !=
              false) {
            iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,
                                  (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                                  sensor_num);
            env_temp = (int32_t)iVar3;
          }
        }
        else {
          iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard,
                                (uint8_t)gCtrlBoard_sensor_num);
          env_temp = (int32_t)iVar3;
        }
      }
      else {
        iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                              sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num);
        env_temp = (int32_t)iVar3;
      }
      set_env_temp(env_temp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ENV TEMP %d\n","Single_Board_PT2_Software_Pattern_Test",env_temp);
    snprintf(tmp1,0x100,"ENV TEMP %d",env_temp);
    log_to_file(tmp1,time_stamp);
    gCooling = false;
    if (0x1e < env_temp) {
      _power_down(gChain,true);
      clear_all_thread();
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"temperature high");
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"Now %d C",env_temp);
      lcd_show(2,lcd_data);
      lcd_show(3,"cool ENV");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ENV temperature too high\n","Single_Board_PT2_Software_Pattern_Test");
      builtin_strncpy(tmp1,"ENV temperature too high",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0x800;
    }
    gVol_comp = get_vol_comp(env_temp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : gVol_comp:%d,env_temp:%d\n","Single_Board_PT2_Software_Pattern_Test",gVol_comp,
           env_temp);
    snprintf(tmp1,0x100,"gVol_comp:%d,env_temp:%d",gVol_comp,env_temp);
    log_to_file(tmp1,time_stamp);
    pwm_set(gFan,100);
    lcd_common_show("Power on","waiting...",(char *)0x0);
    chain_reset_low(gChain);
    usleep(300000);
    _Var2 = APW_power_on(gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
    if (!_Var2) {
      err_exit("power err");
      return 0x800;
    }
    usleep(200000);
    chain_reset_high(gChain);
    usleep(700000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(100000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(5000);
    set_asic_register_stage_1();
    set_chain_ticketmask((uint8_t)gChain,0xffff);
    uart_flush_rx(gChain);
    usleep(50000);
    gStart_receive = true;
    thread_ret = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xbfe2d,
                                (void *)0x0);
    if (thread_ret != 0) {
      _power_down(gChain,false);
      clear_all_thread();
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Receive thread");
      lcd_show(2,"Creat  fail");
      lcd_show(3,"Start again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s :  Receive thread  creat fail, Start again,ret:%d\n",
             "Single_Board_PT2_Software_Pattern_Test",thread_ret);
      snprintf(tmp1,0x100," Receive thread  creat fail, Start again,ret:%d",thread_ret);
      log_to_file(tmp1,time_stamp);
      return 0x800;
    }
    get_all_fan_speed();
    first_find_asics = 0;
    usleep(200000);
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    first_find_asics = gAsic_num;
    if (((gAsic_num != (Local_Config_Information->Hash_Board).Asic_Num) ||
        (gFind_dummy_data != false)) &&
       (get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type),
       gAsic_num != (Local_Config_Information->Hash_Board).Asic_Num)) {
      print_find_asic_result();
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : total %d asics,only find %d\n","Single_Board_PT2_Software_Pattern_Test",
             (Local_Config_Information->Hash_Board).Asic_Num,gAsic_num);
      snprintf(tmp1,0x100,"total %d asics,only find %d",
               (Local_Config_Information->Hash_Board).Asic_Num,gAsic_num);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : gFind_dummy_data:%d\n","Single_Board_PT2_Software_Pattern_Test",
             (uint)gFind_dummy_data);
      snprintf(tmp1,0x100,"gFind_dummy_data:%d",(uint)gFind_dummy_data);
      log_to_file(tmp1,time_stamp);
      _power_down(gChain,true);
      clear_all_thread();
      if ((Local_Config_Information->Hash_Board).Asic_Num < gAsic_num) {
        lcd_common_show("get too much","error asic","address");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : asic num outof %d !!!\n","Single_Board_PT2_Software_Pattern_Test",
               (Local_Config_Information->Hash_Board).Asic_Num);
        snprintf(tmp1,0x100,"asic num outof %d !!!",(Local_Config_Information->Hash_Board).Asic_Num)
        ;
        log_to_file(tmp1,time_stamp);
      }
      else {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"%2d",first_find_asics);
        lcd_common_show("Only find",lcd_data,"ASIC");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : First Only find %d ASIC\n","Single_Board_PT2_Software_Pattern_Test",
               first_find_asics);
        snprintf(tmp1,0x100,"First Only find %d ASIC",first_find_asics);
        log_to_file(tmp1,time_stamp);
      }
      if (first_find_asics != 0) {
        return first_find_asics << 8 | 4;
      }
      return 2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : First: find %d ASIC\n\n","Single_Board_PT2_Software_Pattern_Test",first_find_asics)
    ;
    snprintf(tmp1,0x100,"First: find %d ASIC\n",first_find_asics);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_2();
    do_core_reset();
    usleep(1000000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : gAddress_interval:%d\n","Single_Board_PT2_Software_Pattern_Test",gAddress_interval)
    ;
    snprintf(tmp1,0x100,"gAddress_interval:%d",gAddress_interval);
    log_to_file(tmp1,time_stamp);
    set_asic_register_stage_3();
    usleep(1000000);
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern != false) {
      set_chain_chip_nonce_offset((uint8_t)gChain,true,0);
    }
    usleep(200000);
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : find asic after set freq,asics:%d\n","Single_Board_PT2_Software_Pattern_Test",
           gAsic_num);
    snprintf(tmp1,0x100,"find asic after set freq,asics:%d",gAsic_num);
    log_to_file(tmp1,time_stamp);
    gHeating = true;
    heat_time = 0;
    pwm_set(gFan,0x14);
    do {
      iVar4 = get_ctrlboard_temp_max();
      if (0x33 < iVar4) goto LAB_000c4616;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar4 = get_ctrlboard_temp_max();
      printf("%s : wait temp,max:%d,target:%d\n","Single_Board_PT2_Software_Pattern_Test",iVar4,0x39
            );
      iVar4 = get_ctrlboard_temp_max();
      snprintf(tmp1,0x100,"wait temp,max:%d,target:%d",iVar4,0x39);
      log_to_file(tmp1,time_stamp);
      sleep(1);
      get_all_fan_speed();
      heat_time = heat_time + 1;
    } while (heat_time < 0x12d);
    iVar4 = get_ctrlboard_temp_max();
    if (iVar4 < 0x35) {
      gStart_read_temp_from_pic = false;
      gStart_heart_beat = false;
      gStart_read_temp = false;
      gStart_show_on_lcd = false;
      clear_all_thread();
      _power_down(gChain,true);
      iVar4 = get_ctrlboard_temp_max();
      snprintf(err_str1,0x10,"Max %d",iVar4);
      snprintf(err_str2,0x10,"Need %d ~ %d",0x35,0x39);
      lcd_common_show("Heating Board",err_str1,err_str2);
      return 0x800;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    iVar4 = get_ctrlboard_temp_max();
    printf("%s : warning test max temp:%d,target:%d\n","Single_Board_PT2_Software_Pattern_Test",
           iVar4,0x39);
    iVar4 = get_ctrlboard_temp_max();
    snprintf(tmp1,0x100,"warning test max temp:%d,target:%d",iVar4,0x39);
    log_to_file(tmp1,time_stamp);
LAB_000c4616:
    gHeating = false;
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : set work fan speed %d\n","Single_Board_PT2_Software_Pattern_Test",
           (Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    snprintf(tmp1,0x100,"set work fan speed %d",
             (Local_Config_Information->Test_Info).Fan.Work_Fan_Speed);
    log_to_file(tmp1,time_stamp);
    lcd_common_show("Set Voltage","waiting",(char *)0x0);
    target_vol = gVol_comp + gHistory_Result[gPattern_test_counter].voltage;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Target vol after compensate:%d\n","Single_Board_PT2_Software_Pattern_Test",
           target_vol);
    snprintf(tmp1,0x100,"Target vol after compensate:%d",target_vol);
    log_to_file(tmp1,time_stamp);
    set_vol_ret = false;
    if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
      set_vol_ret = set_pattern_test_voltage_by_step
                              (gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
                               target_vol,'\x05');
    }
    else {
      step = __aeabi_uidiv(gHistory_Result[gPattern_test_counter].pre_open_core_voltage - target_vol
                           ,(Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
      set_vol_ret = set_pattern_test_voltage_by_step
                              (gHistory_Result[gPattern_test_counter].pre_open_core_voltage,
                               target_vol,(uint8_t)step);
    }
    if (set_vol_ret != true) {
      err_exit("power err");
    }
    second_find_asics = 0;
    get_all_fan_speed();
    usleep(200000);
    for (i_1 = 0; i_1 < 3; i_1 = i_1 + 1) {
      get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
      second_find_asics = gAsic_num;
      if ((gAsic_num == (Local_Config_Information->Hash_Board).Asic_Num) &&
         (gFind_dummy_data == false)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : find asic succ,index:%d,asics:%d\n","Single_Board_PT2_Software_Pattern_Test",
               i_1,gAsic_num);
        snprintf(tmp1,0x100,"find asic succ,index:%d,asics:%d",i_1,gAsic_num);
        log_to_file(tmp1,time_stamp);
        break;
      }
      usleep(100000);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : find asic err,index:%d,asics:%d\n","Single_Board_PT2_Software_Pattern_Test",i_1,
             gAsic_num);
      snprintf(tmp1,0x100,"find asic err,index:%d,asics:%d",i_1,gAsic_num);
      log_to_file(tmp1,time_stamp);
    }
    if ((gAsic_num != (Local_Config_Information->Hash_Board).Asic_Num) ||
       (gFind_dummy_data != false)) {
      bad_asic_index = -1;
      if ((Local_Config_Information->Test_Info).Find_Stupid_Asic != false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : second find asic:%d,start find_bad_ri_asic\n",
               "Single_Board_PT2_Software_Pattern_Test",second_find_asics);
        snprintf(tmp1,0x100,"second find asic:%d,start find_bad_ri_asic",second_find_asics);
        log_to_file(tmp1,time_stamp);
        bad_asic_index = find_bad_ri_asic();
      }
      gStart_receive = false;
      _power_down(gChain,true);
      clear_all_thread();
      if (bad_asic_index == -1) {
        if ((Local_Config_Information->Hash_Board).Asic_Num < gAsic_num) {
          lcd_common_show("get too much","error asic","address");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : ERROR:error asic num outof %d !!!\n","Single_Board_PT2_Software_Pattern_Test"
                 ,(Local_Config_Information->Hash_Board).Asic_Num);
          snprintf(tmp1,0x100,"ERROR:error asic num outof %d !!!",
                   (Local_Config_Information->Hash_Board).Asic_Num);
          log_to_file(tmp1,time_stamp);
        }
        else {
          memset(lcd_data,0,0x10);
          sprintf(lcd_data,"%2d",second_find_asics);
          lcd_common_show("Only find",lcd_data,"ASIC");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Second Only find %d ASIC\n","Single_Board_PT2_Software_Pattern_Test",
                 second_find_asics);
          snprintf(tmp1,0x100,"Second Only find %d ASIC",second_find_asics);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"%2d",bad_asic_index);
        lcd_common_show("Bad asic","index(from 0)",lcd_data);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Bad asic index(from 0) %d\n","Single_Board_PT2_Software_Pattern_Test",
               bad_asic_index);
        snprintf(tmp1,0x100,"Bad asic index(from 0) %d",bad_asic_index);
        log_to_file(tmp1,time_stamp);
      }
      if (second_find_asics != 0) {
        return second_find_asics << 8 | 4;
      }
      return 2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Second: find %d ASIC\n\n","Single_Board_PT2_Software_Pattern_Test",
           second_find_asics);
    snprintf(tmp1,0x100,"Second: find %d ASIC\n",second_find_asics);
    log_to_file(tmp1,time_stamp);
    set_chain_core_nonce_overflow_control((uint8_t)gChain,false);
    set_chain_rosc_pad_disable((uint8_t)gChain);
    usleep(200000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : wait temp into target.\n","Single_Board_PT2_Software_Pattern_Test");
    uVar1 = tmp1._20_4_;
    builtin_strncpy(tmp1,"wait temp into target.",0x17);
    tmp1[0x17] = SUB41(uVar1,3);
    log_to_file(tmp1,time_stamp);
    temp_fix = 0x3c;
    while ((temp_fix != 0 && (iVar4 = get_ctrlboard_temp_max(), iVar4 != 0x39))) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar4 = get_ctrlboard_temp_max();
      printf("%s : wait temp come to %d,now:%d,time:%d\n","Single_Board_PT2_Software_Pattern_Test",
             0x39,iVar4,temp_fix);
      iVar4 = get_ctrlboard_temp_max();
      snprintf(tmp1,0x100,"wait temp come to %d,now:%d,time:%d",0x39,iVar4,temp_fix);
      log_to_file(tmp1,time_stamp);
      temp_fix = temp_fix + -1;
      get_all_fan_speed();
      sleep(1);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Nonce test start.\n","Single_Board_PT2_Software_Pattern_Test");
    builtin_strncpy(tmp1,"Nonce test start",0x10);
    tmp1[0x10] = '.';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
    gNoncing = true;
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xc013d,
                                  (void *)0x0);
    }
    else {
      thread_ret = pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0xc2e71,
                                  (void *)0x0);
    }
    if (thread_ret != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Send thread creat fail, Start again\n","Single_Board_PT2_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Send thread creat fail, Start again",0x24);
      log_to_file(tmp1,time_stamp);
      save_exit();
      return 0x800;
    }
    if (send_id != 0) {
      pthread_join(send_id,(void **)0x0);
    }
    receive_id = 0;
    read_temp_from_asic_id = 0;
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern != false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : start receive thread\n","Single_Board_PT2_Software_Pattern_Test");
      builtin_strncpy(tmp1,"start receive thread",0x14);
      tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      get_register_value(0,0xe,true,(Local_Config_Information->Hash_Board).Asic_Type);
      gStart_receive = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Stop receive thread\n","Single_Board_PT2_Software_Pattern_Test");
      builtin_strncpy(tmp1,"Stop receive thread",0x14);
      log_to_file(tmp1,time_stamp);
    }
    if (receive_id != 0) {
      pthread_join(receive_id,(void **)0x0);
    }
    send_id = 0;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : send/receive pattern over.\n","Single_Board_PT2_Software_Pattern_Test");
    uVar1 = tmp1._24_4_;
    builtin_strncpy(tmp1,"send/receive pattern over.",0x1b);
    tmp1[0x1b] = SUB41(uVar1,3);
    log_to_file(tmp1,time_stamp);
    sleep(1);
    _power_down(gChain,true);
    clear_all_thread();
    if (gFind_dummy_data != true) {
      if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
        get_result();
      }
      else {
        get_result_super_software_pattern();
      }
    }
    putchar(10);
    if ((gHistory_Result[gPattern_test_counter].asic_ok == false) ||
       (gHistory_Result[gPattern_test_counter].nonce_rate_ok == false)) {
      if (gTest_loop - 1 <= (uint)gPattern_test_counter) {
        putchar(10);
        puts("<<--Log Anchor Start-->><<--Log Anchor Err-->>");
        printf("%d\n",0xff);
        puts("<<--Log Anchor End-->>");
      }
    }
    else {
      putchar(10);
      puts("<<--Log Anchor Start-->><<--Log Anchor ok-->>");
      printf("%d\n",gHistory_Result[gPattern_test_counter].level);
      printf("%d\n",gHistory_Result[gPattern_test_counter].voltage);
      printf("%d\n",gHistory_Result[gPattern_test_counter].frequence);
      puts("<<--Log Anchor End-->>");
    }
    if (gHistory_Result[gPattern_test_counter].test_standard == '\0') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : All base PT2 test done. STRICT_STANDARD: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Software_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x100,"All base PT2 test done. STRICT_STANDARD: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      iVar6 = do_PT2_summary_work(gPattern_test_counter);
      return iVar6;
    }
    if (gTest_loop - 1 <= (uint)gPattern_test_counter) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : All base PT2 test done. Last test loop: gPattern_test_counter: %d\n\n",
             "Single_Board_PT2_Software_Pattern_Test",(uint)gPattern_test_counter);
      snprintf(tmp1,0x100,"All base PT2 test done. Last test loop: gPattern_test_counter: %d\n",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      find_submit_history_result_index(&history_result_index);
      iVar6 = do_PT2_summary_work(history_result_index);
      return iVar6;
    }
    gPattern_test_counter = gPattern_test_counter + '\x01';
    puts("prepare next test...\n\n");
    pwm_set(gFan,100);
  } while( true );
}

