
void array_write_one_byte(uint8_t address,uint8_t data,uint8_t chain)

{
  uint8_t chain_local;
  uint8_t data_local;
  uint8_t address_local;
  
  eeprom_info[chain][address] = data;
  eeprom_dirty_flag[chain][address >> 3] =
       (byte)(1 << (address & 7)) | eeprom_dirty_flag[chain][address >> 3];
  return;
}

