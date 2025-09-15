
void set_QN_write_data_command(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x20] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set QN_WRITE_DATA_COMMAND is 0x%x\n","set_QN_write_data_command",value
            );
    _applog(7,tmp42,false);
  }
  get_QN_write_data_command();
  return;
}

