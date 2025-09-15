
void init_fpga(void)

{
  int iVar1;
  char acStack_40c [1024];
  undefined4 local_c;
  
  local_c = 0x80008000;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_40c,0x400,"--- %s\n","init_fpga");
    _applog(2,acStack_40c,0);
  }
  write_axi_fpga(0x20,local_c);
  while (iVar1 = read_axi_fpga(0x20), iVar1 < 0) {
    usleep(10000);
  }
  usleep(100000);
  return;
}

