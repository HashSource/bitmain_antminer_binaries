
int LZ4_compress_fast(char *source,char *dest,int inputSize,int maxOutputSize,int acceleration)

{
  int iVar1;
  int maxOutputSize_local;
  int inputSize_local;
  char *dest_local;
  char *source_local;
  LZ4_stream_t ctx;
  int result;
  LZ4_stream_t *ctxPtr;
  
  ctxPtr = &ctx;
  iVar1 = LZ4_compress_fast_extState(ctxPtr,source,dest,inputSize,maxOutputSize,acceleration);
  return iVar1;
}

