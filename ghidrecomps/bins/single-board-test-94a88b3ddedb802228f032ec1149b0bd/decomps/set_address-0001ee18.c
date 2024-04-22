
void set_address(byte param_1,char param_2,byte param_3)

{
  uint uVar1;
  byte bVar2;
  uint local_28;
  int local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined local_14;
  uint local_10;
  uint local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (cgpu._2562268_4_ == 0) {
    local_1c._0_3_ = CONCAT12(param_3,0x541);
    local_1c = (uint)(uint3)local_1c;
    bVar2 = CRC5(&local_1c,0x20);
    local_18 = CONCAT31(local_18._1_3_,bVar2);
    local_28 = (local_1c >> 0x10 & 0xff) << 8 | local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10 |
               local_1c >> 0x18;
    local_24 = (uint)bVar2 << 0x18;
    set_BC_command_buffer(&local_28);
    local_c = get_BC_write_command();
    local_10 = local_c & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_10);
  }
  else {
    local_1c = (uint)CONCAT11(param_3,1);
    if (param_2 != '\0') {
      local_1c = CONCAT31((uint3)param_3,1) | 0x80;
    }
    bVar2 = CRC5(&local_1c,0x1b);
    uVar1 = local_1c;
    local_1c = CONCAT13(bVar2,(uint3)local_1c);
    local_28 = (uVar1 >> 0x10 & 0xff) << 8 | uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 |
               (uint)bVar2;
    set_BC_command_buffer(&local_28);
    local_c = get_BC_write_command();
    local_10 = local_c & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_10);
  }
  return;
}

