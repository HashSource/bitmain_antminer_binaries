
uint16_t CRC16(uint8_t *p_data,uint16_t w_len)

{
  uint16_t w_len_local;
  uint8_t *p_data_local;
  uint16_t wIndex;
  uint8_t chCRCLo;
  uint8_t chCRCHi;
  
  _chCRCLo = 0xffff;
  w_len_local = w_len;
  p_data_local = p_data;
  while (w_len_local != 0) {
    _chCRCLo = CONCAT11(""[(ushort)(chCRCLo ^ *p_data_local)],
                        chCRCHi ^ ""[(ushort)(chCRCLo ^ *p_data_local)]);
    w_len_local = w_len_local - 1;
    p_data_local = p_data_local + 1;
  }
  return _chCRCLo;
}

