
LZ4F_errorCode_t
LZ4F_createDecompressionContext(LZ4F_dctx **LZ4F_decompressionContextPtr,uint versionNumber)

{
  LZ4F_errorCode_t LVar1;
  LZ4F_dctx *pLVar2;
  uint versionNumber_local;
  LZ4F_dctx **LZ4F_decompressionContextPtr_local;
  
  if (LZ4F_decompressionContextPtr == (LZ4F_dctx **)0x0) {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_parameter_null);
  }
  else {
    pLVar2 = LZ4F_createDecompressionContext_advanced
                       ((LZ4F_CustomMem)ZEXT816((ulonglong)0),versionNumber);
    *LZ4F_decompressionContextPtr = pLVar2;
    if (*LZ4F_decompressionContextPtr == (LZ4F_dctx *)0x0) {
      LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
    }
    else {
      LVar1 = 0;
    }
  }
  return LVar1;
}

