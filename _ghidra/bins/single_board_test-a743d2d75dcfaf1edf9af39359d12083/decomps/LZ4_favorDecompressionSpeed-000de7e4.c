
void LZ4_favorDecompressionSpeed(LZ4_streamHC_t *LZ4_streamHCPtr,int favor)

{
  char cVar1;
  bool bVar2;
  int favor_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  bVar2 = favor != 0;
  if (bVar2) {
    favor = 1;
  }
  cVar1 = (char)favor;
  if (!bVar2) {
    cVar1 = '\0';
  }
  LZ4_streamHCPtr->minStateSize[0x4001a] = cVar1;
  return;
}

