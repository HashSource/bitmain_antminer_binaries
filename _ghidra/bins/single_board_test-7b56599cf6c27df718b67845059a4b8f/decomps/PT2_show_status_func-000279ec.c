
void * PT2_show_status_func(void *arg)

{
  int8_t iVar1;
  char *__format;
  uint uVar2;
  uint uVar3;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int8_t temperature_b [4];
  char lcd_data [16];
  int newState;
  uint32_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","PT2_show_status_func","PT2_show_status_func");
  snprintf(tmp1,0x100,"Start %s","PT2_show_status_func");
  log_to_file(tmp1,time_stamp);
  time_counter = 0;
  while (gStart_show_on_lcd != false) {
    if (gHeating == false) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    if (gNoncing == false) {
      uVar3 = 0;
    }
    else {
      uVar3 = 4;
    }
    uVar3 = uVar3 | uVar2 | gCooling;
    if (uVar3 != PT2_show_status_func::lastState) {
      time_counter = 0;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : State changed,reset time counter.\n","PT2_show_status_func");
      builtin_strncpy(tmp1,"State changed,reset time counter",0x20);
      tmp1[0x20] = '.';
      tmp1[0x21] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    PT2_show_status_func::lastState = uVar3;
    if ((gCooling == false) && (gHeating == false)) {
      if (gNoncing != false) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        memset(lcd_data,0,0x10);
        snprintf(lcd_data,0x10,"time:%ds",time_counter);
        lcd_show(1,lcd_data);
        memset(lcd_data,0,0x10);
        snprintf(lcd_data,0x10,"nonce=%d",gHistory_Result[gPattern_test_counter].valid_nonce_num);
        lcd_show(2,lcd_data);
        memset(lcd_data,0,0x10);
        snprintf(lcd_data,0x10,"vol:%d",gVol_comp + gHistory_Result[gPattern_test_counter].voltage);
        lcd_show(3,lcd_data);
      }
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      memset(lcd_data,0,0x10);
      if (gCooling == false) {
        __format = "Heating:%ds";
      }
      else {
        __format = "Cooling:%ds";
      }
      snprintf(lcd_data,0x10,__format,time_counter);
      lcd_show(1,lcd_data);
      memset(lcd_data,0,0x10);
      iVar1 = get_min_value(gHistory_Result[gPattern_test_counter].
                            sensor_local_temperature_from_ctrlboard,(uint8_t)gCtrlBoard_sensor_num);
      snprintf(lcd_data,0x10,"Temp Min:%d",(int)iVar1);
      lcd_show(2,lcd_data);
      memset(lcd_data,0,0x10);
      iVar1 = get_max_value(gHistory_Result[gPattern_test_counter].
                            sensor_local_temperature_from_ctrlboard,(uint8_t)gCtrlBoard_sensor_num);
      snprintf(lcd_data,0x10,"Temp Max:%d",(int)iVar1);
      lcd_show(3,lcd_data);
    }
    time_counter = time_counter + 1;
    if (time_counter % 5 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : time = %d\n","PT2_show_status_func",time_counter);
      snprintf(tmp1,0x100,"time = %d",time_counter);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : gValid_Nonce_Num = %d\n","PT2_show_status_func",
             gHistory_Result[gPattern_test_counter].valid_nonce_num);
      snprintf(tmp1,0x100,"gValid_Nonce_Num = %d",
               gHistory_Result[gPattern_test_counter].valid_nonce_num);
      log_to_file(tmp1,time_stamp);
    }
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s stop\n","PT2_show_status_func","PT2_show_status_func");
  snprintf(tmp1,0x100,"%s stop","PT2_show_status_func");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

