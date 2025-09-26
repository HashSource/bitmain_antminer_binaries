
uint8_t get_temperature_data_position_in_array(uint32_t which_asic_sensor)

{
  uint32_t which_asic_sensor_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t i;
  
  i = '\0';
  while( true ) {
    if (gAsic_sensor_num <= i) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Sensor position error. position = %d\n","get_temperature_data_position_in_array",
             which_asic_sensor);
      snprintf(tmp1,0x800,"Sensor position error. position = %d",which_asic_sensor);
      log_to_file(tmp1,time_stamp);
      return '\0';
    }
    if (gAsic_sensor_addr[i] == which_asic_sensor) break;
    i = i + '\x01';
  }
  return i;
}

