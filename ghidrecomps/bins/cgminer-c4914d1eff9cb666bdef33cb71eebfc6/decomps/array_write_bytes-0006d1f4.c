
void array_write_bytes(uint8_t address,uint8_t *buf,uint8_t chain,uint32_t length)

{
  uint32_t length_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  uint8_t address_local;
  uint32_t i;
  
  for (i = 0; i < length; i = i + 1) {
    array_write_one_byte(address + (char)i,buf[i],chain);
  }
  return;
}

