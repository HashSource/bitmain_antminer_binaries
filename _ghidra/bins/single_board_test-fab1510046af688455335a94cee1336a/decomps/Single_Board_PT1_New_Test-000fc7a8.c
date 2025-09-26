
/* WARNING: Unknown calling convention */

int Single_Board_PT1_New_Test(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  uint8_t uVar3;
  int iVar4;
  int32_t iVar5;
  char time_stamp [48];
  char tmp1 [2048];
  size_t offset;
  size_t len;
  uint8_t eeprom_data_cmp [128];
  uint8_t eeprom_data [128];
  uint32_t asic_num_record [2];
  int32_t thread_ret;
  int test_result;
  _Bool temp;
  
  temp = false;
  asic_num_record[0] = 0;
  asic_num_record[1] = 0;
  len = 0x80;
  gPattern_test_counter = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s, gPattern_test_counter = %d\n","Single_Board_PT1_New_Test",
         "Single_Board_PT1_New_Test",(uint)gPattern_test_counter);
  snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d","Single_Board_PT1_New_Test",
           (uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  _Var2 = init_fpga();
  if (!_Var2) {
    return 0xc;
  }
  fan_turn_on(BOTH_SIZE);
  pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set fan speed as %d\n","Single_Board_PT1_New_Test",
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
  printf("%s: Set Chain %d baud: %d\n","Single_Board_PT1_New_Test",gChain,0x1a);
  snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
  log_to_file(tmp1,time_stamp);
  set_bt8d_chain(gChain,0x1a);
  reset_register_cache_value_to_default((uint8_t)gChain);
  chain_reset_low(gChain);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: chain reset low\n","Single_Board_PT1_New_Test");
  builtin_strncpy(tmp1,"chain reset low",0x10);
  log_to_file(tmp1,time_stamp);
  sleep(1);
  gStart_show_on_lcd = true;
  iVar4 = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5c6c1,(void *)0x0);
  if (iVar4 != 0) {
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
    printf("%s: Show thread creat fail, Start again\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
    log_to_file(tmp1,time_stamp);
    return 0xc;
  }
  iVar5 = eeprom_open(gChain);
  if (iVar5 < 0) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(2,"EEPROM init fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM init fail!!!\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"EEPROM init fail!!!",0x14);
    log_to_file(tmp1,time_stamp);
    return 0;
  }
  _Var2 = Check_EEPROM(gEEPROM_length);
  if (_Var2) {
    gHistory_Result[gPattern_test_counter].eeprom_ok = true;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: chech EEPROM success\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"chech EEPROM success",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: check EEPROM fail\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"check EEPROM fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
     (_Var2 = init_pic(), !_Var2)) {
    gStart_show_on_lcd = false;
    pwm_set(gFan,0);
    pthread_join(show_id,(void **)0x0);
    return 1;
  }
  _Var2 = APW_power_on(g_power_version,gHistory_Result[gPattern_test_counter].pre_open_core_voltage)
  ;
  if (!_Var2) {
    gStart_show_on_lcd = false;
    bitmain_power_off();
    pwm_set(gFan,0);
    pthread_join(show_id,(void **)0x0);
    pthread_join(pic_heart_beat_id,(void **)0x0);
    return 0xc;
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: delay 700ms before check asic num\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1,"delay 700ms before check asic num",0x22);
    log_to_file(tmp1,time_stamp);
    usleep(700000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(100000);
    chain_reset_low(gChain);
    usleep(10000);
    chain_reset_high(gChain);
    usleep(10000);
  }
  else {
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
  }
  gStart_receive = true;
  iVar4 = pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0xf8ca5,(void *)0x0);
  if (iVar4 != 0) {
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
    printf("%s:  Receive thread  creat fail, Start again\n","Single_Board_PT1_New_Test");
    builtin_strncpy(tmp1," Receive thread  creat fail, Start again",0x28);
    tmp1[0x28] = '\0';
    log_to_file(tmp1,time_stamp);
    return 0xc;
  }
  get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
  if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: First: Only Find %d ASIC, try again\n\n","Single_Board_PT1_New_Test",gAsic_num);
    snprintf(tmp1,0x800,"First: Only Find %d ASIC, try again\n",gAsic_num);
    log_to_file(tmp1,time_stamp);
    asic_num_record[0] = gAsic_num;
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    if (gAsic_num < asic_num_record[0]) {
      asic_num_record[0] = gAsic_num;
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: First: Find %d ASIC\n","Single_Board_PT1_New_Test",gAsic_num);
  snprintf(tmp1,0x800,"First: Find %d ASIC",gAsic_num);
  log_to_file(tmp1,time_stamp);
  asic_num_record[0] = gAsic_num;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set chain inactive\n","Single_Board_PT1_New_Test");
  uVar1 = tmp1._16_4_;
  builtin_strncpy(tmp1,"Set chain inactive",0x13);
  tmp1[0x13] = SUB41(uVar1,3);
  log_to_file(tmp1,time_stamp);
  set_chain_inactive((uint8_t)gChain);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set asic address\n","Single_Board_PT1_New_Test");
  builtin_strncpy(tmp1,"Set asic address",0x10);
  tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  set_chain_asic_address((uint8_t)gChain,gAddress_interval);
  usleep(10000);
  gStart_get_vol = true;
  set_uart_relay((uint8_t)gAddress_interval);
  usleep(10000);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) {
    read_temperature_from_Switch_N_times('\x03');
  }
  lcd_show(1,"clib chip temp");
  lcd_show(2,"wait 60s");
  uVar3 = chip_temp_calibration(gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
  if (uVar3 != '\0') {
    gStart_heart_beat = false;
    _power_down(gChain);
    pthread_join(show_id,(void **)0x0);
    pthread_join(pic_heart_beat_id,(void **)0x0);
    lcd_common_show("temp calb","fail",(char *)0x0);
    return 0xd;
  }
  set_chain_baud((uint8_t)gChain,(Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set chain baud as %d\n","Single_Board_PT1_New_Test",
         (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  snprintf(tmp1,0x800,"Set chain baud as %d",
           (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  log_to_file(tmp1,time_stamp);
  usleep(50000);
  get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
  if ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num) {
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Second: Find %d ASIC\n\n","Single_Board_PT1_New_Test",gAsic_num);
  snprintf(tmp1,0x800,"Second: Find %d ASIC\n",gAsic_num);
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
    printf("%s: The MIN ASIC number is %d\n","Single_Board_PT1_New_Test",gAsic_num);
    snprintf(tmp1,0x800,"The MIN ASIC number is %d",gAsic_num);
    log_to_file(tmp1,time_stamp);
    gAsic_num = asic_num_record[0];
    gAsic_num1 = asic_num_record[1];
    print_find_asic_result();
  }
  gStart_get_vol = false;
  _power_down(gChain);
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
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) &&
     ((gHistory_Result[gPattern_test_counter].switch_sensor_all_OK != true ||
      (gHistory_Result[gPattern_test_counter].sensor_calibration_OK != true)))) {
    temp = false;
  }
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != true) {
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false) &&
       (gHistory_Result[gPattern_test_counter].asic_sensor_all_OK != true)) {
      temp = false;
    }
    if (temp != false) {
      _Var2 = write_EEPROM_PT1_marker();
      if (_Var2) {
        gHistory_Result[gPattern_test_counter].eeprom_ok = true;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: write PT1 EEPROM marker success\n","Single_Board_PT1_New_Test");
        builtin_strncpy(tmp1,"write PT1 EEPROM marker success",0x20);
        log_to_file(tmp1,time_stamp);
      }
      else {
        gHistory_Result[gPattern_test_counter].eeprom_ok = false;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: write PT1 EEPROM marker fail\n","Single_Board_PT1_New_Test");
        builtin_strncpy(tmp1,"write PT1 EEPROM marker fail",0x1c);
        tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
    }
    gStart_receive = false;
    _Var2 = prepare_eeprom_data_pt1(temp,eeprom_data,&len,&offset);
    if (!_Var2) {
      _power_down(gChain);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"prepare");
      lcd_show(2,"eeprom data");
      lcd_show(3,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: prepare eeprom data fail\n","Single_Board_PT1_New_Test");
      builtin_strncpy(tmp1,"prepare eeprom data fail",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      test_result = 0xc;
      goto LAB_000fdca0;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: write 0x%x..+0x%x\n","Single_Board_PT1_New_Test",offset,len);
    snprintf(tmp1,0x800,"write 0x%x..+0x%x",offset,len);
    log_to_file(tmp1,time_stamp);
    iVar5 = eeprom_write(gChain,(uint8_t)offset,eeprom_data,len);
    if (iVar5 == 0) {
      iVar5 = eeprom_read(gChain,(uint8_t)offset,eeprom_data_cmp,len);
      if (iVar5 == 0) {
        iVar4 = memcmp(eeprom_data,eeprom_data_cmp,len);
        if (iVar4 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Write EEPROM ok\n\n","Single_Board_PT1_New_Test");
          builtin_strncpy(tmp1,"Write EEPROM ok\n",0x10);
          tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
        }
        else {
          gHistory_Result[gPattern_test_counter].eeprom_ok = false;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Check EEPROM data fail\n\n","Single_Board_PT1_New_Test");
          builtin_strncpy(tmp1,"Check EEPROM data fail\n",0x18);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        gHistory_Result[gPattern_test_counter].eeprom_ok = false;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Read EEPROM fail\n\n","Single_Board_PT1_New_Test");
        builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
        tmp1[0x10] = '\n';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      gHistory_Result[gPattern_test_counter].eeprom_ok = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Write EEPROM fail\n\n","Single_Board_PT1_New_Test");
      builtin_strncpy(tmp1,"Write EEPROM fai",0x10);
      tmp1[0x10] = 'l';
      tmp1[0x11] = '\n';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  test_result = PT1_display_result_on_LCD();
  print_history_result((uint)gPattern_test_counter);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: read EEPROM infor \n\n","Single_Board_PT1_New_Test");
  builtin_strncpy(tmp1,"read EEPROM infor \n",0x14);
  log_to_file(tmp1,time_stamp);
LAB_000fdca0:
  gStart_heart_beat = false;
  gStart_show_on_lcd = false;
  gStart_receive = false;
  pthread_join(show_id,(void **)0x0);
  pthread_join(receive_id,(void **)0x0);
  bitmain_power_off();
  return test_result;
}

