
ushort crc16(uchar *buffer,int len)

{
  char cVar1;
  int iVar2;
  int len_local;
  uchar *buffer_local;
  ushort crc;
  
  crc = 0;
  len_local = len;
  buffer_local = buffer;
  while( true ) {
    iVar2 = len_local;
    if (len_local < 1) {
      iVar2 = 0;
    }
    cVar1 = (char)iVar2;
    if (0 < len_local) {
      cVar1 = '\x01';
    }
    len_local = len_local + -1;
    if (cVar1 == '\0') break;
    crc = crc << 8 ^ (ushort)crc16_table[(uint)*buffer_local ^ (uint)(crc >> 8)];
    buffer_local = buffer_local + 1;
  }
  return crc;
}

