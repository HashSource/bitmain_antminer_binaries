
uint LZ4HC_reverseCountPattern(BYTE *ip,BYTE *iLow,U32 pattern)

{
  U32 UVar1;
  char cVar2;
  BYTE *pBVar3;
  U32 pattern_local;
  BYTE *iLow_local;
  BYTE *ip_local;
  BYTE *iStart;
  BYTE *bytePtr;
  
  pattern_local = pattern;
  iLow_local = iLow;
  ip_local = ip;
  iStart = ip;
  while( true ) {
    pBVar3 = ip_local;
    if (iLow_local + 4 <= ip_local) {
      pBVar3 = (BYTE *)0x1;
    }
    cVar2 = (char)pBVar3;
    if (ip_local < iLow_local + 4) {
      cVar2 = '\0';
    }
    if ((cVar2 == '\0') || (UVar1 = LZ4_read32(ip_local + -4), UVar1 != pattern_local)) break;
    ip_local = ip_local + -4;
  }
  bytePtr = (BYTE *)((int)&pattern_local + 3);
  while( true ) {
    pBVar3 = iLow_local;
    if (iLow_local < ip_local) {
      pBVar3 = (BYTE *)0x1;
    }
    cVar2 = (char)pBVar3;
    if (ip_local <= iLow_local) {
      cVar2 = '\0';
    }
    if ((cVar2 == '\0') || (ip_local[-1] != *bytePtr)) break;
    ip_local = ip_local + -1;
    bytePtr = bytePtr + -1;
  }
  return (int)iStart - (int)ip_local;
}

