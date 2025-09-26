
int LZ4F_localSaveDict(LZ4F_cctx_t *cctxPtr)

{
  int iVar1;
  LZ4F_cctx_t *cctxPtr_local;
  
  if ((cctxPtr->prefs).compressionLevel < 3) {
    iVar1 = LZ4_saveDict((LZ4_stream_t *)cctxPtr->lz4CtxPtr,(char *)cctxPtr->tmpBuff,0x10000);
  }
  else {
    iVar1 = LZ4_saveDictHC((LZ4_streamHC_t *)cctxPtr->lz4CtxPtr,(char *)cctxPtr->tmpBuff,0x10000);
  }
  return iVar1;
}

