
/* WARNING: Unknown calling convention */

int get_fan_control(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x21];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: FAN_CONTROL is 0x%x\n","get_fan_control",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

