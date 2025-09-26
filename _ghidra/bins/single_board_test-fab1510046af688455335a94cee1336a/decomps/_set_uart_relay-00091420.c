
void _set_uart_relay(uint8_t address_interval)

{
  int iVar1;
  int iVar2;
  uint8_t address_interval_local;
  char time_stamp [48];
  char tmp42 [256];
  uint32_t gap;
  uint32_t asic;
  uint8_t asic_addr;
  uint32_t step;
  uint32_t i;
  int32_t domain;
  
  snprintf(tmp42,0x100,"address_interval = %d, Voltage_Domain = %d",(uint)address_interval,
           (g_rt.config)->domains);
  puts(tmp42);
  if ((g_rt.config)->domains < 10) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Voltage_Domain = %d, less than 9, so no need set uart relay\n","_set_uart_relay",
           (uint)address_interval);
    snprintf(tmp42,0x800,"Voltage_Domain = %d, less than 9, so no need set uart relay",
             (uint)address_interval);
    log_to_file(tmp42,time_stamp);
  }
  else {
    iVar2 = (g_rt.config)->domains;
    while (domain = iVar2 + -1, -1 < domain) {
      iVar1 = domain * (g_rt.config)->asics_in_domain;
      set_asic_uart_relay((uint8_t)(g_rt.config)->chain,iVar1 * (uint)address_interval,
                          (g_rt.config)->asics_in_domain + ((g_rt.config)->asics - iVar1) + 0xd,true
                          ,true);
      iVar2 = (g_rt.config)->asics_in_domain * iVar2 + -1;
      set_asic_uart_relay((uint8_t)(g_rt.config)->chain,iVar2 * (uint)address_interval,
                          (g_rt.config)->asics_in_domain + ((g_rt.config)->asics - iVar2) + 0xd,true
                          ,true);
      iVar2 = domain;
    }
  }
  return;
}

