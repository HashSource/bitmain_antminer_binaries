
int LZ4F_compressBlockHC_continue
              (void *ctx,char *src,char *dst,int srcSize,int dstCapacity,int level,LZ4F_CDict *cdict
              )

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *ctx_local;
  
  iVar1 = LZ4_compress_HC_continue((LZ4_streamHC_t *)ctx,src,dst,srcSize,dstCapacity);
  return iVar1;
}

