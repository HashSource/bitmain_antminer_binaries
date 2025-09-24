
size_t LZ4F_compressEnd(LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,
                       LZ4F_compressOptions_t *compressOptionsPtr)

{
  LZ4F_errorCode_t LVar1;
  uint uVar2;
  void *dst;
  LZ4F_compressOptions_t *compressOptionsPtr_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  U32 xxh;
  size_t flushSize;
  BYTE *dstStart;
  BYTE *dstPtr;
  
  LVar1 = LZ4F_flush(cctxPtr,dstBuffer,dstCapacity,compressOptionsPtr);
  uVar2 = LZ4F_isError(LVar1);
  if (uVar2 == 0) {
    dst = (void *)(LVar1 + (int)dstBuffer);
    if (dstCapacity - LVar1 < 4) {
      LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
    }
    else {
      LZ4F_writeLE32(dst,0);
      dstPtr = (BYTE *)((int)dst + 4);
      if ((cctxPtr->prefs).frameInfo.contentChecksumFlag == LZ4F_contentChecksumEnabled) {
        uVar2 = XXH32_digest(&cctxPtr->xxh);
        if (dstCapacity - LVar1 < 8) {
          LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
          return LVar1;
        }
        LZ4F_writeLE32(dstPtr,uVar2);
        dstPtr = (BYTE *)((int)dst + 8);
      }
      cctxPtr->cStage = 0;
      cctxPtr->maxBufferSize = 0;
      if (((int)(cctxPtr->prefs).frameInfo.contentSize == 0 &&
           *(int *)((int)&(cctxPtr->prefs).frameInfo.contentSize + 4) == 0) ||
         (*(int *)((int)&(cctxPtr->prefs).frameInfo.contentSize + 4) ==
          *(int *)((int)&cctxPtr->totalInSize + 4) &&
          (int)(cctxPtr->prefs).frameInfo.contentSize == (int)cctxPtr->totalInSize)) {
        LVar1 = (int)dstPtr - (int)dstBuffer;
      }
      else {
        LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_frameSize_wrong);
      }
    }
  }
  return LVar1;
}

