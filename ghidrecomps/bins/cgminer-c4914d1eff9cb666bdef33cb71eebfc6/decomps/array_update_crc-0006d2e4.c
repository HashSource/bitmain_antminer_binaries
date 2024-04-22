
_Bool array_update_crc(uint8_t chain)

{
  uint8_t chain_local;
  uint16_t crc;
  uint8_t *dram_buf;
  
  dram_buf = eeprom_info[chain];
  crc = 0;
  crc = CRC16(dram_buf,0xfe);
  array_write_bytes(0xfe,(uint8_t *)&crc,chain,2);
  return true;
}

