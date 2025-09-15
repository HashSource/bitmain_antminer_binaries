
void set_merkle_bin_number(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x45] = value & 0xffff;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set MERKLE_BIN_NUMBER is 0x%x\n","set_merkle_bin_number",
             value & 0xffff);
    _applog(7,tmp42,false);
  }
  get_merkle_bin_number();
  return;
}

