
void set_pt_ctrl(int param_1,byte param_2)

{
  undefined4 uVar1;
  char acStack_418 [1024];
  undefined4 local_18;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined4 local_10;
  int local_c;
  
  local_18._0_1_ = (byte)g_pt_ctrl;
  local_18 = CONCAT31((int3)((uint)g_pt_ctrl >> 8),(byte)local_18 & 0xfe | param_2 & 1);
  uVar1 = local_18;
  local_18._2_2_ = (ushort)((uint)g_pt_ctrl >> 0x10);
  local_18 = CONCAT22(local_18._2_2_ & 0xf800 | (ushort)((uint)(param_1 << 0x15) >> 0x15),
                      (short)uVar1);
  local_13 = 1;
  local_14 = 0;
  local_12 = 0x5c;
  local_10 = local_18;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_14);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_418,0x400,"chain %d pt_ctrl %08x\n",local_c,param_1);
      _applog(3,acStack_418,0);
    }
  }
  return;
}

