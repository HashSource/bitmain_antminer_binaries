
uchar CRC5_v1(uchar *ptr,uchar len)

{
  uchar uVar1;
  bool bVar2;
  uchar len_local;
  uchar *ptr_local;
  uchar crcout [5];
  uchar crcin [5];
  uchar din;
  uchar crc;
  uchar k;
  uchar j;
  uchar i;
  
  crcin._0_4_ = DAT_000374d0;
  crcin[4] = DAT_000374d4;
  j = 0x80;
  k = '\0';
  i = '\0';
  ptr_local = ptr;
  while( true ) {
    uVar1 = crcin[3];
    if (len <= i) break;
    bVar2 = (j & *ptr_local) != 0;
    crcout[1] = crcin[0];
    crcout[0] = bVar2 ^ crcin[4];
    crcout[2] = bVar2 ^ crcin[4] ^ crcin[1];
    crcout[3] = crcin[2];
    j = j >> 1;
    k = k + '\x01';
    if (k == '\b') {
      j = 0x80;
      k = '\0';
      ptr_local = ptr_local + 1;
    }
    crcin[0] = crcout[0];
    crcin[1] = crcout[1];
    crcin[2] = crcout[2];
    crcin[3] = crcout[3];
    crcin[4] = uVar1;
    i = i + '\x01';
  }
  crc = '\0';
  if (crcin[4] != '\0') {
    crc = '\x10';
  }
  if (crcin[3] != '\0') {
    crc = crc | 8;
  }
  if (crcin[2] != '\0') {
    crc = crc | 4;
  }
  if (crcin[1] != '\0') {
    crc = crc | 2;
  }
  if (crcin[0] != '\0') {
    crc = crc | 1;
  }
  return crc;
}

