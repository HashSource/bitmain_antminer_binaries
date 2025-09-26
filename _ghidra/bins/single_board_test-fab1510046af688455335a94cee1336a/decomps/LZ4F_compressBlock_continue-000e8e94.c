
int LZ4F_compressBlock_continue
              (void *ctx,char *src,char *dst,int srcSize,int dstCapacity,int level,LZ4F_CDict *cdict
              )

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *ctx_local;
  int acceleration;
  
  if (level < 0) {
    iVar1 = 1 - level;
  }
  else {
    iVar1 = 1;
  }
  iVar1 = LZ4_compress_fast_continue((LZ4_stream_t *)ctx,src,dst,srcSize,dstCapacity,iVar1);
  return iVar1;
}

