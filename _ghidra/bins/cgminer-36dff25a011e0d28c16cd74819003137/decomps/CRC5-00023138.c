
uchar CRC5(uchar *ptr,uchar len)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  byte bVar4;
  BADSPACEBASE *unaff_sp;
  bool bVar5;
  uchar len_local;
  uchar *ptr_local;
  uchar crcout [5];
  uchar crcin [5];
  uchar din;
  uchar crc;
  uchar k;
  uchar j;
  uchar i;
  
  builtin_memcpy(crcin,"\x01\x01\x01\x01",4);
  crcin[4] = '\x01';
  j = 0x80;
  k = '\0';
  i = '\0';
  ptr_local = ptr;
  while( true ) {
    uVar1 = crcin[0];
    uVar2 = crcin[2];
    uVar3 = crcin[3];
    if (len <= i) break;
    bVar5 = (j & *ptr_local) != 0;
    bVar4 = crcin[4] ^ crcin[1];
    j = j >> 1;
    k = k + '\x01';
    if (k == '\b') {
      j = 0x80;
      k = '\0';
      ptr_local = ptr_local + 1;
    }
    crcin[0] = bVar5 ^ crcin[4];
    crcin[1] = uVar1;
    crcin[2] = bVar5 ^ bVar4;
    crcin[3] = uVar2;
    crcin[4] = uVar3;
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

