
/* WARNING: Unknown calling convention */

void eeprom_dump(void)

{
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      travel_eeprom_store((uint8_t)i,false);
    }
  }
  return;
}

