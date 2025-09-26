
/* WARNING: Unknown calling convention */

int32_t get_ctrlboard_temp_min(void)

{
  char time_stamp [48];
  char tmp1 [2048];
  int i;
  int32_t temp;
  
  temp = 0;
  for (i = 2; i < 7; i = i + 1) {
    if (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] != false) {
      if (temp == 0) {
        temp = (int32_t)gHistory_Result[gPattern_test_counter].
                        sensor_local_temperature_from_ctrlboard[i];
      }
      else if (gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[i] <
               temp) {
        temp = (int32_t)gHistory_Result[gPattern_test_counter].
                        sensor_local_temperature_from_ctrlboard[i];
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: get min temp %d\n","get_ctrlboard_temp_min",temp);
  snprintf(tmp1,0x800,"get min temp %d",temp);
  log_to_file(tmp1,time_stamp);
  return temp;
}

