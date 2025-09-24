
int LZ4_compress(char *src,char *dest,int srcSize)

{
  int iVar1;
  int srcSize_local;
  char *dest_local;
  char *src_local;
  
  iVar1 = LZ4_compressBound(srcSize);
  iVar1 = LZ4_compress_default(src,dest,srcSize,iVar1);
  return iVar1;
}

