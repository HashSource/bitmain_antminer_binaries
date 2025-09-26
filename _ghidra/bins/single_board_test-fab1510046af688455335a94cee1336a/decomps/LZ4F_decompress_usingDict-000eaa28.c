
size_t LZ4F_decompress_usingDict
                 (LZ4F_dctx *dctx,void *dstBuffer,size_t *dstSizePtr,void *srcBuffer,
                 size_t *srcSizePtr,void *dict,size_t dictSize,
                 LZ4F_decompressOptions_t *decompressOptionsPtr)

{
  size_t sVar1;
  void *srcBuffer_local;
  size_t *dstSizePtr_local;
  void *dstBuffer_local;
  LZ4F_dctx *dctx_local;
  
  if (dctx->dStage < dstage_getBlockHeader) {
    dctx->dict = (BYTE *)dict;
    dctx->dictSize = dictSize;
  }
  sVar1 = LZ4F_decompress(dctx,dstBuffer,dstSizePtr,srcBuffer,srcSizePtr,decompressOptionsPtr);
  return sVar1;
}

