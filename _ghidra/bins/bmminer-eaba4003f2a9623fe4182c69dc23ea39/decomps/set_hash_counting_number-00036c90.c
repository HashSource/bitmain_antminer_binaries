
void set_hash_counting_number(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x24] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set DHASH_ACC_CONTROL is 0x%x\n","set_hash_counting_number",value);
    _applog(7,tmp42,false);
  }
  get_hash_counting_number();
  return;
}

