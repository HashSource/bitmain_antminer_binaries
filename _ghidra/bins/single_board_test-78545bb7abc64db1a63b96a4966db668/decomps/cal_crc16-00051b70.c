
uint16_t cal_crc16(uint8_t *pdata,uint16_t data_len)

{
  byte bVar1;
  uint8_t uVar2;
  uint16_t data_len_local;
  uint8_t *pdata_local;
  uint8_t save_lo;
  uint8_t save_hi;
  uint8_t ch;
  uint8_t cl;
  uint16_t flag;
  uint16_t i;
  uint8_t crc16_hi;
  uint8_t crc16_lo;
  
  crc16_lo = 0xff;
  crc16_hi = 0xff;
  for (i = 0; i < data_len; i = i + 1) {
    crc16_lo = crc16_lo ^ pdata[i];
    for (flag = 0; uVar2 = crc16_lo, flag < 8; flag = flag + 1) {
      bVar1 = crc16_hi >> 1;
      crc16_lo = crc16_lo >> 1;
      if ((crc16_hi & 1) != 0) {
        crc16_lo = crc16_lo | 0x80;
      }
      crc16_hi = bVar1;
      if ((uVar2 & 1) != 0) {
        crc16_hi = bVar1 ^ 0xa0;
        crc16_lo = crc16_lo ^ 1;
      }
    }
  }
  return CONCAT11(crc16_hi,crc16_lo);
}

