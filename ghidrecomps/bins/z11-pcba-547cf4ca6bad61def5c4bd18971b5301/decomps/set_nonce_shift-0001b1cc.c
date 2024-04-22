
void set_nonce_shift(byte param_1)

{
  char acStack_418 [1024];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_14 = DAT_000333d8;
  local_18._0_1_ = (byte)g_nonce_shift;
  local_18 = CONCAT31((int3)((uint)g_nonce_shift >> 8),(byte)local_18 & 0xe0 | param_1 & 0x1f);
  g_nonce_shift = local_18;
  local_10 = local_18;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"%s %08x\n","set_nonce_shift",g_nonce_shift);
      _applog(2,acStack_418,0);
    }
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_14);
  }
  return;
}

