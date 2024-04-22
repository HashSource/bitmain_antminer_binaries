
void set_baud_chain(undefined4 param_1)

{
  byte bVar1;
  char acStack_418 [1024];
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined4 local_14;
  undefined4 local_10;
  byte local_9;
  
  local_10._1_1_ = (byte)((uint)g_misc_control >> 8);
  bVar1 = local_10._1_1_ & 0xe0;
  local_17 = 1;
  local_18 = 0;
  local_16 = 0x1c;
  local_14 = local_10;
  g_misc_control = local_10;
  for (local_9 = 0; local_9 == 0; local_9 = local_9 + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"%s bt8d=%d\n","set_baud_chain",param_1);
      _applog(2,acStack_418,0);
    }
    midd_ioctl(*(undefined4 *)(g_chain + (uint)local_9 * 0x20),1,&local_18);
  }
  return;
}

