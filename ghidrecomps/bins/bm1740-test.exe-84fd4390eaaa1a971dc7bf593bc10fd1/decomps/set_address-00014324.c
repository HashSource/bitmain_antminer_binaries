
void set_address(void)

{
  char acStack_114 [256];
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_10 = 0;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),0x14,0);
    usleep(100000);
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      local_14 = local_10 * addr_interval;
      midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),0x13,&local_14);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_114,0x100,"chain %d chip %d addres %08x\n",local_c,local_10,local_14);
        _applog(3,acStack_114,0);
      }
      usleep(50000);
    }
  }
  return;
}

