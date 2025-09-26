
int LZ4_compressHC_limitedOutput_continue
              (LZ4_streamHC_t *ctx,char *src,char *dst,int srcSize,int maxDstSize)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  LZ4_streamHC_t *ctx_local;
  
  iVar1 = LZ4_compress_HC_continue(ctx,src,dst,srcSize,maxDstSize);
  return iVar1;
}

