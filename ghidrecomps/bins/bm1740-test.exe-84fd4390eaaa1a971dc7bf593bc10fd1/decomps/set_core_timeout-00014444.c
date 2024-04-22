
void set_core_timeout(undefined4 param_1)

{
  char acStack_114 [256];
  undefined local_14;
  undefined local_13;
  undefined4 local_10;
  int local_c;
  
  local_13 = 1;
  local_14 = 0;
  local_10 = param_1;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),0xe,&local_14);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_114,0x100,"chain %d core-timeout %08x\n",local_c,param_1);
      _applog(3,acStack_114,0);
    }
  }
  return;
}

