
void set_frequency_with_addr_plldatai(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_30;
  uint local_2c;
  byte local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar2 = opt_multi_version;
  uVar3 = *(undefined4 *)(freq_pll_1385 + param_1 * 0x10 + 0xc);
  if (opt_multi_version != 0) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    if (param_2 == 0) {
      uVar2 = 0x4809000c;
      local_30._0_2_ = 0x48;
    }
    else {
      local_30._0_2_ = 0x58;
      uVar2 = 0x5809000c;
    }
    local_30._0_3_ = CONCAT12((char)param_3,(undefined2)local_30);
    local_30 = CONCAT13(0xc,(undefined3)local_30);
    local_2c = CONCAT13((char)uVar3,
                        CONCAT12((char)((uint)uVar3 >> 8),
                                 CONCAT11((char)((uint)uVar3 >> 0x10),(char)((uint)uVar3 >> 0x18))))
    ;
    local_30._0_2_ = CONCAT11(9,(undefined)local_30);
    local_28 = CRC5(&local_30,0x40);
    local_1c = (uint)local_28 << 0x18;
    local_24 = uVar2 | param_3 << 8;
    local_20 = uVar3;
    while (uVar2 = get_BC_write_command(), (int)uVar2 < 0) {
      cgsleep_us(500,0);
    }
    set_BC_command_buffer(&local_24);
    set_BC_write_command(param_4 << 0x10 | 0x80800000U | uVar2 & 0xfff0ffff);
    cgsleep_us(10000,0);
    return;
  }
  local_2c = opt_multi_version;
  local_30 = 7;
  local_28 = 0;
  local_24 = opt_multi_version;
  local_20 = opt_multi_version;
  local_1c = opt_multi_version;
  uVar1 = CRC5(&local_30,0x1b);
  local_24 = uVar1 | 0x7000000;
  local_30 = CONCAT13((char)uVar1,(undefined3)local_30);
  set_BC_command_buffer(&local_24);
  uVar1 = get_BC_write_command();
  uVar4 = param_4 << 0x10 | 0x80800000;
  set_BC_write_command(uVar1 & 0xfff0ffff | uVar4);
  cgsleep_us(3000,0);
  local_20 = uVar2;
  local_30 = 0x82;
  local_1c = uVar2;
  local_2c = uVar2;
  local_28 = 0;
  local_24 = uVar2;
  uVar2 = CRC5(&local_30,0x1b);
  local_24 = uVar2 | 0x82000000;
  local_30 = CONCAT13((char)uVar2,(undefined3)local_30);
  set_BC_command_buffer(&local_24);
  uVar2 = get_BC_write_command();
  set_BC_write_command(uVar2 & 0xfff0ffff | uVar4);
  cgsleep_us(5000,0);
  return;
}

