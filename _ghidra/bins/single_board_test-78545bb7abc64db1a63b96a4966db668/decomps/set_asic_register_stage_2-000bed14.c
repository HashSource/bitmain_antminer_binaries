
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_asic_register_stage_2(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  set_chain_analog_mux_control
            ((uint8_t)gChain,
             (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set Diode_Vdd_Mux_Sel = 0x%03x\n","set_asic_register_stage_2",
         (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
  snprintf(tmp1,0x100,"Set Diode_Vdd_Mux_Sel = 0x%03x",
           (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set chain inactive\n","set_asic_register_stage_2");
  builtin_strncpy(tmp1,"Set chain inacti",0x10);
  tmp1[0x10] = 'v';
  tmp1[0x11] = 'e';
  tmp1[0x12] = '\0';
  log_to_file(tmp1,time_stamp);
  set_chain_inactive((uint8_t)gChain);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set asic address\n","set_asic_register_stage_2");
  builtin_strncpy(tmp1,"Set asic address",0x10);
  tmp1._16_2_ = tmp1._16_2_ & 0xff00;
  log_to_file(tmp1,time_stamp);
  set_chain_asic_address((uint8_t)gChain,gAddress_interval);
  usleep(10000);
  set_chain_clock_select_control
            ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode
             ,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set pulse_mode = 0x%02x, clk_sel = 0x%02x\n","set_asic_register_stage_2",
         (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,
         (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
  snprintf(tmp1,0x100,"Set pulse_mode = 0x%02x, clk_sel = 0x%02x",
           (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode,
           (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  set_chain_clock_delay_control
            ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
             (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
             (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x\n",
         "set_asic_register_stage_2",(Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
         (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
         (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
  snprintf(tmp1,0x100,"Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x",
           (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel,
           (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel,
           (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  set_chain_analog_mux_control((uint8_t)gChain,'\x02');
  set_chain_adc_control_disable((uint8_t)gChain);
  set_chain_iodriver_clko_ds((uint8_t)gChain,'\x01');
  enable_work_send();
  set_uart_relay((uint8_t)gAddress_interval);
  usleep(10000);
  usleep(1000000);
  return;
}

