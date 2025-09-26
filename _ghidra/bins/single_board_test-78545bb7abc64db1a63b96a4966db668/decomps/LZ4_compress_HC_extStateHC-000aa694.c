
int LZ4_compress_HC_extStateHC
              (void *state,char *src,char *dst,int srcSize,int dstCapacity,int compressionLevel)

{
  LZ4_streamHC_t *pLVar1;
  int iVar2;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *state_local;
  LZ4_streamHC_t *ctx;
  
  pLVar1 = LZ4_initStreamHC(state,0x40038);
  if (pLVar1 == (LZ4_streamHC_t *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = LZ4_compress_HC_extStateHC_fastReset(state,src,dst,srcSize,dstCapacity,compressionLevel)
    ;
  }
  return iVar2;
}

