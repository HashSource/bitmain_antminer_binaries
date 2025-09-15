
void set_BC_write_command(int param_1)

{
  int iVar1;
  char acStack_40c [1027];
  byte local_9;
  
  local_9 = 0;
  if (param_1 < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) goto LAB_00020e2c;
      usleep(1000);
      local_9 = local_9 + 1;
    } while (local_9 < 0x65);
    local_9 = 0;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_40c,0x400,"%s: timeout\n\n","set_BC_write_command");
      _applog(2,acStack_40c,0);
    }
  }
LAB_00020e2c:
  write_axi_fpga(0x30,param_1);
  return;
}

