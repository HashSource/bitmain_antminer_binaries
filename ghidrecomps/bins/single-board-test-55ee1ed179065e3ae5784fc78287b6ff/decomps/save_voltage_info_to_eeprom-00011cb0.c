
char save_voltage_info_to_eeprom(uint param_1,uint param_2)

{
  undefined uVar1;
  int iVar2;
  undefined4 local_18;
  ushort local_14;
  undefined local_12;
  undefined local_11;
  uint local_10;
  char local_9;
  
  local_9 = '\0';
  local_11 = 0;
  local_12 = 0;
  local_18 = CONCAT13((char)(param_1 / 10),0xaa55);
  local_14 = (ushort)(byte)(param_2 / 10);
  uVar1 = CRC5(&local_18,0x28);
  local_14 = CONCAT11(uVar1,(undefined)local_14);
  iVar2 = test_eeprom();
  if (iVar2 != 0) {
    for (local_10 = 0; (int)local_10 < 6; local_10 = local_10 + 1) {
      local_9 = save_byte_to_eeprom((local_10 & 0xff) - 0x66 & 0xff,
                                    *(undefined *)((int)&local_18 + local_10));
      if (local_9 != '\x01') {
        puts("save_voltage_info_to_eeprom failed!");
        return local_9;
      }
    }
  }
  return local_9;
}

