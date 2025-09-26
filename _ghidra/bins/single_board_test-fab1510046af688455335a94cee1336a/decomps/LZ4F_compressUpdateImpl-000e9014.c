
size_t LZ4F_compressUpdateImpl
                 (LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,void *srcBuffer,
                 size_t srcSize,LZ4F_compressOptions_t *compressOptionsPtr,
                 LZ4F_blockCompression_t blockCompression)

{
  compressFunc_t compress_00;
  LZ4F_errorCode_t LVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  BYTE *pBVar5;
  uint __n;
  void *srcBuffer_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  size_t sizeToCopy_1;
  int realDictSize_1;
  int realDictSize;
  size_t sizeToCopy;
  size_t bytesWritten;
  compressFunc_t compress;
  BYTE *dstStart;
  BYTE *srcEnd;
  size_t blockSize;
  LZ4F_lastBlockStatus lastBlockCompressed;
  BYTE *dstPtr;
  BYTE *srcPtr;
  
  uVar4 = cctxPtr->maxBlockSize;
  pBVar5 = (BYTE *)(srcSize + (int)srcBuffer);
  lastBlockCompressed = notDone;
  compress_00 = LZ4F_selectCompression
                          ((cctxPtr->prefs).frameInfo.blockMode,(cctxPtr->prefs).compressionLevel,
                           blockCompression);
  if (cctxPtr->cStage == 1) {
    sVar2 = LZ4F_compressBound_internal(srcSize,&cctxPtr->prefs,cctxPtr->tmpInSize);
    if (dstCapacity < sVar2) {
      LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
    }
    else if ((blockCompression == LZ4B_UNCOMPRESSED) && (dstCapacity < srcSize)) {
      LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
    }
    else {
      dstPtr = (BYTE *)dstBuffer;
      if (cctxPtr->blockCompression != blockCompression) {
        sVar2 = LZ4F_flush(cctxPtr,dstBuffer,dstCapacity,compressOptionsPtr);
        dstPtr = (BYTE *)(sVar2 + (int)dstBuffer);
        cctxPtr->blockCompression = blockCompression;
      }
      if (compressOptionsPtr == (LZ4F_compressOptions_t *)0x0) {
        compressOptionsPtr = &k_cOptionsNull;
      }
      srcPtr = (BYTE *)srcBuffer;
      if (cctxPtr->tmpInSize != 0) {
        __n = uVar4 - cctxPtr->tmpInSize;
        if (srcSize < __n) {
          memcpy(cctxPtr->tmpIn + cctxPtr->tmpInSize,srcBuffer,srcSize);
          cctxPtr->tmpInSize = cctxPtr->tmpInSize + srcSize;
          srcPtr = pBVar5;
        }
        else {
          lastBlockCompressed = fromTmpBuffer;
          memcpy(cctxPtr->tmpIn + cctxPtr->tmpInSize,srcBuffer,__n);
          srcPtr = (BYTE *)(__n + (int)srcBuffer);
          sVar2 = LZ4F_makeBlock(dstPtr,cctxPtr->tmpIn,uVar4,compress_00,cctxPtr->lz4CtxPtr,
                                 (cctxPtr->prefs).compressionLevel,cctxPtr->cdict,
                                 (cctxPtr->prefs).frameInfo.blockChecksumFlag);
          dstPtr = dstPtr + sVar2;
          if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) {
            cctxPtr->tmpIn = cctxPtr->tmpIn + uVar4;
          }
          cctxPtr->tmpInSize = 0;
        }
      }
      for (; uVar4 <= (uint)((int)pBVar5 - (int)srcPtr); srcPtr = srcPtr + uVar4) {
        lastBlockCompressed = fromSrcBuffer;
        sVar2 = LZ4F_makeBlock(dstPtr,srcPtr,uVar4,compress_00,cctxPtr->lz4CtxPtr,
                               (cctxPtr->prefs).compressionLevel,cctxPtr->cdict,
                               (cctxPtr->prefs).frameInfo.blockChecksumFlag);
        dstPtr = dstPtr + sVar2;
      }
      if (((cctxPtr->prefs).autoFlush != 0) && (srcPtr < pBVar5)) {
        lastBlockCompressed = fromSrcBuffer;
        sVar2 = LZ4F_makeBlock(dstPtr,srcPtr,(int)pBVar5 - (int)srcPtr,compress_00,
                               cctxPtr->lz4CtxPtr,(cctxPtr->prefs).compressionLevel,cctxPtr->cdict,
                               (cctxPtr->prefs).frameInfo.blockChecksumFlag);
        dstPtr = dstPtr + sVar2;
        srcPtr = pBVar5;
      }
      if (((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) &&
         (lastBlockCompressed == fromSrcBuffer)) {
        if (compressOptionsPtr->stableSrc == 0) {
          iVar3 = LZ4F_localSaveDict(cctxPtr);
          cctxPtr->tmpIn = cctxPtr->tmpBuff + iVar3;
        }
        else {
          cctxPtr->tmpIn = cctxPtr->tmpBuff;
        }
      }
      if (((cctxPtr->prefs).autoFlush == 0) &&
         (cctxPtr->tmpBuff + cctxPtr->maxBufferSize < cctxPtr->tmpIn + uVar4)) {
        iVar3 = LZ4F_localSaveDict(cctxPtr);
        cctxPtr->tmpIn = cctxPtr->tmpBuff + iVar3;
      }
      if (srcPtr < pBVar5) {
        memcpy(cctxPtr->tmpIn,srcPtr,(int)pBVar5 - (int)srcPtr);
        cctxPtr->tmpInSize = (int)pBVar5 - (int)srcPtr;
      }
      if ((cctxPtr->prefs).frameInfo.contentChecksumFlag == LZ4F_contentChecksumEnabled) {
        XXH32_update(&cctxPtr->xxh,srcBuffer,srcSize);
      }
      uVar4 = (uint)cctxPtr->totalInSize;
      iVar3 = *(int *)((int)&cctxPtr->totalInSize + 4);
      *(size_t *)&cctxPtr->totalInSize = srcSize + uVar4;
      *(uint *)((int)&cctxPtr->totalInSize + 4) = iVar3 + (uint)CARRY4(srcSize,uVar4);
      LVar1 = (int)dstPtr - (int)dstBuffer;
    }
  }
  else {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_compressionState_uninitialized);
  }
  return LVar1;
}

