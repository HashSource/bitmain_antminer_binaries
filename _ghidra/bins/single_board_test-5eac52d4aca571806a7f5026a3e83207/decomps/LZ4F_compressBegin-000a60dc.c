
size_t LZ4F_compressBegin(LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,
                         LZ4F_preferences_t *preferencesPtr)

{
  size_t sVar1;
  LZ4F_preferences_t *preferencesPtr_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  
  sVar1 = LZ4F_compressBegin_usingCDict
                    (cctxPtr,dstBuffer,dstCapacity,(LZ4F_CDict *)0x0,preferencesPtr);
  return sVar1;
}

