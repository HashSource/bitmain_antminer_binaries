
int LZ4_uncompress(char *source,char *dest,int outputSize)

{
  int iVar1;
  int outputSize_local;
  char *dest_local;
  char *source_local;
  
  iVar1 = LZ4_decompress_fast(source,dest,outputSize);
  return iVar1;
}

