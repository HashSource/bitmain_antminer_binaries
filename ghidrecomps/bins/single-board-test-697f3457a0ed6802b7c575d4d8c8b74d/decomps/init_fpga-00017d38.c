
/* WARNING: Unknown calling convention */

void init_fpga(void)

{
  uint uVar1;
  char tmp42 [1024];
  uint data;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","init_fpga");
    _applog(2,tmp42,false);
  }
  write_axi_fpga(0x20,0x80008000);
  while (uVar1 = read_axi_fpga(0x20), (int)uVar1 < 0) {
    usleep(10000);
  }
  usleep(100000);
  return;
}

