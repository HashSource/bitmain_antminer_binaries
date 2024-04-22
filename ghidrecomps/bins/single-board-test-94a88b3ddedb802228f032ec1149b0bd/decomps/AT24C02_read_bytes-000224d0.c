
void AT24C02_read_bytes(byte param_1,int param_2,undefined param_3,uint param_4)

{
  undefined uVar1;
  uint local_14;
  
  printf("--- %s\n","AT24C02_read_bytes");
  if (param_4 + param_1 < 0x101) {
    for (local_14 = 0; local_14 < param_4; local_14 = local_14 + 1) {
      uVar1 = AT24C02_read_one_byte((uint)param_1 + (local_14 & 0xff) & 0xff,param_3);
      *(undefined *)(param_2 + local_14) = uVar1;
    }
  }
  else {
    printf("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n","AT24C02_read_bytes",
           param_1 + param_4,0x100);
  }
  return;
}

