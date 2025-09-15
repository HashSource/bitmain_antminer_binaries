
uint8_t eeprom_read_one_byte(uint8_t address,uint8_t chain)

{
  uint8_t uVar1;
  uint8_t chain_local;
  uint8_t address_local;
  uint8_t data;
  
  uVar1 = read_eeprom_iic(chain,address);
  return uVar1;
}

