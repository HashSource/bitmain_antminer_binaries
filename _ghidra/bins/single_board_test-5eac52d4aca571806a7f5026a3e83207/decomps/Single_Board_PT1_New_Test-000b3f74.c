
/* WARNING: Unknown calling convention */

int Single_Board_PT1_New_Test(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  char time_stamp [48];
  char tmp1 [256];
  pthread_t m_board_protect_id;
  int sensor_id;
  eeprom_v1 eeprom_tmp;
  uint32_t asic_num_record [2];
  _Bool res;
  int32_t thread_ret;
  int test_result;
  _Bool temp;
  
  temp = false;
  asic_num_record[0] = 0;
  asic_num_record[1] = 0;
  sensor_id = 0;
  gPattern_test_counter = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s, gPattern_test_counter = %d\n","Single_Board_PT1_New_Test",
         "Single_Board_PT1_New_Test",(uint)gPattern_test_counter);
  snprintf(tmp1,0x100,"Start %s, gPattern_test_counter = %d","Single_Board_PT1_New_Test",
           (uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  _Var2 = temp_sensor_check();
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : first sensor check res:%d\n","Single_Board_PT1_New_Test",(uint)_Var2);
  snprintf(tmp1,0x100,"first sensor check res:%d",(uint)_Var2);
  log_to_file(tmp1,time_stamp);
  if (!_Var2) {
    lcd_common_show("Sensor Check","Err",(char *)0x0);
    bitmain_power_off();
    return 0xc;
  }
  _Var2 = init_fpga();
  if (!_Var2) {
    return 0xc;
  }
  fan_turn_on(BOTH_SIZE);
  pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set fan speed as %d\n","Single_Board_PT1_New_Test",
         (Local_Config_Information->Test_Info).Fan.Fan_Speed);
  snprintf(tmp1,0x100,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
  log_to_file(tmp1,time_stamp);
  reset_global_variables();
  _Var2 = check_chain();
  if (!_Var2) {
    pwm_set(gFan,100);
    return 0xc;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set Chain %d baud: %d\n","Single_Board_PT1_New_Test",gChain,0x1a);
  snprintf(tmp1,0x100,"Set Chain %d baud: %d",gChain,0x1a);
  log_to_file(tmp1,time_stamp);
  set_bt8d_chain(gChain,0x1a);
  reset_register_cache_value_to_default((uint8_t)gChain);
  gStart_show_on_lcd = true;
  iVar3 = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x270bd,(void *)0x0);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chech EEPROM start\n","Single_Board_PT1_New_Test");
  builtin_strncpy(tmp1,"chech EEPROM sta",0x10);
  tmp1[0x10] = 'r';
  tmp1[0x11] = 't';
  tmp1[0x12] = '\0';
  log_to_file(tmp1,time_stamp);
  _Var2 = Check_EEPROM_compat(gEEPROM_length);
  if (_Var2) {
    gHistory_Result[gPattern_test_counter].eeprom_ok = true;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chech EEPROM success\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"chech EEPROM success",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : check EEPROM fail\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"check EEPROM fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  chain_reset_low(gChain);
  usleep(200000);
  _Var2 = APW_power_on(gHistory_Result[gPattern_test_counter].pre_open_core_voltage - 100);
  if (!_Var2) {
    err_exit("power err");
    return 0xc;
  }
  _Var2 = read_temperature_from_CtrlBoard_N_times('\x03',&sensor_id);
  if (!_Var2) {
    memset(tmp1,0,0x40);
    sprintf(tmp1,"sensor[%d] err",sensor_id);
    err_exit(tmp1);
    return 0xc;
  }
  m_board_protect_id = 0;
  iVar3 = pthread_create(&m_board_protect_id,(pthread_attr_t *)0x0,(__start_routine *)0xb3e31,
                         (void *)0x0);
  if (iVar3 != 0) {
    err_exit("thread err");
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : board protect start...\n","Single_Board_PT1_New_Test");
  uVar1 = tmp1._20_4_;
  builtin_strncpy(tmp1,"board protect start...",0x17);
  tmp1[0x17] = SUB41(uVar1,3);
  log_to_file(tmp1,time_stamp);
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
  usleep(100000);
  gStart_receive = true;
  iVar3 = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xb3331,(void *)0x0);
  if (iVar3 != 0) {
    gStart_heart_beat = false;
    gStart_receive = false;
    _power_down(gChain,false);
    if (show_id != 0) {
      pthread_join(show_id,(void **)0x0);
    }
    if (pic_heart_beat_id != 0) {
      pthread_join(pic_heart_beat_id,(void **)0x0);
    }
    pthread_join(receive_id,(void **)0x0);
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Receive thread");
    lcd_show(2,"Creat  fail");
    lcd_show(3,"Start again");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s :  Receive thread  creat fail, Start again\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
    tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    return 0xc;
  }
  get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
  if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : First: Only Find %d ASIC, try again\n\n","Single_Board_PT1_New_Test",gAsic_num);
    snprintf(tmp1,0x100,"First: Only Find %d ASIC, try again\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    asic_num_record[0] = gAsic_num;
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (gAsic_num < asic_num_record[0]) {
      asic_num_record[0] = gAsic_num;
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : First: Find %d ASIC\n","Single_Board_PT1_New_Test",gAsic_num);
  snprintf(tmp1,0x100,"First: Find %d ASIC",gAsic_num);
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Hash_Board).Asic_Num == gAsic_num) {
    asic_num_record[0] = gAsic_num;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set chain inactive\n","Single_Board_PT1_New_Test");
    uVar1 = tmp1._16_4_;
    builtin_strncpy(tmp1,"Set chain inactive",0x13);
    tmp1[0x13] = SUB41(uVar1,3);
    log_to_file(tmp1,time_stamp);
    set_chain_inactive((uint8_t)gChain);
    usleep(10000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set asic address\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"Set asic address",0x10);
    tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    set_chain_asic_address((uint8_t)gChain,gAddress_interval);
    usleep(10000);
    set_uart_relay((uint8_t)gAddress_interval);
    usleep(10000);
    set_chain_baud((uint8_t)gChain,(Local_Config_Information->Test_Info).Test_Speed.Baudrate);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set chain baud as %d\n","Single_Board_PT1_New_Test",
           (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
    snprintf(tmp1,0x100,"Set chain baud as %d",
             (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
    log_to_file(tmp1,time_stamp);
    usleep(50000);
    usleep(500000);
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
      get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Second: Find %d ASIC\n\n","Single_Board_PT1_New_Test",gAsic_num);
    snprintf(tmp1,0x100,"Second: Find %d ASIC\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    asic_num_record[1] = gAsic_num;
    if ((asic_num_record[0] == (Local_Config_Information->Hash_Board).Asic_Num) &&
       (gAsic_num == (Local_Config_Information->Hash_Board).Asic_Num)) {
      gHistory_Result[gPattern_test_counter].asic_ok = true;
    }
    else {
      gAsic_num = get_min_value_uint32(asic_num_record,'\x02');
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : The MIN ASIC number is %d\n","Single_Board_PT1_New_Test",gAsic_num);
      snprintf(tmp1,0x100,"The MIN ASIC number is %d",gAsic_num);
      log_to_file(tmp1,time_stamp);
      gAsic_num = asic_num_record[0];
      gAsic_num1 = asic_num_record[1];
      print_find_asic_result();
    }
  }
  pthread_cancel(m_board_protect_id);
  pthread_join(m_board_protect_id,(void **)0x0);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : board protect end...\n","Single_Board_PT1_New_Test");
  builtin_strncpy(tmp1,"board protect end...",0x14);
  tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  if (((Local_Config_Information->Repair_Mode).Enable_Repair != false) &&
     ((Local_Config_Information->Repair_Mode).Close_Power_Delay != 0)) {
    gStart_show_on_lcd = false;
    if (show_id != 0) {
      pthread_join(show_id,(void **)0x0);
    }
    show_id = 0;
    show_ng_asics();
  }
  _power_down(gChain,false);
  if ((gHistory_Result[gPattern_test_counter].asic_ok != false) &&
     (gHistory_Result[gPattern_test_counter].eeprom_ok != false)) {
    temp = true;
  }
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
     (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true)) {
    temp = false;
  }
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false)
     && (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK != true)) {
    temp = false;
  }
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != true) {
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false) &&
       (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)) {
      temp = false;
    }
    if (temp != false) {
      gHistory_Result[gPattern_test_counter].eeprom_ok = true;
    }
    gStart_receive = false;
    _Var2 = prepare_eeprom_data_pt1(temp);
    if (!_Var2) {
      _power_down(gChain,false);
      gStart_show_on_lcd = false;
      if (show_id != 0) {
        pthread_join(show_id,(void **)0x0);
      }
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"prepare");
      lcd_show(2,"eeprom data");
      lcd_show(3,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : prepare eeprom data fail\n","Single_Board_PT1_New_Test");
      builtin_strncpy(tmp1,"prepare eeprom data fail",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      test_result = 0xc;
      goto LAB_000b4f9e;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : do no write eeprom for shmoo/customer repair mode\n\n","Single_Board_PT1_New_Test")
    ;
    builtin_strncpy(tmp1,"do no write eeprom for shmoo/customer repair mod",0x30);
    tmp1[0x30] = 'e';
    tmp1[0x31] = '\n';
    tmp1[0x32] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  gStart_show_on_lcd = false;
  if (show_id != 0) {
    pthread_join(show_id,(void **)0x0);
  }
  test_result = PT1_display_result_on_LCD();
  print_history_result((uint)gPattern_test_counter);
LAB_000b4f9e:
  gStart_heart_beat = false;
  gStart_receive = false;
  if (pic_heart_beat_id != 0) {
    pthread_join(pic_heart_beat_id,(void **)0x0);
  }
  if (receive_id != 0) {
    pthread_join(receive_id,(void **)0x0);
  }
  return test_result;
}

