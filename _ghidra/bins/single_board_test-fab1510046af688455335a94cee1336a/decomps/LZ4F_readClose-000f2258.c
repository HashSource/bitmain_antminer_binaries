
LZ4F_errorCode_t LZ4F_readClose(LZ4_readFile_t *lz4fRead)

{
  LZ4F_errorCode_t LVar1;
  LZ4_readFile_t *lz4fRead_local;
  
  if (lz4fRead == (LZ4_readFile_t *)0x0) {
    LVar1 = 0xffffffff;
  }
  else {
    LZ4F_freeDecompressionContext(lz4fRead->dctxPtr);
    free(lz4fRead->srcBuf);
    free(lz4fRead);
    LVar1 = 0;
  }
  return LVar1;
}

