
size_t LZ4F_compressFrame_usingCDict
                 (LZ4F_cctx *cctx,void *dstBuffer,size_t dstCapacity,void *srcBuffer,size_t srcSize,
                 LZ4F_CDict *cdict,LZ4F_preferences_t *preferencesPtr)

{
  size_t sVar1;
  LZ4F_errorCode_t code;
  uint uVar2;
  void *pvVar3;
  void *srcBuffer_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctx_local;
  LZ4F_compressOptions_t options;
  LZ4F_preferences_t prefs;
  size_t tailSize;
  size_t cSize;
  size_t headerSize;
  BYTE *dstEnd;
  BYTE *dstPtr;
  BYTE *dstStart;
  
  if (preferencesPtr == (LZ4F_preferences_t *)0x0) {
    memset(&prefs,0,0x38);
  }
  else {
    prefs.frameInfo.blockSizeID = (preferencesPtr->frameInfo).blockSizeID;
    prefs.frameInfo.blockMode = (preferencesPtr->frameInfo).blockMode;
    prefs.frameInfo.contentChecksumFlag = (preferencesPtr->frameInfo).contentChecksumFlag;
    prefs.frameInfo.frameType = (preferencesPtr->frameInfo).frameType;
    prefs.frameInfo.contentSize._0_4_ = (size_t)(preferencesPtr->frameInfo).contentSize;
    prefs.frameInfo.contentSize._4_4_ = *(int *)((int)&(preferencesPtr->frameInfo).contentSize + 4);
    prefs.frameInfo.dictID = (preferencesPtr->frameInfo).dictID;
    prefs.frameInfo.blockChecksumFlag = (preferencesPtr->frameInfo).blockChecksumFlag;
    prefs.compressionLevel = preferencesPtr->compressionLevel;
    prefs.autoFlush = preferencesPtr->autoFlush;
    prefs.favorDecSpeed = preferencesPtr->favorDecSpeed;
    prefs.reserved[0] = preferencesPtr->reserved[0];
    prefs.reserved[1] = preferencesPtr->reserved[1];
    prefs.reserved[2] = preferencesPtr->reserved[2];
  }
  if ((size_t)prefs.frameInfo.contentSize != 0 || prefs.frameInfo.contentSize._4_4_ != 0) {
    prefs.frameInfo.contentSize._0_4_ = srcSize;
    prefs.frameInfo.contentSize._4_4_ = 0;
  }
  prefs.frameInfo.blockSizeID = LZ4F_optimalBSID(prefs.frameInfo.blockSizeID,srcSize);
  prefs.autoFlush = 1;
  sVar1 = LZ4F_getBlockSize(prefs.frameInfo.blockSizeID);
  if (srcSize <= sVar1) {
    prefs.frameInfo.blockMode = LZ4F_blockIndependent;
  }
  memset(&options,0,0x10);
  options.stableSrc = 1;
  sVar1 = LZ4F_compressFrameBound(srcSize,&prefs);
  if (dstCapacity < sVar1) {
    code = LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
  }
  else {
    code = LZ4F_compressBegin_usingCDict(cctx,dstBuffer,dstCapacity,cdict,&prefs);
    uVar2 = LZ4F_isError(code);
    if (uVar2 == 0) {
      pvVar3 = (void *)(code + (int)dstBuffer);
      code = LZ4F_compressUpdate(cctx,pvVar3,(int)dstBuffer + (dstCapacity - (int)pvVar3),srcBuffer,
                                 srcSize,&options);
      uVar2 = LZ4F_isError(code);
      if (uVar2 == 0) {
        pvVar3 = (void *)(code + (int)pvVar3);
        code = LZ4F_compressEnd(cctx,pvVar3,(int)dstBuffer + (dstCapacity - (int)pvVar3),&options);
        uVar2 = LZ4F_isError(code);
        if (uVar2 == 0) {
          code = (int)pvVar3 + (code - (int)dstBuffer);
        }
      }
    }
  }
  return code;
}

