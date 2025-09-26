
void LZ4F_initStream(void *ctx,LZ4F_CDict *cdict,int level,LZ4F_blockMode_t blockMode)

{
  LZ4_stream_t *dictionaryStream;
  LZ4_streamHC_t *dictionary_stream;
  LZ4F_blockMode_t blockMode_local;
  int level_local;
  LZ4F_CDict *cdict_local;
  void *ctx_local;
  
  if (level < 3) {
    if ((cdict != (LZ4F_CDict *)0x0) || (blockMode == LZ4F_blockLinked)) {
      LZ4_resetStream_fast((LZ4_stream_t *)ctx);
    }
    if (cdict == (LZ4F_CDict *)0x0) {
      dictionaryStream = (LZ4_stream_t *)0x0;
    }
    else {
      dictionaryStream = cdict->fastCtx;
    }
    LZ4_attach_dictionary((LZ4_stream_t *)ctx,dictionaryStream);
  }
  else {
    LZ4_resetStreamHC_fast((LZ4_streamHC_t *)ctx,level);
    if (cdict == (LZ4F_CDict *)0x0) {
      dictionary_stream = (LZ4_streamHC_t *)0x0;
    }
    else {
      dictionary_stream = cdict->HCCtx;
    }
    LZ4_attach_HC_dictionary((LZ4_streamHC_t *)ctx,dictionary_stream);
  }
  return;
}

