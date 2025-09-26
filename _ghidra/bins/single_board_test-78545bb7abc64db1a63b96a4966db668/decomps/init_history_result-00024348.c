
void init_history_result(uint32_t test_loop_counter)

{
  double dVar1;
  uint32_t test_loop_counter_local;
  uint32_t i;
  
  if (test_loop_counter == 0) {
    memset(gHistory_Result,0,0x1e2a6c0);
  }
  gHistory_Result[test_loop_counter].asic_ok = false;
  gHistory_Result[test_loop_counter].nonce_rate_ok = false;
  gHistory_Result[test_loop_counter].eeprom_ok = false;
  gHistory_Result[test_loop_counter].pic_sensor_all_OK = false;
  gHistory_Result[test_loop_counter].asic_sensor_all_OK = true;
  gHistory_Result[test_loop_counter].apw_power_ok = true;
  gHistory_Result[test_loop_counter].pic_ok = true;
  gHistory_Result[test_loop_counter].level =
       (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[test_loop_counter].Level;
  dVar1 = (double)(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[test_loop_counter].
                  Voltage;
  gHistory_Result[test_loop_counter].voltage = (uint)(0.0 < dVar1) * (int)(longlong)dVar1;
  gHistory_Result[test_loop_counter].frequence =
       (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[test_loop_counter].Frequence;
  dVar1 = (double)(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[test_loop_counter].
                  Pre_Open_Core_Voltage;
  gHistory_Result[test_loop_counter].pre_open_core_voltage =
       (uint)(0.0 < dVar1) * (int)(longlong)dVar1;
  memset(gHistory_Result[test_loop_counter].ok_asic_list,0,0x100);
  memset(gHistory_Result[test_loop_counter].bad_asic_list,1,0x100);
  memset(gHistory_Result[test_loop_counter].pic_sensor_OK,0,4);
  memset(gHistory_Result[test_loop_counter].asic_sensor_OK,1,0x100);
  memset(gHistory_Result[test_loop_counter].sensor_local_temperature_from_pic,-0x7f,4);
  gHistory_Result[test_loop_counter].test_standard = 0xff;
  print_history_result(test_loop_counter);
  return;
}

