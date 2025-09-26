
int LZ4_decoderRingBufferSize(int maxBlockSize)

{
  int iVar1;
  int maxBlockSize_local;
  
  if (maxBlockSize < 0) {
    iVar1 = 0;
  }
  else if (maxBlockSize < 0x7e000001) {
    maxBlockSize_local = maxBlockSize;
    if (maxBlockSize < 0x10) {
      maxBlockSize_local = 0x10;
    }
    iVar1 = maxBlockSize_local + 0x1000e;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

