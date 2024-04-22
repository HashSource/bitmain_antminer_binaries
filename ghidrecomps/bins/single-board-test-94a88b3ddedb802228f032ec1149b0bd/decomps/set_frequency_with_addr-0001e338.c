
void set_frequency_with_addr(undefined2 param_1,char param_2,undefined param_3,byte param_4)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 local_40;
  undefined2 local_3a;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  byte local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_38 = 0;
  local_3a = 0;
  local_40 = 0;
  local_14 = (uint)param_4;
  get_plldata(0x569,param_1,&local_38,&local_3a,&local_40);
  if (cgpu._2562268_4_ == 0) {
    memset(&local_28,0,9);
    memset(&local_34,0,0xc);
    if (param_2 == '\0') {
      local_28._0_1_ = 0x48;
    }
    else {
      local_28._0_1_ = 0x58;
    }
    local_28._0_2_ = CONCAT11(9,(undefined)local_28);
    local_28._0_3_ = CONCAT12(param_3,(undefined2)local_28);
    local_28 = CONCAT13((char)PLL_PARAMETER,(uint3)local_28);
    local_24 = CONCAT13((char)local_40,
                        CONCAT12((char)((uint)local_40 >> 8),
                                 CONCAT11((char)((uint)local_40 >> 0x10),
                                          (char)((uint)local_40 >> 0x18))));
    local_20 = CRC5(&local_28,0x40);
    local_34 = (local_28 >> 0x10 & 0xff) << 8 | local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 |
               local_28 >> 0x18;
    local_30 = (local_24 >> 0x10 & 0xff) << 8 | local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10 |
               local_24 >> 0x18;
    local_2c = (uint)local_20 << 0x18;
    while( true ) {
      local_18 = get_BC_write_command();
      if (-1 < (int)local_18) break;
      usleep(500);
    }
    set_BC_command_buffer(&local_34);
    local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
    set_BC_write_command(local_1c);
  }
  else {
    memset(&local_28,0,9);
    memset(&local_34,0,0xc);
    local_28._0_2_ = CONCAT11((char)((uint)local_38 >> 0x10),7);
    local_28._0_3_ = CONCAT12((char)((uint)local_38 >> 8),(undefined2)local_28);
    local_28._3_1_ = (byte)local_38;
    bVar2 = CRC5(&local_28,0x1b);
    local_28._3_1_ = local_28._3_1_ | bVar2;
    uVar1 = local_28;
    local_34 = (uint)local_28._2_1_ << 8 |
               (uint)(uint3)local_28 << 0x18 | (uint)local_28._1_1_ << 0x10 | (uint)local_28._3_1_;
    local_28 = uVar1;
    set_BC_command_buffer(&local_34);
    local_18 = get_BC_write_command();
    local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
    set_BC_write_command(local_1c);
    usleep(3000);
    memset(&local_28,0,9);
    memset(&local_34,0,0xc);
    local_28._0_3_ = CONCAT12((char)((ushort)local_3a >> 8),0x82);
    local_28._3_1_ = (byte)local_3a;
    bVar2 = CRC5(&local_28,0x1b);
    local_28._3_1_ = local_28._3_1_ | bVar2;
    uVar1 = local_28;
    local_34 = (uint)local_28._2_1_ << 8 |
               (uint)(uint3)local_28 << 0x18 | (uint)local_28._1_1_ << 0x10 | (uint)local_28._3_1_;
    local_28 = uVar1;
    set_BC_command_buffer(&local_34);
    local_18 = get_BC_write_command();
    local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
    set_BC_write_command(local_1c);
    usleep(5000);
  }
  return;
}

