
undefined4 power_save_eeprom_data(byte param_1,int param_2,byte param_3)

{
  undefined4 uVar1;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  byte local_114 [4];
  byte local_110;
  undefined auStack_10f [254];
  char local_11;
  uint local_10;
  ushort local_c;
  short local_a;
  
  memset(local_114,0,0x100);
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_a = 0;
  local_10 = param_3 + 7;
  if (((char)param_1 < '\0') || (0x20 < param_3)) {
    printf("invalid param addr 0x%02x, len %d\n",(uint)param_1,(uint)param_3);
    uVar1 = 0;
  }
  else {
    local_114[0] = 0x55;
    local_114[1] = 0xaa;
    local_114[2] = param_3 + 5;
    local_114[3] = 0x86;
    local_110 = param_1;
    for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
      auStack_10f[local_c] = *(undefined *)(param_2 + (uint)local_c);
    }
    for (local_c = 2; local_c < (ushort)(param_3 + 5); local_c = local_c + 1) {
      local_a = (ushort)local_114[local_c] + local_a;
    }
    local_114[local_10 - 2] = (byte)local_a;
    local_114[local_10 - 1] = (byte)((ushort)local_a >> 8);
    local_11 = power_send_cmd(local_114,local_10 & 0xff,&local_134,8);
    if (local_11 == '\x01') {
      if (local_130._1_1_ == '\x01') {
        puts("save eeprom data success ");
        uVar1 = 1;
      }
      else {
        puts("save eeprom data failed ");
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

