
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void do_core_reset(void)

{
  char time_stamp [48];
  char tmp1 [2048];
  int asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: interval %d, total ASIC num %d\n","do_core_reset",gAddress_interval,
         (Local_Config_Information->Hash_Board).Asic_Num);
  snprintf(tmp1,0x800,"interval %d, total ASIC num %d",gAddress_interval,
           (Local_Config_Information->Hash_Board).Asic_Num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: ccdly pwth %d %d\n","do_core_reset",
         (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
         (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
  snprintf(tmp1,0x800,"ccdly pwth %d %d",
           (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
           (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
  log_to_file(tmp1,time_stamp);
  for (asic = 0; (uint)asic < (Local_Config_Information->Hash_Board).Asic_Num; asic = asic + 1) {
    set_asic_core_srst_fast((uint8_t)gChain,g_start_address + asic * gAddress_interval);
    usleep(10000);
    set_asic_clock_select_control
              ((uint8_t)gChain,asic * gAddress_interval + g_start_address,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,'\0');
    usleep(10000);
    set_asic_clock_delay_control
              ((uint8_t)gChain,asic * gAddress_interval + g_start_address,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
               (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,'\0');
    set_asic_core_enable((uint8_t)gChain,g_start_address + asic * gAddress_interval);
    usleep(10000);
  }
  return;
}

