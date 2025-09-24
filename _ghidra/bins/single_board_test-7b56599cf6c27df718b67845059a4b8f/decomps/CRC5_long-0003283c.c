
uint8_t CRC5_long(uint8_t *pdata,uint32_t length)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  byte bVar4;
  BADSPACEBASE *unaff_sp;
  bool bVar5;
  uint32_t length_local;
  uint8_t *pdata_local;
  uint8_t crcout [5];
  uint8_t crcin [5];
  uint8_t din;
  uint8_t crc;
  uint32_t k;
  uint32_t j;
  uint32_t i;
  
  builtin_memcpy(crcin,"\x01\x01\x01\x01\x01",5);
  j = 0x80;
  k = 0;
  i = 0;
  pdata_local = pdata;
  while( true ) {
    uVar1 = crcin[0];
    uVar2 = crcin[2];
    uVar3 = crcin[3];
    if (length <= i) break;
    bVar5 = (j & *pdata_local) != 0;
    bVar4 = crcin[4] ^ crcin[1];
    j = j >> 1;
    k = k + 1;
    if (k == 8) {
      j = 0x80;
      k = 0;
      pdata_local = pdata_local + 1;
    }
    crcin[0] = bVar5 ^ crcin[4];
    crcin[1] = uVar1;
    crcin[2] = bVar5 ^ bVar4;
    crcin[3] = uVar2;
    crcin[4] = uVar3;
    i = i + 1;
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

