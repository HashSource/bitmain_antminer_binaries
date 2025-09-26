
/* WARNING: Unknown calling convention */

int32_t get_ctrlboard_temp_max(void)

{
  int i_1;
  int i;
  int32_t temp;
  
  temp = 0;
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
    for (i_1 = 0; (uint)i_1 < gCtrlBoard_sensor_num; i_1 = i_1 + 1) {
      if (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i_1] != false) {
        if (temp == 0) {
          temp = (int32_t)gHistory_Result[gPattern_test_counter].
                          sensor_local_temperature_from_ctrlboard[i_1];
        }
        else if ((temp < gHistory_Result[gPattern_test_counter].
                         sensor_local_temperature_from_ctrlboard[i_1]) &&
                (gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i_1] !=
                 -1)) {
          temp = (int32_t)gHistory_Result[gPattern_test_counter].
                          sensor_local_temperature_from_ctrlboard[i_1];
        }
      }
    }
  }
  else {
    for (i = 0; i < (int)(uint)(Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                               sensor_num; i = i + 1) {
      if (gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] != false) {
        if (temp == 0) {
          temp = (int32_t)gHistory_Result[gPattern_test_counter].
                          sensor_local_temperature_from_switch[i];
        }
        else if ((temp < gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                         [i]) &&
                (gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i] !=
                 -1)) {
          temp = (int32_t)gHistory_Result[gPattern_test_counter].
                          sensor_local_temperature_from_switch[i];
        }
      }
    }
  }
  return temp;
}

