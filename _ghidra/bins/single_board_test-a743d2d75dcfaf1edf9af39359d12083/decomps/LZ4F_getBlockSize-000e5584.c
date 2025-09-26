
size_t LZ4F_getBlockSize(LZ4F_blockSizeID_t blockSizeID)

{
  LZ4F_errorCode_t LVar1;
  LZ4F_blockSizeID_t blockSizeID_local;
  int blockSizeIdx;
  
  blockSizeID_local = blockSizeID;
  if (blockSizeID == LZ4F_default) {
    blockSizeID_local = LZ4F_max64KB;
  }
  if ((blockSizeID_local < LZ4F_max64KB) || (LZ4F_max4MB < blockSizeID_local)) {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_maxBlockSize_invalid);
  }
  else {
    LVar1 = LZ4F_getBlockSize::blockSizes[blockSizeID_local - LZ4F_max64KB];
  }
  return LVar1;
}

