
/* WARNING: Unknown calling convention */

int PT1_plus_display_result_on_LCD(void)

{
  bool bVar1;
  uint uVar2;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t bad_asic_addr [4];
  char lcd_data [16];
  uint32_t test_result;
  uint8_t j;
  uint8_t i;
  uint8_t bad_asic_num;
  _Bool temp;
  
  bad_asic_addr[0] = 0;
  bad_asic_addr[1] = 0;
  bad_asic_addr[2] = 0;
  bad_asic_addr[3] = 0;
  bad_asic_num = '\0';
  j = '\0';
  test_result = 0;
  lcd_clear_result();
  bVar1 = gHistory_Result[gPattern_test_counter].eeprom_ok == true &&
          gHistory_Result[gPattern_test_counter].asic_ok == true;
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
     (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK != true)) {
    bVar1 = false;
  }
  if (bVar1) {
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"ASIC:   OK");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ASIC:   OK\n\n","PT1_plus_display_result_on_LCD");
    builtin_strncpy(tmp1,"ASIC:   OK\n",0xc);
    log_to_file(tmp1,time_stamp);
    lcd_show(2,"EEPROM: OK");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM: OK\n\n","PT1_plus_display_result_on_LCD");
    builtin_strncpy(tmp1,"EEPROM: OK\n",0xc);
    log_to_file(tmp1,time_stamp);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      lcd_show(3,"PIC sensor: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: PIC sensor: OK\n\n","PT1_plus_display_result_on_LCD");
      builtin_strncpy(tmp1,"PIC sensor: OK\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    if (gHistory_Result[gPattern_test_counter].asic_ok == false) {
      lcd_show(0,"ASIC:   NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ASIC:   NG\n\n","PT1_plus_display_result_on_LCD");
      builtin_strncpy(tmp1,"ASIC:   NG\n",0xc);
      log_to_file(tmp1,time_stamp);
      for (i = '\0'; (uint)i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + '\x01') {
        if ((gHistory_Result[gPattern_test_counter].bad_asic_list[i] != true) &&
           (bad_asic_num = bad_asic_num + '\x01', j < 4)) {
          uVar2 = (uint)j;
          j = j + '\x01';
          bad_asic_addr[uVar2] = (uint)i;
        }
      }
      if (bad_asic_num != '\0') {
        memset(lcd_data,0,0x10);
        if (bad_asic_num == '\x01') {
          sprintf(lcd_data,"B_A: %d",bad_asic_addr[0]);
        }
        else if (bad_asic_num == '\x02') {
          sprintf(lcd_data,"B_A: %d %d",bad_asic_addr[0],bad_asic_addr[1]);
        }
        else if (bad_asic_num == '\x03') {
          sprintf(lcd_data,"B_A: %d %d %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2]);
        }
        else {
          sprintf(lcd_data,"B_A: %d %d %d %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2],
                  bad_asic_addr[3]);
        }
        lcd_show(3,lcd_data);
      }
      test_result = (uint)bad_asic_num << 8 | 6;
    }
    else {
      lcd_show(0,"ASIC:   OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ASIC:   OK\n\n","PT1_plus_display_result_on_LCD");
      builtin_strncpy(tmp1,"ASIC:   OK\n",0xc);
      log_to_file(tmp1,time_stamp);
    }
    if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
      lcd_show(1,"EEPROM: NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM: NG\n\n","PT1_plus_display_result_on_LCD");
      builtin_strncpy(tmp1,"EEPROM: NG\n",0xc);
      log_to_file(tmp1,time_stamp);
      test_result = 0xb;
    }
    else {
      lcd_show(1,"EEPROM: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: EEPROM: OK\n\n","PT1_plus_display_result_on_LCD");
      builtin_strncpy(tmp1,"EEPROM: OK\n",0xc);
      log_to_file(tmp1,time_stamp);
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      if (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK == false) {
        lcd_show(2,"PIC sensor: NG");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: PIC sensor: NG\n\n","PT1_plus_display_result_on_LCD");
        builtin_strncpy(tmp1,"PIC sensor: NG\n",0x10);
        log_to_file(tmp1,time_stamp);
        test_result = 10;
      }
      else {
        lcd_show(2,"PIC sensor: OK");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: PIC sensor: OK\n\n","PT1_plus_display_result_on_LCD");
        builtin_strncpy(tmp1,"PIC sensor: OK\n",0x10);
        log_to_file(tmp1,time_stamp);
      }
    }
  }
  return test_result;
}

