
int LZ4_compressHC_withStateHC(void *state,char *src,char *dst,int srcSize)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *state_local;
  
  iVar1 = LZ4_compressBound(srcSize);
  iVar1 = LZ4_compress_HC_extStateHC(state,src,dst,srcSize,iVar1,0);
  return iVar1;
}

