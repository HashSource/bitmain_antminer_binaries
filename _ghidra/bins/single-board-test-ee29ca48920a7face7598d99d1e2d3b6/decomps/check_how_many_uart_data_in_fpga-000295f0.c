
uint check_how_many_uart_data_in_fpga(byte param_1)

{
  uint uVar1;
  char acStack_408 [1024];
  
  switch(param_1) {
  case 0:
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case 1:
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 & 0x3ff;
    break;
  case 2:
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case 3:
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 & 0x3ff;
    break;
  case 4:
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case 5:
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 & 0x3ff;
    break;
  case 6:
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case 7:
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 & 0x3ff;
    break;
  case 8:
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case 9:
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 & 0x3ff;
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_408,0x400,"%s: The uart%d is not supported!!!\n",
               "check_how_many_uart_data_in_fpga",(uint)param_1);
      _applog(2,acStack_408,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}

