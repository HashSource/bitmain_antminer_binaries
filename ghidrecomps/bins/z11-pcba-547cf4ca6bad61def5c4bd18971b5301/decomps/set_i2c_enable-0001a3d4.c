
void set_i2c_enable(void)

{
  char acStack_41c [1024];
  uint local_1c;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  uint local_14;
  int local_10;
  int local_c;
  
  local_1c = g_misc_control | 0x4060;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      local_17 = 0;
      local_18 = *(undefined *)((int)&sensor_chip_addr + local_10);
      local_16 = 0x1c;
      local_14 = local_1c;
      midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_18);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"enable i2c, chain %d sensor %08x\n",local_c,
                 (uint)*(byte *)((int)&sensor_chip_addr + local_10));
        _applog(2,acStack_41c,0);
      }
      usleep(50000);
    }
  }
  return;
}

