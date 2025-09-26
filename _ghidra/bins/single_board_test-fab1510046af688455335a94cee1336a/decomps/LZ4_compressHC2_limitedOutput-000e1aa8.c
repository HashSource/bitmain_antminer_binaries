
int LZ4_compressHC2_limitedOutput(char *src,char *dst,int srcSize,int maxDstSize,int cLevel)

{
  int iVar1;
  int maxDstSize_local;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  
  iVar1 = LZ4_compress_HC(src,dst,srcSize,maxDstSize,cLevel);
  return iVar1;
}

