
/* WARNING: Unknown calling convention */

int PT1_display_result_on_LCD(void)

{
  bool bVar1;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t test_result;
  _Bool temp;
  
  bVar1 = true;
  test_result = 0;
  lcd_clear_result();
  if (gHistory_Result[gPattern_test_counter].asic_ok == false) {
    show_ng_asics();
    bVar1 = false;
    if (gAsic_num == 0) {
      test_result = 2;
    }
    else {
      test_result = gAsic_num << 8 | 3;
    }
  }
  else {
    lcd_show(1,"ASIC:   OK");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ASIC:   OK\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"ASIC:   OK\n",0xc);
    log_to_file(tmp1,time_stamp);
  }
  if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
    lcd_show(2,"EEPROM: NG");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : EEPROM: NG\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"EEPROM: NG\n",0xc);
    log_to_file(tmp1,time_stamp);
    bVar1 = false;
    test_result = 0xb;
  }
  else {
    lcd_show(2,"EEPROM: OK");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : EEPROM: OK\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"EEPROM: OK\n",0xc);
    log_to_file(tmp1,time_stamp);
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    if (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK == false) {
      lcd_show(3,"PIC sensor: NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor: NG\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"PIC sensor: NG\n",0x10);
      log_to_file(tmp1,time_stamp);
      bVar1 = false;
      test_result = 10;
    }
    else {
      lcd_show(3,"PIC sensor: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor: OK\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"PIC sensor: OK\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false) {
    if (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK == false) {
      lcd_show(3,"CB sensor: NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : CBoard sensor: NG\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"CBoard sensor: N",0x10);
      tmp1[0x10] = 'G';
      tmp1[0x11] = '\n';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
      bVar1 = false;
      test_result = 10;
    }
    else {
      lcd_show(3,"CB sensor: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : CBoard sensor: OK\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"CBoard sensor: O",0x10);
      tmp1[0x10] = 'K';
      tmp1[0x11] = '\n';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if (bVar1) {
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    test_result = 0;
  }
  return test_result;
}

