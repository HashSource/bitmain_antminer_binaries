
uint16_t CRC16(uchar *p_data,uint16_t w_len)

{
  byte bVar1;
  char cVar2;
  uint16_t w_len_local;
  uchar *p_data_local;
  uint16_t wIndex;
  uchar chCRCLo;
  uchar chCRCHi;
  uint16_t uVar3;
  
  _chCRCLo = 0xffff;
  w_len_local = w_len;
  p_data_local = p_data;
  while( true ) {
    uVar3 = w_len_local;
    if (w_len_local == 0) {
      uVar3 = 0;
    }
    cVar2 = (char)uVar3;
    if (w_len_local != 0) {
      cVar2 = '\x01';
    }
    w_len_local = w_len_local - 1;
    if (cVar2 == '\0') break;
    bVar1 = *p_data_local;
    p_data_local = p_data_local + 1;
    _chCRCLo = CONCAT11(""[(ushort)(chCRCLo ^ bVar1)],chCRCHi ^ ""[(ushort)(chCRCLo ^ bVar1)]);
  }
  return _chCRCLo;
}

