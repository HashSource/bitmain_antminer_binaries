
void LZ4_resetStreamHC_fast(LZ4_streamHC_t *LZ4_streamHCPtr,int compressionLevel)

{
  int compressionLevel_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  if (LZ4_streamHCPtr->minStateSize[0x4001b] == '\0') {
    if ((LZ4_streamHCPtr->internal_donotuse).end != (LZ4_byte *)0x0) {
      (LZ4_streamHCPtr->internal_donotuse).end =
           (LZ4_streamHCPtr->internal_donotuse).end +
           -(int)(LZ4_streamHCPtr->internal_donotuse).prefixStart;
    }
    (LZ4_streamHCPtr->internal_donotuse).prefixStart = (LZ4_byte *)0x0;
    (LZ4_streamHCPtr->internal_donotuse).dictCtx = (LZ4HC_CCtx_internal *)0x0;
  }
  else {
    LZ4_initStreamHC(LZ4_streamHCPtr,0x40038);
  }
  LZ4_setCompressionLevel(LZ4_streamHCPtr,compressionLevel);
  return;
}

