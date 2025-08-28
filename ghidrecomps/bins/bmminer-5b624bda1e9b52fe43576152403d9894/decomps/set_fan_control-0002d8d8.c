
/* WARNING: Unknown calling convention */

void set_fan_control(uint value)

{
  _Bool _Var1;
  char tmp42 [2048];
  
  _Var1 = opt_debug;
  axi_fpga_addr[0x21] = value;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set FAN_CONTROL is 0x%x\n","set_fan_control",value);
    _applog(7,tmp42,false);
  }
  get_fan_control();
  return;
}

