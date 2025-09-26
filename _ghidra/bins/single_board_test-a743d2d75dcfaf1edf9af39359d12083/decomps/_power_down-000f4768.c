
void _power_down(uint32_t chain)

{
  char *pcVar1;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Sleep %d seconds then power down\n","_power_down",
         (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  snprintf(tmp1,0x800,"Sleep %d seconds then power down",
           (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  log_to_file(tmp1,time_stamp);
  sleep((Local_Config_Information->Repair_Mode).Close_Power_Delay);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: reset low\n","_power_down");
  builtin_strncpy(tmp1,"reset lo",8);
  tmp1[8] = 'w';
  tmp1[9] = '\0';
  log_to_file(tmp1,time_stamp);
  chain_reset_low(chain);
  sleep(1);
  pcVar1 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56601");
  if (((pcVar1 == (char *)0x0) &&
      (pcVar1 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56611"),
      pcVar1 == (char *)0x0)) &&
     ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: drive mos low\n","_power_down");
    builtin_strncpy(tmp1,"drive mos lo",0xc);
    tmp1[0xc] = 'w';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
    disable_dc_dc((uint8_t)chain);
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: APW off\n","_power_down");
  builtin_strncpy(tmp1,"APW off",8);
  log_to_file(tmp1,time_stamp);
  bitmain_power_off();
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Sleep %d seconds then slow down FAN\n","_power_down",
         (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  snprintf(tmp1,0x800,"Sleep %d seconds then slow down FAN",
           (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard != 0) {
    gCooling = true;
  }
  sleep((Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  pwm_set(gFan,0);
  gStart_show_on_lcd = false;
  return;
}

