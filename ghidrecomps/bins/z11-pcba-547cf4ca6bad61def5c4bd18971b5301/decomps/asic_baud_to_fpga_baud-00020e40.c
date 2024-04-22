
undefined4 asic_baud_to_fpga_baud(byte param_1)

{
  undefined4 uVar1;
  char acStack_408 [1024];
  
  switch(param_1) {
  case 0:
    uVar1 = 1;
    break;
  case 1:
    uVar1 = 3;
    break;
  case 2:
    uVar1 = 5;
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_408,0x400,"%s: Don\'t support ASIC baud = %d, error!!!\n",
               "asic_baud_to_fpga_baud",(uint)param_1);
      _applog(2,acStack_408,0);
    }
    uVar1 = 0x35;
    break;
  case 6:
    uVar1 = 0xd;
    break;
  case 0x1a:
    uVar1 = 0x35;
  }
  return uVar1;
}

