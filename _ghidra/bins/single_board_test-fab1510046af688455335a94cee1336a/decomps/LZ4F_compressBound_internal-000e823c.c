
size_t LZ4F_compressBound_internal
                 (size_t srcSize,LZ4F_preferences_t *preferencesPtr,size_t alreadyBuffered)

{
  int iVar1;
  char cVar2;
  size_t sVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  size_t alreadyBuffered_local;
  LZ4F_preferences_t *preferencesPtr_local;
  size_t srcSize_local;
  LZ4F_preferences_t prefsNull;
  size_t frameEnd;
  size_t blockCRCSize;
  uint nbBlocks;
  size_t lastBlockSize;
  size_t partialBlockSize;
  uint nbFullBlocks;
  size_t maxSrcSize;
  size_t bufferedSize;
  size_t maxBuffered;
  size_t blockSize;
  LZ4F_blockSizeID_t blockID;
  U32 flush;
  LZ4F_preferences_t *prefsPtr;
  
  memset(&prefsNull,0,0x38);
  prefsNull.frameInfo.contentChecksumFlag = LZ4F_contentChecksumEnabled;
  prefsNull.frameInfo.blockChecksumFlag = LZ4F_blockChecksumEnabled;
  if (preferencesPtr == (LZ4F_preferences_t *)0x0) {
    preferencesPtr = &prefsNull;
  }
  uVar5 = preferencesPtr->autoFlush;
  sVar3 = srcSize;
  if (srcSize == 0) {
    sVar3 = 1;
  }
  cVar2 = (char)sVar3;
  if (srcSize != 0) {
    cVar2 = '\0';
  }
  sVar3 = LZ4F_getBlockSize((preferencesPtr->frameInfo).blockSizeID);
  if (sVar3 - 1 <= alreadyBuffered) {
    alreadyBuffered = sVar3 - 1;
  }
  iVar1 = __aeabi_uidiv(alreadyBuffered + srcSize,sVar3);
  uVar6 = alreadyBuffered + srcSize & sVar3 - 1;
  if (uVar5 == 0 && cVar2 == '\0') {
    uVar6 = 0;
  }
  uVar5 = uVar6;
  if (uVar6 != 0) {
    uVar5 = 1;
  }
  bVar4 = (byte)uVar5;
  if (uVar6 == 0) {
    bVar4 = 0;
  }
  return (preferencesPtr->frameInfo).contentChecksumFlag * 4 + 4 +
         (iVar1 + (uint)bVar4) * ((preferencesPtr->frameInfo).blockChecksumFlag * 4 + 4) +
         iVar1 * sVar3 + uVar6;
}

