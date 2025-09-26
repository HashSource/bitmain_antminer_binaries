
/* WARNING: Unknown calling convention */

LZ4_streamHC_t * LZ4_createStreamHC(void)

{
  LZ4_streamHC_t *LZ4_streamHCPtr;
  LZ4_streamHC_t *state;
  
  LZ4_streamHCPtr = (LZ4_streamHC_t *)calloc(1,0x40038);
  if (LZ4_streamHCPtr == (LZ4_streamHC_t *)0x0) {
    LZ4_streamHCPtr = (LZ4_streamHC_t *)0x0;
  }
  else {
    LZ4_setCompressionLevel(LZ4_streamHCPtr,9);
  }
  return LZ4_streamHCPtr;
}

