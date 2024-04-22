
void set_address(void)

{
  char acStack_414 [1024];
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_10 = 0;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),4,0);
    usleep(100000);
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      local_14 = local_10 * addr_interval;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_414,0x400,"%s %08x\n","set_address",local_14);
        _applog(2,acStack_414,0);
      }
      midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),3,&local_14);
      usleep(50000);
    }
  }
  return;
}

