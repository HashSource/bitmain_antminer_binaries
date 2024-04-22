
void set_frequency_with_addr(undefined4 param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort local_842;
  uint local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  byte local_830;
  uint local_82c;
  uint local_828;
  uint local_824;
  char acStack_820 [2052];
  
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  local_82c = 0;
  local_828 = 0;
  local_824 = 0;
  local_840 = 0;
  local_842 = 0;
  local_83c = 0;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_820,0x800,"\n--- %s\n",DAT_00031494);
    _applog(7,acStack_820,0);
  }
  get_plldata_constprop_17(param_1,&local_840,&local_842,&local_83c);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_820,0x800,"%s: frequency = %d\n",DAT_00031494,param_1);
    _applog(7,acStack_820,0);
  }
  uVar4 = local_83c;
  uVar6 = opt_multi_version;
  if (opt_multi_version == 0) {
    local_834 = opt_multi_version;
    uVar7 = local_840 & 0xff;
    local_830 = 0;
    bVar1 = (byte)(local_840 >> 8);
    bVar2 = (byte)(local_840 >> 0x10);
    local_838._0_2_ = CONCAT11(bVar2,7);
    local_838 = CONCAT13((char)local_840,CONCAT12(bVar1,(undefined2)local_838));
    local_82c = opt_multi_version;
    local_828 = opt_multi_version;
    local_824 = opt_multi_version;
    uVar5 = CRC5(&local_838,0x1b);
    uVar7 = uVar5 & 0xff | uVar7;
    uVar8 = param_4 << 0x10 | 0x80800000;
    local_838 = CONCAT13((char)uVar7,(undefined3)local_838);
    local_82c = uVar7 | (uint)bVar1 << 8 | (uint)bVar2 << 0x10 | 0x7000000;
    set_BC_command_buffer(&local_82c);
    uVar5 = get_BC_write_command();
    set_BC_write_command(uVar5 & 0xfff0ffff | uVar8);
    cgsleep_us(3000,0);
    local_834 = uVar6;
    uVar3 = local_842 >> 8;
    bVar1 = (byte)local_842;
    local_838._0_3_ = CONCAT12((char)(local_842 >> 8),0x82);
    local_838 = CONCAT13(bVar1,(undefined3)local_838);
    local_830 = 0;
    local_82c = uVar6;
    local_828 = uVar6;
    local_824 = uVar6;
    uVar6 = CRC5(&local_838,0x1b);
    uVar6 = (uint)bVar1 | uVar6 & 0xff;
    local_838 = CONCAT13((char)uVar6,(undefined3)local_838);
    local_82c = uVar6 | (uint)uVar3 << 8 | 0x82000000;
    set_BC_command_buffer(&local_82c);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | uVar8);
    *(short *)(dev + (param_4 + 0x2a24) * 2 + 7) = (short)param_1;
    cgsleep_us(5000,0);
    return;
  }
  local_830 = 0;
  local_82c = 0;
  local_828 = 0;
  local_824 = 0;
  if (param_2 == 0) {
    uVar6 = 0x4809000c;
    local_838._0_1_ = 0x48;
  }
  else {
    local_838._0_1_ = 0x58;
    uVar6 = 0x5809000c;
  }
  local_838._0_2_ = CONCAT11(9,(undefined)local_838);
  local_838._0_3_ = CONCAT12((char)param_3,(undefined2)local_838);
  local_838 = CONCAT13(0xc,(undefined3)local_838);
  local_830 = CRC5(&local_838,0x40);
  local_824 = (uint)local_830 << 0x18;
  local_828 = uVar4;
  local_82c = uVar6 | param_3 << 8;
  set_BC_command_buffer(&local_82c);
  uVar6 = get_BC_write_command();
  set_BC_write_command(uVar6 & 0xfff0ffff | param_4 << 0x10 | 0x80800000U);
  *(short *)(dev + (param_4 + 0x2a24) * 2 + 7) = (short)param_1;
  cgsleep_us(10000,0);
  return;
}

