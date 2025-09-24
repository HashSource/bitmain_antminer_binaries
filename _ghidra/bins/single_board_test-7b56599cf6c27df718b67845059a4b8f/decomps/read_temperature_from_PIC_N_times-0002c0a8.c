
void read_temperature_from_PIC_N_times(uint8_t N)

{
  int8_t iVar1;
  int8_t iVar2;
  int32_t iVar3;
  uint8_t N_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t data [2];
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  temp = true;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","read_temperature_from_PIC_N_times","read_temperature_from_PIC_N_times");
  snprintf(tmp1,0x100,"Start %s","read_temperature_from_PIC_N_times");
  log_to_file(tmp1,time_stamp);
  j = '\0';
  while( true ) {
    if (N <= j) {
      return;
    }
    for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
      memset(data,0,2);
      iVar3 = pic_read_iic((uint8_t)gChain,gPic_sensor_i2c_addr + gPic_sensor_low_3_bits_addr[i],
                           gPic_temperature_reg_addr,data,2);
      if (iVar3 == 2) {
        if (data[0] != '\0') {
          gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] = true;
          gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i] = data[0];
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : gHistory_Result[%d].sensor_local_temperature_from_pic[%d] = %d\n",
                 "read_temperature_from_PIC_N_times",(uint)gPattern_test_counter,(uint)i,
                 (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i]);
          snprintf(tmp1,0x100,"gHistory_Result[%d].sensor_local_temperature_from_pic[%d] = %d",
                   (uint)gPattern_test_counter,(uint)i,
                   (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i])
          ;
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read PIC sensor %d fail\n","read_temperature_from_PIC_N_times",(uint)i);
        snprintf(tmp1,0x100,"Read PIC sensor %d fail",(uint)i);
        log_to_file(tmp1,time_stamp);
      }
      usleep(50000);
    }
    for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Read from Pic ::    Sensor %d:      local: %d\n",
             "read_temperature_from_PIC_N_times",(uint)i,
             (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i]);
      snprintf(tmp1,0x100,"Read from Pic ::    Sensor %d:      local: %d",(uint)i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[i]);
      log_to_file(tmp1,time_stamp);
    }
    iVar1 = get_max_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic,
                          (uint8_t)gPic_sensor_num);
    iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic,
                          (uint8_t)gPic_sensor_num);
    if (10 < (int)iVar1 - (int)iVar2) {
      for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
        gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] = false;
      }
    }
    for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
      temp = (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] & temp) != 0;
    }
    if (temp != false) break;
    j = j + '\x01';
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : All PIC sensor read out data\n","read_temperature_from_PIC_N_times");
  builtin_strncpy(tmp1,"All PIC sensor read out data",0x1c);
  tmp1[0x1c] = '\0';
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].pic_sensor_all_OK = true;
  return;
}

