
void set_baud(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_840;
  undefined4 local_83c;
  byte local_838;
  uint local_834;
  uint local_830;
  int local_82c;
  char acStack_828 [2052];
  
  uVar5 = param_1 & 0x1f;
  uVar6 = uVar5 << 8 | 0x200080;
  iVar4 = 0;
  local_840 = 0;
  local_83c = 0;
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  local_82c = 0;
  do {
    while (*(int *)(dev + (iVar4 + 2) * 4) != 1) {
      iVar4 = iVar4 + 1;
      if (iVar4 == 0x10) goto LAB_000348ce;
    }
    if (opt_multi_version == 0) {
      local_840 = CONCAT22(CONCAT11(local_840._3_1_,(byte)uVar5),0x1086);
      uVar2 = CRC5(&local_840,0x1b);
      local_840 = CONCAT13((char)uVar2,(undefined3)local_840);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                 DAT_000349a8,0x86,0x10,uVar5,uVar2);
        _applog(7,acStack_828,0);
      }
      local_834 = local_840 << 0x18 | (local_840 >> 8 & 0xff) << 0x10 |
                  (local_840 >> 0x10 & 0xff) << 8 | local_840 >> 0x18;
    }
    else {
      local_840 = 0x1c000958;
      local_83c = CONCAT13(0x80,(uint3)(byte)uVar5 << 0x10);
      local_83c = CONCAT22(local_83c._2_2_,0x2000);
      local_838 = CRC5(&local_840,0x40);
      local_82c = (uint)local_838 << 0x18;
      local_834 = 0x5809001c;
      local_830 = uVar6;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x\n",
                 DAT_000349a8,0x5809001c,uVar6,local_82c);
        _applog(7,acStack_828,0);
      }
    }
    set_BC_command_buffer(&local_834);
    uVar3 = get_BC_write_command();
    uVar1 = iVar4 << 0x10;
    iVar4 = iVar4 + 1;
    set_BC_write_command(uVar3 & 0xfff0ffff | uVar1 | 0x80800000);
  } while (iVar4 != 0x10);
LAB_000348ce:
  cgsleep_us(50000,0);
  uVar6 = get_BC_write_command();
  set_BC_write_command(uVar6 & 0xffffffe0 | uVar5);
  *(char *)(dev + 0x542f) = (char)param_1;
  return;
}

