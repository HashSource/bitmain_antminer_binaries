
uint8_t array_read_one_byte(uint8_t address,uint8_t chain)

{
  uint8_t chain_local;
  uint8_t address_local;
  
  return eeprom_info[chain][address];
}

