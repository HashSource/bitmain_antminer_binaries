
int LZ4F_compressBlockHC
              (void *ctx,char *src,char *dst,int srcSize,int dstCapacity,int level,LZ4F_CDict *cdict
              )

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *ctx_local;
  
  LZ4F_initStream(ctx,cdict,level,LZ4F_blockIndependent);
  if (cdict == (LZ4F_CDict *)0x0) {
    iVar1 = LZ4_compress_HC_extStateHC_fastReset(ctx,src,dst,srcSize,dstCapacity,level);
  }
  else {
    iVar1 = LZ4_compress_HC_continue((LZ4_streamHC_t *)ctx,src,dst,srcSize,dstCapacity);
  }
  return iVar1;
}

