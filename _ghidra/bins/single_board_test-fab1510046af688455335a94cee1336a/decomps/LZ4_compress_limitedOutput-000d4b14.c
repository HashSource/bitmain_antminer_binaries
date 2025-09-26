
int LZ4_compress_limitedOutput(char *source,char *dest,int inputSize,int maxOutputSize)

{
  int iVar1;
  int maxOutputSize_local;
  int inputSize_local;
  char *dest_local;
  char *source_local;
  
  iVar1 = LZ4_compress_default(source,dest,inputSize,maxOutputSize);
  return iVar1;
}

