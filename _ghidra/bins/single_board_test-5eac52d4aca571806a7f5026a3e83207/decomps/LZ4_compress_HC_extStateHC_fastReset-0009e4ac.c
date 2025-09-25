
int LZ4_compress_HC_extStateHC_fastReset
              (void *state,char *src,char *dst,int srcSize,int dstCapacity,int compressionLevel)

{
  size_t alignment;
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *state_local;
  LZ4HC_CCtx_internal *ctx;
  
  srcSize_local = srcSize;
  dst_local = dst;
  src_local = src;
  state_local = state;
  ctx = (LZ4HC_CCtx_internal *)state;
  alignment = LZ4_streamHC_t_alignment();
  iVar1 = LZ4_isAligned(state_local,alignment);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    LZ4_resetStreamHC_fast((LZ4_streamHC_t *)state_local,compressionLevel);
    LZ4HC_init_internal(ctx,(BYTE *)src_local);
    iVar1 = LZ4_compressBound(srcSize_local);
    if (dstCapacity < iVar1) {
      iVar1 = LZ4HC_compress_generic
                        (ctx,src_local,dst_local,&srcSize_local,dstCapacity,compressionLevel,
                         limitedOutput);
    }
    else {
      iVar1 = LZ4HC_compress_generic
                        (ctx,src_local,dst_local,&srcSize_local,dstCapacity,compressionLevel,
                         notLimited);
    }
  }
  return iVar1;
}

