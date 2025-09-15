
_Bool _eeprom_get_freq(uint8_t chain,uint32_t *buf,uint8_t mode)

{
  byte bVar1;
  uint32_t *buf_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t freq_addr;
  uint8_t *eeprom_buf;
  int i;
  
  if (mode == '\x01') {
    bVar1 = 0x88;
  }
  else {
    bVar1 = 2;
  }
  for (i = 0; i < 0x3c; i = i + 1) {
    buf[i] = (uint)eeprom_info[chain][i + (uint)bVar1] * 5;
  }
  return true;
}

