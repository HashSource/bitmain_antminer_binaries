
LZ4F_errorCode_t LZ4F_createCompressionContext(LZ4F_cctx **LZ4F_compressionContextPtr,uint version)

{
  LZ4F_errorCode_t LVar1;
  LZ4F_cctx *pLVar2;
  uint version_local;
  LZ4F_cctx **LZ4F_compressionContextPtr_local;
  
  if (LZ4F_compressionContextPtr == (LZ4F_cctx **)0x0) {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_parameter_null);
  }
  else {
    pLVar2 = LZ4F_createCompressionContext_advanced((LZ4F_CustomMem)ZEXT816((ulonglong)0),version);
    *LZ4F_compressionContextPtr = pLVar2;
    if (*LZ4F_compressionContextPtr == (LZ4F_cctx *)0x0) {
      LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
    }
    else {
      LVar1 = 0;
    }
  }
  return LVar1;
}

