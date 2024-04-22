
void eeprom_read_bytes(uint8_t address,uint8_t *buf,uint8_t chain,uint32_t length)

{
  uint8_t uVar1;
  uint32_t length_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  uint8_t address_local;
  uint32_t i;
  
  for (i = 0; i < length; i = i + 1) {
    uVar1 = eeprom_read_one_byte(address + (char)i,chain);
    buf[i] = uVar1;
    usleep(10000);
  }
  return;
}

