
void set_fan_control(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x21] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set FAN_CONTROL is 0x%x\n","set_fan_control",value);
    _applog(7,tmp42,false);
  }
  get_fan_control();
  return;
}

