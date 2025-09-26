
size_t LZ4F_compressFrame(void *dstBuffer,size_t dstCapacity,void *srcBuffer,size_t srcSize,
                         LZ4F_preferences_t *preferencesPtr)

{
  size_t sVar1;
  LZ4F_AllocFunction p_Var4;
  LZ4F_CallocFunction p_Var5;
  LZ4F_FreeFunction p_Var2;
  LZ4F_CustomMem cmem;
  undefined8 uVar3;
  undefined8 uVar6;
  size_t srcSize_local;
  void *srcBuffer_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4_stream_t lz4ctx;
  LZ4F_cctx_t cctx;
  size_t result;
  LZ4F_cctx_t *cctxPtr;
  
  memset(&cctx,0,0xb0);
  cctx.version = 100;
  cctx.maxBufferSize = 0x500000;
  if ((preferencesPtr == (LZ4F_preferences_t *)0x0) || (preferencesPtr->compressionLevel < 3)) {
    LZ4_initStream(&lz4ctx,0x4020);
    cctx.lz4CtxPtr = &lz4ctx;
    cctx.lz4CtxAlloc = 1;
    cctx.lz4CtxState = 1;
  }
  sVar1 = LZ4F_compressFrame_usingCDict
                    (&cctx,dstBuffer,dstCapacity,srcBuffer,srcSize,(LZ4F_CDict *)0x0,preferencesPtr)
  ;
  if ((preferencesPtr != (LZ4F_preferences_t *)0x0) && (2 < preferencesPtr->compressionLevel)) {
    p_Var2 = cctx.cmem.customFree;
    uVar3 = CONCAT44(preferencesPtr,p_Var2);
    p_Var4 = cctx.cmem.customAlloc;
    register0x00000028 = cctx.cmem.customCalloc;
    cmem = (LZ4F_CustomMem)CONCAT88(uVar3,uVar6);
    LZ4F_free(cctx.lz4CtxPtr,cmem);
  }
  return sVar1;
}

