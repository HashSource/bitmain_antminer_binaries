
int LZ4_compress_default(char *src,char *dst,int srcSize,int maxOutputSize)

{
  int iVar1;
  int maxOutputSize_local;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  
  iVar1 = LZ4_compress_fast(src,dst,srcSize,maxOutputSize,1);
  return iVar1;
}

