
void set_block_header_version(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x4c] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set BLOCK_HEADER_VERSION is 0x%x\n","set_block_header_version",value);
    _applog(7,tmp42,false);
  }
  get_block_header_version();
  return;
}

