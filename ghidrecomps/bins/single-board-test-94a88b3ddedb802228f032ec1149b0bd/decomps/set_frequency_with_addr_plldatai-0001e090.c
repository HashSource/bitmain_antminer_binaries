
void set_frequency_with_addr_plldatai(int param_1,char param_2,undefined param_3,byte param_4)

{
  undefined4 uVar1;
  byte bVar2;
  uint local_38;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  uint local_28;
  byte local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  undefined2 local_e;
  undefined4 local_c;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_c = 0;
  local_e = 0;
  local_18 = (uint)param_4;
  local_14 = *(undefined4 *)(freq_pll_1385 + param_1 * 0x10 + 0xc);
  if (cgpu._2562268_4_ == 0) {
    memset(&local_2c,0,9);
    memset(&local_38,0,0xc);
    if (param_2 == '\0') {
      local_2c._0_1_ = 0x48;
    }
    else {
      local_2c._0_1_ = 0x58;
    }
    local_2c._0_2_ = CONCAT11(9,(undefined)local_2c);
    local_2c._0_3_ = CONCAT12(param_3,(undefined2)local_2c);
    local_2c = CONCAT13((char)PLL_PARAMETER,(uint3)local_2c);
    local_28 = CONCAT13((char)local_14,
                        CONCAT12((char)((uint)local_14 >> 8),
                                 CONCAT11((char)((uint)local_14 >> 0x10),
                                          (char)((uint)local_14 >> 0x18))));
    local_24 = CRC5(&local_2c,0x40);
    local_38 = (local_2c >> 0x10 & 0xff) << 8 | local_2c << 0x18 | (local_2c >> 8 & 0xff) << 0x10 |
               local_2c >> 0x18;
    local_34 = (local_28 >> 0x10 & 0xff) << 8 | local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 |
               local_28 >> 0x18;
    local_30 = (uint)local_24 << 0x18;
    while( true ) {
      local_1c = get_BC_write_command();
      if (-1 < (int)local_1c) break;
      usleep(500);
    }
    set_BC_command_buffer(&local_38);
    local_20 = local_1c & 0xfff0ffff | local_18 << 0x10 | 0x80800000;
    set_BC_write_command(local_20);
  }
  else {
    memset(&local_2c,0,9);
    memset(&local_38,0,0xc);
    local_2c._0_2_ = CONCAT11((char)((uint)local_c >> 0x10),7);
    local_2c._0_3_ = CONCAT12((char)((uint)local_c >> 8),(undefined2)local_2c);
    local_2c._3_1_ = (byte)local_c;
    bVar2 = CRC5(&local_2c,0x1b);
    local_2c._3_1_ = local_2c._3_1_ | bVar2;
    uVar1 = local_2c;
    local_38 = (uint)local_2c._2_1_ << 8 |
               (uint)(uint3)local_2c << 0x18 | (uint)local_2c._1_1_ << 0x10 | (uint)local_2c._3_1_;
    local_2c = uVar1;
    set_BC_command_buffer(&local_38);
    local_1c = get_BC_write_command();
    local_20 = local_1c & 0xfff0ffff | local_18 << 0x10 | 0x80800000;
    set_BC_write_command(local_20);
    usleep(3000);
    memset(&local_2c,0,9);
    memset(&local_38,0,0xc);
    local_2c._0_3_ = CONCAT12((char)((ushort)local_e >> 8),0x82);
    local_2c._3_1_ = (byte)local_e;
    bVar2 = CRC5(&local_2c,0x1b);
    local_2c._3_1_ = local_2c._3_1_ | bVar2;
    uVar1 = local_2c;
    local_38 = (uint)local_2c._2_1_ << 8 |
               (uint)(uint3)local_2c << 0x18 | (uint)local_2c._1_1_ << 0x10 | (uint)local_2c._3_1_;
    local_2c = uVar1;
    set_BC_command_buffer(&local_38);
    local_1c = get_BC_write_command();
    local_20 = local_1c & 0xfff0ffff | local_18 << 0x10 | 0x80800000;
    set_BC_write_command(local_20);
    usleep(5000);
  }
  return;
}

