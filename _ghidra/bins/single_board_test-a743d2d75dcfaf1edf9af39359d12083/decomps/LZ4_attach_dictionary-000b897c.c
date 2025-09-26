
void LZ4_attach_dictionary(LZ4_stream_t *workingStream,LZ4_stream_t *dictionaryStream)

{
  LZ4_stream_t *dictionaryStream_local;
  LZ4_stream_t *workingStream_local;
  LZ4_stream_t_internal *dictCtx;
  
  if (dictionaryStream == (LZ4_stream_t *)0x0) {
    dictionaryStream = (LZ4_stream_t *)0x0;
  }
  dictCtx = (LZ4_stream_t_internal *)dictionaryStream;
  if (dictionaryStream != (LZ4_stream_t *)0x0) {
    if ((workingStream->internal_donotuse).currentOffset == 0) {
      (workingStream->internal_donotuse).currentOffset = 0x10000;
    }
    if ((dictionaryStream->internal_donotuse).dictSize == 0) {
      dictCtx = (LZ4_stream_t_internal *)0x0;
    }
  }
  (workingStream->internal_donotuse).dictCtx = dictCtx;
  return;
}

