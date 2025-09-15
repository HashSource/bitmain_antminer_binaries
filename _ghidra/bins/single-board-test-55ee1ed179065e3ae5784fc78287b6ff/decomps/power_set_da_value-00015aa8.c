
void power_set_da_value(byte param_1)

{
  byte bVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  byte local_24 [4];
  undefined4 local_20;
  ushort local_1c;
  short local_1a;
  
  local_24[0] = 0x55;
  local_24[1] = 0xaa;
  local_24[2] = 6;
  local_24[3] = 0x83;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_1a = 0;
  local_20 = (uint)param_1;
  for (local_1c = 2; local_1c < 6; local_1c = local_1c + 1) {
    local_1a = (ushort)local_24[local_1c] + local_1a;
  }
  local_20._0_3_ = CONCAT12((byte)local_1a,(ushort)param_1);
  bVar1 = (byte)((ushort)local_1a >> 8);
  local_20 = CONCAT13(bVar1,(uint3)local_20);
  printf("%s, %02x, %02x, %02x, %02x, %02x, %02x, %02x, %02x\n","power_set_da_value",0x55,0xaa,6,
         0x83,(uint3)local_20 & 0xff,0,(uint)(byte)local_1a,(uint)bVar1);
  power_send_cmd(local_24,8,&local_44,8);
  return;
}

