
uint LZ4HC_countPattern(BYTE *ip,BYTE *iEnd,U32 pattern32)

{
  reg_t rVar1;
  uint uVar2;
  char cVar3;
  BYTE *pBVar4;
  U32 pattern32_local;
  BYTE *iEnd_local;
  BYTE *ip_local;
  BYTE byte;
  reg_t diff;
  reg_t pattern;
  BYTE *iStart;
  U32 bitOffset;
  reg_t patternByte;
  
  ip_local = ip;
  while( true ) {
    pBVar4 = ip_local;
    if (ip_local < iEnd + -3) {
      pBVar4 = (BYTE *)0x1;
    }
    cVar3 = (char)pBVar4;
    if (iEnd + -3 <= ip_local) {
      cVar3 = '\0';
    }
    if (cVar3 == '\0') break;
    rVar1 = LZ4_read_ARCH(ip_local);
    if ((pattern32 ^ rVar1) != 0) {
      uVar2 = LZ4_NbCommonBytes(pattern32 ^ rVar1);
      return (uint)(ip_local + (uVar2 - (int)ip));
    }
    ip_local = ip_local + 4;
  }
  uVar2 = LZ4_isLittleEndian();
  patternByte = pattern32;
  if (uVar2 == 0) {
    for (bitOffset = 0x18;
        (ip_local < iEnd && ((BYTE)(pattern32 >> (bitOffset & 0xff)) == *ip_local));
        bitOffset = bitOffset - 8) {
      ip_local = ip_local + 1;
    }
  }
  else {
    for (; (ip_local < iEnd && ((uint)*ip_local == (patternByte & 0xff))); ip_local = ip_local + 1)
    {
      patternByte = patternByte >> 8;
    }
  }
  return (uint)(ip_local + -(int)ip);
}

