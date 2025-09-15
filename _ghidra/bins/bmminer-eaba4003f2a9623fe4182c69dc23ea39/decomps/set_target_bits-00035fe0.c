
void set_target_bits(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x4e] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set TARGET_BITS is 0x%x\n","set_target_bits",value);
    _applog(7,tmp42,false);
  }
  get_target_bits();
  return;
}

