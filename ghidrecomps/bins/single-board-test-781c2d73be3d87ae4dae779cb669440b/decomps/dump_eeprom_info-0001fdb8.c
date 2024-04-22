
void dump_eeprom_info(eeprom_layout_t eeprom)

{
  uint in_r0;
  byte *pbVar1;
  undefined4 local_10;
  byte local_c [12];
  
  pbVar1 = (byte *)((int)&local_10 + 3);
  local_10 = in_r0;
  puts("\n--- dump eeprom info:");
  printf("fixture_header:      0x%04x\n",local_10 & 0xffff);
  printf("fixture_version:     0x%04x\n",local_10 >> 0x10);
  printf("hash_board_sn:       0x");
  do {
    pbVar1 = pbVar1 + 1;
    printf("%02x",(uint)*pbVar1);
  } while (pbVar1 != eeprom.hash_board_sn + 3);
  putchar(10);
  printf("pcb_version:         0x%04x\n",(uint)(ushort)eeprom.hash_board_sn._4_2_);
  printf("bom_version:         0x%04x\n",(uint)(ushort)eeprom.hash_board_sn._6_2_);
  printf("temp_sensor_type:    0x%02x\n",(uint)eeprom.hash_board_sn[8]);
  printf("product_id:          0x%02x\n",(uint)eeprom.hash_board_sn[9]);
  printf("crc_test_fixture:    0x%04x\n",(uint)(ushort)eeprom.hash_board_sn._10_2_);
  return;
}

