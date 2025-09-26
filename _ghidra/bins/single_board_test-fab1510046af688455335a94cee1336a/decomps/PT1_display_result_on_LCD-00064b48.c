
/* WARNING: Unknown calling convention */

int PT1_display_result_on_LCD(void)

{
  bool bVar1;
  uint32_t uVar2;
  char time_stamp [48];
  char tmp1 [2048];
  char buffer [16];
  uint32_t id_buf [5];
  char *location [12];
  char lcd_data [16];
  uint32_t num;
  int index;
  uint16_t sesor_state;
  int i;
  uint32_t test_result;
  _Bool temp;
  
  bVar1 = true;
  test_result = 0;
  lcd_clear_result();
  if (gHistory_Result[gPattern_test_counter].asic_ok == false) {
    memset(lcd_data,0,0x10);
    sprintf(lcd_data,"ASIC: NG %d %d",gAsic_num,gAsic_num1);
    lcd_show(0,lcd_data);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ASIC:   NG\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"ASIC:   NG\n",0xc);
    log_to_file(tmp1,time_stamp);
    uVar2 = find_ng_asic_id(id_buf,5);
    memset(lcd_data,0,0x10);
    for (i = 0; (uint)i < uVar2; i = i + 1) {
      sprintf(lcd_data + i * 3," %02d",id_buf[i]);
    }
    lcd_show(1,lcd_data);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ASIC NG ID:%s\n\n","PT1_display_result_on_LCD",lcd_data);
    snprintf(tmp1,0x800,"ASIC NG ID:%s\n",lcd_data);
    log_to_file(tmp1,time_stamp);
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
    printf("%s: ASIC:   OK\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"ASIC:   OK\n",0xc);
    log_to_file(tmp1,time_stamp);
  }
  if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
    lcd_show(2,"EEPROM: NG");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM: NG\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"EEPROM: NG\n",0xc);
    log_to_file(tmp1,time_stamp);
    bVar1 = false;
    test_result = 0xb;
  }
  else {
    lcd_show(2,"EEPROM: OK");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM: OK\n\n","PT1_display_result_on_LCD");
    builtin_strncpy(tmp1,"EEPROM: OK\n",0xc);
    log_to_file(tmp1,time_stamp);
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    if (gHistory_Result[gPattern_test_counter].pic_sensor_all_OK == false) {
      lcd_show(3,"PIC sensor: NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: PIC sensor: NG\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"PIC sensor: NG\n",0x10);
      log_to_file(tmp1,time_stamp);
      bVar1 = false;
      test_result = 10;
    }
    else {
      lcd_show(3,"PIC sensor: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: PIC sensor: OK\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"PIC sensor: OK\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  location[0] = "U5";
  location[1] = "U4";
  location[2] = "U121";
  location[3] = "U124";
  location[4] = "U113";
  location[5] = "U132";
  location[6] = "U136";
  location[7] = "U9";
  location[8] = "U19";
  location[9] = "U77";
  location[10] = "U73";
  location[0xb] = "U26";
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) {
    if (gHistory_Result[gPattern_test_counter].switch_sensor_all_OK == false) {
      sesor_state = 0;
      for (index = 0; index < 0xc; index = index + 1) {
        if (gHistory_Result[gPattern_test_counter].switch_sensor_OK[index] != true) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: sensor: NG index%d  location :%s\n\n","PT1_display_result_on_LCD",index,
                 location[index]);
          snprintf(tmp1,0x800,"sensor: NG index%d  location :%s\n",index,location[index]);
          log_to_file(tmp1,time_stamp);
          sesor_state = sesor_state | (ushort)(1 << (index & 0xffU));
        }
      }
      snprintf(buffer,0x10,"sNG %0x",(uint)sesor_state);
      lcd_show(3,buffer);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: sensor: NG %s\n\n","PT1_display_result_on_LCD",buffer);
      snprintf(tmp1,0x800,"sensor: NG %s\n",buffer);
      log_to_file(tmp1,time_stamp);
      if (gHistory_Result[gPattern_test_counter].switch_OK != true) {
        lcd_show(3,"Switch :NG");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Switch :NG\n\n","PT1_display_result_on_LCD");
        builtin_strncpy(tmp1,"Switch :NG\n",0xc);
        log_to_file(tmp1,time_stamp);
        bVar1 = false;
        test_result = 10;
      }
    }
    else {
      lcd_show(3,"SW sensor: OK");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: switch sensor: OK\n\n","PT1_display_result_on_LCD");
      builtin_strncpy(tmp1,"switch sensor: O",0x10);
      tmp1[0x10] = 'K';
      tmp1[0x11] = '\n';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false) {
    if (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK == false) {
      lcd_show(3,"CB sensor: NG");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: CBoard sensor: NG\n\n","PT1_display_result_on_LCD");
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
      printf("%s: CBoard sensor: OK\n\n","PT1_display_result_on_LCD");
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

