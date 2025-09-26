
int LZ4_freeStreamHC(LZ4_streamHC_t *LZ4_streamHCPtr)

{
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  if (LZ4_streamHCPtr != (LZ4_streamHC_t *)0x0) {
    free(LZ4_streamHCPtr);
  }
  return 0;
}

