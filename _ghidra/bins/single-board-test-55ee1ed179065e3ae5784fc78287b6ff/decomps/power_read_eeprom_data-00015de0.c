
undefined4 power_read_eeprom_data(byte param_1,int param_2,byte param_3)

{
  undefined4 uVar1;
  undefined1 auStack_118 [5];
  undefined1 auStack_113 [251];
  byte local_18 [11];
  char local_d;
  ushort local_c;
  short local_a;
  
  local_18[0] = 0x55;
  local_18[1] = 0xaa;
  local_18[2] = 6;
  local_18[3] = 6;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  memset(auStack_118,0,0x100);
  local_a = 0;
  if (((char)param_1 < '\0') || (0x20 < param_3)) {
    printf("invalid param addr 0x%02x, len %d\n",(uint)param_1,(uint)param_3);
    uVar1 = 0;
  }
  else {
    local_18[5] = param_3;
    local_18[4] = param_1;
    for (local_c = 2; local_c < 6; local_c = local_c + 1) {
      local_a = (ushort)local_18[local_c] + local_a;
    }
    local_18[6] = (char)local_a;
    local_18[7] = (char)((ushort)local_a >> 8);
    local_d = power_send_cmd(local_18,8,auStack_118,param_3 + 7);
    if (local_d == '\x01') {
      printf("read eeprom data:");
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        *(undefined1 *)(param_2 + (uint)local_c) = auStack_113[local_c];
        printf("%02x ",(uint)*(byte *)(param_2 + (uint)local_c));
      }
      putchar(10);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

