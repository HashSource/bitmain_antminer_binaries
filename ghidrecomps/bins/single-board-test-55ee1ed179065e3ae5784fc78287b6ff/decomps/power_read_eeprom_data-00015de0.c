
undefined4 power_read_eeprom_data(byte param_1,int param_2,byte param_3)

{
  undefined4 uVar1;
  undefined auStack_118 [5];
  undefined auStack_113 [251];
  undefined4 local_18;
  undefined4 local_14;
  char local_d;
  ushort local_c;
  short local_a;
  
  local_18 = DAT_0002b2a4;
  local_14 = DAT_0002b2a8;
  memset(auStack_118,0,0x100);
  local_a = 0;
  if (((char)param_1 < '\0') || (0x20 < param_3)) {
    printf("invalid param addr 0x%02x, len %d\n",(uint)param_1,(uint)param_3);
    uVar1 = 0;
  }
  else {
    local_14._0_2_ = CONCAT11(param_3,param_1);
    for (local_c = 2; local_c < 6; local_c = local_c + 1) {
      local_a = (ushort)*(byte *)((int)&local_18 + (uint)local_c) + local_a;
    }
    local_14 = CONCAT13((char)((ushort)local_a >> 8),CONCAT12((char)local_a,(undefined2)local_14));
    local_d = power_send_cmd(&local_18,8,auStack_118,param_3 + 7);
    if (local_d == '\x01') {
      printf("read eeprom data:");
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        *(undefined *)(param_2 + (uint)local_c) = auStack_113[local_c];
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

