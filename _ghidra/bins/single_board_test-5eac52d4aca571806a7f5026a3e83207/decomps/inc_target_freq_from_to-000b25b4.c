
void inc_target_freq_from_to(uint32_t from_freq,uint32_t to_freq)

{
  uint32_t to_freq_local;
  uint32_t from_freq_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t user_divider;
  
  usleep(5000);
  memset(&user_divider,0,4);
  set_chain_pllparameter_userdivider((uint8_t)gChain,'\0',user_divider);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x\n"
         ,"inc_target_freq_from_to",(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
         (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  snprintf(tmp1,0x100,
           "Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x"
           ,(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
           (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
    inc_freq_with_fixed_step_parallel
              ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel,
               from_freq,to_freq,6.25);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : use config smooth_voltage\n","inc_target_freq_from_to");
    builtin_strncpy(tmp1,"use config smooth_voltag",0x18);
    tmp1[0x18] = 'e';
    tmp1[0x19] = '\0';
    log_to_file(tmp1,time_stamp);
    inc_freq_with_adjust_voltage
              ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel,
               from_freq,to_freq,6.25);
  }
  set_chain_baud((uint8_t)gChain,(Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set chain baud as %d\n","inc_target_freq_from_to",
         (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  snprintf(tmp1,0x100,"Set chain baud as %d",
           (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  log_to_file(tmp1,time_stamp);
  return;
}

