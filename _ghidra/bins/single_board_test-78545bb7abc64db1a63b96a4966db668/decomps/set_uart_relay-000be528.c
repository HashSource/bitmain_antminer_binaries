
void set_uart_relay(uint8_t address_interval)

{
  uint32_t uVar1;
  int iVar2;
  uint8_t address_interval_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t gap;
  uint32_t asic;
  uint8_t asic_addr;
  uint32_t step;
  uint32_t i;
  int32_t domain;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : address_interval = %d, Voltage_Domain = %d\n","set_uart_relay",(uint)address_interval
         ,(Local_Config_Information->Hash_Board).Voltage_Domain);
  snprintf(tmp1,0x100,"address_interval = %d, Voltage_Domain = %d",(uint)address_interval,
           (Local_Config_Information->Hash_Board).Voltage_Domain);
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Hash_Board).Voltage_Domain < 10) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Voltage_Domain = %d, less than 9, so no need set uart relay\n","set_uart_relay",
           (uint)address_interval);
    snprintf(tmp1,0x100,"Voltage_Domain = %d, less than 9, so no need set uart relay",
             (uint)address_interval);
    log_to_file(tmp1,time_stamp);
  }
  else {
    uVar1 = (Local_Config_Information->Hash_Board).Voltage_Domain;
    while (domain = uVar1 - 1, -1 < domain) {
      iVar2 = domain * (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain;
      set_asic_uart_relay((uint8_t)gChain,iVar2 * (uint)address_interval,
                          (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain +
                          ((Local_Config_Information->Hash_Board).Asic_Num - iVar2) + 0xd,true,true)
      ;
      iVar2 = (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain * uVar1 + -1;
      set_asic_uart_relay((uint8_t)gChain,iVar2 * (uint)address_interval,
                          (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain +
                          ((Local_Config_Information->Hash_Board).Asic_Num - iVar2) + 0xd,true,true)
      ;
      set_asic_iodriver_clko_ds((uint8_t)gChain,iVar2 * (uint)address_interval,'\x0f');
      uVar1 = domain;
    }
  }
  return;
}

