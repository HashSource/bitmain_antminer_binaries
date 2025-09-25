
void LZ4_attach_HC_dictionary(LZ4_streamHC_t *working_stream,LZ4_streamHC_t *dictionary_stream)

{
  LZ4_streamHC_t *dictionary_stream_local;
  LZ4_streamHC_t *working_stream_local;
  
  if (dictionary_stream == (LZ4_streamHC_t *)0x0) {
    dictionary_stream = (LZ4_streamHC_t *)0x0;
  }
  (working_stream->internal_donotuse).dictCtx = (LZ4HC_CCtx_internal *)dictionary_stream;
  return;
}

