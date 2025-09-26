
/* WARNING: Type propagation algorithm not settling */

void read_temperature_from_Switch_N_times(uint8_t N)

{
  uint8_t N_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t data [2];
  int8_t asic_temp;
  int8_t pcb_temp;
  int32_t ret;
  uint8_t sensor_dev_addr;
  uint8_t switch_dev_addr;
  uint8_t sesnor_id;
  _Bool temp;
  int j;
  int i;
  
  pcb_temp = '\0';
  asic_temp = '\0';
  temp = true;
  j = 0;
  while( true ) {
    if ((int)(uint)N <= j) {
      return;
    }
    for (i = 0; i < (int)(uint)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                               sensor_num; i = i + 1) {
      pcb_temp = '\0';
      asic_temp = '\0';
      sesnor_id = (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                  switch_sensor_info[i].channel;
      switch_dev_addr =
           (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.switch_addr;
      sensor_dev_addr =
           (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                    switch_sensor_info[i].sensor_addr;
      ret = pca_switch_read((uint8_t)gChain,sesnor_id,switch_dev_addr,sensor_dev_addr,&pcb_temp,
                            &asic_temp);
      if (ret == 0) {
        if (pcb_temp == '\0') {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read switch sensor fail temp 0,sesnor_id: %d\n",
                 "read_temperature_from_Switch_N_times",(uint)sesnor_id);
          snprintf(tmp1,0x100,"Read switch sensor fail temp 0,sesnor_id: %d",(uint)sesnor_id);
          log_to_file(tmp1,time_stamp);
        }
        else {
          gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] = true;
          gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i] = pcb_temp;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read from switch ::    Sensor %d:      remote: %d\n",
                 "read_temperature_from_Switch_N_times",i,(int)asic_temp);
          snprintf(tmp1,0x100,"Read from switch ::    Sensor %d:      remote: %d",i,(int)asic_temp);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read switch sensor fail,sesnor_id: %d\n","read_temperature_from_Switch_N_times"
               ,(uint)sesnor_id);
        snprintf(tmp1,0x100,"Read switch sensor fail,sesnor_id: %d",(uint)sesnor_id);
        log_to_file(tmp1,time_stamp);
      }
    }
    for (i = 0; i < (int)(uint)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                               sensor_num; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Read from switch ::    Sensor %d:      local: %d\n",
             "read_temperature_from_Switch_N_times",i,
             (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i]);
      snprintf(tmp1,0x100,"Read from switch ::    Sensor %d:      local: %d",i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i]);
      log_to_file(tmp1,time_stamp);
    }
    for (i = 0; i < (int)(uint)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                               sensor_num; i = i + 1) {
      temp = (gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] & temp) != 0;
    }
    if (temp != false) break;
    j = j + 1;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : All switch sensor read out data\n","read_temperature_from_Switch_N_times");
  builtin_strncpy(tmp1,"All switch sensor read out data",0x20);
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].switch_sensor_all_ok = true;
  return;
}

