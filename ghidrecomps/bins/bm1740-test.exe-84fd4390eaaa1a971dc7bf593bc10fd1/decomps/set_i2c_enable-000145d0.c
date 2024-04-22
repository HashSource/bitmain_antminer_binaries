
void set_i2c_enable(void)

{
  char acStack_114 [256];
  undefined local_14;
  undefined local_13;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      local_13 = 0;
      local_14 = (undefined)*(undefined4 *)((int)&sensor_chip_addr + local_10 * 4);
      midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),5,&local_14);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_114,0x100,"enable i2c, chain %d sensor %08x\n",local_c,local_10);
        _applog(3,acStack_114,0);
      }
      usleep(50000);
    }
  }
  return;
}

