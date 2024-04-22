
void read_asic_register(byte param_1,char param_2,undefined param_3,undefined param_4)

{
  uint3 uVar1;
  uint uVar2;
  byte bVar3;
  undefined uVar4;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined local_1c;
  uint local_18;
  uint local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  if (cgpu._2562268_4_ == 0) {
    uVar4 = 0x44;
    if (param_2 != '\0') {
      uVar4 = 0x54;
    }
    local_24._0_2_ = CONCAT11(5,uVar4);
    local_24._0_3_ = CONCAT12(param_3,(undefined2)local_24);
    local_24 = CONCAT13(param_4,(uint3)local_24);
    bVar3 = CRC5(&local_24,0x20);
    local_20 = CONCAT31(local_20._1_3_,bVar3);
    local_30 = (local_24 >> 0x10 & 0xff) << 8 | local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10 |
               local_24 >> 0x18;
    local_2c = (uint)bVar3 << 0x18;
    set_BC_command_buffer(&local_30);
    local_14 = get_BC_write_command();
    local_18 = local_14 & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_18);
  }
  else {
    local_24._0_2_ = CONCAT11(param_3,4);
    local_24._0_3_ = CONCAT12(param_4,(undefined2)local_24);
    uVar1 = (uint3)local_24;
    local_24 = (uint)(uint3)local_24;
    if (param_2 != '\0') {
      local_24 = CONCAT31(uVar1 >> 8,4) | 0x80;
    }
    bVar3 = CRC5(&local_24,0x1b);
    uVar2 = local_24;
    local_24 = CONCAT13(bVar3,(uint3)local_24);
    local_30 = (uVar2 >> 0x10 & 0xff) << 8 | uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
               (uint)bVar3;
    set_BC_command_buffer(&local_30);
    local_14 = get_BC_write_command();
    local_18 = local_14 & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_18);
  }
  return;
}

