
LZ4_streamHC_t * LZ4_initStreamHC(void *buffer,size_t size)

{
  size_t alignment;
  int iVar1;
  size_t size_local;
  void *buffer_local;
  LZ4HC_CCtx_internal *hcstate;
  LZ4_streamHC_t *LZ4_streamHCPtr;
  
  if (buffer == (void *)0x0) {
    buffer = (LZ4_streamHC_t *)0x0;
  }
  else if ("ame" < size) {
    alignment = LZ4_streamHC_t_alignment();
    iVar1 = LZ4_isAligned(buffer,alignment);
    if (iVar1 == 0) {
      buffer = (LZ4_streamHC_t *)0x0;
    }
    else {
      memset(buffer,0,0x40020);
      LZ4_setCompressionLevel((LZ4_streamHC_t *)buffer,9);
    }
  }
  else {
    buffer = (LZ4_streamHC_t *)0x0;
  }
  return (LZ4_streamHC_t *)buffer;
}

