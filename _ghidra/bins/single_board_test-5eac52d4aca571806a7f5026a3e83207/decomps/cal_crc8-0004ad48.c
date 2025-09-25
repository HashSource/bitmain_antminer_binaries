
uint8_t cal_crc8(uint8_t *ptr,uint16_t len)

{
  uint16_t uVar1;
  uint8_t *puVar2;
  uint16_t len_local;
  uint8_t *ptr_local;
  uint8_t i;
  uint8_t crc;
  
  crc = '\0';
  len_local = len;
  ptr_local = ptr;
  while (uVar1 = len_local - 1, len_local != 0) {
    puVar2 = ptr_local + 1;
    crc = crc ^ *ptr_local;
    for (i = '\0'; len_local = uVar1, ptr_local = puVar2, i < 8; i = i + '\x01') {
      if ((crc & 1) == 0) {
        crc = crc >> 1;
      }
      else {
        crc = ~(crc >> 1 ^ 0x73);
      }
    }
  }
  return crc;
}

