
void asic_addr_interval(void)

{
  char acStack_10c [256];
  undefined4 local_c;
  
  local_c = calculate_asic_number(4);
  addr_interval = __aeabi_idiv(0x100,local_c);
  sensor_chip_addr._0_4_ = 0;
  sensor_chip_addr._4_4_ = addr_interval * 3;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf(acStack_10c,0x100,"addr-interval %d\n",addr_interval);
    _applog(3,acStack_10c,0);
  }
  return;
}

