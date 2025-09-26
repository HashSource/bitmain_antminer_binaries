
int LZ4_compress_continue(LZ4_stream_t *LZ4_stream,char *source,char *dest,int inputSize)

{
  int iVar1;
  int inputSize_local;
  char *dest_local;
  char *source_local;
  LZ4_stream_t *LZ4_stream_local;
  
  iVar1 = LZ4_compressBound(inputSize);
  iVar1 = LZ4_compress_fast_continue(LZ4_stream,source,dest,inputSize,iVar1,1);
  return iVar1;
}

