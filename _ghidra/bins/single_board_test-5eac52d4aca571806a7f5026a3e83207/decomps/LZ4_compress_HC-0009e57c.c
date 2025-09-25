
int LZ4_compress_HC(char *src,char *dst,int srcSize,int dstCapacity,int compressionLevel)

{
  void *state;
  int iVar1;
  int dstCapacity_local;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  int cSize;
  LZ4_streamHC_t *statePtr;
  
  state = malloc(0x40038);
  if (state == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = LZ4_compress_HC_extStateHC(state,src,dst,srcSize,dstCapacity,compressionLevel);
    free(state);
  }
  return iVar1;
}

