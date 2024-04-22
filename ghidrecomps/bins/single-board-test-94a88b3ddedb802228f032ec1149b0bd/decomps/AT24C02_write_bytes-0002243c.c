
void AT24C02_write_bytes(byte param_1,int param_2,undefined param_3,uint param_4)

{
  uint local_c;
  
  printf("--- %s\n","AT24C02_write_bytes");
  if (param_4 + param_1 < 0x101) {
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      AT24C02_write_one_byte
                ((uint)param_1 + (local_c & 0xff) & 0xff,*(undefined *)(local_c + param_2),param_3);
      usleep(5000);
    }
  }
  else {
    printf("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n","AT24C02_write_bytes",
           param_1 + param_4,0x100);
  }
  return;
}

