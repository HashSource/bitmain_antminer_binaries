
int LZ4HC_compress_generic
              (LZ4HC_CCtx_internal *ctx,char *src,char *dst,int *srcSizePtr,int dstCapacity,
              int cLevel,limitedOutput_directive limit)

{
  int iVar1;
  int *srcSizePtr_local;
  char *dst_local;
  char *src_local;
  LZ4HC_CCtx_internal *ctx_local;
  
  if (ctx->dictCtx == (LZ4HC_CCtx_internal *)0x0) {
    iVar1 = LZ4HC_compress_generic_noDictCtx(ctx,src,dst,srcSizePtr,dstCapacity,cLevel,limit);
  }
  else {
    iVar1 = LZ4HC_compress_generic_dictCtx(ctx,src,dst,srcSizePtr,dstCapacity,cLevel,limit);
  }
  return iVar1;
}

