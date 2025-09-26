
void * read_temperature_from_CtrlBoard(void *arg)

{
  int32_t iVar1;
  uint uVar2;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t gCtrlBoard_sensor_addr [2];
  int8_t data [2];
  int32_t ret;
  uint8_t sleep_counter;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s\n","read_temperature_from_CtrlBoard","read_temperature_from_CtrlBoard");
  snprintf(tmp1,0x800,"Start %s","read_temperature_from_CtrlBoard");
  log_to_file(tmp1,time_stamp);
  for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
    gCtrlBoard_sensor_addr[i] = gCtrlBoard_sensor_low_3_bits_addr[i];
  }
  iVar1 = tsensor_open(gChain,gCtrlBoard_sensor_addr,(uint8_t)gCtrlBoard_sensor_num);
  if (iVar1 < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %s: chain %d tsensor_open failed\n\n","read_temperature_from_CtrlBoard",
           "read_temperature_from_CtrlBoard",gChain);
    snprintf(tmp1,0x800,"%s: chain %d tsensor_open failed\n","read_temperature_from_CtrlBoard",
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  else {
    while (gStart_read_temp != false) {
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        memset(data,0,2);
        iVar1 = tsensor_read(gChain,gCtrlBoard_sensor_addr[i],gCtrlBoard_temperature_reg_addr,
                             (uint8_t *)data,2);
        if (iVar1 == 2) {
          if (data[0] != '\0') {
            gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] = true;
            gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[i] =
                 data[0];
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Read CtrlBoard sensor fail,addr: %d\n","read_temperature_from_CtrlBoard",
                 (uint)gCtrlBoard_sensor_addr[i]);
          snprintf(tmp1,0x800,"Read CtrlBoard sensor fail,addr: %d",(uint)gCtrlBoard_sensor_addr[i])
          ;
          log_to_file(tmp1,time_stamp);
        }
      }
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Read from ctrlboard ::    Sensor %d:      local: %d\n",
               "read_temperature_from_CtrlBoard",(uint)i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                    [i]);
        snprintf(tmp1,0x800,"Read from ctrlboard ::    Sensor %d:      local: %d",(uint)i,
                 (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                      [i]);
        log_to_file(tmp1,time_stamp);
        if ('3' < gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[i])
        {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: RUN temperature too high! Read from ctrlboard ::    Sensor %d:      local: %d\n"
                 ,"read_temperature_from_CtrlBoard",(uint)i,
                 (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                      [i]);
          snprintf(tmp1,0x800,
                   "RUN temperature too high! Read from ctrlboard ::    Sensor %d:      local: %d",
                   (uint)i,(int)gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard[i]);
          log_to_file(tmp1,time_stamp);
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"run temperature too high!");
          lcd_show(2,"test end!");
          bitmain_power_off();
          gStart_show_on_lcd = false;
        }
      }
      if ((gCtrlBoard_sensor_num == 2) &&
         (3 < (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[0]
              - (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                     [1])) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Water flow reversal!\n","read_temperature_from_CtrlBoard");
        builtin_strncpy(tmp1,"Water flow reversal!",0x14);
        tmp1[0x14] = '\0';
        log_to_file(tmp1,time_stamp);
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Water flow reversal!");
        lcd_show(2,"test end!");
        bitmain_power_off();
        gStart_show_on_lcd = false;
        gWater_flow_reversal = true;
      }
      sleep_counter = '\0';
      while ((gStart_read_temp != false &&
             (uVar2 = (uint)sleep_counter, sleep_counter = sleep_counter + '\x01',
             uVar2 < gRead_Pic_Temperature_time_interval))) {
        sleep(1);
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %s stop\n","read_temperature_from_CtrlBoard","read_temperature_from_CtrlBoard");
    snprintf(tmp1,0x800,"%s stop","read_temperature_from_CtrlBoard");
    log_to_file(tmp1,time_stamp);
  }
  return (void *)0x0;
}

