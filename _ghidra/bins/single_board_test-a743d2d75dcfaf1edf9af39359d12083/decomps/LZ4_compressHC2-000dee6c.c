
int LZ4_compressHC2(char *src,char *dst,int srcSize,int cLevel)

{
  int iVar1;
  int cLevel_local;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  
  iVar1 = LZ4_compressBound(srcSize);
  iVar1 = LZ4_compress_HC(src,dst,srcSize,iVar1,cLevel);
  return iVar1;
}

