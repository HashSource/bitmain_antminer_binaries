
int LZ4_compress_limitedOutput_continue
              (LZ4_stream_t *LZ4_stream,char *src,char *dst,int srcSize,int dstCapacity)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  LZ4_stream_t *LZ4_stream_local;
  
  iVar1 = LZ4_compress_fast_continue(LZ4_stream,src,dst,srcSize,dstCapacity,1);
  return iVar1;
}

