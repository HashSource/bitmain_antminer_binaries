
int LZ4_compress_HC_destSize
              (void *state,char *source,char *dest,int *sourceSizePtr,int targetDestSize,int cLevel)

{
  LZ4_streamHC_t *LZ4_streamHCPtr;
  int iVar1;
  int *sourceSizePtr_local;
  char *dest_local;
  char *source_local;
  void *state_local;
  LZ4_streamHC_t *ctx;
  
  LZ4_streamHCPtr = LZ4_initStreamHC(state,0x40038);
  if (LZ4_streamHCPtr == (LZ4_streamHC_t *)0x0) {
    iVar1 = 0;
  }
  else {
    LZ4HC_init_internal(&LZ4_streamHCPtr->internal_donotuse,(BYTE *)source);
    LZ4_setCompressionLevel(LZ4_streamHCPtr,cLevel);
    iVar1 = LZ4HC_compress_generic
                      (&LZ4_streamHCPtr->internal_donotuse,source,dest,sourceSizePtr,targetDestSize,
                       cLevel,fillOutput);
  }
  return iVar1;
}

