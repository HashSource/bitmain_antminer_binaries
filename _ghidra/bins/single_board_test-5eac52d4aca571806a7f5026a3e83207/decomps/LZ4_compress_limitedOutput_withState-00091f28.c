
int LZ4_compress_limitedOutput_withState(void *state,char *src,char *dst,int srcSize,int dstSize)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *state_local;
  
  iVar1 = LZ4_compress_fast_extState(state,src,dst,srcSize,dstSize,1);
  return iVar1;
}

