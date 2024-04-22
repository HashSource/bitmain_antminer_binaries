
void set_timeout(ushort param_1)

{
  char acStack_114 [256];
  undefined local_14;
  undefined local_13;
  uint local_10;
  int local_c;
  
  local_13 = 1;
  local_14 = 0;
  local_10 = (uint)param_1;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),0x1f,&local_14);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_114,0x100,"chain %d timeout %08x\n",local_c,(uint)param_1);
      _applog(3,acStack_114,0);
    }
  }
  return;
}

