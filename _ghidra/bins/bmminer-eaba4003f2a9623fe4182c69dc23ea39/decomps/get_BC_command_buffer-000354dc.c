
int get_BC_command_buffer(uint *buf)

{
  uint uVar1;
  uint *buf_local;
  char tmp42 [2048];
  int ret;
  
  *buf = axi_fpga_addr[0x31];
  buf[1] = axi_fpga_addr[0x32];
  uVar1 = axi_fpga_addr[0x33];
  buf[2] = uVar1;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: BC_COMMAND_BUFFER buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x\n",
             "get_BC_command_buffer",*buf,buf[1],buf[2]);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

