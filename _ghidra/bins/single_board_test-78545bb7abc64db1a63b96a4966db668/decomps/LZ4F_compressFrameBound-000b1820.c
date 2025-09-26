
size_t LZ4F_compressFrameBound(size_t srcSize,LZ4F_preferences_t *preferencesPtr)

{
  size_t sVar1;
  LZ4F_preferences_t *preferencesPtr_local;
  size_t srcSize_local;
  LZ4F_preferences_t prefs;
  size_t headerSize;
  
  if (preferencesPtr == (LZ4F_preferences_t *)0x0) {
    memset(&prefs,0,0x38);
  }
  else {
    prefs.frameInfo.blockSizeID = (preferencesPtr->frameInfo).blockSizeID;
    prefs.frameInfo.blockMode = (preferencesPtr->frameInfo).blockMode;
    prefs.frameInfo.contentChecksumFlag = (preferencesPtr->frameInfo).contentChecksumFlag;
    prefs.frameInfo.frameType = (preferencesPtr->frameInfo).frameType;
    prefs.frameInfo.contentSize._0_4_ = (undefined4)(preferencesPtr->frameInfo).contentSize;
    prefs.frameInfo.contentSize._4_4_ =
         *(undefined4 *)((int)&(preferencesPtr->frameInfo).contentSize + 4);
    prefs.frameInfo.dictID = (preferencesPtr->frameInfo).dictID;
    prefs.frameInfo.blockChecksumFlag = (preferencesPtr->frameInfo).blockChecksumFlag;
    prefs.compressionLevel = preferencesPtr->compressionLevel;
    prefs.favorDecSpeed = preferencesPtr->favorDecSpeed;
    prefs.reserved[0] = preferencesPtr->reserved[0];
    prefs.reserved[1] = preferencesPtr->reserved[1];
    prefs.reserved[2] = preferencesPtr->reserved[2];
  }
  prefs.autoFlush = 1;
  sVar1 = LZ4F_compressBound_internal(srcSize,&prefs,0);
  return sVar1 + 0x13;
}

