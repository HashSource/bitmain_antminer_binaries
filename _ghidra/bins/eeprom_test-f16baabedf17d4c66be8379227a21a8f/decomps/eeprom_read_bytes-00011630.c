
void eeprom_read_bytes(uint8_t address,uint8_t *buf,uint8_t chain,uint8_t length)

{
  uint8_t uVar1;
  uint8_t *buf_local;
  uint8_t length_local;
  uint8_t chain_local;
  uint8_t address_local;
  uint8_t i;
  
  if ((uint)length + (uint)address < 0x101) {
    for (i = '\0'; i < length; i = i + '\x01') {
      uVar1 = eeprom_read_one_byte(i + address,chain);
      buf[i] = uVar1;
    }
  }
  return;
}

