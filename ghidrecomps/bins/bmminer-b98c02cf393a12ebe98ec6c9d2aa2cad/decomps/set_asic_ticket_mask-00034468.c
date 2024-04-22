
void set_asic_ticket_mask(uint param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_840;
  undefined4 local_83c;
  byte local_838;
  uint local_834;
  uint local_830;
  int local_82c;
  char acStack_828 [2052];
  
  iVar8 = 0;
  local_840 = 0;
  local_83c = 0;
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  local_82c = 0;
  do {
    while (*(int *)(dev + (iVar8 + 2) * 4) != 1) {
      iVar8 = iVar8 + 1;
      if (iVar8 == 0x10) {
        return;
      }
    }
    if (opt_multi_version == 0) {
      local_840._0_3_ = CONCAT12((char)(param_1 & 0x1f),0x1086);
      uVar6 = CRC5(&local_840,0x1b);
      local_840 = CONCAT13((char)uVar6,(undefined3)local_840);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                 DAT_00034608,0x86,0x10,param_1 & 0x1f,uVar6);
        _applog(7,acStack_828,0);
      }
      local_834 = local_840 << 0x18 | (local_840 >> 8 & 0xff) << 0x10 |
                  (local_840 >> 0x10 & 0xff) << 8 | local_840 >> 0x18;
    }
    else {
      bVar2 = bit_swap_table[param_1 & 0xff];
      bVar3 = bit_swap_table[param_1 >> 0x18];
      bVar4 = bit_swap_table[param_1 >> 0x10 & 0xff];
      bVar5 = bit_swap_table[param_1 >> 8 & 0xff];
      local_840 = 0x18000958;
      local_83c = CONCAT31(CONCAT12(bVar2,CONCAT11(bVar5,bVar4)),bVar3);
      local_838 = CRC5(&local_840,0x40);
      local_82c = (uint)local_838 << 0x18;
      local_834 = 0x58090018;
      local_830 = (uint)bVar2 | (uint)bVar3 << 0x18 | (uint)bVar4 << 0x10 | (uint)bVar5 << 8;
    }
    set_BC_command_buffer(&local_834);
    uVar7 = get_BC_write_command();
    uVar1 = iVar8 << 0x10;
    iVar8 = iVar8 + 1;
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar1 | 0x80800000);
  } while (iVar8 != 0x10);
  return;
}

