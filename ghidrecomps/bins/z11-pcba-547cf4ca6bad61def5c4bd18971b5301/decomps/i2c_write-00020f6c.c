
void i2c_write(undefined4 param_1)

{
  int iVar1;
  char acStack_40c [1024];
  uint local_c;
  
  local_c = 0;
  do {
    iVar1 = read_axi_fpga(0xc);
    if (iVar1 < 0) {
      write_axi_fpga(0xc,param_1);
      return;
    }
    usleep(5000);
  } while (local_c < 0x15);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_40c,0x400,"%s: i2c always busy, break\n","i2c_write");
    _applog(2,acStack_40c,0);
  }
  return;
}

