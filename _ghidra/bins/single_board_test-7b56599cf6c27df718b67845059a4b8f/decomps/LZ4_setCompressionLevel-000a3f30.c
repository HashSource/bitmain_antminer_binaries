
void LZ4_setCompressionLevel(LZ4_streamHC_t *LZ4_streamHCPtr,int compressionLevel)

{
  int compressionLevel_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  compressionLevel_local = compressionLevel;
  if (compressionLevel < 1) {
    compressionLevel_local = 9;
  }
  if (0xc < compressionLevel_local) {
    compressionLevel_local = 0xc;
  }
  (LZ4_streamHCPtr->internal_donotuse).compressionLevel = (short)compressionLevel_local;
  return;
}

