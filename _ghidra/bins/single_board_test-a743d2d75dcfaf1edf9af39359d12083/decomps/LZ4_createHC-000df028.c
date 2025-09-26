
void * LZ4_createHC(char *inputBuffer)

{
  LZ4_streamHC_t *hc4_00;
  char *inputBuffer_local;
  LZ4_streamHC_t *hc4;
  
  hc4_00 = LZ4_createStreamHC();
  if (hc4_00 == (LZ4_streamHC_t *)0x0) {
    hc4_00 = (LZ4_streamHC_t *)0x0;
  }
  else {
    LZ4HC_init_internal(&hc4_00->internal_donotuse,(BYTE *)inputBuffer);
  }
  return hc4_00;
}

