
char * LZ4_slideInputBufferHC(void *LZ4HC_Data)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *LZ4HC_Data_local;
  BYTE *bufferStart;
  LZ4_streamHC_t *ctx;
  
  iVar2 = *(int *)((int)LZ4HC_Data + 0x40004);
  iVar1 = *(int *)((int)LZ4HC_Data + 0x40010);
  iVar3 = *(int *)((int)LZ4HC_Data + 0x4000c);
  LZ4_resetStreamHC_fast((LZ4_streamHC_t *)LZ4HC_Data,(int)*(short *)((int)LZ4HC_Data + 0x40018));
  return (char *)((iVar1 - iVar3) + iVar2);
}

