
void set_frequency_scanfreq(int param_1)

{
  char acStack_41c [1024];
  char local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_10 = 0;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    get_plldata(*(undefined4 *)(local_c * 4 + param_1),&local_14);
    local_1c[0] = (char)local_c * (char)addr_interval;
    local_1c[1] = 0;
    local_1c[2] = 0xc;
    local_18 = local_14;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_41c,0x400,"%s addr %02x %d %08x\n","set_frequency_scanfreq",
               addr_interval * local_c,*(undefined4 *)(local_c * 4 + param_1),local_14);
      _applog(2,acStack_41c,0);
    }
    midd_ioctl(*(undefined4 *)(g_chain + local_10 * 0x20),1,local_1c);
    usleep(50000);
  }
  return;
}

