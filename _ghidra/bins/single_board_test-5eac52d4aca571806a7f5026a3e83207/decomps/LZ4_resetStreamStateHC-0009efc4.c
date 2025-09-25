
int LZ4_resetStreamStateHC(void *state,char *inputBuffer)

{
  LZ4_streamHC_t *hc4_00;
  char *inputBuffer_local;
  void *state_local;
  LZ4_streamHC_t *hc4;
  
  hc4_00 = LZ4_initStreamHC(state,0x40038);
  if (hc4_00 != (LZ4_streamHC_t *)0x0) {
    LZ4HC_init_internal(&hc4_00->internal_donotuse,(BYTE *)inputBuffer);
  }
  return (uint)(hc4_00 == (LZ4_streamHC_t *)0x0);
}

