
/* WARNING: Unknown calling convention */

void set_BC_command_buffer(uint *value)

{
  _Bool _Var1;
  uint *puVar2;
  uint buf [4];
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  buf[1] = 0;
  axi_fpga_addr[0x31] = *value;
  _Var1 = opt_debug;
  buf[2] = 0;
  puVar2[0x32] = value[1];
  buf[3] = 0;
  buf[0] = 0;
  puVar2[0x33] = value[2];
  if ((_Var1 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,
             "%s: set BC_COMMAND_BUFFER value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x\n",
             "set_BC_command_buffer",*value,value[1],value[2]);
    _applog(7,tmp42,false);
  }
  get_BC_command_buffer(buf);
  return;
}

