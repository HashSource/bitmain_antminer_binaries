
size_t LZ4F_compressUpdate(LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,void *srcBuffer,
                          size_t srcSize,LZ4F_compressOptions_t *compressOptionsPtr)

{
  size_t sVar1;
  void *srcBuffer_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  
  sVar1 = LZ4F_compressUpdateImpl
                    (cctxPtr,dstBuffer,dstCapacity,srcBuffer,srcSize,compressOptionsPtr,
                     LZ4B_COMPRESSED);
  return sVar1;
}

