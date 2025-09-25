
void * read_temperature_from_PIC(void *arg)

{
  int32_t iVar1;
  uint uVar2;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int8_t data [2];
  uint8_t sleep_counter;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","read_temperature_from_PIC","read_temperature_from_PIC");
  snprintf(tmp1,0x100,"Start %s","read_temperature_from_PIC");
  log_to_file(tmp1,time_stamp);
  while (gStart_read_temp_from_pic != false) {
    for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
      memset(data,0,2);
      iVar1 = pic_read_iic((uint8_t)gChain,gPic_sensor_i2c_addr + gPic_sensor_low_3_bits_addr[i],
                           gPic_temperature_reg_addr,(uint8_t *)data,2);
      if (iVar1 == 2) {
        if (data[0] != '\0') {
          gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] = true;
          gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i] = data[0];
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read PIC sensor %d fail\n","read_temperature_from_PIC",(uint)i);
        snprintf(tmp1,0x100,"Read PIC sensor %d fail",(uint)i);
        log_to_file(tmp1,time_stamp);
      }
    }
    for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Read from Pic ::    Sensor %d:      local: %d\n","read_temperature_from_PIC",
             (uint)i,(int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic
                          [i]);
      snprintf(tmp1,0x100,"Read from Pic ::    Sensor %d:      local: %d",(uint)i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i]);
      log_to_file(tmp1,time_stamp);
    }
    sleep_counter = '\0';
    while ((gStart_read_temp_from_pic != false &&
           (uVar2 = (uint)sleep_counter, sleep_counter = sleep_counter + '\x01',
           uVar2 < gRead_Pic_Temperature_time_interval))) {
      sleep(1);
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s stop\n","read_temperature_from_PIC","read_temperature_from_PIC");
  snprintf(tmp1,0x100,"%s stop","read_temperature_from_PIC");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

