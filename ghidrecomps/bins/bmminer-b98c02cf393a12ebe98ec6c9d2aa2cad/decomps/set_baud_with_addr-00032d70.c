
void set_baud_with_addr(uint param_1,int param_2,undefined param_3,int param_4,int param_5,
                       int param_6,int param_7)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint local_828;
  undefined4 local_824;
  byte local_820;
  uint local_81c;
  uint local_818;
  int local_814;
  char acStack_810 [2048];
  
  local_824 = 0;
  local_820 = 0;
  local_81c = 0;
  local_818 = 0;
  local_814 = 0;
  if (opt_multi_version != 0) {
    if (param_2 == 0) {
      local_828._0_1_ = 0x48;
    }
    else {
      local_828._0_1_ = 0x58;
    }
    local_828._0_2_ = CONCAT11(9,(undefined)local_828);
    local_828 = CONCAT13(0x1c,CONCAT12(param_3,(undefined2)local_828));
    if (param_7 == 0) {
      local_824._0_2_ = 0x2140;
    }
    else {
      local_824._0_2_ = 0x2040;
    }
    bVar1 = (byte)param_1;
    bVar2 = bVar1 & 0x1f;
    if (param_5 == 0) {
      local_824._0_3_ = CONCAT12(bVar1,(undefined2)local_824) & 0x1fffff;
      local_824 = CONCAT13(0x80,(uint3)local_824);
    }
    else {
      bVar2 = bVar2 | 0x40;
      local_824._0_3_ = CONCAT12(bVar1,(undefined2)local_824) & 0x1fffff | 0x400000;
      local_824 = CONCAT13(0xe0,(uint3)local_824);
    }
    if (param_6 != 0) {
      local_824 = CONCAT13(local_824._3_1_,CONCAT12(bVar2,(undefined2)local_824)) | 0x800000;
    }
    local_820 = 0;
    local_820 = CRC5(&local_828,0x40);
    local_814 = (uint)local_820 << 0x18;
    local_81c = local_828 << 0x18 | (local_828 >> 8 & 0xff) << 0x10 |
                (local_828 >> 0x10 & 0xff) << 8 | local_828 >> 0x18;
    local_818 = local_824 << 0x18 | (local_824 >> 8 & 0xff) << 0x10 |
                (local_824 >> 0x10 & 0xff) << 8 | local_824 >> 0x18;
    while (uVar4 = get_BC_write_command(), (int)uVar4 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(&local_81c);
    set_BC_write_command(param_4 << 0x10 | 0x80800000U | uVar4 & 0xfff0ffff);
    return;
  }
  local_828 = (uint)CONCAT12((char)(param_1 & 0x1f),0x1086);
  uVar3 = CRC5(&local_828,0x1b);
  local_828 = CONCAT13((char)uVar3,(undefined3)local_828);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_810,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
             DAT_00032f0c,0x86,0x10,param_1 & 0x1f,uVar3);
    _applog(7,acStack_810,0);
  }
  local_81c = local_828 << 0x18 | (local_828 >> 8 & 0xff) << 0x10 | (local_828 >> 0x10 & 0xff) << 8
              | local_828 >> 0x18;
  set_BC_command_buffer(&local_81c);
  uVar4 = get_BC_write_command();
  set_BC_write_command(uVar4 & 0xfff0ffff | param_4 << 0x10 | 0x80800000U);
  return;
}

