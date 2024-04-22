
void set_pt_result(undefined4 param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  char acStack_418 [1024];
  undefined4 local_18;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined4 local_10;
  int local_c;
  
  bVar1 = (byte)local_18 & 0xfe;
  bVar2 = local_18._1_1_ & 0xf0;
  local_13 = 1;
  local_14 = 0;
  local_12 = 0x60;
  local_10 = local_18;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_14);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"chain %d pt_result %08x\n",local_c,param_1);
      _applog(2,acStack_418,0);
    }
  }
  return;
}

