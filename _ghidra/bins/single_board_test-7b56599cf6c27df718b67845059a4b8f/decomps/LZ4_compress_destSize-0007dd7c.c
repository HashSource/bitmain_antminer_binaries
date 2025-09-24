
int LZ4_compress_destSize(char *src,char *dst,int *srcSizePtr,int targetDstSize)

{
  int iVar1;
  int targetDstSize_local;
  int *srcSizePtr_local;
  char *dst_local;
  char *src_local;
  LZ4_stream_t ctxBody;
  int result;
  LZ4_stream_t *ctx;
  
  ctx = &ctxBody;
  iVar1 = LZ4_compress_destSize_extState(ctx,src,dst,srcSizePtr,targetDstSize);
  return iVar1;
}

