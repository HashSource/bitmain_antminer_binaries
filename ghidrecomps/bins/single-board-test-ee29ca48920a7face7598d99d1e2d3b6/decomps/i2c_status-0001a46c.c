
undefined4 i2c_status(byte param_1,byte param_2)

{
  undefined4 uVar1;
  char acStack_420 [1024];
  byte local_20;
  byte local_1f;
  undefined local_1e;
  int local_1c;
  byte local_14;
  undefined local_13;
  undefined local_12;
  int local_c;
  
  local_13 = 0;
  local_12 = 0x20;
  local_14 = param_2;
  midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x20),0,&local_14);
  local_1e = 0x20;
  local_1c = 0;
  local_20 = param_1;
  local_1f = param_2;
  local_c = read_reg_item(&local_20,500);
  if (local_c < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      snprintf(acStack_420,0x400,"chain %d, chipaddr %02x - i2c no-response\n",(uint)param_1,
               (uint)param_2);
      _applog(1,acStack_420,0);
    }
    uVar1 = 0xffffffff;
  }
  else if (local_1c < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      snprintf(acStack_420,0x400,"chain %d, chipaddr %02x - i2c is busy\n",(uint)param_1,
               (uint)param_2);
      _applog(1,acStack_420,0);
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

