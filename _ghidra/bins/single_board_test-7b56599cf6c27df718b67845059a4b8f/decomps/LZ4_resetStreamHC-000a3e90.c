
void LZ4_resetStreamHC(LZ4_streamHC_t *LZ4_streamHCPtr,int compressionLevel)

{
  int compressionLevel_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  LZ4_initStreamHC(LZ4_streamHCPtr,0x40038);
  LZ4_setCompressionLevel(LZ4_streamHCPtr,compressionLevel);
  return;
}

