
void read_temperature_from_asic_N_times(uint8_t N)

{
  int8_t iVar1;
  int8_t iVar2;
  int iVar3;
  uint8_t N_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t asic_addr [4];
  uint32_t sensor_addr [4];
  uint8_t data [2];
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  sensor_addr[0] = 0;
  sensor_addr[1] = 0;
  sensor_addr[2] = 0;
  sensor_addr[3] = 0;
  temp = true;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s\n","read_temperature_from_asic_N_times","read_temperature_from_asic_N_times")
  ;
  snprintf(tmp1,0x800,"Start %s","read_temperature_from_asic_N_times");
  log_to_file(tmp1,time_stamp);
  for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
    set_asic_analog_mux_control((uint8_t)gChain,(uint)gAsic_sensor_addr[i],'\0');
    usleep(10000);
    enable_asic_tfs_rfs(gChain & 0xff,gAsic_sensor_addr[i]);
    usleep(10000);
    iVar3 = strcmp((Local_Config_Information->Hash_Board).Sensor_Info.Asic_Sensor.Asic_Sensor_Model,
                   "TMP451");
    if (iVar3 != 0) {
      strcmp((Local_Config_Information->Hash_Board).Sensor_Info.Asic_Sensor.Asic_Sensor_Model,
             "TMP461");
    }
    set_asic_data_by_iic(gChain & 0xff,gAsic_sensor_addr[i],gAsic_sensor_i2c_addr,9,4);
    usleep(50000);
  }
  j = '\0';
  while( true ) {
    if (N <= j) {
      return;
    }
    for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
      get_asic_temp_by_iic(gChain & 0xff,sensor_addr[i],gAsic_sensor_i2c_addr,0);
      usleep(50000);
      get_register_value(gAsic_sensor_addr[i] - 1,8,false,
                         (Local_Config_Information->Hash_Board).Asic_Type);
      usleep(50000);
      get_asic_temp_by_iic(gChain & 0xff,sensor_addr[i],gAsic_sensor_i2c_addr,1);
      usleep(50000);
      get_register_value(gAsic_sensor_addr[i] - 1,9,false,
                         (Local_Config_Information->Hash_Board).Asic_Type);
      usleep(50000);
    }
    for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Read from Asic :: Sensor %d:\t\tlocal: %d,\t remote: %d\n",
             "read_temperature_from_asic_N_times",(uint)i,
             (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_asic[i],
             (int)gHistory_Result[gPattern_test_counter].sensor_remote_temperature_from_asic[i]);
      snprintf(tmp1,0x800,"Read from Asic :: Sensor %d:\t\tlocal: %d,\t remote: %d",(uint)i,
               (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_asic[i],
               (int)gHistory_Result[gPattern_test_counter].sensor_remote_temperature_from_asic[i]);
      log_to_file(tmp1,time_stamp);
    }
    iVar1 = get_max_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_asic,
                          (uint8_t)gAsic_sensor_num);
    iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_asic,
                          (uint8_t)gAsic_sensor_num);
    if (10 < (int)iVar1 - (int)iVar2) {
      for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
        gHistory_Result[gPattern_test_counter].asic_sensor_OK[i] = false;
      }
    }
    iVar1 = get_max_value(gHistory_Result[gPattern_test_counter].sensor_remote_temperature_from_asic
                          ,(uint8_t)gAsic_sensor_num);
    iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].sensor_remote_temperature_from_asic
                          ,(uint8_t)gAsic_sensor_num);
    if (10 < (int)iVar1 - (int)iVar2) {
      for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
        gHistory_Result[gPattern_test_counter].asic_sensor_OK[i] = false;
      }
    }
    for (i = '\0'; i < gAsic_sensor_num; i = i + '\x01') {
      temp = (gHistory_Result[gPattern_test_counter].asic_sensor_OK[i] & temp) != 0;
    }
    if (temp != false) break;
    j = j + '\x01';
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: All ASIC sensor read out data\n","read_temperature_from_asic_N_times");
  builtin_strncpy(tmp1,"All ASIC sensor read out dat",0x1c);
  tmp1[0x1c] = 'a';
  tmp1[0x1d] = '\0';
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].asic_sensor_all_OK = true;
  return;
}

