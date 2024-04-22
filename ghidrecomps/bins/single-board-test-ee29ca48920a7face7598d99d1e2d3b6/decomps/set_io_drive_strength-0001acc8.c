
void set_io_drive_strength(void)

{
  char acStack_418 [1024];
  undefined local_18;
  undefined local_17;
  undefined local_16;
  uint local_14;
  uint local_10;
  char local_9;
  
  local_10 = g_io_drive_strength & 0xffff0fff | 0x3000;
  local_17 = 1;
  local_18 = 0;
  local_16 = 0x30;
  local_14 = local_10;
  g_io_drive_strength = local_10;
  for (local_9 = '\0'; local_9 == '\0'; local_9 = local_9 + '\x01') {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"%s %08x\n","set_io_drive_strength",local_14);
      _applog(2,acStack_418,0);
    }
    midd_ioctl(local_9,1,&local_18);
  }
  return;
}

