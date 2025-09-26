
_Bool easy_check_base_PT2_result(uint32_t test_loop_index)

{
  _Bool _Var1;
  uint32_t test_loop_index_local;
  
  if ((gHistory_Result[test_loop_index].test_standard == '\0') &&
     (gHistory_Result[test_loop_index].eeprom_ok != false)) {
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false)
       || (gHistory_Result[test_loop_index].switch_sensor_all_OK == false)) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

