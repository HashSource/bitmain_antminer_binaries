
int LZ4_uncompress_unknownOutputSize(char *source,char *dest,int isize,int maxOutputSize)

{
  int iVar1;
  int maxOutputSize_local;
  int isize_local;
  char *dest_local;
  char *source_local;
  
  iVar1 = LZ4_decompress_safe(source,dest,isize,maxOutputSize);
  return iVar1;
}

