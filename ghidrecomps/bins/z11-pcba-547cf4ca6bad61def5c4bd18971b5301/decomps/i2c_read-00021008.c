
uint i2c_read(uint param_1)

{
  char acStack_410 [1024];
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0xff;
  i2c_write(param_1 | 0x2000000);
  do {
    usleep(5000);
    local_10 = read_axi_fpga(0xc);
    if ((int)local_10 < 0) {
      return local_10 & 0xff;
    }
  } while (local_c < 0x15);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_410,0x400,"%s: i2c always busy, break\n","i2c_read");
    _applog(2,acStack_410,0);
  }
  return 0xff;
}

