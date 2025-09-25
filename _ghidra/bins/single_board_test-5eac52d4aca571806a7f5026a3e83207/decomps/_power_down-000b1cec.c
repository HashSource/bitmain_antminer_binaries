
void _power_down(uint32_t chain,_Bool cooling)

{
  int32_t iVar1;
  _Bool cooling_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  int i;
  
  pwm_set(gFan,100);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Sleep %d seconds then power down\n","_power_down",
         (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  snprintf(tmp1,0x100,"Sleep %d seconds then power down",
           (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  log_to_file(tmp1,time_stamp);
  sleep((Local_Config_Information->Repair_Mode).Close_Power_Delay);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : reset low\n","_power_down");
  builtin_strncpy(tmp1,"reset low",10);
  log_to_file(tmp1,time_stamp);
  chain_reset_low(chain);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : APW off\n","_power_down");
  builtin_strncpy(tmp1,"APW off",8);
  log_to_file(tmp1,time_stamp);
  i = 0;
  while ((i < 3 && (iVar1 = bitmain_power_off(), iVar1 != 0))) {
    i = i + 1;
  }
  if (2 < i) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : warning three times poweroff failed! will reboot system\n","_power_down");
    builtin_strncpy(tmp1,"warning three times poweroff failed! will reboot system",0x38);
    log_to_file(tmp1,time_stamp);
    system("reboot");
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Sleep %d seconds then slow down FAN\n","_power_down",
         (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  snprintf(tmp1,0x100,"Sleep %d seconds then slow down FAN",
           (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  log_to_file(tmp1,time_stamp);
  if ((cooling) &&
     ((Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard != 0)) {
    gCooling = true;
    sleep((Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  }
  pwm_set(gFan,100);
  gStart_show_on_lcd = false;
  return;
}

