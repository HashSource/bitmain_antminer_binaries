
/* WARNING: Unknown calling convention */

int32_t get_ctrlboard_temp_min(void)

{
  int i;
  int32_t temp;
  
  temp = 0;
  for (i = 0; (uint)i < gCtrlBoard_sensor_num; i = i + 1) {
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
  return temp;
}

