
size_t LZ4F_uncompressedUpdate
                 (LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,void *srcBuffer,
                 size_t srcSize,LZ4F_compressOptions_t *compressOptionsPtr)

{
  LZ4F_errorCode_t LVar1;
  void *srcBuffer_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  
  if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockIndependent) {
    LVar1 = LZ4F_compressUpdateImpl
                      (cctxPtr,dstBuffer,dstCapacity,srcBuffer,srcSize,compressOptionsPtr,
                       LZ4B_UNCOMPRESSED);
  }
  else {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_blockMode_invalid);
  }
  return LVar1;
}

