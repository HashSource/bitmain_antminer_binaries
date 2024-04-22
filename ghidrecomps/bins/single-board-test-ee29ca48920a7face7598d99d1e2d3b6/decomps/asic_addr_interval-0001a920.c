
void asic_addr_interval(void)

{
  char acStack_40c [1024];
  undefined4 local_c;
  
  local_c = calculate_asic_number(3);
  addr_interval = __aeabi_idiv(0x100,local_c);
  sensor_chip_addr._0_1_ = 0;
  sensor_chip_addr._1_1_ = (undefined)((addr_interval & 0xff) << 1);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_40c,0x400,"%s %u\n","asic_addr_interval",addr_interval);
    _applog(2,acStack_40c,0);
  }
  return;
}

