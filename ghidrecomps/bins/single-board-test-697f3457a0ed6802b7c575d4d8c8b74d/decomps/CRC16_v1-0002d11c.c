
ushort CRC16_v1(uchar *buffer,int len)

{
  int len_local;
  uchar *buffer_local;
  ushort crc;
  
  crc = 0xffff;
  len_local = len;
  buffer_local = buffer;
  while (len_local != 0) {
    crc = crc_itu_t_byte(crc,*buffer_local);
    len_local = len_local + -1;
    buffer_local = buffer_local + 1;
  }
  return crc;
}

