
/* WARNING: Unknown calling convention */

int get_QN_write_data_command(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x20];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: QN_WRITE_DATA_COMMAND is 0x%x\n","get_QN_write_data_command",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

