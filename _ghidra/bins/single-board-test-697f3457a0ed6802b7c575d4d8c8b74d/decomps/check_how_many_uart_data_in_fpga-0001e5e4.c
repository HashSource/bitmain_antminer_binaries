
uint check_how_many_uart_data_in_fpga(uchar which_uart)

{
  uint uVar1;
  uchar which_uart_local;
  char tmp42 [1024];
  
  switch(which_uart) {
  case '\0':
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x01':
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x02':
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x03':
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x04':
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x05':
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x06':
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\a':
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\b':
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\t':
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 & 0x3ff;
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga"
               ,(uint)which_uart);
      _applog(2,tmp42,false);
    }
    uVar1 = 0;
  }
  return uVar1;
}

