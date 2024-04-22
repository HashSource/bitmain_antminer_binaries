
void read_temp(uint param_1,byte param_2,uint param_3,uint param_4,byte param_5,int param_6)

{
  uint uVar1;
  undefined local_30;
  undefined local_2f;
  byte local_2e;
  undefined local_2d;
  undefined local_2c;
  undefined local_2b;
  byte local_2a;
  undefined local_29;
  byte local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (opt_multi_version != 0) {
    local_29 = (undefined)param_3;
    local_30 = 0x48;
    local_2d = 0x20;
    local_2c = 1;
    local_2b = (undefined)(param_1 | param_4);
    local_2e = param_5;
    local_2f = 9;
    local_2a = param_2;
    local_28 = CRC5(&local_30,0x40);
    local_1c = (uint)local_28 << 0x18;
    local_24 = (uint)param_5 << 8 | 0x48090020;
    local_20 = param_3 | 0x1000000 | (uint)param_2 << 8 | (param_1 | param_4) << 0x10;
    while (uVar1 = get_BC_write_command(), (int)uVar1 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(&local_24);
    set_BC_write_command(param_6 << 0x10 | 0x80800000U | uVar1 & 0xfff0ffff);
  }
  return;
}

