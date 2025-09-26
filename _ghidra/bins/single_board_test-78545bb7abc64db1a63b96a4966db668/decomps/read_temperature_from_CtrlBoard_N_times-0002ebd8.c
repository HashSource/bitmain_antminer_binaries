
void read_temperature_from_CtrlBoard_N_times(uint8_t N)

{
  int32_t iVar1;
  uint8_t N_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t gCtrlBoard_sensor_addr [2];
  uint8_t data [2];
  int32_t ret;
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  temp = true;
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","read_temperature_from_CtrlBoard_N_times",
         "read_temperature_from_CtrlBoard_N_times");
  snprintf(tmp1,0x100,"Start %s","read_temperature_from_CtrlBoard_N_times");
  log_to_file(tmp1,time_stamp);
  for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
    gCtrlBoard_sensor_addr[i] = gCtrlBoard_sensor_i2c_addr + gCtrlBoard_sensor_low_3_bits_addr[i];
  }
  iVar1 = tsensor_open(gChain,gCtrlBoard_sensor_addr,(uint8_t)gCtrlBoard_sensor_num);
  if (iVar1 < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s: chain %d tsensor_open failed\n\n","read_temperature_from_CtrlBoard_N_times",
           "read_temperature_from_CtrlBoard_N_times",gChain);
    snprintf(tmp1,0x100,"%s: chain %d tsensor_open failed\n",
             "read_temperature_from_CtrlBoard_N_times",gChain);
    log_to_file(tmp1,time_stamp);
  }
  else {
    for (j = '\0'; j < N; j = j + '\x01') {
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        memset(data,0,2);
        iVar1 = tsensor_read(gChain,gCtrlBoard_sensor_addr[i],gPic_temperature_reg_addr,data,2);
        if (iVar1 == 2) {
          if (data[0] != '\0') {
            gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] = true;
            gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[i] =
                 data[0];
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : gHistory_Result[%d].sensor_local_temperature_from_ctrlboard[%d] = %d\n",
                   "read_temperature_from_CtrlBoard_N_times",(uint)gPattern_test_counter,(uint)i,
                   (int)gHistory_Result[gPattern_test_counter].
                        sensor_local_temperature_from_ctrlboard[i]);
            snprintf(tmp1,0x100,
                     "gHistory_Result[%d].sensor_local_temperature_from_ctrlboard[%d] = %d",
                     (uint)gPattern_test_counter,(uint)i,
                     (int)gHistory_Result[gPattern_test_counter].
                          sensor_local_temperature_from_ctrlboard[i]);
            log_to_file(tmp1,time_stamp);
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read CtrlBoard sensor fail,addr: %d\n",
                 "read_temperature_from_CtrlBoard_N_times",(uint)gCtrlBoard_sensor_addr[i]);
          snprintf(tmp1,0x100,"Read CtrlBoard sensor fail,addr: %d",(uint)gCtrlBoard_sensor_addr[i])
          ;
          log_to_file(tmp1,time_stamp);
        }
        usleep(50000);
      }
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read from CtrlBoard ::    Sensor %d:      local: %d\n",
               "read_temperature_from_CtrlBoard_N_times",(uint)i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                    [i]);
        snprintf(tmp1,0x100,"Read from CtrlBoard ::    Sensor %d:      local: %d",(uint)i,
                 (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard
                      [i]);
        log_to_file(tmp1,time_stamp);
      }
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        temp = (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] & temp) != 0;
      }
      if (temp != false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : All CtrlBoard sensor read out data\n","read_temperature_from_CtrlBoard_N_times"
              );
        builtin_strncpy(tmp1,"All CtrlBoard sensor read out da",0x20);
        tmp1[0x20] = 't';
        tmp1[0x21] = 'a';
        tmp1[0x22] = '\0';
        log_to_file(tmp1,time_stamp);
        gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK = true;
        return;
      }
    }
  }
  return;
}

