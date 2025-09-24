
LZ4F_blockSizeID_t LZ4F_optimalBSID(LZ4F_blockSizeID_t requestedBSID,size_t srcSize)

{
  LZ4F_blockSizeID_t LVar1;
  size_t srcSize_local;
  LZ4F_blockSizeID_t requestedBSID_local;
  size_t maxBlockSize;
  LZ4F_blockSizeID_t proposedBSID;
  
  proposedBSID = LZ4F_max64KB;
  for (maxBlockSize = 0x10000;
      (LVar1 = requestedBSID, proposedBSID < requestedBSID &&
      (LVar1 = proposedBSID, maxBlockSize < srcSize)); maxBlockSize = maxBlockSize << 2) {
    proposedBSID = proposedBSID + 1;
  }
  return LVar1;
}

