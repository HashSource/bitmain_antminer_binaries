
void * PT2_show_status_func(void *arg)

{
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  int8_t temperature_b [4];
  char lcd_data [16];
  uint32_t fpga_reg_val;
  uint32_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: in PT2_show_status_func()\n","PT2_show_status_func");
  builtin_strncpy(tmp1,"in PT2_show_status_func(",0x18);
  tmp1[0x18] = ')';
  tmp1[0x19] = '\0';
  log_to_file(tmp1,time_stamp);
  temperature_b[0] = '\0';
  temperature_b[1] = '\0';
  temperature_b[2] = '\0';
  temperature_b[3] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s\n","PT2_show_status_func","PT2_show_status_func");
  snprintf(tmp1,0x800,"Start %s","PT2_show_status_func");
  log_to_file(tmp1,time_stamp);
  time_counter = 0;
  while (gStart_show_on_lcd != false) {
    lcd_clear_result();
    memset(lcd_data,0,0x10);
    if (gCooling == false) {
      sprintf(lcd_data,"time: %ds, %.1fV",time_counter,lcd_data,
              (double)((float)(longlong)gVol_comp / 100.0));
    }
    else {
      sprintf(lcd_data,"time: %ds Cool",time_counter);
    }
    lcd_show(0,lcd_data);
    memset(lcd_data,0,0x10);
    sprintf(lcd_data,"nonce=%d",gHistory_Result[gPattern_test_counter].valid_nonce_num);
    lcd_show(1,lcd_data);
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      for (i = 0; i < gPic_sensor_num; i = i + 1) {
        if (gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i] != -0x7f) {
          temperature_b[i] =
               gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i];
        }
      }
      if (gPic_sensor_num == 0) {
        lcd_show(2,"No Pic sensor");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: No Pic sensor\n","PT2_show_status_func");
        builtin_strncpy(tmp1,"No Pic senso",0xc);
        tmp1[0xc] = 'r';
        tmp1[0xd] = '\0';
        log_to_file(tmp1,time_stamp);
      }
      else if (gPic_sensor_num == 1) {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T1:%d",(int)temperature_b[0]);
        lcd_show(2,lcd_data);
      }
      else if (gPic_sensor_num == 2) {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T1:%d  T2:%d",(int)temperature_b[0],(int)temperature_b[1]);
        lcd_show(2,lcd_data);
      }
      else if (gPic_sensor_num == 3) {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T1:%d  T2:%d",(int)temperature_b[0],(int)temperature_b[1]);
        lcd_show(2,lcd_data);
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T3:%d       ",(int)temperature_b[2]);
        lcd_show(3,lcd_data);
      }
      else {
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T1:%d  T2:%d",(int)temperature_b[0],(int)temperature_b[1]);
        lcd_show(2,lcd_data);
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"T3:%d  T4:%d",(int)temperature_b[2],(int)temperature_b[3]);
        lcd_show(3,lcd_data);
      }
    }
    time_counter = time_counter + 1;
    if (time_counter % 5 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: time = %d\n","PT2_show_status_func",time_counter);
      snprintf(tmp1,0x800,"time = %d",time_counter);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: gValid_Nonce_Num = %d\n","PT2_show_status_func",
             gHistory_Result[gPattern_test_counter].valid_nonce_num);
      snprintf(tmp1,0x800,"gValid_Nonce_Num = %d",
               gHistory_Result[gPattern_test_counter].valid_nonce_num);
      log_to_file(tmp1,time_stamp);
    }
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: %s stop\n","PT2_show_status_func","PT2_show_status_func");
  snprintf(tmp1,0x800,"%s stop","PT2_show_status_func");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

