
void eeprom_write_one_byte(uint8_t address,uint8_t data,uint8_t chain)

{
  uint8_t chain_local;
  uint8_t data_local;
  uint8_t address_local;
  
  write_eeprom_iic(chain,address,data);
  return;
}

