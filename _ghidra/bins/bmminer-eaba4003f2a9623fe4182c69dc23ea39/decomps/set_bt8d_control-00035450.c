
void set_bt8d_control(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0xf] = value;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: set_bt8d_control is 0x%x\n","set_bt8d_control",value);
    _applog(5,tmp42,false);
  }
  get_bt8d_control();
  return;
}

