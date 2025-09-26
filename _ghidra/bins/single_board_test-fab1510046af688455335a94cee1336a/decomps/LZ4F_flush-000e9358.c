
size_t LZ4F_flush(LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,
                 LZ4F_compressOptions_t *compressOptionsPtr)

{
  compressFunc_t compress_00;
  int iVar1;
  LZ4F_errorCode_t LVar2;
  LZ4F_compressOptions_t *compressOptionsPtr_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  int realDictSize;
  compressFunc_t compress;
  BYTE *dstPtr;
  BYTE *dstStart;
  
  if (cctxPtr->tmpInSize == 0) {
    LVar2 = 0;
  }
  else if (cctxPtr->cStage == 1) {
    if (dstCapacity < cctxPtr->tmpInSize + 8) {
      LVar2 = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
    }
    else {
      compress_00 = LZ4F_selectCompression
                              ((cctxPtr->prefs).frameInfo.blockMode,
                               (cctxPtr->prefs).compressionLevel,cctxPtr->blockCompression);
      LVar2 = LZ4F_makeBlock(dstBuffer,cctxPtr->tmpIn,cctxPtr->tmpInSize,compress_00,
                             cctxPtr->lz4CtxPtr,(cctxPtr->prefs).compressionLevel,cctxPtr->cdict,
                             (cctxPtr->prefs).frameInfo.blockChecksumFlag);
      if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) {
        cctxPtr->tmpIn = cctxPtr->tmpIn + cctxPtr->tmpInSize;
      }
      cctxPtr->tmpInSize = 0;
      if (cctxPtr->tmpBuff + cctxPtr->maxBufferSize < cctxPtr->tmpIn + cctxPtr->maxBlockSize) {
        iVar1 = LZ4F_localSaveDict(cctxPtr);
        cctxPtr->tmpIn = cctxPtr->tmpBuff + iVar1;
      }
    }
  }
  else {
    LVar2 = LZ4F_returnErrorCode(LZ4F_ERROR_compressionState_uninitialized);
  }
  return LVar2;
}

