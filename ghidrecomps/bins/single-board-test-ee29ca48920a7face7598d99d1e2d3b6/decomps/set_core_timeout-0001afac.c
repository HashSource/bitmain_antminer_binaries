
void set_core_timeout(undefined4 param_1)

{
  char acStack_414 [1024];
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined4 local_10;
  int local_c;
  
  local_13 = 1;
  local_14 = 0;
  local_12 = 0x28;
  g_core_timeout = param_1;
  local_10 = param_1;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_414,0x400,"%s %08x\n","set_core_timeout",param_1);
      _applog(2,acStack_414,0);
    }
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_14);
  }
  return;
}

