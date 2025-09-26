
int LZ4_compressHC2_limitedOutput_withStateHC
              (void *state,char *src,char *dst,int srcSize,int maxDstSize,int cLevel)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *state_local;
  
  iVar1 = LZ4_compress_HC_extStateHC(state,src,dst,srcSize,maxDstSize,cLevel);
  return iVar1;
}

