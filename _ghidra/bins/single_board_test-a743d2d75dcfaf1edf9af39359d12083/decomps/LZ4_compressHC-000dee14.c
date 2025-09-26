
int LZ4_compressHC(char *src,char *dst,int srcSize)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  
  iVar1 = LZ4_compressBound(srcSize);
  iVar1 = LZ4_compress_HC(src,dst,srcSize,iVar1,0);
  return iVar1;
}

