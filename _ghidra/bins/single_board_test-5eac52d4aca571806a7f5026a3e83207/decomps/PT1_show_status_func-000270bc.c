
void * PT1_show_status_func(void *arg)

{
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_data [16];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","PT1_show_status_func","PT1_show_status_func");
  snprintf(tmp1,0x100,"Start %s","PT1_show_status_func");
  log_to_file(tmp1,time_stamp);
  time_counter = 0;
  while (gStart_show_on_lcd != false) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    memset(lcd_data,0,0x10);
    sprintf(lcd_data,"time: %ds",time_counter);
    lcd_show(1,lcd_data);
    lcd_show(2,"Testing...");
    time_counter = time_counter + 1;
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s stop\n","PT1_show_status_func","PT1_show_status_func");
  snprintf(tmp1,0x100,"%s stop","PT1_show_status_func");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

