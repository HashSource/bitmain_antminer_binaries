
int LZ4F_compressBlock(void *ctx,char *src,char *dst,int srcSize,int dstCapacity,int level,
                      LZ4F_CDict *cdict)

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
  LZ4F_initStream(ctx,cdict,level,LZ4F_blockIndependent);
  if (cdict == (LZ4F_CDict *)0x0) {
    iVar1 = LZ4_compress_fast_extState_fastReset(ctx,src,dst,srcSize,dstCapacity,iVar1);
  }
  else {
    iVar1 = LZ4_compress_fast_continue((LZ4_stream_t *)ctx,src,dst,srcSize,dstCapacity,iVar1);
  }
  return iVar1;
}

